#ifndef START_WIDGET_H
#define START_WIDGET_H

#include "login_widget.h"


/*Interfaccia che permette di scegliere le 3 modalità di utilizzo:
 a)utilizzo lato cliente
 b)utilizzo lato admin
 c)simulazione interazione cliente-admin
  NB::nei primi 2 casi non ha senso il concetto di
             'pubblicazione delle modifiche'
*/

//explicit ClientWidget(LinQedInClient*,LinQedInAdmin*)
//explicit AdminWidget(LinQedInAdmin*,LinQedInClient*);
class StartWidget: public QWidget{
    Q_OBJECT
private:
    //elementi grafici
    QLabel* welcomeLabels[2];
    QPushButton* modeButtons[3];
public:
    explicit StartWidget();    //ritorna l'username inserito nella lineEdit
public slots:
    //slot per il bottone 'Enter'
   void avviaLatoCliente();    //===> avvia LoginWidget in modalità 'solo cliente'
   void avviaLatoAdmin();      //====> avvia AdminWidget senza passare il cliente logico
   void avviaSimulazione();    //===> avvia LoginWidget in modalità 'simulazione';
};

#endif
