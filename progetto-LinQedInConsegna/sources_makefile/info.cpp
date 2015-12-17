#include "../headers/info.h"

Info::Info(const QString& n/*nome*/,const QString& c/*cognome*/,
        const Username& u,const TipoAccount& t,const QList<QString>& s/*skills*/,
        const QList<QString>& l /*lingue*/,
        const QList<QString>& s1/*università*/,const QList<Username>& c1,const QString& p/*password*/):
                    nome(n),cognome(c),uname(u),tAcc(t),skills(s),lingue(l),
                    studi(s1),contatti(c1),password(p){}

