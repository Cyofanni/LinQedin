#include "../headers/linq_login.h"

LinQedInLogin::LinQedInLogin(const Username& u,const QString& p): db(new DB),uname(u),password(p){
                                                        //costruire il database!!!!!
    db->load();         //carica il database in memoria
}

bool LinQedInLogin::check() const{
    bool allow = false;
    for (int i = 0; i < db->sizeDB(); ++i){
        Profilo pf = (db->at(i))->pf;
        if (pf.getUsername() == uname and pf.getPassword() == password){
          //se c'è un utente con username e password passati
            allow = true;
            break;
        }
    }
    delete db;    //dealloca l'oggetto DB puntato da db
    //allow: true se c'è un utente con username e password passati
    //allow: false altrimenti
    return allow;
}
