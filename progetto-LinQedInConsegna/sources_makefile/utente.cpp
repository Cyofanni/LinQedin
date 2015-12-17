#include "../headers/utente.h"

Utente::Utente(const QString& n, const QString& c, const Username& u, const TipoAccount& t,
               const QList<QString>& s, const QList<QString>& l,
                const QList<QString>& s1, const QList<Username>& c1,const QString& p):
                                                                     pf(n,c,u,t,s,l,s1,c1,p),
                                                                     rete(new Rete){
    //la rete va allocata a partire dalla lista di contatti letta da file e contenuta in profilo
    //ma deve riceverli come puntatori ad utente
}

Utente::~Utente(){
    delete rete;      //delete chiama il distruttore ridefinito di Rete
}
