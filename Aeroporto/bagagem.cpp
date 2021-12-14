//
// Created by andre on 06/12/2021.
//

#include "bagagem.h"

Bagagem::Bagagem(int nb, float p) : numBilhete(nb), peso(p){}

int Bagagem::getNumBilhete() const {
    return numBilhete;
}

float Bagagem::getPeso() const {
    return peso;
}
