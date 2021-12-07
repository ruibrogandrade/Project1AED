#ifndef AED_PROJECT1_VOO_H
#define AED_PROJECT1_VOO_H

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
    int numVoo, dataPartida, duração;
    string origem, destino;
protected:
    int vagas;
    int lotação; //const
public:
    Voo();
    Voo(int lot);
    Voo(int numVoo, int dataPartida, int duração, int lot, string origem, string destino);
    int getNumVoo() const;
    int getDataPartida() const;
    int getDuração() const;
    int getNumLugares() const;
    int getNumLugaresOcupados() const;
    int getVagas();
    string getOrigem() const;
    string getDestino() const;
};



#endif //AED_PROJECT1_VOO_H
