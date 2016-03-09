#pragma once
#include "GenericSocket.h"
#include "SocketTools.h"
class TCPSpcket :
	public GenericSocket
{
public:
	TCPSpcket();
	~TCPSpcket();
	TCPSpcket(SOCKET sock);
	int Listen(int backlog);
	int Connect(SocketAddress &sa);
	int Send(const void* data);
	int Recieve(void* data, int lenData);
	std::shared_ptr<TCPSpcket> Accept(SocketAddress &from);
};

