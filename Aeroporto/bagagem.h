//
// Created by andre on 06/12/2021.
//

#ifndef PROJETO1AED_BAGAGEM_H
#define PROJETO1AED_BAGAGEM_H


class Bagagem {
    int numBilhete; //funciona como id
    float peso;
public:
    Bagagem(int nb, float p);
    int getNumBilhete() const;
    float getPeso() const;
};


#endif //PROJETO1AED_BAGAGEM_H
