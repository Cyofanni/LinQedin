#include "../headers/utente_basic.h"

UtenteBasic::UtenteBasic(const QString& n, const QString& c, const Username& u,
                         const TipoAccount& t, const QList<QString>& s, const QList<QString>& l,
                         const QList<QString>& s1, const QList<Username>& c1,
                         const QString& p/*password*/):
                         Utente(n,c,u,t,s,l,s1,c1,p) {}

OttieniInfos* UtenteBasic::getFuntore() const{
    return new EsisteUtente();
}
