//
// Created by andre on 06/12/2021.
//

#include "bagagem.h"

/**
 * Construtor que inicializa atributos da bagagem
 * @param nb número do bilhete associado à mala
 * @param p peso da mala
 */

Bagagem::Bagagem(int nb, float p) : numBilhete(nb), peso(p){}

/**
 * Getter para o número do bilhete
 * @return número do bilhete
 */

int Bagagem::getNumBilhete() const {
    return numBilhete;
}

/**
 * Getter do peso da mala
 * @return peso da mala
 */

float Bagagem::getPeso() const {
    return peso;
}
