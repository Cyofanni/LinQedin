#include "../headers/db.h"

//Il metodo load() carica il database correttamente
void DB::load(){      //metodo chiamato dai costruttori di LinQedInClient e LinQedInAdmin
    //carica da file
             //come si caricano con il tipo dinamico giusto?
             //la terza riga di ogni utente fornisce il tipo di account

     DBParser parsimonious("../data/db.xml");
     //l'oggetto parsimonious deve permettere di caricare un contenitore locale con tutti i dati
     QList< QMap<QString,QString> > utenti;     //contenitore locale delle coppie 'nomeAttributo: valore'
     parsimonious.parseXML(utenti);     //l'invocazione a parseXML inserisce nella lista 'utenti' i dati

     while (!utenti.isEmpty()){
         QMap<QString,QString> utente = utenti.takeFirst();
         QList<QString> sk,li,st;
         QList<QString> coQString;    //contiene i contatti come lista di stringhe
         QList<Username> coUsername; //contiene i contatti come lista di Username copiati da coQString
         //ottenere le liste splittando con la virgola
         //liste di stringhe OK
         sk = utente["skills"].split(",");
         li = utente["lingue"].split(",");
         st = utente["studi"].split(",");
         coQString = utente["contatti"].split(",");
         for (int i = 0; i < coQString.size(); ++i){
             coUsername.append(Username(coQString.at(i)));  //conversione da QStringList a QList<Username>
         }

         if (utente["tipoacc"] == "Basic"){                    //l'accesso ai tag interni ad utente avviene tramite []
               db.push_back(new UtenteBasic(utente["nome"],utente["cognome"],Username(utente["username"]),
                     basic,sk,li,st,coUsername,utente["password"]));
         }
         else if (utente["tipoacc"] == "Business"){
               db.push_back(new UtenteBusiness(utente["nome"],utente["cognome"],Username(utente["username"]),
                     business,sk,li,st,coUsername,utente["password"]));
         }
         else if (utente["tipoacc"] == "Executive"){
               db.push_back(new UtenteExecutive(utente["nome"],utente["cognome"],Username(utente["username"]),
                     executive,sk,li,st,coUsername,utente["password"]));
         }
     }
}

void DB::insert(Utente* u){      //controllare che l'utente non esista gia'
    int pos = -1; 
    try{
	findInDB((u->pf).getUsername(),pos);   //se l'utente non esiste nel database --> lancia eccezione  
	throw UtenteEsistente();
    }
    catch(UtenteNonEsistente&){      //cattura eccezione e inserisce utente che prima non c'era
	db.push_back(u);
    }
}

//Metodo invocato dall'admin
void DB::remove(const Username& u){
    //NB: LA RIMOZIONE DI UN UTENTE DAL DB DEVE PROVOCARE LA RIMOZIONE DALLE RETI DI TUTTI GLI UTENTI
    //DELL'UTENTE RIMOSSO==>RIMOZIONE SOLO TESTUALE IN QUANTO LE RETI DEGLI UTENTI DIVERSI
    //DAL CLIENTE LOGGATO NON SONO CARICATE IN MEMORIA!!!
    int posUtDaRim = -1;
    for (int i = 0; i < db.size(); ++i){
        if ((db.at(i)->pf).getUsername() == u){
              posUtDaRim = i;   //memorizza posizione dell'utente da rimuovere
        }
        (db.at(i)->pf).removeContattoText(u);
    }
    if (posUtDaRim >= 0){     //se l'utente che si vuole rimuovere è stato trovato nella lista
        db.removeAt(posUtDaRim);   //
    }
    else{        //posUtDaRim = -1  ===> lancia un'eccezione 'UtenteNonEsistente'
        throw UtenteNonEsistente();
    }
}

void DB::modificaAccount(const Username& u,TipoAccount t_nuovo){
    /*ricerca nel DB dell'utente con username u e modifica del campo dati tAcc;
     */
    try{       //blocco try-catch in quanto findInDB può lanciare l'eccezione 'UtenteNonEsistente'
        int pos = -1;
        findInDB(u,pos);
     //findInDB definita sotto;;;;;pos è passato per riferimento e memorizza la posizione dell'utente u nel db
     //db.at(i) deve puntare ad un utente con il tipo t_nuovo
     /*RIPENSARE BENE QUESTO CODICE*/
     //NB::Per avere i permessi di scrittura bisogna accedere alla lista con l'operatore di subscripting []
       // (db[pos]).setInnerPointer(t_nuovo);
        Utente* tmp = db[pos];
        Profilo prof = db[pos]->pf;

        switch(t_nuovo){   //ora modificare il contenuto dell'oggetto dopo il tipo del puntatore
        case basic:
         //   (db[pos]->pf).setTipoAccount(basic);
            db[pos] = new UtenteBasic(prof.getNome(),prof.getCognome(),
                            prof.getUsername(),basic/*prof.getTipoAccount()*/,prof.getSkills(),prof.getLingue(),
                            prof.getStudi(),prof.getContatti(),prof.getPassword());
            break;
        case business:
         //   (db[pos]->pf).setTipoAccount(business);
            db[pos] = new UtenteBusiness(prof.getNome(),prof.getCognome(),
                                prof.getUsername(),business/*prof.getTipoAccount()*/,prof.getSkills(),prof.getLingue(),
                                prof.getStudi(),prof.getContatti(),prof.getPassword());
            break;
        case executive:
        //    (db[pos]->pf).setTipoAccount(executive);
            db[pos] = new UtenteExecutive(prof.getNome(),prof.getCognome(),
                                prof.getUsername(),executive/*prof.getTipoAccount()*/,prof.getSkills(),prof.getLingue(),
                                prof.getStudi(),prof.getContatti(),prof.getPassword());
            break;
        }
        delete tmp;
     }
    catch(UtenteNonEsistente& e){
        //Informare l'utente dell'applicazione della non esistenza dell'utente cercato
        QMessageBox msgBox;
        msgBox.setText("Impossibile modificare il profilo dell'utente cercato");
        msgBox.exec();
    }
}

void DB::save() const{          //usa QXmlStreamWriter
    //passata lineare su db e riscrittura di tutto, non solo delle parti modificate
    QFile file("../data/db.xml");       //per ora passo direttamente db.xml
    if (!(file.open(QIODevice::WriteOnly))){
        return;
    }

    QXmlStreamWriter xmlWriter(&file);
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();

    xmlWriter.writeStartElement("accounts");
    for (int i = 0; i < db.size(); ++i){
         xmlWriter.writeStartElement("utente");

         xmlWriter.writeTextElement("nome",(db[i]->pf).getNome());
         xmlWriter.writeTextElement("cognome",(db[i]->pf).getCognome());
         xmlWriter.writeTextElement("username",QString(((db[i]->pf).getUsername()))); //il secondo parametro deve essere di tipo QString ==> Username->QString
         switch((db[i]->pf).getTipoAccount()){    //getTipoAccount ritorna un intero di enum, ma sul file va scritta una stringa
            case basic:
               xmlWriter.writeTextElement("tipoacc","Basic");
            break;
            case business:
               xmlWriter.writeTextElement("tipoacc","Business");
            break;
            case executive:
                xmlWriter.writeTextElement("tipoacc","Executive");
            break;
         }

         /*ORA I TAG SKILLS, STUDI ETC... NON CONTENGONO PIù ALTRI TAG ==> SEMPLICE SCRITTURA DI TESTO*/
         QString writeSk;    //contiene la lista di skills come stringa con virgole separatrici
         for (int j = 0; j < ((db[i]->pf).getSkills()).size(); ++j){
            writeSk.append((((db[i]->pf).getSkills()).at(j)));
            if (j < (db[i]->pf).getSkills().size() - 1){
                writeSk.append(",");
            }
         }
         //Utilizza interfaccia pubblica della classe Profilo
         xmlWriter.writeTextElement("skills",(db[i]->pf).getSkillsAsString());
         xmlWriter.writeTextElement("lingue",(db[i]->pf).getLingueAsString());
         xmlWriter.writeTextElement("studi",(db[i]->pf).getStudiAsString());
         xmlWriter.writeTextElement("contatti",(db[i]->pf).getContattiAsString());

         xmlWriter.writeTextElement("password",(db[i]->pf).getPassword());

         xmlWriter.writeEndElement();    //</utente>
    }

    xmlWriter.writeEndElement();     //</accounts>
}

Utente* DB::findInDB(const Username& u,int& pos) const{  //ritorna uno SmartUtente con il tipo dinamico giusto;;; pos memorizza la posizione
    /*throw UtenteNonEsistente se non trova l'utente con Username u*/
    Utente* ret = 0;
    for (int i = 0; i < db.size(); ++i){
        if ((db.at(i)->pf).getUsername() == u){
            ret = db.at(i);
            pos = i;
        }
    }
    if (ret == 0){
        throw UtenteNonEsistente();
    }

    return ret;
}


//mostra i profili(in base ai permessi) degli utenti nel DB che hanno nome OPPURE cognome uguali a quelli passati
void DB::ricerca(OttieniInfos* funtore,const QString& nome,const QString& cognome,QTextEdit** edit) const{
    //OttieniInfos è un puntatore polimorfo, già costruito da u->getFuntore,invocata da ricercaNelDB
    Utente* uSptr = 0;
    int conta_ut_trov = 0;    //contatore per cambiare textEdit
    for (int i = 0; i < db.size(); ++i){
       //db[it] è uno SmartUtente& per cui esiste  l'operatore ->
        //CaseInsensitive compare
       //NB::QString::compare() RITORNA 0 SE LE STRINGHE PASSATE SONO UGUALI
       if ((!(QString::compare(((db[i])->pf).getNome(),nome,Qt::CaseInsensitive)) or
               !(QString::compare(((db[i])->pf).getCognome(),cognome,Qt::CaseInsensitive)))
               and (nome != "" or cognome != "")){
              //almeno uno tra nome e cognome devono essere stringhe non vuote
           uSptr = db[i];
           //utilizzare il funtore,va dereferenziato perché è un puntatore
           InfoVis_Basic* tmp = (*funtore)(uSptr->pf,edit[conta_ut_trov]);  //passare direttamente il profilo,non il puntatore a Utente
           delete tmp;
		   conta_ut_trov++;
       }
   }
   if (!uSptr){      //se non esiste alcun utente con nome e cognome passati
        edit[0]->setText("l'utente cercato non esiste\n");
   }
}

void DB::sincronizza(const DB* dbase){    //copia il database in dbase nel db di invocazione
    //db: database del client
    //dbase->db: database dell'admin
    db.clear();      //azzera il database corrente    ====>  GARBAGE!!!! ELIMINARE ANCHE GLI OGGETTI PUNTATI!!!!!
    for (int i = 0; i < (dbase->db).size(); ++i){      //copia il database da dbase
	    db.push_back((dbase->db)[i]);
    }
}

int DB::sizeDB() const{
    return db.size();
}

Utente* DB::at(int i) const{
    return db.at(i);
}

DB::~DB(){
   for (int i = 0; i < db.size(); ++i){
	  delete db.at(i);
   }
   db.clear();
}

DB::DBParser::DBParser(const QString& s){}

void DB::DBParser::parseXML(QList<QMap <QString,QString> >& accounts) const{
   //dare percorso assoluto altrimenti problemi
   QFile* file = new QFile("../data/db.xml");     //per ora passo direttamente il nome del file

   if (!file->open(QIODevice::ReadOnly | QIODevice::Text)){
       return;
   }
   /*http://developer.nokia.com/community/wiki/QXmlStreamReader_to_parse_XML_in_Qt*/
   QXmlStreamReader xml(file);
   //Parsing del file XML fino alla fine

   while (!xml.atEnd() && !xml.hasError()){
       //leggi il prossimo elemento
       QXmlStreamReader::TokenType token = xml.readNext();
       if (token == QXmlStreamReader::StartDocument){
           continue;
       }
       if (token == QXmlStreamReader::StartElement){
           //se il nome del token è 'accounts', andiamo al prossimo
           if (xml.name() == "accounts"){
               continue;
           }
           //se il nome del token è 'utente', ricaviamo le informazioni
           if (xml.name() == "utente"){
               accounts.append(this->parseUtente(xml));     //aggiunta al contenitore di una coppia chiave-valore
           }
       }
   }   //end of while loop

   if (xml.hasError()){
       //error handling
   }
   xml.clear();
}

QMap<QString,QString> DB::DBParser::parseUtente(QXmlStreamReader& xml) const{      //xml riferimento NON costante
    QMap<QString,QString> utente;       //dizionario relativo ad un singolo utente
    //controlla che stiamo realmente ottenendo un utente
    if (xml.tokenType() != QXmlStreamReader::StartElement && xml.name() == "utente"){
        return utente;
    }
    /*per ora l'elemento 'utente' non ha attributi*/
    xml.readNext();

    //IL CICLO TERMINA
    while(!(xml.tokenType() == QXmlStreamReader::EndElement && xml.name() == "utente")) {
        if(xml.tokenType() == QXmlStreamReader::StartElement) {
            //è stato trovato 'nome'
            if(xml.name() == "nome") {
                this->addElementDataToMap(xml,utente);
            }
            // è stato trovato 'cognome'.
            if(xml.name() == "cognome") {
                this->addElementDataToMap(xml,utente);
            }
            // è stato trovato 'username'.
            if(xml.name() == "username") {
                this->addElementDataToMap(xml,utente);
            }
            if (xml.name() == "tipoacc"){
                this->addElementDataToMap(xml,utente);
            }
            if (xml.name() == "skills"){      //IL TAG 'skills' CONTIENE ALTRI TAG AL SUO INTERNO ==> metodo parseSkills???
                //parseSkills(xml)            -- alternativa 1 difficile
                this->addElementDataToMap(xml,utente);   //--alternativa 2 facile
            }
            if (xml.name() == "lingue"){      //IL TAG 'lingue' CONTIENE ALTRI TAG AL SUO INTERNO ==> metodo parseLingue???
                //parseLingue(xml)          -- alternativa 1 difficile
                this->addElementDataToMap(xml,utente);   //--alternativa 2 facile
            }
            if (xml.name() == "studi"){       //IL TAG 'studi' CONTIENE ALTRI TAG AL SUO INTERNO ==> metodo parseStudi???
                //parseStudi(xml)           -- alternativa 1 difficile
                this->addElementDataToMap(xml,utente);   //--alternativa 2 facile
            }
            if (xml.name() == "contatti"){   //IL TAG 'contatti' CONTIENE ALTRI TAG AL SUO INTERNO ==> metodo parseContatti???
                //parseContatti(xml)            -- alternativa 1 difficile
                this->addElementDataToMap(xml,utente);   //--alternativa 2 facile
            }
            if (xml.name() == "password"){
                this->addElementDataToMap(xml,utente);
            }
       }
       xml.readNext();
    }//end of while loop

    return utente;
}

void DB::DBParser::addElementDataToMap(QXmlStreamReader& xml,QMap<QString,QString>& map) const{
    if (xml.tokenType() != QXmlStreamReader::StartElement){
        return;
    }
    QString elementName = xml.name().toString();
    xml.readNext();

    if (xml.tokenType() != QXmlStreamReader::Characters){
        return;
    }
    map.insert(elementName,xml.text().toString());
}
