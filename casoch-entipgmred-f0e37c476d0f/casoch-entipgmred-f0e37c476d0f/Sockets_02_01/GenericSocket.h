#pragma once
#define WIN32_LEAN_AND_MEAN
#include <WinSock2.h>
#include <Windows.h>
#include "SocketAddress.h"

class GenericSocket
{
private:
	SOCKET sock;
public:
	SOCKET GetSock();
	GenericSocket(int type);
	~GenericSocket();
	int Bind(SocketAddress& address);
};

