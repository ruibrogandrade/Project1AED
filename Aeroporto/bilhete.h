
#ifndef PROJETO1_BILHETE_H
#define PROJETO1_BILHETE_H

class Bilhete{  //como relaciono esta classe com a classe Voo?
    //deixo estar esta classe aqui,
    //ou meto-a no passageiro.h?
private:
    int numBilhete;
    int quantBagagem;
public:
    Bilhete();
    bool bagagem();
    int getNumBilhete();
};

#endif //PROJETO1_BILHETE_H
