#include "../headers/username.h"

Username::Username(const QString& str): login(str){}

Username::operator QString(){
    return login;
}

QString Username::getUsernameAsQString() const{
   return login;
}

bool Username::operator==(const Username& u) const{
    return login == u.login;	         //uguaglianza tra stringhe
}

bool Username::operator!=(const Username& u) const{
    return !(*this == u);
}
