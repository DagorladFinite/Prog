#include <TCPSpcket.h>
#include <SocketTools.h>
#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <vector>

void sendToAll(std::vector<std::shared_ptr<TCPSpcket>> directions,std::string message,int numberOfConnections){

	for (int i = 0; i < numberOfConnections; i++) {

		directions[i]->Send(message.c_str());
	}



}

void routine(std::string direccion,int conexiones) {

	//Creamos el socket de dispatching para saber cuando se nos conectan
	TCPSpcket dispatchSock;
	SocketAddress addressReceive;
	addressReceive.SetAddress(direccion);
	dispatchSock.Bind(addressReceive);
	std::vector<std::shared_ptr<TCPSpcket>> clientList;
	dispatchSock.Listen(conexiones);

	SocketAddress comesFrom;

	for (int i = 0; i < conexiones; i++)
	{
		clientList.push_back(dispatchSock.Accept(comesFrom));

	}
	
	sendToAll(clientList,"BEGIN",conexiones);
	

}

int main(int argc, char *argv[])
{
	//Cargamos librería sockets
	SocketTools::CargarLibreria();
	//Recibimos los argumentos de consola que nos indican qué dirección y puerto escuchar y a qué dirección y puerto mandar
	std::string direccion = argv[1];
	int conexiones = atoi(argv[2]);
	
	routine(direccion,conexiones);

	//Liberamos la librería
	SocketTools::DescargarLibreria();
}
