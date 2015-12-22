#include "../headers/admin_widget.h"
//prova branching
//STRUTTURA FINESTRA DELL'ADMIN
        /*PARTE SINISTRA*/                                /*PARTE DESTRA*/
/* QLineEdit per l'inserimento di uno username      Cerca in LinQedIn (QPushButton)        Rimuovi da LinQedIn (QPushButton)
                                                    QTextEdit con l'output
                                                    della ricerca
                                                    ******************************
                                                    ******************************
                                                    Basic     Business    Executive (QRadioButtons)
                                                    i radio buttons sopra permettono di cambiare la
                                                    tipologia dell'account dell'utente mostrato sopra
*/


AdminWidget::AdminWidget(LinQedInAdmin* ad,LinQedInClient* cl): admin(ad),client(cl),clicks(0){
     creaParteAlta();
     creaParteBassa();
     creaGuiInsertUtente();
     QVBoxLayout* mainLayout = new QVBoxLayout;     //layout verticale

     //#############################
     QMenuBar* menuBar = new QMenuBar(0);      //l'usuale barra in alto a sinistra
     QMenu* fileMenu = menuBar->addMenu(tr("File"));
     fileMenu->addSeparator();
     QAction* exitAction = fileMenu->addAction(tr("Close LinQedInAdmin"));
     QMenu* viewMenu = menuBar->addMenu(tr("&View"));
     QAction* fullScreenAction = viewMenu->addAction(tr("Full screen"));
     QAction* normalViewAction = viewMenu->addAction(tr("Normal view"));
      //CONNESSIONI SIGNAL-SLOT
     connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));
     connect(fullScreenAction, SIGNAL(triggered()), this, SLOT(showFullScreen()));
     connect(normalViewAction, SIGNAL(triggered()), this, SLOT(showNormal()));

     connect(buttons[0],SIGNAL(clicked()),this,SLOT(showProfilo()));
     connect(buttons[1],SIGNAL(clicked()),this,SLOT(removeFromLinQedIn()));
     connect(rButtons[0],SIGNAL(clicked()),this,SLOT(changeToBasic()));
     
     connect(rButtons[1],SIGNAL(clicked()),this,SLOT(changeToBusiness()));
     
     connect(rButtons[2],SIGNAL(clicked()),this,SLOT(changeToExecutive()));
     connect(rButtons[2],SIGNAL(clicked()),this,SLOT(count_clicks()));
     connect(insertUtente,SIGNAL(clicked()),this,SLOT(insertNuovoUtente()));
     
     if (client){
		 connect(rButtons[0],SIGNAL(clicked()),this,SLOT(count_clicks()));
		 connect(rButtons[1],SIGNAL(clicked()),this,SLOT(count_clicks()));
		 connect(rButtons[2],SIGNAL(clicked()),this,SLOT(count_clicks()));
	 }
     
     //#############################
      
    //########################## 
     QFont f("Arial",25,QFont::Bold);
     QPalette* palette = new QPalette;
     palette->setColor(QPalette::WindowText,Qt::blue);
     title = new QLabel;
     title->setText(tr("LinQedIn admin interface")); 
     title->setFont(f);
     title->setAlignment(Qt::AlignCenter);
     title->setPalette(*palette);
    //###############################
 

     mainLayout->setMenuBar(menuBar);
     /*#########*/mainLayout->addWidget(title); 
     mainLayout->addWidget(boxAlto);
     
 
     mainLayout->addWidget(boxBasso);
     mainLayout->addWidget(boxInsertUtente);
     setLayout(mainLayout);

 }

void AdminWidget::creaParteAlta(){
     boxAlto = new QGroupBox;
     QVBoxLayout* layoutAlto = new QVBoxLayout;
     QVBoxLayout* layoutAltoAnn1 = new QVBoxLayout;
     inputLabel = new QLabel(tr("Inserisci username"));
     inputLabel->setAlignment(Qt::AlignCenter);
     insertUsername = new QLineEdit();
     layoutAltoAnn1->addWidget(inputLabel);
     layoutAltoAnn1->addWidget(insertUsername);
     buttons[0] = new QPushButton(tr("Cerca in LinQedIn"));
     buttons[1] = new QPushButton(tr("Rimuovi da LinQedIn"));

     layoutAlto->addLayout(layoutAltoAnn1);
     for (int i = 0; i < 2; ++i){
         layoutAlto->addWidget(buttons[i]);
     }

     boxAlto->setLayout(layoutAlto);
}

void AdminWidget::creaParteBassa(){
    boxBasso = new QGroupBox;
    QHBoxLayout* layoutBasso = new QHBoxLayout;      //layout esterno
    QVBoxLayout* layoutBassoAnn1 = new QVBoxLayout;   //layout annidato di primo livello
    mostraProfilo = new QTextEdit;
    changeAccLabel = new QLabel("Modifica privilegi account");
    rButtons[0] = new QRadioButton(tr("Basic"));
    rButtons[1] = new QRadioButton(tr("Business"));
    rButtons[2] = new QRadioButton(tr("Executive"));
    layoutBassoAnn1->addWidget(changeAccLabel);
    for (int i = 0; i < 3; ++i){
        layoutBassoAnn1->addWidget(rButtons[i]);
    }
    layoutBasso->addWidget(mostraProfilo);
    layoutBasso->addLayout(layoutBassoAnn1);


    boxBasso->setLayout(layoutBasso);
}

void AdminWidget::creaGuiInsertUtente(){
    boxInsertUtente = new QGroupBox;
    QVBoxLayout* layout = new QVBoxLayout;
    QHBoxLayout* layoutSkills = new QHBoxLayout;   //layout per le 5 lineEdit delle skills
    QHBoxLayout* layoutLingue = new QHBoxLayout;   //layout per le 5 lineEdit delle lingue
    QHBoxLayout* layoutStudi = new QHBoxLayout;   //layout per le 5 lineEdit degli studi
    
    QFont f("Arial",20,QFont::Bold);
    QPalette* palette = new QPalette;
    labelNuovoUtente = new QLabel;
    labelNuovoUtente->setText(tr("Dati nuovo utente LinQedIn")); 
    labelNuovoUtente->setFont(f);
    labelNuovoUtente->setAlignment(Qt::AlignCenter);
    labelNuovoUtente->setPalette(*palette);
    
    nome = new QLineEdit;
    nome->setPlaceholderText(tr("inserisci nome"));
    cognome = new QLineEdit;
    cognome->setPlaceholderText(tr("inserisci cognome"));
	username = new QLineEdit;
	username->setPlaceholderText(tr("inserisci username"));
	tipoacc = new QLineEdit;
	tipoacc->setPlaceholderText(tr("inserisci tipo account"));
	password = new QLineEdit;
	password->setPlaceholderText(tr("inserisci password"));
	insertUtente = new QPushButton(tr("Aggiungi a LinQedIn"));
	
	for (int i = 0; i < 3; ++i){
		skLiSt[i] = new QLabel;
	}
	skLiSt[0]->setText("Inserisci le competenze");
	skLiSt[1]->setText("Inserisci le lingue");
	skLiSt[2]->setText("Inserisci gli studi");
    for (int i = 0; i < 5; ++i){
		skills[i] = new QLineEdit;
		layoutSkills->addWidget(skills[i]);
    }
    for (int i = 0; i < 5; ++i){
		lingue[i] = new QLineEdit;
		layoutLingue->addWidget(lingue[i]);
    }
    for (int i = 0; i < 5; ++i){
		studi[i] = new QLineEdit;
		layoutStudi->addWidget(studi[i]);	
    }
    layout->addWidget(labelNuovoUtente);
    layout->addWidget(nome);
    layout->addWidget(cognome);
    layout->addWidget(username);
    layout->addWidget(tipoacc); 
    layout->addWidget(skLiSt[0]);   
    layout->addLayout(layoutSkills);
    layout->addWidget(skLiSt[1]);
    layout->addLayout(layoutLingue);
    layout->addWidget(skLiSt[2]);
    layout->addLayout(layoutStudi);
    layout->addWidget(password);
    layout->addWidget(insertUtente);    //aggiungi bottone
    
    boxInsertUtente->setLayout(layout);
}

//SLOTS

 //slot per bottone 'Cerca in LinQedIn'
void AdminWidget::showProfilo(){    //slot per bottone 'Cerca in LinQedIn'
    /*trova nel DB l'utente con username inserito nella lineEdit insertUseame
        ==> fallo puntare da un puntatore locale e ottieni il campo profilo ==> profilo ha l'interfaccia pubblica necessaria
    */

    //La gestione dell'eccezione è affidata a ADMIN::find()
    Utente* u = admin->find((insertUsername->text()).simplified());    //u è uno smart pointer all'utente ricercato
    // u->pf ottiene il profilo
    //scrivere dati su la textEdit 'mostraProfilo'
    //NB::visualizzaProfilo riceve un QTextEdit*
    if (u){   //
        (u->pf).visualizzaProfilo(mostraProfilo,0);
    }
}

//slot per bottone 'Rimuovi da LinQedIn'
//NB:: DA QUI PARTE LA CATENA DI PROBLEMI 'UTENTE-RETE---RETE-UTENTE'
//NB::L'UTENTE LOGGATO NON PUò ESSERE RIMOSSO
void AdminWidget::removeFromLinQedIn(){           //rimuovi -> salva -> pubblica modifiche
	if (client){
        if (client->getUsername() != Username((insertUsername->text()).simplified())){
       //verifica che l'utente da rimuovere non sia quello attualmente loggato
            admin->remove(Username((insertUsername->text()).simplified()));     //ottenere il testo dalla lineEdit insertUsername e casting da QString a Username
          //PUBBLICA SOLO SE IN MODALITÀ INTERAZIONE
			admin->pubblicaModifiche(client);      //admin pubblica le modifiche al db al client ==> chiama DB::sincronizza
	   
		}
		else{  //L'UTENTE LOGGATO NON PUò ESSERE RIMOSSO
			OutputMessage msg("Impossibile rimuovere l'utente " + client->getUsername());
		}
   }
   else{
        admin->remove(Username((insertUsername->text()).simplified()));
   }
}


void AdminWidget::changeToBasic(){
    /*invoca LinQedInAdmin::changeSubscriptionType() ==> invoca DB::modificaAccount() ==> */
    admin->changeSubscriptionType((insertUsername->text()).simplified(),basic);
    if (client){   //PUBBLICA SOLO SE IN MODALITÀ INTERAZIONE
        //if (clicks == 0){
			admin->pubblicaModifiche(client);  /*admin pubblica a client ==> invoca (client->db)->sincronizza() e risintonizza il puntatore a utente nel cliente*/
        //}
        /*else if (clicks > 0){
			OutputMessage("Le modifiche multiple non sono permesse con l'interazione cliente-amministratore");
        }*/
    }
}

void AdminWidget::changeToBusiness(){
    /*invoca LinQedInAdmin::changeSubscriptionType() ==> invoca DB::modificaAccount() ==>
      invoca SmartUtente::setInnerPointer()*/
    admin->changeSubscriptionType((insertUsername->text()).simplified(),business);
    if (client){  //PUBBLICA SOLO SE IN MODALITÀ INTERAZIONE
        //if (clicks == 0){
			admin->pubblicaModifiche(client);   /*admin pubblica a client ==> invoca (client->db)->sincronizza()    e risintonizza il puntatore a utente nel cliente*/
        //}
        /*else if (clicks > 0){
			OutputMessage("Le modifiche multiple non sono permesse con l'interazione cliente-amministratore");
        }*/
	}
}

void AdminWidget::changeToExecutive(){
    /*invoca LinQedInAdmin::changeSubscriptionType() ==> invoca DB::modificaAccount() ==>
      invoca SmartUtente::setInnerPointer()*/
    admin->changeSubscriptionType((insertUsername->text()).simplified(),executive);
    
    //NB::CHIAMATA DA EFFETTUARE SOLO SE IL PUNTATORE 'client' È DIVERSO DA NULL CIOÈ SE SI È MODALITÀ 'SIMULAZIONE CLIENT-ADMIN'
	if (client){    //PUBBLICA SOLO SE IN MODALITÀ INTERAZIONE
        //if (clicks == 0){
			admin->pubblicaModifiche(client);         /*admin pubblica a client ==> invoca (client->db)->sincronizza() e risintonizza il puntatore a utente nel cliente*/
        //}
        /*else if (clicks > 0){
			OutputMessage("Le modifiche multiple non sono permesse con l'interazione cliente-amministratore");
        }*/
    }  			                                    
}

void AdminWidget::insertNuovoUtente(){
    //allocare l'utente con tipo giusto
    //controllare se il username non esiste gia'
    Utente* toAddPtr;
    QList<QString> listOfSkills;
    QList<QString> listOfLingue; 
    QList<QString> listOfStudi;
    QList<Username> listOfContatti;    //solo da passare al costruttore, non da riempire
    for (int i = 0; i < 5; ++i){
 	if (skills[i]->text() != ""){
        listOfSkills.push_back((skills[i]->text()).simplified());
	}
    } 
    for (int i = 0; i < 5; ++i){
 	if (lingue[i]->text() != ""){
        listOfLingue.push_back((lingue[i]->text()).simplified());
	}
    }
    for (int i = 0; i < 5; ++i){
 	if (studi[i]->text() != ""){
        listOfStudi.push_back((studi[i]->text()).simplified());
	}
    }    
    if (nome->text()!="" and cognome->text()!="" and username->text()!="" and
		tipoacc->text()!="" and password->text()!=""){         //almeno nome,cognome,username,tipoacc e password devono esserci

        if (!(QString::compare((tipoacc->text()).simplified(),"basic",Qt::CaseInsensitive))){
            toAddPtr = new UtenteBasic((nome->text()).simplified(),(cognome->text()).simplified(),Username((username->text()).simplified()),basic,
            listOfSkills,listOfLingue,listOfStudi,listOfContatti,(password->text()).simplified());
    	}
    	else if(!(QString::compare(tipoacc->text(),"business",Qt::CaseInsensitive))){
        toAddPtr = new UtenteBusiness((nome->text()).simplified(),(cognome->text()).simplified(),Username((username->text()).simplified()),business,
                                      listOfSkills,listOfLingue,listOfStudi,listOfContatti,(password->text()).simplified());
    	}
    	else if (!(QString::compare(tipoacc->text(),"executive",Qt::CaseInsensitive))){
            toAddPtr = new UtenteExecutive((nome->text()).simplified(),(cognome->text()).simplified(),Username((username->text()).simplified()),executive,
                                           listOfSkills,listOfLingue,listOfStudi,listOfContatti,(password->text()).simplified());
    	}
        try{
	        admin->insert(toAddPtr);       
	        if (client){   //PUBBLICA SOLO SE IN MODALITÀ INTERAZIONE
			admin->pubblicaModifiche(client);
		}
    	}
    	catch(UtenteEsistente& e){
            OutputMessage msg("Impossibile aggiungere l'utente, username gia' presente nel database.");
        }
    }
    else{
         //comunicare che ci sono troppi campi vuoti
         OutputMessage msg("I campi nome,cognome,username,tipoaccount e password non possono essere vuoti.");
    }
}

void AdminWidget::count_clicks(){
    if ((insertUsername->text()).simplified() != ""){
        clicks++;
    }
}

//###########################END OF SLOTS
