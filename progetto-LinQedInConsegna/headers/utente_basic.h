#ifndef UTENTE_BASIC_H
#define UTENTE_BASIC_H
#include "utente.h"
#include "esiste_utente.h"

class UtenteBasic: public Utente{
    public:
        UtenteBasic(const QString&,const QString&,const Username&,const TipoAccount&,
                    const QList<QString>&,const QList<QString>&,
                    const QList<QString>&,const QList<Username>&,const QString&/*password*/);
                    //costruire il sottooggetto Utente

        virtual OttieniInfos* getFuntore() const;      //overriding
};

#endif
