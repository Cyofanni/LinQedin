#ifndef LINQ_LOGIN_H
#define LINQ_LOGIN_H

#include "db.h"


class LinQedInLogin{
private:
    DB* db;      //contiene la sua copia del database
    Username uname;
    QString password;
public:
    LinQedInLogin(const Username&,const QString&);
    bool check() const;    //controlla se username e password passati sono nel db
};

#endif // LINQ_LOGIN_H
