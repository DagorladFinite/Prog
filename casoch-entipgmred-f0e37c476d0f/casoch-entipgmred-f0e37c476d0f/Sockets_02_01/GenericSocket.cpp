#include "GenericSocket.h"
#include "SocketTools.h"


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
	SocketTools::MostrarError("Binded!");
	system("pause");
	return 0;
}
