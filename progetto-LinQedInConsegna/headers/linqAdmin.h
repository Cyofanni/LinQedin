#ifndef LINQADMIN_H
#define LINQADMIN_H

#include "db.h"

/*#################*/
#include "linqClient.h"
/*#################*/

class LinQedInClient;
class LinQedInAdmin{
    public:
        DB* db;     //inizializzato da file,gestito in memoria,salvabile su file

        LinQedInAdmin();
        void insert(Utente* u);    //inserisce nuovo utente nel DB
        void remove(const Username&) throw (UtenteNonEsistente);           //deve implicare la rimozione dell'utente da tutte le reti

        Utente* find(const Username&) const;      //potrebbe ritornare qualcosa?
        void changeSubscriptionType(const Username& u,TipoAccount t_nuovo);      //cambia tra Basic, Business, Executive //invoca DB::modificaAccount(Username,TipoAccount)
        void save() const;
        void pubblicaModifiche(LinQedInClient* client) const;//passata lineare e copia di tutti gli SmartUtente del DB del client
};

#endif
