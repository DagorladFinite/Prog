#pragma once
#define WIN32_LEAN_AND_MEAN
#include <WinSock2.h>
#include <Windows.h>
#include "SocketAddress.h"

class GenericSocket
{
protected:
	SOCKET sock;
public:
	SOCKET GetSock();
	GenericSocket(int type);
	virtual ~GenericSocket();
	int Bind(SocketAddress& address);
	int nonblocking(bool nonBLocking);
};

