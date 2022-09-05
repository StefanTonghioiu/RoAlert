#include "Mesaje.h"

string separa(string& old) {
    int pos = 0;
    pos = old.find("|");
    string ret = old.substr(0, pos);
    old.erase(0, pos + 1);
    return ret;
}
//FUNCTION OVERLOAD pe Select
string select(string select, string from, string where, string equals) {
    string querystring = "SELECT ";
    querystring += select;
    querystring += " FROM ";
    querystring += from;
    querystring += " WHERE ";
    querystring += where;
    querystring += "= '";
    querystring += equals;
    querystring += "'";

    return querystring;
}


string select(string select, string from) {
    string querystring = "SELECT ";
    querystring += select;
    querystring += " FROM ";
    querystring += from;

    return querystring;
}

string DeleteSQL(string del, string id, string nume) {
    string querystring = "DELETE FROM ";
    querystring += del;
    querystring += " WHERE " + del + "." + id + "='" + nume + "'";

    return querystring;

}
string insert(string insert, string campuri, string Valori) {
    string querystring = "INSERT INTO ";
    querystring += insert;
    querystring += "(";
    querystring += campuri;
    querystring += ") VALUES (";
    querystring += Valori;
    querystring += ")";

    return querystring;

}

void Mesaje::raspuns()
{
    int i = buff.find("&");
    string comanda = buff.substr(0, i);
    buff.erase(0, i + 1);
    if (comanda == "Logare")
        Answer(credential(buff), ClientSocket);
    if (comanda == "Sos")
        Answer(sos_button(), ClientSocket);
    if (comanda == "Raport")
        Answer(report(), ClientSocket);

}

string Mesaje::credential(string buff)
{
    int i;
        string username;
        string pass;
        i = buff.find("&");
        username = buff.substr(0, i);
        buff.erase(0, i + 1);
        i = buff.find("&");
        pass = buff.substr(0, i);
        buff.erase(0, i + 1);
        pass += "&";
        string dpassword;
        dpassword = BazaDeDate->MakeARequestQuery(select("parola", "DateConectare", "username", username));
        
        if (username == "admin" && pass == "1234") {
            buff.clear();
            buff = "Admin";
        }
        else if(pass==dpassword) {
            buff.clear();
            buff = username+"&"+pass;
        }
        else {
            buff = "denied";
        }
    return buff;
}

string Mesaje::sos_button()
{
        buff = " Mesajul de ajutor a fost trimis ! \r\n In cateva secunde va vom verifica !";
        return buff;
}

string Mesaje::feedback()
{
    return string();
}

string Mesaje::report()
{
    string raport;
    int i = buff.find("&");
    raport = buff.substr(0, i);
    buff.erase(0, i + 1);
    buff.clear();
    //sent report to clasa specifica
    buff = "Raport trimis cu succes";
    return buff;
}

string Mesaje::signUp()
{
    return string();
}

void Mesaje::Answer(string buff, SOCKET ClientSocket)
{
    send(ClientSocket, buff.c_str(), buff.size(), 0);
    printf("Message sent: %s\n", buff);
}
