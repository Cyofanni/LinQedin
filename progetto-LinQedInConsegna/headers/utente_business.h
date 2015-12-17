#ifndef UTENTE_BUSINESS_H
#define UTENTE_BUSINESS_H
#include "utente_basic.h"
#include "profilo_completo_di.h"

class UtenteBusiness: public UtenteBasic{
    public:
        UtenteBusiness(const QString&,const QString&,const Username&,const TipoAccount&,
                        const QList<QString>&,const QList<QString>&,
                        const QList<QString>&,const QList<Username>&,const QString&/*password*/);
                        //costruire il sottooggetto UtenteBasic

        virtual OttieniInfos* getFuntore() const;     //overriding
};

#endif
