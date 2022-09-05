#pragma once
class IServer
{
public:
    virtual void ConnEstablishClient()=0;
    virtual void ConnectToWinsock()=0;
    virtual void MantainConnection()=0;
    virtual void BrokeConn()=0;
    virtual void IpBind() = 0;
    virtual void CleanUp() = 0;
   // virtual void datedebaza(DBclass* b) = 0;
};

