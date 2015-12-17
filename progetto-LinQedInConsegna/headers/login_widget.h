#ifndef LOGIN_WIDGET_H
#define LOGIN_WIDGET_H

#include "linq_login.h"
#include "client_widget.h"
#include "admin_widget.h"
#include <QWidget>
#include <QMessageBox>

typedef enum {latoCliente,simulazione} modUtilizzo;   

class LoginWidget: public QWidget{
    Q_OBJECT
private:
    modUtilizzo linqEdInMode;     //campo dati che registra la modalità di utilizzo di linqedin
    LinQedInLogin* l_login;     //logic login

    //elementi grafici
    QLabel* welcomeLabel;
    QLineEdit* lineEdits[2];
    QPushButton* enterButton;
public:
    /*IL COSTRUTTORE DEVE ACCETTARE UN PARAMETRO CHE INDICA LA MODALITÀ CON CUI FAR PARTIRE LINQEDIN
		a) 0: modalità 'SOLO CLIENTE'
		b) 1: modalità 'SIMULAZIONE UTENTE-CLIENTE'
	*/ 
    explicit LoginWidget(modUtilizzo);           
    Username getUsername() const;     //ritorna l'username inserito nella lineEdit
public slots:
    //slot per il bottone 'Enter'
   void avviaLinQedIn();
};

#endif // LOGIN_WIDGET_H
