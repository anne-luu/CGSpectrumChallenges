#include <enet/enet.h>
#include <vector>
#include <iostream>
#include <string>
#include "Client.h"

using namespace std;

ENetAddress address;
ENetHost* server = nullptr;

vector<ENetPeer*> peers;

bool CreateServer()
{
    /* Bind the server to the default localhost.     */
    /* A specific host address can be specified by   */
    /* enet_address_set_host (& address, "x.x.x.x"); */
    address.host = ENET_HOST_ANY;
    /* Bind the server to port 1234. */
    address.port = 1234;
    server = enet_host_create(&address /* the address to bind the server host to */,
        32      /* allow up to 32 clients and/or outgoing connections */,
        2      /* allow up to 2 channels to be used, 0 and 1 */,
        0      /* assume any amount of incoming bandwidth */,
        0      /* assume any amount of outgoing bandwidth */);

    return server != nullptr;
}

int main(int argc, char** argv)
{
    if (enet_initialize() != 0)
    {
        fprintf(stderr, "An error occrred while initializing ENet.\n");
        cout << "An error occurred while initalizing ENet." << endl;
        return EXIT_FAILURE;
    }

    atexit(enet_deinitialize);

    cout << "1) Create Server " << endl;
    cout << "2) Create Client " << endl;
    int UserInput;
    cin >> UserInput;

    if (UserInput == 1)
    {
        if (!CreateServer())
        {
            fprintf(stderr,
                "An error occurred while trying to create an ENet server host.\n");
            exit(EXIT_FAILURE);
        }

        while (1)
        {
            ENetEvent event;
            /* Wait up to 1000 milliseconds for an event. */
            while (enet_host_service(server, &event, 10000) > 0)
            {
                switch (event.type)
                {
                case ENET_EVENT_TYPE_CONNECT:
                    /*cout << "A new client connected from "
                        << event.peer->address.host << ":"
                        << event.peer->address.port << ".\n";*/
                    /* Store any relevant client information here. */
                    event.peer->data = (void*)("Client information");
                    
                    peers.push_back(event.peer);
                    
                    break;
                case ENET_EVENT_TYPE_RECEIVE:
                    /*cout << "A packet of length " << event.packet->dataLength
                        << " containing " << (char*)event.packet->data
                        << " was received from " << (char*)event.peer->data
                        << " on channel " << event.channelID << ".\n";*/
                    cout << (char*)event.packet->data << endl;

                    {
                        string message = string((char*)event.packet->data);
                        ENetPacket* packet = enet_packet_create(message.c_str(),
                            message.size() + 1,
                            ENET_PACKET_FLAG_RELIABLE);

                        for (auto p : peers)
                        {
                            if (p != event.peer)
                            {
                                enet_peer_send(p, 0, packet);
                            }
                        }                        
                    }

                    /* Clean up the packet now that we're done using it. */
                    enet_packet_destroy(event.packet);

                    break;

                case ENET_EVENT_TYPE_DISCONNECT:
                    printf("%s disconnected.\n", (char*)event.peer->data);
                    /* Reset the peer's client information. */
                    event.peer->data = NULL;
                }
            }
        }
    }
    else if (UserInput == 2)
    {
        string name;
        cout << "Enter name: ";
        cin >> name;

        cin.ignore(100, '\n');
        cin.clear();

        Client client("127.0.0.1", 1234, name);

        string message;

        while (1)
        {
            cout << "Message: " << endl;
            std::getline(cin, message);

            client.SendMessage(message);
        }
    }
    else
    {
        cout << "Invalid Input" << endl;
    }

    if (server != nullptr)
    {
        enet_host_destroy(server);
    }

    return EXIT_SUCCESS;
}