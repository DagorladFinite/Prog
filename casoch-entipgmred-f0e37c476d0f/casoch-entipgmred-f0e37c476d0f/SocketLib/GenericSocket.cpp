#include "GenericSocket.h"
#include "SocketTools.h"


SOCKET GenericSocket::GetSock()
{
	return sock;
}

GenericSocket::GenericSocket(int type)
{
	sock = socket(AF_INET, type, 0);
	if (sock == INVALID_SOCKET)
	{
		SocketTools::MostrarError("Error en GenericSocket constructor");
	}
}


GenericSocket::~GenericSocket()
{
	int err = closesocket(sock);
	if (err == -1)
	{
		SocketTools::MostrarError("Error al GenericSocket::~GenericSocket");
	}
}

int GenericSocket::Bind(SocketAddress & address)
{
	const sockaddr _A= address.getAddr();
	int err = bind(sock, &_A , sizeof(address));
	if (err == -1)
	{
		SocketTools::MostrarError("Error al GenericSocket::Bind");
		return -1;
	}
	//system("pause");
	return 0;
}

int GenericSocket::nonblocking(bool nonBLocking)
{
	u_long* argv;
	if (nonBLocking)
		argv = (u_long*)1;
	else
		argv = (u_long*)0;

	int err = ioctlsocket(sock, FIONBIO, argv);
	if (err == -1)
	{
		SocketTools::MostrarError("Error al GenericSocket::nonblocking");
	}
	return err;
}
