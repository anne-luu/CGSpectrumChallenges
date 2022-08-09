#include "Client.h"

void Client::ClientListenerThread()
{
    while (isConnected)
    {
        ENetEvent event;
        /*Wait up to 1000 milliseconds for an event. */
        while (enet_host_service(client, &event, 1000) > 0)
        {
            switch (event.type)
            {
            case ENET_EVENT_TYPE_RECEIVE:
                /*cout << "A packet of length " << event.packet->dataLength
                    << " containing " << (char*)event.packet->data << ".\n";*/                
                cout << (char*)event.packet->data << endl;
                
                /* Clean up the packet now that we're done using it. */
                enet_packet_destroy(event.packet);

                break;
            }
        }
    }
}

Client::Client(string addr, unsigned short port, string name)
    :name(name)
    ,peer(nullptr)
    ,isConnected(true)
{ 
    client = enet_host_create(NULL /* create a client host */,
        1 /* only allow 1 outgoing connection */,
        2 /* allow up 2 channels to be used, 0 and 1 */,
        0 /* assume any amount of incoming bandwidth */,
        0 /* assume any amount of outgoing bandwidth */);

    //Connect to server
    enet_address_set_host(&address, addr.c_str());
    address.port = port;

    if (client == nullptr)
    {
        fprintf(stderr, "An error occurred while trying to create an ENet client host.\n");
        //exit(EXIT_FAILURE);
        return;
    }

    /* Initiate the connection, allocating the two channels 0 and 1. */
    peer = enet_host_connect(client, &address, 2, 0);

    if (peer == NULL)
    {
        fprintf(stderr, "No available peers for initiating an ENet connection.\n");
        //exit(EXIT_FAILURE);
        return;
    }

    ENetEvent event;

    /* Wait up to 5 seconds for the connection attempt to succeed. */
    if (enet_host_service(client, &event, 5000) > 0 &&
        event.type == ENET_EVENT_TYPE_CONNECT)
    {
        cout << "Connection to 127.0.0.1:" << address.port << " succeeded." << std::endl;
    }
    else
    {
        /* Either the 5 seconds are up or a disconnect event was */
        /* received. Reset the peer in the event the 5 seconds   */
        /* had run out without any significant event.            */
        enet_peer_reset(peer);
        cout << "Connection to 127.0.0.1:" << address.port << " failed." << endl;
        return;
    }

    cout << "Created Client " << name << " at port " << address.port << endl;

    string message = name + " joins the chat.";
    ENetPacket* packet = enet_packet_create(message.c_str(),
        message.size() + 1,
        ENET_PACKET_FLAG_RELIABLE);

    enet_host_broadcast(client, 0, packet);

    clientListener = std::thread(&Client::ClientListenerThread, this);
}

Client::~Client()
{
    clientListener.join();

    if (client != nullptr)
    {
        enet_host_destroy(client);
    }

    std::cout << "Destroy Client " << address.port << std::endl;
}

void Client::SendMessage(string message)
{
    message = name + ": " + message;
    ENetPacket* packet = enet_packet_create(message.c_str(),
        message.size() + 1,
        ENET_PACKET_FLAG_RELIABLE);

    enet_host_broadcast(client, 0, packet);
}

ENetHost* Client::GetHost()
{
    return client;
}

void Client::Disconnect()
{
    isConnected = false;
}