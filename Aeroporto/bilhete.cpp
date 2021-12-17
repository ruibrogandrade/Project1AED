#include "bilhete.h"

Bilhete::Bilhete() { //inicializei com valores para ver se eliminava o erro: undefined reference to `Passageiro::bilhetes'
    //mas nao resultou :(
    this->numBilhete = 0;
    this->quantBagagem = 0;
    this->numVoo = 0;
    this->bagagem = false;
}

int Bilhete::getBagagem() const{
    return bagagem;
}

void Bilhete::setBagagem(bool bagagem) {
    this->bagagem=bagagem;
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


