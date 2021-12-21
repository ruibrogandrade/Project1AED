
#ifndef PROJETO1_BILHETE_H
#define PROJETO1_BILHETE_H

#include <iostream>
#include <string>

using namespace std;

class Bilhete{
private:
    int numBilhete;
    int quantBagagem;
    int numVoo;
    string nome;
public:
    Bilhete();
    Bilhete(int nrBilh, int quantBag, int nrVoo, string nome);
    int getNumBilhete() const;
    void setNumBilhete(int numBilhete);
    int getNumVoo() const;
    void setNumVoo(int numVoo);
    int getQuantBagagem() const;
    void setQuantBagagem(int bagagem);
    string getNome();

    void setNome(string nome);
};

#endif //PROJETO1_BILHETE_H
