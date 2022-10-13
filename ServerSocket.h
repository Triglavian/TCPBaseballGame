#pragma once
#include <WinSock2.h>
#include "ClientSocket.h"

class ServerSocket
{
public:
	ServerSocket();
	~ServerSocket();
	bool IsInvalidSock();		//create and validate invalid socket creation error
	bool IsUnbindedSocket();	//validate unbinded socket error 
	bool IsWrongConnection();	//validate incommlete connection with client
	void BindSocket();			//bind socket to connect
	void ListenToConnection();	//keep listening until receive any client's connection
	SOCKET GetSocket();			//socket value returner
private:
	sockaddr_in* serverAddr;
	sockaddr_in* clientAddr;
	SOCKET* listenSocket;
	int cAddrSize;
	int result;
};

