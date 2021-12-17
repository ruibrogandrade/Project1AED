
#ifndef PROJETO1_BILHETE_H
#define PROJETO1_BILHETE_H

class Bilhete{  //como relaciono esta classe com a classe Voo?
    //deixo estar esta classe aqui,
    //ou meto-a no passageiro.h? -> numVoo como atributo privado
private:
    int numBilhete;
    int quantBagagem;
    int numVoo;
    bool bagagem; //se ja temos o int quantBagagem, este sendo = 0 ja dava para
    //perceber se ha bagagem ou nao, por isso nao acho que seja preciso este bool
public:
    Bilhete();
    Bilhete(int nrBilh, int quantBag, int nrVoo) {
        this->numBilhete = nrBilh;
        this->quantBagagem = quantBag;
        this->numVoo = nrVoo;
    };
    int getNumBilhete() const;
    void setNumBilhete(int numBilhete);
    int getNumVoo() const;
    void setNumVoo(int numVoo);
    int getBagagem() const;
    void setBagagem(bool bagagem);

};

#endif //PROJETO1_BILHETE_H
