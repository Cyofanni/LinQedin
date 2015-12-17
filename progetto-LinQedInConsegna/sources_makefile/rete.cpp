#include "../headers/rete.h"

void Rete::add(Utente* u){
    rete.push_back(u);
}

void Rete::remove(int i){
    //ricerca nel campo 'rete'
    rete.removeAt(i);     //dovrebbe rimuovere solo il puntatore, non l'oggetto puntato
}

int Rete::sizeRete() const{
    return rete.size();
}

Utente* Rete::at(int i) const{
    return rete.at(i);
}

Rete::~Rete(){
    rete.clear();        //dealloca solo i puntatori, perché puntano ad oggetti condivisi con il database che quindi non vanno deallocati
}
