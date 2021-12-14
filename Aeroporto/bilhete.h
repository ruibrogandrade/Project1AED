
#ifndef PROJETO1_BILHETE_H
#define PROJETO1_BILHETE_H

class Bilhete{  //como relaciono esta classe com a classe Voo?
    //deixo estar esta classe aqui,
    //ou meto-a no passageiro.h?
private:
    int numBilhete;
    int quantBagagem;
    int numVoo;
    bool bagagem;
public:
    Bilhete();
    int getNumBilhete() const;
    void setNumBilhete(int numBilhete);
    int getNumVoo() const;
    void setNumVoo(int numVoo);
    int getBagagem() const;
    void setBagagem(bool bagagem);
};

#endif //PROJETO1_BILHETE_H
