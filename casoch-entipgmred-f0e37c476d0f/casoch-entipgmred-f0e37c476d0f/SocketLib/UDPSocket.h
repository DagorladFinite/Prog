#pragma once
#include "GenericSocket.h"
//#include "SocketAddress.h"
class UDPSocket :
	public GenericSocket
{
public:
	UDPSocket();
	~UDPSocket();
	int Enviar(const void* data, int lendData, SocketAddress& to);
	int Recibir(void* data, int lenData,  SocketAddress& from);
};

