#include "../headers/esiste_utente.h"

InfoVis_Basic* EsisteUtente::operator()(const Profilo& p,QTextEdit* qed) const{
    return new InfoVis_Basic(p,qed);     //il costruttore di InfoVisBasic stampa "l'utente cercato esiste"
}
