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

bool ServerSocket::IsInvalidSock()
{
	*listenSocket = socket(AF_INET, SOCK_STREAM, 0);
	serverAddr->sin_family = AF_INET;
	serverAddr->sin_port = htons(9000);	//linker error
	serverAddr->sin_addr.s_addr = htonl(INADDR_ANY);
	cAddrSize = sizeof(serverAddr);
	return *listenSocket == INVALID_SOCKET;
}

bool ServerSocket::IsUnbindedSocket()
{
	return result == SOCKET_ERROR;
}

bool ServerSocket::IsWrongConnection()
{
	return result == SOCKET_ERROR;
}

void ServerSocket::BindSocket() {
	result = bind(*listenSocket, (sockaddr*)serverAddr, sizeof(*serverAddr));	//llinker error
}

void ServerSocket::ListenToConnection()
{
	result = listen(*listenSocket, SOMAXCONN);	//linker error
}

SOCKET ServerSocket::GetSocket()
{
	return *listenSocket;
}

//void ServerSocket::AcceptConnection(ClientSocket& clientSocket)
//{
//	//메인 서버에서 현재 대기중인 클라 소켓을 받아와서 연결할 수 있도록 작성
//	clientSocket.AcceptConnection(*listenSocket);
//}
