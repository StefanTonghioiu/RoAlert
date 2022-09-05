#pragma once
#include "IServer.h"
#include<iostream>
#include "Mesaje.h"
#pragma comment(lib, "Ws2_32.lib")
#include <WS2tcpip.h>
#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT "27000"
#include <string>
using namespace std;
class Server :
    public IServer
{
private:
    WSADATA wsaData;
    int iResult;

    SOCKET ListenSocket;
    SOCKET ClientSocket;

    struct addrinfo* result;
    struct addrinfo hints;
    sockaddr_in client;
    DBclass* baza;
    int iSendResult;
    char recvbuf[DEFAULT_BUFLEN];
    int recvbuflen = DEFAULT_BUFLEN;
public:
    Server(DBclass*b) : IServer() {
        ListenSocket = INVALID_SOCKET;
        ClientSocket = INVALID_SOCKET;
        result = NULL;
        baza = b;
    }
    virtual ~Server() {};
    virtual void ConnEstablishClient();
    virtual void ConnectToWinsock();
    virtual void MantainConnection();
    virtual void BrokeConn();
    virtual void IpBind();
    virtual void CleanUp();
};

