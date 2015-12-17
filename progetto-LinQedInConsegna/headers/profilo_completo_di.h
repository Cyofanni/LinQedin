#ifndef PROFILO_COMPLETO_DI_H
#define PROFILO_COMPLETO_DI_H

#include "esiste_utente.h"

class ProfiloCompletoDi: public EsisteUtente{    //Funtore per servizio Business: permette di ottenere da una ricerca il profilo completo di un utente;
    public:
        InfoVis_Business* operator() (const Profilo&,QTextEdit*) const;
};

#endif // PROFILO_COMPLETO_DI_H
