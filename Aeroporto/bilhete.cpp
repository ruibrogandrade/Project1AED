#include "bilhete.h"

Bilhete::Bilhete() {}

int Bilhete::getQuantBagagem() const{
    return quantBagagem;
}

void Bilhete::setQuantBagagem(int quantBagagem) {
    this->quantBagagem = quantBagagem;
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


