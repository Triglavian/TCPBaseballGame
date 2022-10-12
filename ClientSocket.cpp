#include "ClientSocket.h"

ClientSocket::ClientSocket()
{
	socket = new SOCKET();
	clientAddr = new sockaddr_in();
	retval = 0;
	addrLen = 0;
	num = 0;
	flag = false;
	protocol = Protocol::MAX;
}

ClientSocket::~ClientSocket()
{
	closesocket(*socket);
	if (socket != nullptr) delete socket;
	if (clientAddr != nullptr) delete clientAddr;
}

void ClientSocket::AcceptConnection(const SOCKET lSocket)	//validate accept() result
{
	SetAddrLen();
	*socket = accept(lSocket, (sockaddr*)clientAddr, &addrLen);	//linker error
}

bool ClientSocket::IsFailToAccept()
{
	return *socket == INVALID_SOCKET;
}

sockaddr_in* ClientSocket::GetSockAddr()	//get client ip address
{
	return clientAddr;
}

int ClientSocket::SendBoolPacket(const Protocol& protocol)
{
	this->protocol = protocol;
	flag = true;
	int retval = packetHandler.SendBoolPacket(*socket, protocol, flag);
	flag = false;
	return retval;
}

int ClientSocket::SendBoolPacket(const Protocol& protocol, const bool& flag)
{
	this->protocol = protocol;
	this->flag = flag;
	int retval = packetHandler.SendBoolPacket(*socket, protocol, flag);
	return retval;
}

int ClientSocket::SendIntPacket()
{
	return packetHandler.SendIntPacket(*socket, protocol, num);
}

int ClientSocket::SendAccPacket()
{
	return packetHandler.SendAccPacket(*socket, protocol, acc);
}

int ClientSocket::SendStrPacket()
{
	return packetHandler.SendStrPacket(*socket, protocol, str);
}

int ClientSocket::SendResultPacket()
{
	return packetHandler.SendResultPacket(*socket, protocol, result);
}

int ClientSocket::SendReportPacket(const GameReport& report)
{
	return packetHandler.SendReportPacket(*socket, protocol, report);
}

int ClientSocket::RecvBoolPacket()
{
	return packetHandler.RecvBoolPacket(*socket, protocol, &flag);
}

int ClientSocket::RecvIntPacket()
{
	return packetHandler.RecvIntPacket(*socket, protocol, &num);
}

int ClientSocket::RecvAccPacket()
{
	return packetHandler.RecvAccPacket(*socket, protocol, &acc);
}

int ClientSocket::RecvStrPacket()
{
	return packetHandler.RecvStrPacket(*socket, protocol, &str);
}

int ClientSocket::RecvResultPacket()
{
	return packetHandler.RecvResultPacket(*socket, protocol, &result);
}

void ClientSocket::SetNum(const int& num)
{
	this->num = num;
}

void ClientSocket::SetFlag(const bool& flag)
{
	this->flag = flag;
}

Protocol ClientSocket::GetProtocol()
{
	return protocol;
}
void ClientSocket::SetProtocol(const Protocol& protocol)
{
	this->protocol = protocol;
}

void ClientSocket::SetResult(const Result& result)
{
	this->result = result;
}

int ClientSocket::Getnum()
{
	return num;
}

bool ClientSocket::GetFlag()
{
	return flag;
}

AccountForm& ClientSocket::GetAccountData()
{
	return acc;
}

std::string ClientSocket::GetStr()
{
	return str;
}

Result ClientSocket::GetResult()
{
	return result;
}

void ClientSocket::ClearTempDatas()
{
	flag = false;
	num = 0;
	acc.Clear();
}

void ClientSocket::SetAddrLen()	//set client address object size to val
{
	addrLen = sizeof(*clientAddr);
}
