#pragma once
#include <enet/enet.h>
#include <iostream>
#include <string>
#include <thread>

using std::string;
using std::cout;
using std::endl;

class Client
{
	ENetAddress address;
	ENetHost* client;
	ENetPeer* peer;
	string name; 
	std::thread clientListener;
	bool isConnected;

	void ClientListenerThread();

public:
	Client(string address, unsigned short port, string name);
	~Client();

	void SendMessage(string message);
	ENetHost* GetHost();
	void Disconnect();
};

