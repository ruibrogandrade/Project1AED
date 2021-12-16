#ifndef PROJETO1_VOO_H
#define PROJETO1_VOO_H

#include <iostream>
#include <vector>
#include "Data.h"

using namespace std;

class Voo{
private: //estes atributos estariam tbm em protected para de alguma
    //maneira a classe Bilhete conseguir aceder?
    int numVoo, duracao;
    string origem, destino;
    Data dataPartida;
protected:
    int vagas; //int vagas{}; porque é q puseram assim dantes?
    int lotacao; //const
public:
    Voo();
    Voo(int numVoo, Data dataPartida, int duracao, int lot, string origem, string destino);
    int getNumVoo() const; //Porque é que os getters eram const?
    void setNumVoo(int numVoo);
    Data getDataPartida() const;
    void setDataPartida(Data dataPartida);
    int getDuracao() const;
    void setDuracao(int duracao);
    int getNumLugares() const;
    void setNumLugares(int lotacao);
    int getNumLugaresOcupados() const;
    int getVagas() const;
    void setVagas(int vagas);
    string getOrigem() const;
    void setOrigem(string origem);
    string getDestino() const;
    void setDestino(string destino);
};



#endif //PROJETO1_VOO_H
