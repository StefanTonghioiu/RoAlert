#include <iostream>
#include "factory.h"


using namespace std;

void main() {


	DBclass baza;
	baza.ConnectToDatabase();
	IServer* srv = factory::createInst(&baza);
	srv->ConnectToWinsock();
	srv->IpBind();

	while (true)
	{
		srv->ConnEstablishClient();
		srv->MantainConnection();
		srv->BrokeConn();
	}

	srv->CleanUp();

}
