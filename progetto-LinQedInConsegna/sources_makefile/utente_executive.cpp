#include "../headers/utente_executive.h"

UtenteExecutive::UtenteExecutive(const QString& n, const QString& c, const Username & u,
                                const TipoAccount& t, const QList<QString>& s, const QList<QString>& l,
                                const QList<QString>& s1, const QList<Username>& c1,const QString& p):
                                UtenteBusiness(n,c,u,t,s,l,s1,c1,p) {}

OttieniInfos* UtenteExecutive::getFuntore() const{
    return new OttieniAncheReteDi();
}
