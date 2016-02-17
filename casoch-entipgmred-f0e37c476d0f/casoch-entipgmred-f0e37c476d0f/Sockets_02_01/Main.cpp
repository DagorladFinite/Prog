#include "GenericSocket.h"
#include "SocketTools.h"

void test()
{
	GenericSocket socket(SOCK_DGRAM);
}

int main()
{
	SocketTools::CargarLibreria();
	test();
	SocketTools::DescargarLibreria();
	//GenericSocket::Bind();
	system("pause");
}