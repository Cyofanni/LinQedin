#ifndef LINQINCLIENT_H
#define LINQINCLIENT_H

#include "db.h"
#include "eccezioni.h"
#include <QTextEdit>

class LinQedInAdmin;      //dichiarazione incompleta invece di inclusione

class LinQedInClient{
    friend class LinQedInAdmin; 	//così l'admin ha accesso a db
    friend class ClientWidget;

    private:
        Utente* u;
        DB* db;         //inizializzato da file, usato in sola lettura;;;;;;;;; perché PUNTATORE a DB????

    public:
        LinQedInClient(const Username& s/*,LinQedInAdmin* admin*/); //il cliente in costruzione dichiara di dipendere dall'amministratore admin

        void aggiornaProfilo(const QString&,const QString&,const QList<QString>&,
                             const QList<QString>&,const QList<QString>&);
        Profilo showProfilo() const;      //usata da Mostra il mio profilo nella GUI del client

        void insertInRete(Utente*);
	
	void removeFromRete(Utente*);	   //rimuove il contatto con username un dalla rete dell'utente cliente d'invocazione

        void ricercaNelDB(const QString&,const QString&,QTextEdit**);  //mostra i profili(in base ai permessi) degli utenti nel DB che hanno nome OPPURE cognome uguali a quelli passati
            //comportamento diverso in base al tipo dinamico del puntatore u
        Username getUsername() const;
};


#endif
