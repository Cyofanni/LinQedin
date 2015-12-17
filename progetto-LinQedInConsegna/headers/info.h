#ifndef INFO_H
#define INFO_H
#include "username.h"
#include <QList>


typedef enum {basic,business,executive} TipoAccount;

class Info{
    //dati personali,competenze lavorative,lingue conosciute,titoli di studio
    //tipo account: Basic,Business,Executive
    friend class Profilo;             //Profilo
private:
        QString nome,cognome;
        Username uname;
        TipoAccount tAcc;
        QList<QString> skills,lingue,studi;				//liste di stringhe per le competenze,le lingue,e le università dell'utente
        QList<Username> contatti;
        QString password;
public:
        Info(const QString& /*nome*/,const QString& /*cognome*/,const Username&,
             const TipoAccount&,const QList<QString>&/*skills*/,const QList<QString>&/*lingue*/,
             const QList<QString>&/*studi*/,const QList<Username>&/*contatti*/,const QString&/*password*/);
};

#endif
