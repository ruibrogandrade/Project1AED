
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
    int vagas;
    int lotacao; //const
public:
    Voo();
    Voo(int lot);
    Voo(int numVoo, Data dataPartida, int duracao, int lot, string origem, string destino);
    int getNumVoo(); //Porque é que os getters eram const?
    void setNumVoo(int numVoo);
    Data getDataPartida();
    void setDataPartida(Data dataPartida);
    int getDuracao();
    void setDuracao(int duracao);
    int getNumLugares();
    void setNumLugares(int lotacao);
    int getNumLugaresOcupados();
    int getVagas();
    void setVagas(int vagas);
    string getOrigem();
    void setOrigem(string origem);
    string getDestino();
    void setDestino(string destino);
};



#endif //PROJETO1_VOO_H
