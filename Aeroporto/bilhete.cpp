#include "bilhete.h"

Bilhete::Bilhete() {}

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