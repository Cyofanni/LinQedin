#ifndef UTENTE_EXECUTIVE_H
#define UTENTE_EXECUTIVE_H

#include "utente_business.h"
#include "ottieni_anche_rete_di.h"

class UtenteExecutive: public UtenteBusiness{
    public:
        UtenteExecutive(const QString&,const QString&,const Username&,const TipoAccount&,
                        const QList<QString>&,const QList<QString>&,
                        const QList<QString>&,const QList<Username>&,const QString&/*password*/);

        virtual OttieniInfos* getFuntore() const;    //overriding
};

#endif
