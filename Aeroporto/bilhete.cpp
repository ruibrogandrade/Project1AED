#include "bilhete.h"

Bilhete::Bilhete() { //inicializei com valores para ver se eliminava o erro: undefined reference to `Passageiro::bilhetes'
    //mas nao resultou :(
    this->numBilhete = 0;
    this->quantBagagem = 0;
    this->numVoo = 0;
}

int Bilhete::getQuantBagagem() const{
    return quantBagagem;
}

void Bilhete::setQuantBagagem(int quantBagagem) {
    this->quantBagagem=quantBagagem;
}

int Bilhete::getNumVoo() const {
    return numVoo;
}

void Bilhete::setNumVoo(int numVoo) {
    this->numVoo=numVoo;
}

int Bilhete::getNumBilhete() const {
    return numBilhete;
}

void Bilhete::setNumBilhete(int numBilhete) {
    this->numBilhete=numBilhete;
}


