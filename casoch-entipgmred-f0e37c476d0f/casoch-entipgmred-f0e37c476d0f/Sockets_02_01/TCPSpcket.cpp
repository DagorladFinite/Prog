#include "TCPSpcket.h"



TCPSpcket::TCPSpcket():GenericSocket(SOCK_STREAM)
{
}

TCPSpcket::TCPSpcket(SOCKET sock) : GenericSocket(SOCK_STREAM)
{
	this->sock = sock;
}

 TCPSpcket TCPSpcket::Accept(SocketAddress & from) {
	sockaddr sa;
	int sizesa = sizeof(sockaddr);
	SOCKET newsocket = accept(sock, &sa, &sizesa);
	from.SetAddress(sa);
	TCPSpcket tcpSocket(newsocket);
	return tcpSocket;
}


TCPSpcket::~TCPSpcket()
{
	shutdown(sock, SD_BOTH);
}

int TCPSpcket::Listen(int backlog)
{
	int err = listen(sock, backlog);

	if (err == -1)
	{
		SocketTools::MostrarError("Error al TCPSocket::Listen");
	}
	return 0;
}

int TCPSpcket::Connect(SocketAddress & sa)
{
	
	sockaddr dir;
	sa.getAddr(dir);
	int Size = sizeof(dir);
	int err = connect(sock, &dir, Size);
	if (err == -1)
	{
		SocketTools::MostrarError("Error al TCPSocket::Connect");
	}
	return err;
}

int TCPSpcket::Send(const void * data)
{
	int numByteSent = send(sock, (const char*)data, 1300, 0);

	if (numByteSent > 0) {
		return numByteSent;
	}
	else {
		SocketTools::MostrarError("Error en TCPSOCKET::Send");
		return -1;
	}
	//return 0;
}

int TCPSpcket::Recieve(void * data, int lenData)
{
	//char* buffer;
	int numByteRecieved = recv(sock, (char*) data, lenData, 0);
	
	 if(numByteRecieved == 0) {
		SocketTools::MostrarError("Closed Connection");
		//return -1;
	}
	 else if (numByteRecieved < 0) {
		 SocketTools::MostrarError("Error en TCPSocket::Recieve");
	 }
	return numByteRecieved;
}
