#include "../headers/utente_business.h"

UtenteBusiness::UtenteBusiness(const QString& n, const QString& c, const Username& u,
                                const TipoAccount& t, const QList<QString>& s, const QList<QString>& l,
                                const QList<QString>& s1, const QList<Username>& c1,const QString& p):
                                UtenteBasic(n,c,u,t,s,l,s1,c1,p){}

OttieniInfos* UtenteBusiness::getFuntore() const{
    return new ProfiloCompletoDi();
}
