//STRUTTURA FINESTRA DEL CLIENT
    /*SINISTRA*/                                      /*DESTRA*/
/*   Mostra il mio profilo(QPushButton)            Casella per l'inserimento di un nome(QLineEdit) Aggiungi a i tuoi contatti(QPushButton)
     Spazio per la visualizzazione                                                                 Rimuovi dai tuoi contatti(QPushButton)
     dei dati personali                                                                            Mostra profilo(QPushButton)
     (QTextEdit --> testo modificabile)
     **************************                    Spazio per la visualizzazione(in base ai permessi) del profilo dell'utente inserito nella QLineEdit sopra (QTextEdit)
     **************************                    *******************************
     **************************                    *******************************
     **************************                    *******************************
     **************************                    *******************************
     Pubblica modifiche(QPushButton)
*/

//INTERFACCIA GRAFICA PER LinQedInClient


#ifndef CLIENT_WIDGET_H
#define CLIENT_WIDGET_H

#include <QWidget>
#include "linqClient.h"
#include "linqAdmin.h"   //per la pubblicazione delle modifiche al database dell'admin
#include <QMenuBar>
#include <QBoxLayout>
#include <QGroupBox>
#include <QTextEdit>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

#define NUM_TEXT_EDITS 4
#define NUM_LABELS 2
#define NUM_LINE_EDITS 3
#define NUM_BUTTONS 5
#define NUM_FIELDS 8

class ClientWidget: public QWidget{             //ClientWidget is a QWidget
    Q_OBJECT             //macro per compilare signals e slots
public:
    explicit ClientWidget(LinQedInClient*,LinQedInAdmin* =0);        //costruttore
public slots:          //funzioni pubbliche per la risposta ai segnali
    void mostraMioProfilo();
    void pubblicaModifiche();
    void insertContatto();
    void removeContatto();
    void mostraProfilo();
    //void showRete();

private:
    LinQedInClient* client;          //il LinQedInClient e' incapsulato come campo dati
    LinQedInAdmin* admin;

    void logicInitialize();      //inizializzazione del cliente logico
    void pubblicaModificheLogica();  //per la pubblicazione delle modifiche al database dell'admin

    //puntatori a componenti grafiche di ClientWidget incapsulati come campi dati privati
    QLabel* title;
    QGroupBox* boxSinistra;   //widget che raggruppa altri widget
    QGroupBox* boxDestra;
    QTextEdit* editMyProfilo;    //QTextEdit per la visualizzazione del profilo dell'cliente corrente
    //====> SOSTITUIRE CON DELLE QLineEdit per i campi modificabili,con delle QLabel per i campi non modificabili(tipo account,username,contatti)
	//////######
	QLabel* fields[8];
	QLineEdit* wFields[8];
	
	////#########
	
    
    QTextEdit* editProfilo[NUM_TEXT_EDITS];  //QTextEdit per la visualizzazione dei profili degli utenti cercati per nome e cognome

    QLabel* labels[NUM_LABELS];          //array di puntatori a QLabel
    QLineEdit* lineEdits[NUM_LINE_EDITS];   //l'array sta per insertUsername,insertNome,insertCognome

    QPushButton* buttons[NUM_BUTTONS];    //array di puntatori a QPushButton

    //metodi privati per il setup di ClientWidget
    void creaParteSinistra();  //questo metodo
    void creaParteDestra();
};

#endif
