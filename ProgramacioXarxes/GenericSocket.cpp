#include "GenericSocket.h"



GenericSocket::GenericSocket()
{
}

GenericSocket::GenericSocket(int _type)
{
	s = socket(AF_INET, _type, 0);

	if (s == INVALID_SOCKET) {
		std::string errormessage = "Error al crear socket: ";
		SocketTools::ShowError(errormessage);
	}
	else {
		std::string errormessage = "Socket Correcto: ";
		SocketTools::ShowError(errormessage);
	}
}


GenericSocket::~GenericSocket()
{
	int temp = shutdown(s, SD_BOTH);
	if (temp != 0)
	{
		std::string errormessage = "Error al destruir socket: ";
		SocketTools::ShowError(errormessage);
	}

	closesocket(s);
}
