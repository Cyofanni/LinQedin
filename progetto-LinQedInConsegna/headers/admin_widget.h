//STRUTTURA FINESTRA DELL'ADMIN
        //PARTE SINISTRA                                //PARTE DESTRA
/*    Inserisci utente QLabel                       Cerca in LinQedIn (QPushButton)        Rimuovi da LinQedIn (QPushButton)
   QLineEdit per l'inserimento di uno username      QTextEdit con l'output
                                                    della ricerca
                                                    ******************************
                                                    ******************************
                                                    Basic     Business    Executive (QRadioButtons)
                                                    i radio buttons sopra permettono di cambiare la
                                                    tipologia dell'account dell'utente mostrato sopra
*/

#ifndef ADMIN_WIDGET_H
#define ADMIN_WIDGET_H

#include <QWidget>
#include "linqAdmin.h"
#include <QMenuBar>
#include <QGroupBox>
#include <QBoxLayout>
#include <QTextEdit>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QRadioButton>


class LinQedInClient;

class AdminWidget: public QWidget{
    Q_OBJECT
public:
    explicit AdminWidget(LinQedInAdmin*,LinQedInClient* =0);
public slots:
    void removeFromLinQedIn();
    void showProfilo();
    void changeToBasic();
    void changeToBusiness();
    void changeToExecutive();
    void insertNuovoUtente();	 //slot per l'inserimento di un nuovo utente
    void count_clicks();
    
private:
    LinQedInAdmin* admin;       //puntatore all'amministratore logico
    LinQedInClient* client;    //puntatore al cliente a cui l'admin pubblica

    QLabel* title;
    QGroupBox* boxAlto;
    QGroupBox* boxBasso;
    QLabel* inputLabel;
    QLabel* changeAccLabel;
    QLineEdit* insertUsername;
    QPushButton* buttons[2];   //array di puntatori a QPushButton
    QTextEdit* mostraProfilo;
    QRadioButton* rButtons[3];  //array di puntatori a QRadioButton
    //AGGIUNGERE gli widget PER L'INSERIMENTO DEI DATI DI UN NUOVO UTENTE 
    QGroupBox* boxInsertUtente;      //box per gli widget di inserimento nuovo utente   
    QLabel* labelNuovoUtente;    //label 'Dati nuovo utente LinQedIn'
    QLabel* skLiSt[3];
    QLineEdit* nome;        //lineEdit per nome
    QLineEdit* cognome;     //lineEdit per cognome
    QLineEdit* username;    //lineEdit per username
    QLineEdit* tipoacc;	 
    QLineEdit* skills[5];    //vettore di 5 lineEdit per le skills
    QLineEdit* lingue[5];    //vettore di 5 lineEdit per le lingue
    QLineEdit* studi[5];    //vettore di 5 lineEdit per le skills
    QLineEdit* password;    //lineEdit per password 
    QPushButton* insertUtente;  
    //dei contatti si occupera l'utente
    QLabel* fields[8];
    
    //################
    int clicks;
    
    void creaParteAlta();
    void creaParteBassa();
    void creaGuiInsertUtente();
    //METODO PER LA GRAFICA DELL'INSERIMENTO DI UN NUOVO UTENTE
};

#endif // ADMIN_WIDGET_H
