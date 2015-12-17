#include "../headers/start_widget.h"

StartWidget::StartWidget(){
	QVBoxLayout* layout = new QVBoxLayout;
    QHBoxLayout* layout3Buttons = new QHBoxLayout;

    QMenuBar* menuBar = new QMenuBar(0);      //l'usuale barra in alto a sinistra
    QMenu* fileMenu = menuBar->addMenu(tr("File"));
    fileMenu->addSeparator();
    QAction* exitAction = fileMenu->addAction(tr("Close LinQedIn"));
    //CONNESSIONI SIGNAL-SLOT
    connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));
    layout->setMenuBar(menuBar);
	
	/////////////////////////////
	for (int i = 0; i < 2; ++i){
		welcomeLabels[i] = new QLabel;
    }
    QFont f("Arial",20,QFont::Bold);
    QPalette* palette = new QPalette;
    palette->setColor(QPalette::WindowText,Qt::blue);
    welcomeLabels[0]->setText(tr("Benvenuto in LinQedIn"));
    welcomeLabels[0]->setFont(f);
    welcomeLabels[0]->setAlignment(Qt::AlignCenter);
    welcomeLabels[0]->setPalette(*palette);
    
    QFont f1("Arial",15,QFont::Bold);
    QPalette* palette1 = new QPalette;
    palette1->setColor(QPalette::WindowText,Qt::blue);
    welcomeLabels[1]->setText(tr("Seleziona l'interfaccia di utilizzo di LinQedIn"));
    welcomeLabels[1]->setFont(f1);
    welcomeLabels[1]->setAlignment(Qt::AlignCenter);
    welcomeLabels[1]->setPalette(*palette1);
    
    modeButtons[0] = new QPushButton(tr("Cliente"));
    modeButtons[1] = new QPushButton(tr("Amministratore"));
    modeButtons[2] = new QPushButton(tr("Interazione cliente@amministratore"));
	for (int i = 0; i < 3; ++i){
		layout3Buttons->addWidget(modeButtons[i]);
    }
    
	for (int i = 0; i < 2; ++i){
		layout->addWidget(welcomeLabels[i]);
    }
    
    layout->addLayout(layout3Buttons);

    connect(modeButtons[0],SIGNAL(clicked()),this,SLOT(avviaLatoCliente()));
    connect(modeButtons[1],SIGNAL(clicked()),this,SLOT(avviaLatoAdmin()));
    connect(modeButtons[2],SIGNAL(clicked()),this,SLOT(avviaSimulazione()));
    

    setFixedSize(600,200);      //lo start widget deve avere una dimensione fissa
    setLayout(layout);
}

//SLOTS
void StartWidget::avviaLatoCliente(){
	//avvia LoginWidget con parametro 'latoCliente'
    LoginWidget* login = new LoginWidget(latoCliente);
    login->show();
    this->hide();
}

void StartWidget::avviaLatoAdmin(){
    //avvia direttamente AdminWidget senza cliente
    LinQedInAdmin* admin = new LinQedInAdmin;
    AdminWidget* awPtr = new AdminWidget(admin,NULL);
    awPtr->show();
    this->hide();
}

void StartWidget::avviaSimulazione(){
	//avvia LoginWidget con parametro 'simulazione'
    LoginWidget* login = new LoginWidget(simulazione);
    login->show();
    this->hide();
}

