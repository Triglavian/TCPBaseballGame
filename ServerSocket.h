#pragma once
#include <WinSock2.h>
#include "ClientSocket.h"

class ServerSocket
{
public:
	ServerSocket();
	~ServerSocket();
	bool IsInvalidSock();
	bool IsUnbindedSocket();
	bool IsWrongConnection();
	void BindSocket();
	void ListenToConnection();
	SOCKET GetSocket();
private:
	sockaddr_in* serverAddr;
	sockaddr_in* clientAddr;
	SOCKET* listenSocket;
	int cAddrSize;
	int result;
	//void AcceptConnection(ClientSocket& clientSocket);
};

