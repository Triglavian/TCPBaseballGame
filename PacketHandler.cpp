#include "PacketHandler.h"

PacketHandler::PacketHandler()
{

}

PacketHandler::~PacketHandler()
{

}

int PacketHandler::SendBoolPacket(SOCKET socket, Protocol protocol, bool data)
{
	return SendPacket(socket, protocol, data);
}

int PacketHandler::SendIntPacket(SOCKET socket, Protocol protocol, int data)
{
	return SendPacket(socket, protocol, data);
}

int PacketHandler::SendAccPacket(SOCKET socket, Protocol protocol, AccountForm data)
{
	return SendPacket(socket, protocol, data);
}

int PacketHandler::SendStrPacket(SOCKET socket, Protocol protocol, std::string data)
{
	return SendPacket(socket, protocol, data);
}

int PacketHandler::SendResultPacket(SOCKET socket, Protocol protocol, Result data)
{
	return SendPacket(socket, protocol, data);
}

int PacketHandler::SendReportPacket(SOCKET socket, Protocol protocol, GameReport data)
{
	return SendPacket(socket, protocol, data);
}

int PacketHandler::RecvBoolPacket(SOCKET socket, Protocol& protocol, bool* data)
{
	return RecvPacket(socket, protocol, data);
}

int PacketHandler::RecvIntPacket(SOCKET socket, Protocol& protocol, int* data)
{
	return RecvPacket(socket, protocol, data);
}

int PacketHandler::RecvAccPacket(SOCKET socket, Protocol& protocol, AccountForm* data)
{
	return RecvPacket(socket, protocol, data);
}

int PacketHandler::RecvStrPacket(SOCKET socket, Protocol& protocol, std::string* data)
{
	return RecvPacket(socket, protocol, data);
}

int PacketHandler::RecvResultPacket(SOCKET socket, Protocol& protocol, Result* data)
{
	return RecvPacket(socket, protocol, data);
}

int PacketHandler::RecvReportPacket(SOCKET socket, Protocol& protocol, GameReport* data)
{
	return RecvPacket(socket, protocol, data);
}
