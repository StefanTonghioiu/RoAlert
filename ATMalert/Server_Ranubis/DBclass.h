#pragma once

#include <iostream>
#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>

#define SQL_RESULT_LEN 240
#define SQL_RETURN_CODE_LEN 1000
using namespace std;

class DBclass
{
    private:
        SQLHANDLE ConnectionHandle;
        SQLHANDLE StatementHandle;
        SQLHANDLE EnvironmentHandle;
        SQLWCHAR CodeLen[SQL_RETURN_CODE_LEN];

    public:
        void ConnectToDatabase();
        void DisconnectDatabase();
        string MakeARequestQuery(string str);
        void MakeASendQuery(string str);
};

