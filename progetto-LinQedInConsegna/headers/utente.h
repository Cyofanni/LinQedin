#ifndef UTENTE_H
#define UTENTE_H

/*########*/
/*########*/

#include "profilo.h"
#include "ottieni_infos.h"

#include "rete.h"

//NB: PER LE DICHIARAZIONI DI AMICIZIA NON SERVONO DICHIARAZIONI INCOMPLETE DI CLASSI
class Utente{					//classe base astratta
    friend class DB;		//DB può accedere alla rete interna ad ogni utente
    friend class LinQedInClient;
    private:
        Rete* rete;
    public:
        Profilo pf;
        Utente(const QString&,const QString&,const Username&,const TipoAccount&,    //invoca il costruttore di Profilo	per costruire pf
               const QList<QString>&,const QList<QString>&,
               const QList<QString>&,const QList<Username>&,const QString&/*password*/);

        virtual OttieniInfos* getFuntore() const = 0;     //ritorna il funtore adatto in base al tipo di utente
        virtual ~Utente();       /*distruttore virtuale:deve distruggere la rete==>solo i puntatori
                                 del contenuti nella lista vanno deallocati,non gli oggetti puntati
                                 'QList::clear()' will only destroy pointers, not the objects behind them (same with removeAt() of course).
                                 Delete needs to be called explicitely on each item or, as already said, qDeleteAll() can be used.*/
};

#endif
