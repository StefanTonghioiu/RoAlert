#pragma once
#include "IServer.h"
#include "Server.h"
#include "DBclass.h"
#include<iostream>
using namespace std;
class factory
{
public:
	static IServer* createInst(DBclass* b) {
		return new Server(b);
	}
};

