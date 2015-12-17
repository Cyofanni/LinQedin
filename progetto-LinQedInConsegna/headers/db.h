/*Qt xml parsing: http://developer.nokia.com/community/wiki/QXmlStreamReader_to_parse_XML_in_Qt*/

#ifndef DB_H
#define DB_H

#include "utente.h"      //==> include rete
#include "utente_basic.h"
#include "utente_business.h"
#include "utente_executive.h"
#include "ottieni_anche_rete_di.h"     //include tutte le altre classi funtori
#include "eccezioni.h"        //per l'eccezione UtenteNonEsistente
#include <QXmlStreamReader>        //XML parsing in this class
#include <QXmlStreamWriter>        //use into 'save' function
#include <QFile>
#include <QMap>
#include <QList>
#include <QString>
#include <QStringList>     //per il metodo split
#include <QMessageBox>

class QTextEdit;      //per 'ricerca'

class Rete;
//I metodi di DB useranno i puntatori smart
class DB{
    friend class Rete;       //Rete ha bisogno di accedere a db
private:
        QList<Utente*> db;
        //classe interna: garantisce il caricamento in un contenitore di tutti dati
        class DBParser{
            private:
                QMap<QString,QString> parseUtente(QXmlStreamReader&) const;				/*metodo privato di utilità: invocato da parseXML*/
                void addElementDataToMap(QXmlStreamReader&,QMap<QString,QString>&) const;   /*metodo privato di utilità: invocato da parseXML*/
            public:
                DBParser(const QString&);
                void parseXML(QList< QMap<QString,QString> >&) const;
        }; //fine della classe DBParser
public:       
	void load();				//carica da file
             //come si caricano con il tipo dinamico giusto?
             //la terza riga di ogni utente fornisce il tipo di account
             /*Ho bisogno di una funzione che ritorni il puntatore giusto in base all'input da file -->
              */


        void insert(Utente* u);		//inserisce l'utente u nel database, in RAM, 
            //db.push_back(SmartUtente(u));     //cast da Utente* a SmartUtente

        void remove(const Username& u);	//deve implicare la rimozione dell'utente da tutte le reti
            //per rimuovere un utente bisogna settare a 0 il campo numFollowers di Utente

        void modificaAccount(const Username&,TipoAccount);          //modificaAccount("gmazzocc",executive)
        void save() const;		//salva su file ogni tipo di modifica

        //restituisce il puntatore(smart) 0 se l'utente non è stato trovato
        Utente* findInDB(const Username&,int&) const; //cerca l'utente (con il suo tipo) avente username u nel DB


        void ricerca(OttieniInfos*,const QString&,const QString&,QTextEdit**) const;
                //tipo dinamico di funtore: EsisteUtente o ProfiloCompletoDi o OttieniAncheReteDi
                //passata lineare su campo dati db
        void sincronizza(const DB*);     //metodo per la copia nel contenitore db del contenitore di un altro DB

        int sizeDB() const;    //restituisce la dimensione del database
        Utente* at(int i) const;    //restituisce il puntatore smart nella locazione i
	
	~DB(); 
};

#endif
