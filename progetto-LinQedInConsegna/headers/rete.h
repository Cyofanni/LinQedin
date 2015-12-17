#ifndef RETE_H
#define RETE_H

#include "username.h"
#include  <QList>
//Serve accesso a DB per effettuare assegnazione tra smart Utenti

class Utente;


class Rete{
private:
    QList<Utente*> rete;
public:
    void add(Utente*);

    void remove(int);

    /*Metodi pubblici utili a mantenere il contenitore 'rete' privato::
       non fanno altro che utilizzare i metodi 'size()' e 'at()' di QList
    */
    int sizeRete() const;
    Utente* at(int i) const;
    ~Rete();      //Distruttore,dealloca solo i puntatori,non gli oggetti puntati
};

#endif
