#ifndef PROFILO_H
#define PROFILO_H

#include "info.h"
#include <QTextEdit>   //per visualizza profilo
#include <QLineEdit>
#include <QFont>

class Profilo{
    private:
        Info infos;

    public:
         Profilo(const QString& /*nome*/,const QString&/*cognome*/,const Username&,
                 const TipoAccount&,const QList<QString>&/*skills*/,
                 const QList<QString>& /*lingue*/,const QList<QString>&/*università*/,
                 const QList<Username>&/*contatti*/,const QString&/*password*/);
                    //chiama il costruttore di Info per costruire infos

        QString getNome() const;
        QString getCognome() const;
        Username getUsername() const;
        TipoAccount getTipoAccount() const;		//ritorna il tipo dell'account come intero
        QString getTipoAccountAsString() const;
        void setTipoAccount(const TipoAccount&);			//usata dall'admin per modificare il tipo di account di un utente
        QList<QString> getSkills() const;
        QList<QString> getLingue() const;
        QList<QString> getStudi() const;
        QList<Username> getContatti() const;
        QString getPassword() const;

        QString getSkillsAsString() const;
        QString getLingueAsString() const;
        QString getStudiAsString() const;
        QString getContattiAsString() const;
         //permette di modificare nome,cognome,username etc...

        void modificaProfilo(const QString& /*nome*/,const QString&/*cognome*/,
                  const QList<QString>&/*skills*/,const QList<QString>& /*lingue*/,
                             const QList<QString>&/*università*/);
                             //i contatti sono modificati tramite i bottoni 'Aggiungi' e 'Rimuovi' del client
        void addContattoText(const Username&);  //aggiunge un Username alla lista di contatti (operazione puramente 'testuale')
        void removeContattoText(const Username&); //rimuove un Username alla lista di contatti (operazione puramente 'testuale')

        void visualizzaProfilo(QTextEdit*,QLineEdit**) const;
};

#endif
