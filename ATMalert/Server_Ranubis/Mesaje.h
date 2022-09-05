#pragma once
#include<iostream>
#include <WS2tcpip.h>
#include "DBclass.h"

using namespace std;
class Mesaje
{
private:
	string buff;
	SOCKET ClientSocket;
	DBclass* BazaDeDate;
public:
	Mesaje(string s, SOCKET ClientSocket, DBclass* b) : buff(s), ClientSocket(ClientSocket){ BazaDeDate = b; };
	~Mesaje() {};
	void raspuns();
	string credential(string buff);
	string sos_button();
	string feedback();
	string report();
	string signUp();
	void Answer(string buff, SOCKET ClientSocket);
};

