#include <TCPSpcket.h>
#include <SocketTools.h>
#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <vector>

void routine(std::string direccion, std::string nick) {

	//Creamos el socket de conexion
	TCPSpcket connectSock;
	SocketAddress addressSend;
	addressSend.SetAddress(direccion);

	//Nos conectamos al servidor
	connectSock.Connect(addressSend);

	char message[1300];
	connectSock.Recieve(message, 1300);

	std::string strMessage = message;
	if (strMessage == "BEGIN"){

		std::cout << "SE ISO CONEXION MANES";
		system("pause");
	}
}

int main(int argc, char *argv[])
{
	//Cargamos librería sockets
	SocketTools::CargarLibreria();

	std::string direccion = argv[1];
	std::string nick = argv[2];

	routine(direccion, nick);


	//Liberamos la librería
	SocketTools::DescargarLibreria();
}