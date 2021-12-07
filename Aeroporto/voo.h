
#ifndef PROJETO1_VOO_H
#define PROJETO1_VOO_H



#include <iostream>
#include <vector>
using namespace std;


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
    int getNumVoo() const; //Porque é que os getters eram const?
    void setNumVoo(int numVoo);
    int getDataPartida() const;
    void setDataPartida(int dataPartida);
    int getDuracao()const;
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
