#include "../headers/client_widget.h"

//STRUTTURA FINESTRA DEL CLIENT
/*   Il mio profilo(QPushButton)                            Casella per l'inserimento di un username(QLineEdit)
 *                                                  Aggiungi a i tuoi contatti(QPushButton)           Rimuovi dai tuoi contatti(QPushButton)
     Spazio per la visualizzazione                 Casella per l'inserimento di un nome               Casella per l'inserimento di un cognome
     dei dati personali                                                         Mostra profilo(QPushButton)
     (QTextEdit --> testo modificabile)
     **************************                    Spazio per la visualizzazione(in base ai permessi) del profilo dell'utente inserito nella QLineEdit sopra (QTextEdit)
     **************************                    ****************     **************
     **************************                    ****************     **************
     **************************
     **************************                    ****************     **************
     **************************                    ****************     **************
     **************************
     Pubblica modifiche(QPushButton)
*/

ClientWidget::ClientWidget(LinQedInClient* cl,LinQedInAdmin* ad): client(cl),admin(ad){
                                                               //costruttore di ClientWidget,
                                                              //riceve un cliente logico ed un admin logico
    creaParteSinistra();
    creaParteDestra();
    QVBoxLayout* firstMainLayout = new QVBoxLayout;
    QHBoxLayout* mainLayout = new QHBoxLayout;     //layout orizzontale
    //create menu
    /*##################################################PARTE DI DEFAULT*/
    QMenuBar* menuBar = new QMenuBar(0);      //l'usuale barra in alto a sinistra
    QMenu* fileMenu = menuBar->addMenu(tr("File"));
    fileMenu->addSeparator();
    QAction* exitAction = fileMenu->addAction(tr("Close LinQedInClient"));
    QMenu* viewMenu = menuBar->addMenu(tr("&View"));
    QAction* fullScreenAction = viewMenu->addAction(tr("Full screen"));
    QAction* normalViewAction = viewMenu->addAction(tr("Normal view"));
    //CONNESSIONI SIGNAL-SLOT
    connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));
    connect(fullScreenAction, SIGNAL(triggered()), this, SLOT(showFullScreen()));
    connect(normalViewAction, SIGNAL(triggered()), this, SLOT(showNormal()));
    firstMainLayout->setMenuBar(menuBar);


    connect(buttons[0],SIGNAL(clicked()),this,SLOT(mostraMioProfilo()));
    connect(buttons[1],SIGNAL(clicked()),this,SLOT(pubblicaModifiche()));
    connect(buttons[2],SIGNAL(clicked()),this,SLOT(insertContatto()));
    connect(buttons[3],SIGNAL(clicked()),this,SLOT(removeContatto()));
    connect(buttons[4],SIGNAL(clicked()),this,SLOT(mostraProfilo()));

    /*###################################################################*/
    
     //########################## 
    QFont f("Arial",25,QFont::Bold);
    QPalette* palette = new QPalette;
    palette->setColor(QPalette::WindowText,Qt::blue);
    title = new QLabel;
    title->setText(tr("LinQedIn client interface")); 
    title->setFont(f);
    title->setAlignment(Qt::AlignCenter);
    title->setPalette(*palette);
    //###############################
    firstMainLayout->addWidget(title);

    mainLayout->addWidget(boxSinistra);
    mainLayout->addWidget(boxDestra);
    
    firstMainLayout->addLayout(mainLayout);

    setLayout(firstMainLayout);
}

/*##############
BOTTONE
TEXTEDIT
BOTTONE
##############*/
void ClientWidget::creaParteSinistra(){
    boxSinistra = new QGroupBox;
    
    QVBoxLayout* layoutSinistra = new QVBoxLayout;
    
    for (int i = 0; i < NUM_FIELDS; i++){
		fields[i] = new QLabel;
		wFields[i] = new QLineEdit;
	}
    
    QFont f("Arial",13,QFont::Bold);
    QPalette* palette = new QPalette;
    palette->setColor(QPalette::WindowText,Qt::blue);
    
    fields[0]->setText(tr("Nome")); 
    fields[1]->setText(tr("Cognome")); 
    fields[2]->setText(tr("Username")); 
    fields[3]->setText(tr("Tipo account")); 
    fields[4]->setText(tr("Skills")); 
    fields[5]->setText(tr("Lingue")); 
    fields[6]->setText(tr("Studi")); 
    fields[7]->setText(tr("Contatti"));
    
    buttons[0] = new QPushButton(tr("Mostra il mio profilo"));
    buttons[1] = new QPushButton(tr("Pubblica modifiche"));     //AGGIUNGERLO SOLO SE IL PUNTATORE 'admin' non è NULL CIOÈ SE SI È MODALITÀ 'SIMULAZIONE CLIENT-ADMIN'
    
     
    layoutSinistra->addWidget(buttons[0]);
    for (int i = 0; i < NUM_FIELDS; i++){
		fields[i]->setFont(f);
		//fields[i]->setAlignment(Qt::AlignCenter);
		fields[i]->setPalette(*palette);
		layoutSinistra->addWidget(fields[i]);
		layoutSinistra->addWidget(wFields[i]);  
	}
    
    layoutSinistra->addWidget(buttons[1]);
      
    editMyProfilo = new QTextEdit;
    
    boxSinistra->setLayout((layoutSinistra));
}

/*
********************************    v
o    r   i   z   z   o  n      *    e
LINEDIT            BOTTONE  v  *    r
                   BOTTONE  e  *    t
                   BOTTONE  r  *    i
********************************    c
TEXTEDIT                       *    a
********************************    l
*/

void ClientWidget::creaParteDestra(){
    boxDestra = new QGroupBox;

    QVBoxLayout* layoutDestra = new QVBoxLayout;     //layout esterno
    QHBoxLayout* layout2Bottoni = new QHBoxLayout;   //layout orizz per i 2 bottoni 'Aggiungi' e 'Rimuovi'
    QHBoxLayout* layout2LineEdit = new QHBoxLayout;  //layout orizz per le 2 textEdit 'insertNome' 'insertCognome'
    QVBoxLayout* layoutTextEdit = new QVBoxLayout;  //per sistemare le textEdit che mostrano i profili
    QHBoxLayout* layoutTextEditAnn[2];  //per sistemare le 2 textEdit superiori e le 2 inferiori

    for (int i = 0; i < NUM_LINE_EDITS; ++i){           //ciclo per allocare i QLineEdit
        lineEdits[i] = new QLineEdit;
    }
    lineEdits[0]->setPlaceholderText(tr("inserisci username"));
    lineEdits[1]->setPlaceholderText(tr("inserisci nome"));
    lineEdits[2]->setPlaceholderText(tr("inserisci cognome"));
    //############
    buttons[2] = new QPushButton(tr("Aggiungi ai contatti"));
    buttons[3] = new QPushButton(tr("Rimuovi dai contatti"));
    buttons[4] = new QPushButton(tr("Mostra profilo"));
    //###########
    layout2Bottoni->addWidget(buttons[2]);
    layout2Bottoni->addWidget(buttons[3]);  //===>layout2Bottoni completo
    //##########
    layout2LineEdit->addWidget(lineEdits[1]);
    layout2LineEdit->addWidget(lineEdits[2]);

    layoutDestra->addWidget(lineEdits[0]);
    layoutDestra->addLayout(layout2Bottoni);
    layoutDestra->addLayout(layout2LineEdit);
    layoutDestra->addWidget(buttons[4]);

    for (int i = 0; i < NUM_TEXT_EDITS; ++i){
         editProfilo[i] = new QTextEdit;
         editProfilo[i]->setReadOnly(true);
    }

    for (int i = 0; i < 2; ++i){
        layoutTextEditAnn[i] = new QHBoxLayout;
    }

    for (int i = 0; i < NUM_TEXT_EDITS; ++i){
        if (i < 2){
            layoutTextEditAnn[0]->addWidget(editProfilo[i]);
        }
        else{
            layoutTextEditAnn[1]->addWidget(editProfilo[i]);
        }
    }


    for (int i = 0; i < 2; ++i){
        layoutTextEdit->addLayout(layoutTextEditAnn[i]);
    }

    layoutDestra->addLayout(layoutTextEdit);

    boxDestra->setLayout(layoutDestra);
}


void ClientWidget::pubblicaModificheLogica(){
		(admin->db)->sincronizza(client->db);    //db privato in client==> ClientWidget amico di linqClient
    //invoca DB::sincronizza per copiare il database del client nel database dell'admin
}


//SLOT PER IL BOTTONE "Mostra il mio profilo"
//mostra il profilo dell'utente corrente
void ClientWidget::mostraMioProfilo(){
    /*showProfilo ritorna il Profilo dell'utente corrente-->Profilo ha dei metodi pubblici per ricavare i dati*/
    //scrivere su editMyProfilo i dati del Profilo
    Profilo prof = client->showProfilo();
    prof.visualizzaProfilo(0,wFields);
}

//SLOT PER IL BOTTONE "Pubblica Modifiche"
void ClientWidget::pubblicaModifiche(){
    //aggiorna profilo deve ottenere il testo di 'editMyProfilo' per righe
   // QStringList lines = (editMyProfilo->toPlainText()).split("\n");   //ottiene le righe del textEdit

    //SPLITTARE DAI 2 PUNTI IN POI!!!!!
    QList<QString> sk = ((wFields[4]->text()).simplified()).split(","); //SPLITTARE DAI 2 PUNTI IN POI!!!!!! con mid() 8: posizione da cui partire
    //ottiene skills come lista di stringhe
    QList<QString> li = ((wFields[5]->text()).simplified()).split(","); //SPLITTARE DAI 2 PUNTI IN POI!!!!!!
    //ottiene lingue come lista di stringhe
    QList<QString> st = ((wFields[6]->text()).simplified()).split(","); //SPLITTARE DAI 2 PUNTI IN POI!!!!!!
    //ottiene studi come lista di stringhe
    /*passa al metodo aggiornaProfilo le righe contenenti:
     * nome (riga 0)
     * cognome (riga 2)
     * skills (riga 8)
     * lingue (riga 10)
     * studi (riga 12)
     * */                       /*nome: */        /*cognome*/         /*skills etc...*/
    client->aggiornaProfilo((wFields[0]->text()).simplified(),wFields[1]->text().simplified(),sk,li,st);

    //NB::LE MODIFICHE VANNO RESE PUBBLICHE ALL'ADMIN ==> AGGIORNARE DATABASE DELL'ADMIN//NB::LE MODIFICHE VANNO RESE PUBBLICHE ALL'ADMIN ==> AGGIORNARE DATABASE DELL'ADMIN
    //NB::CHIAMATA DA EFFETTUARE SOLO SE IL PUNTATORE 'admin' non è NULL CIOÈ SE SI È MODALITÀ 'SIMULAZIONE CLIENT-ADMIN'	
    if (admin){
		pubblicaModificheLogica();      //il client pubblica le modifiche all'admin in RAM
	}
}

//SLOT PER IL BOTTONE "Aggiungi"
void ClientWidget::insertContatto(){
    int pos;   //parametro fake da passare a findInDB
    try{       //blocco try-catch in quanto l'utente cercato potrebbe non esistere
        Utente* uPtr = (client->db)->findInDB((lineEdits[0]->text()).simplified(),pos);  //ottenere il testo dalla lineEdit insertUsername e convertirlo in Username
        try{    //eccezione annidata,l'utente esiste ma è già nella rete
            client->insertInRete(uPtr);   //insertInRete invoca RETE::add()
       //     pubblicaModificheLogica(); //se è andato tutto bene=> PUBBLICA MODIFICHE ALL'ADMIN
        }
        catch(UtenteInRete& e){
            OutputMessage("L'utente inserito esiste nella rete di contatti");
        }
    }
    catch(UtenteNonEsistente& e){
        OutputMessage msg("L'utente cercato non esiste");
    }
}

//SLOT PER IL BOTTONE "Rimuovi"
void ClientWidget::removeContatto(){
    int pos;   //parametro fake da passare a findInDB
    /*NB::l'utente da rimuovere dalla rete di contatti deve essere presente
          sia nel database sia nella rete*/
    try{
        Utente* uPtr = (client->db)->findInDB((lineEdits[0]->text()).simplified(),pos);  //ottenere il testo dalla lineEdit insertUsername e convertirlo in Username
        try{
            client->removeFromRete(uPtr);     //'removeFromRete() può lanciare l'eccezione UtenteNonInRete'
     //       pubblicaModificheLogica();    //se è andato tutto bene=> PUBBLICA MODIFICHE ALL'ADMIN
        }
        catch(UtenteNonInRete& e){
            OutputMessage msg("L'utente inserito non è nella rete di contatti");
        }
    }
    catch(UtenteNonEsistente& e){
        OutputMessage msg("L'utente cercato non esiste");
    }
}

//SLOT PER IL BOTTONE "Mostra profilo"
//PARTIRE DA QUI PER LE RICERCHE CRESCENTI
void ClientWidget::mostraProfilo(){       //ottenere il testo dalla lineEdit insertUsername
    //ricercaNelDB riceve anche il puntatore alla TextEdit su cui visualizzare le infos
    client->ricercaNelDB((lineEdits[1]->text()).simplified(),(lineEdits[2]->text()).simplified(),editProfilo);
}
