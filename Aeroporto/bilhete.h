
#ifndef PROJETO1_BILHETE_H
#define PROJETO1_BILHETE_H

class Bilhete{
private:
    int numBilhete;
    int quantBagagem;
    int numVoo;
public:
    Bilhete();
    Bilhete(int nrBilh, int quantBag, int nrVoo);
    int getNumBilhete() const;
    void setNumBilhete(int numBilhete);
    int getNumVoo() const;
    void setNumVoo(int numVoo);
    int getQuantBagagem() const;
    void setQuantBagagem(int bagagem);

};

#endif //PROJETO1_BILHETE_H
