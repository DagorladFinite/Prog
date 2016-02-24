#include "UDPSocket.h"



UDPSocket::UDPSocket():GenericSocket(SOCK_DGRAM)
{
}


UDPSocket::~UDPSocket()
{
}

int UDPSocket::Enviar(const void * data, int lendData, SocketAddress& to)
{
	const sockaddr address = to.getAddr();
	sendto(GenericSocket::GetSock(), (const char*)data, lendData, 0, &address, sizeof(to));
	return 0;
}

int UDPSocket::Recibir(void * data, int lenData, SocketAddress & from)
{
	sockaddr address;
	int longr = sizeof(address);
	recvfrom(GenericSocket::GetSock(), (char*)data, lenData, 0, &address, &longr);
	from.SetAddress(address);
	return 0;
}
