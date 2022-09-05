#include "Server.h"

void Server::ConnEstablishClient()
{
    int clientSize = sizeof(client);
    ClientSocket = accept(ListenSocket, (sockaddr*)&client, &clientSize);
    if (ClientSocket == INVALID_SOCKET) {
        printf("accept failed with error: %d\n", WSAGetLastError());
        closesocket(ListenSocket);
        WSACleanup();
        return;
    }
    char host[NI_MAXHOST];	 //numele clientului
    char service[NI_MAXSERV];//service port-client connection

    ZeroMemory(host, NI_MAXHOST);
    ZeroMemory(service, NI_MAXSERV);

    if (getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0)
    {
        cout << host << " connected on port " << service << endl;
    }
    else {
        inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
        cout << host << " connected on port " << ntohs(client.sin_port) << endl;
    }
}

void Server::ConnectToWinsock()
{
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        printf("WSAStartup failed with error: %d\n", iResult);
        WSACleanup();
        return;
    }

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_flags = AI_PASSIVE;
    
    
    iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
    if (iResult != 0) {
        printf("getaddrinfo failed with error: %d\n", iResult);
        WSACleanup();
        return;
    }

    //creare socket ascultare
    ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (ListenSocket == INVALID_SOCKET) {
        printf("socket failed with error: %ld\n", WSAGetLastError());
        freeaddrinfo(result);
        WSACleanup();
        return;
    }

}

void Server::MantainConnection()
{

    char buff[4096];
    do {
        ZeroMemory(buff, 4096);
        int bytesReceived = recv(ClientSocket, buff, 4096, 0);
        if (bytesReceived == SOCKET_ERROR)
        {
            break;
        }
        if (bytesReceived == 0) {
            break;
        }
        Mesaje mesager(buff,ClientSocket,baza);
        cout << "Am primit : " << buff << endl;
        mesager.raspuns();
         
    } while (true);
}

void Server::BrokeConn()
{
    closesocket(ClientSocket);
}

void Server::IpBind()
{
    iResult = bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen);
    if (iResult == SOCKET_ERROR) {
        printf("bind failed with error: %d\n", WSAGetLastError());
        freeaddrinfo(result);
        closesocket(ListenSocket);
        WSACleanup();
        return;
    }

    freeaddrinfo(result);
    //creare socket listen
    iResult = listen(ListenSocket, SOMAXCONN);
    if (iResult == SOCKET_ERROR) {
        printf("listen failed with error: %d\n", WSAGetLastError());
        closesocket(ListenSocket);
        WSACleanup();
        return;
    }
}

void Server::CleanUp()
{
    closesocket(ListenSocket);
    WSACleanup();
}
