#ifndef AED_PROJECT1_VOO_H
#define AED_PROJECT1_VOO_H

#include <iostream>
#include <vector>
using namespace std;


class Voo{
private:
    int numVoo, dataPartida, duração;
    string origem, destino;
public:
    Voo();
    Voo(int numVoo, int dataPartida, int duração, string origem, string destino);
    int getNumVoo() const;
    int getDataPartida() const;
    int getDuração() const;
    string getOrigem() const;
    string getDestino() const;
};



#endif //AED_PROJECT1_VOO_H
