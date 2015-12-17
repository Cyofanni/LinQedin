#include "../headers/linqClient.h"
#include <QDebug>

//NB::ALLA COSTRUZIONE DEL CLIENTE SI DEVE ANCHE POPOLARE LA SUA RETE CON PUNTATORI AD UTENTE
LinQedInClient::LinQedInClient(const Username& s/*,LinQedInAdmin* admin*/): db(new DB){
    db->load();     //il cliente carica da file

    //NB:: this e' di tipo LinQedInClient* const
     int pos = -1;   //parametro 'dummy' da passare a findInDB, oppure per utilizzo futuro
     u = /*(Utente*)*/db -> findInDB(s,pos);     //cerca l'utente client nel DB --> db deve essere già popolato alla costruzione del client

     QList<Username> listaContatti = (u->pf).getContatti();  //lista contatti del profilo dell'utente(semplici Username)

     //cicla sulla lista degli username dei contatti (letta prima da file)
     for (int i = 0; i < listaContatti.size(); ++i){
           //cicla sul database già caricato
           for (int j = 0; j < db->sizeDB(); ++j){
               if (((db->at(j))->pf).getUsername() == Username(listaContatti.at(i))){
                   (u->rete)->add(db->at(j));     
               }
           }
     }
     //RETI CARICATE
}

void LinQedInClient::aggiornaProfilo(const QString& n/*nome*/,const QString& c/*cognome*/,
                 const QList<QString>& s/*skills*/,const QList<QString>& l/*lingue*/,
                                     const QList<QString>& s1/*studi*/){
     (u->pf).modificaProfilo(n,c,s,l,s1);
     db->save();   //salva modifiche su file
}

Profilo LinQedInClient::showProfilo() const{
    return u->pf;
}


void LinQedInClient::insertInRete(Utente *uPtrAdd){    //throws exception UtenteInRete
    Profilo prof_to_add = uPtrAdd->pf;
    bool presente = false;   //flag per controllare se l'utente da aggiungere è già presente nella rete
    for (int i = 0; i < (u->rete)->sizeRete(); ++i){
        if (prof_to_add.getUsername() == (((u->rete)->at(i))->pf).getUsername()){
            presente = true;
        }
    }
    if (!presente){      //se non c'era già
        (u->rete)->add(uPtrAdd);       //aggiunge il puntatore passato
        (u->pf).addContattoText(prof_to_add.getUsername());   //modifica il campo 'contatti' del profilo del cliente
        db->save();    //salva le modifiche su file
    }
    else{
        //lancia l'eccezione 'UtenteInRete'
        throw UtenteInRete();
    }
}

void LinQedInClient::removeFromRete(Utente* uPtrRem){     //rimuove il contatto con username un dalla rete dell'utente cliente d'invocazione
    //throws exception 'UtenteNonInRete'
    Profilo prof_to_rem = uPtrRem->pf;
    bool presente = false;
    int pos_to_rem;
    for (int i = 0; i < (u->rete)->sizeRete(); ++i){
        if (prof_to_rem.getUsername() == (((u->rete)->at(i))->pf).getUsername()){
            presente = true;
            pos_to_rem = i;
        }
    }

    if (presente){       //se l'utente c'era
        (u->rete)->remove(pos_to_rem);      //rimozione del puntatore
        (u->pf).removeContattoText(prof_to_rem.getUsername());  //modifica il campo 'contatti' del profilo del cliente
        db->save();       //salva le modifiche su file
    }
    else{       //se l'utente non c'era
        //lancia un'eccezione di tipo 'UtenteNonInRete'
        throw UtenteNonInRete();
    }
}

void LinQedInClient::ricercaNelDB(const QString& nome,const QString& cognome,QTextEdit** edit){
    //mostra i profili(in base ai permessi) degli utenti nel DB che hanno nome OPPURE cognome uguali a quelli passati
                //comportamento diverso in base al tipo dinamico del puntatore u
    OttieniInfos* funtore = u->getFuntore();
    db->ricerca(funtore,nome,cognome,edit);   //u->getFuntore ritorna il funtore adatto al tipo di u,utente in cliente
    delete funtore;  //getFuntore alloca sullo heap
}

Username LinQedInClient::getUsername() const{
    return (u->pf).getUsername();
}
