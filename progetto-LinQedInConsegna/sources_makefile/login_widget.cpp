#include "../headers/login_widget.h"
#include <QtCore>


LoginWidget::LoginWidget(modUtilizzo mod): linqEdInMode(mod){
    QVBoxLayout* layout = new QVBoxLayout;
    QHBoxLayout* layout2LineEdit = new QHBoxLayout;

    QMenuBar* menuBar = new QMenuBar(0);      //l'usuale barra in alto a sinistra
    QMenu* fileMenu = menuBar->addMenu(tr("File"));
    fileMenu->addSeparator();
    QAction* exitAction = fileMenu->addAction(tr("Close LinQedIn"));
    //CONNESSIONI SIGNAL-SLOT
    connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));
    layout->setMenuBar(menuBar);


    welcomeLabel = new QLabel;
    for (int i = 0; i < 2; ++i){
        lineEdits[i] = new QLineEdit;
        layout2LineEdit->addWidget(lineEdits[i]);
    }
    lineEdits[0]->setPlaceholderText("inserisci il tuo username");
    lineEdits[1]->setPlaceholderText("inserisci la tua password");

    lineEdits[1]->setEchoMode(QLineEdit::Password);

    enterButton = new QPushButton(tr("Entra in LinQedIn"));

    QFont f("Arial",20,QFont::Bold);
    QPalette* palette = new QPalette;
    palette->setColor(QPalette::WindowText,Qt::blue);
    welcomeLabel->setText(tr("Benvenuto in LinQedIn"));
    welcomeLabel->setFont(f);
    welcomeLabel->setAlignment(Qt::AlignCenter);
    welcomeLabel->setPalette(*palette);

    layout->addWidget(welcomeLabel);
    layout->addLayout(layout2LineEdit);
    layout->addWidget(enterButton);

    connect(enterButton,SIGNAL(clicked()),this,SLOT(avviaLinQedIn()));

    setFixedSize(400,150);      //il login widget deve avere una dimensione fissa
    setLayout(layout);
}

Username LoginWidget::getUsername() const{
    return lineEdits[0]->text();
}

//SLOT PER 'enterButton'
//CONTROLLA IL CAMPO 'mode' e avvia i widget giusti di conseguenza
//Solo per cliente e simulazione
void LoginWidget::avviaLinQedIn(){
    Username uname = Username((lineEdits[0]->text()).simplified());
    
    l_login = new LinQedInLogin(uname,lineEdits[1]->text());
    //oggetto puntato da l_login costruito correttamente
    LinQedInAdmin* admin;  //il puntatore admin serve a ClientWidget
    
    if (l_login->check()){        //se il login ha avuto successo
	   if (linqEdInMode == simulazione){
         	admin = new LinQedInAdmin;   //NB::QUESTO CODICE DEVE ESSERE ESEGUITO SOLO SE linqEdInMode==simulazione
       }
       else if (linqEdInMode == latoCliente){
		    admin = 0;
	   }
	   LinQedInClient* client = new LinQedInClient(uname);   //carica il proprio db dal file
       ClientWidget* cwPtr = new ClientWidget(client,admin);   //client pubblica ad admin
       /*NB::il ClientWidget DEVE ESSERE ALLOCATO SULLO HEAP COSì RIMANE ATTIVO ANCHE AL RITORNO DA
         QUESTA FUNZIONE!!!!!!!*/
       cwPtr->show();
       if (linqEdInMode == simulazione){
		   AdminWidget* awPtr = new AdminWidget(admin,client);  //admin pubblica a client==> NB::QUESTO CODICE DEVE ESSERE ESEGUITO SOLO SE linqEdInMode==simulazione
		   awPtr->show();
	   }
       this->hide();     //nasconde la finestra di login
    }
    
    else{    //se il login non è riuscito
        OutputMessage("Username o password non corretti");
    }
    delete l_login;     //dealloca l'oggetto per il login logico 
}
