#include "../headers/linqAdmin.h"


LinQedInAdmin::LinQedInAdmin(): db(new DB){
    db -> load();
}

void LinQedInAdmin::insert(Utente* u){ //throw(UtenteEsistente)
    db->insert(u);       //puo' lanciare l'eccezione 'UtenteEsistente'
    db->save();
} 

void LinQedInAdmin::remove(const Username& u) throw (UtenteNonEsistente){
    try{
        db -> remove(u);
        db->save();
    }
    catch(UtenteNonEsistente& e){
           //Gestire la non esistenza dell'utente ==> informare l'utente dell'applicazione
        OutputMessage msg("L'utente cercato non esiste");
    }
}

Utente* LinQedInAdmin::find(const Username& u) const{
    //invoca DB::find()
    Utente* ret;
    try{   //
        int pos;
        ret = db->findInDB(u,pos);
    }
    catch(UtenteNonEsistente& e){
        //Informare l'utente dell'applicazione della non esistenza dell'utente cercato
        OutputMessage msg("L'utente cercato non esiste");
    }
    return ret;
}

void LinQedInAdmin::changeSubscriptionType(const Username& u, TipoAccount t_nuovo){
    db->modificaAccount(u,t_nuovo);    
    db->save();    
}

void LinQedInAdmin::save() const{
    db->save();
}

void LinQedInAdmin::pubblicaModifiche(LinQedInClient* client) const{
    /*passata lineare e copia di tutti gli Utente* del DB del client;;;
      LinQedInAdmin ha accesso al puntatore db del client;;;
      serve anche l'accesso al contenitore del a cui punta db;;;*/
     (client->db)->sincronizza(this->db);  //copia il db dell'admin nel db del client
     //'sincronizza' (definita in db) copia il db dell'parametro nel db dell'oggetto d'invocazione

     /*NB:: DOPO LA SINCRONIZZAZIONE, BISOGNA RICERCARE L'UTENTE DEL CLIENTE,
      ALTRIMENTI RIMANE LO STESSO DI PRIMA INDIPENDENTEMENTE DALL'AGGIORNAMETO DEL DATABASE!!!!!*/

     int pos = 0;  //parametro fake da passare a findInDB
     Utente* utClientePtr = client->u;   //puntatore a utente (campo dati privato di cliente)
     Profilo profCliente = utClientePtr->pf;  //profilo dell'utente del cliente (campo dati pubblico di utente)

     //qDebug() << profCliente.getUsername();
     //(client->u) = (client->db)->findInDB(profCliente.getUsername(),pos);
     for (int i = 0; i < db->sizeDB(); ++i){
         if ((db->at(i)->pf).getUsername() == profCliente.getUsername()){
             delete client->u;
             if ((db->at(i)->pf).getTipoAccount() == basic){
                 client -> u = new UtenteBasic(profCliente.getNome(),profCliente.getCognome(),
                               profCliente.getUsername(),basic/*prof.getTipoAccount()*/,profCliente.getSkills(),profCliente.getLingue(),
                                        profCliente.getStudi(),profCliente.getContatti(),profCliente.getPassword());
             }
             else if ((db->at(i)->pf).getTipoAccount() == business){
                 client -> u = new UtenteBusiness(profCliente.getNome(),profCliente.getCognome(),
                                  profCliente.getUsername(),business/*prof.getTipoAccount()*/,profCliente.getSkills(),profCliente.getLingue(),
                                 profCliente.getStudi(),profCliente.getContatti(),profCliente.getPassword());

             }
             else if ((db->at(i)->pf).getTipoAccount() == executive){
                 client -> u = new UtenteExecutive(profCliente.getNome(),profCliente.getCognome(),
                               profCliente.getUsername(),executive/*prof.getTipoAccount()*/,profCliente.getSkills(),profCliente.getLingue(),
                                        profCliente.getStudi(),profCliente.getContatti(),profCliente.getPassword());
             }
         }
     }
}
