#include "ServerSocket.h"

ServerSocket::ServerSocket()
{
	serverAddr = new sockaddr_in();
	clientAddr = new sockaddr_in();
	listenSocket = new SOCKET();
	cAddrSize = 0;
	result = 0;
}

ServerSocket::~ServerSocket()
{
	if (serverAddr != nullptr) delete serverAddr;
	if (clientAddr != nullptr) delete clientAddr;
	if (listenSocket != nullptr) {
		closesocket(*listenSocket);
		delete listenSocket;
	}
}

bool ServerSocket::IsInvalidSock()	//create and validate invalid socket creation error
{
	*listenSocket = socket(AF_INET, SOCK_STREAM, 0);
	serverAddr->sin_family = AF_INET;
	serverAddr->sin_port = htons(9000);	//linker error
	serverAddr->sin_addr.s_addr = htonl(INADDR_ANY);
	cAddrSize = sizeof(serverAddr);
	return *listenSocket == INVALID_SOCKET;
}

bool ServerSocket::IsUnbindedSocket()	//validate unbinded socket error 
{
	return result == SOCKET_ERROR;
}

bool ServerSocket::IsWrongConnection()	//validate incommlete connection with client
{
	return result == SOCKET_ERROR;
}

void ServerSocket::BindSocket() //bind socket to connect
{
	result = bind(*listenSocket, (sockaddr*)serverAddr, sizeof(*serverAddr));
}

void ServerSocket::ListenToConnection()	//keep listening until receive any client's connection
{
	result = listen(*listenSocket, SOMAXCONN);
}

SOCKET ServerSocket::GetSocket()	//socket value returner
{
	return *listenSocket;
}