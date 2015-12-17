#ifndef ESISTE_UTENTE_H
#define ESISTE_UTENTE_H

#include "ottieni_infos.h"

class EsisteUtente: public OttieniInfos{        //Funtore per servizio Basic:controlla solamente se nel DB LinkedIn esiste un utente con un dato nome e/o cognome;
    public:
        InfoVis_Basic* operator() (const Profilo&,QTextEdit*) const;  //dal puntatore a utente ottengo tutte le infos
};


#endif // ESISTE_UTENTE_H
