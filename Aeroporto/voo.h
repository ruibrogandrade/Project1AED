
#ifndef PROJETO1_VOO_H
#define PROJETO1_VOO_H



#include <iostream>
#include <vector>
using namespace std;

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


class Voo{
private: //estes atributos estariam tbm em protected para de alguma
    //maneira a classe Bilhete conseguir aceder?
    int numVoo, dataPartida, duracao;
    string origem, destino;
protected:
    int vagas;
    int lotacao; //const
public:
    Voo();
    Voo(int lot);
    Voo(int numVoo, int dataPartida, int duracao, int lot, string origem, string destino);
    int getNumVoo() const;
    int getDataPartida() const;
    int getduracao() const;
    int getNumLugares() const;
    int getNumLugaresOcupados() const;
    int getVagas();
    string getOrigem() const;
    string getDestino() const;
};



#endif //PROJETO1_VOO_H
