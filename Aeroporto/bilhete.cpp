#include "bilhete.h"

/**
 * Construtor de bilhete
 */
Bilhete::Bilhete() {}

/**
 * Getter para a baggagem
 * @return bagagem
 */

int Bilhete::getBagagem() const{
    return bagagem;
}

/**
 * Setter para bagagem
 * @param bagagem
 */

void Bilhete::setBagagem(bool bagagem) {
    this->bagagem=bagagem;
}

/**
 * Getter para o número do voo
 * @return número do voo
 */

int Bilhete::getNumVoo() const {
    return numVoo;
}

/**
 * Setter para o número do voo
 * @param numVoo
 */

void Bilhete::setNumVoo(int numVoo) {
    this->numVoo=numVoo;
}

/**
 * Getter para o número do bilhete
 * @return número do bilhete
 */

int Bilhete::getNumBilhete() const {
    return numBilhete;
}

/**
 *Setter para o número do bilhete
 * @param numBilhete
 */

void Bilhete::setNumBilhete(int numBilhete) {
    this->numBilhete=numBilhete;
}