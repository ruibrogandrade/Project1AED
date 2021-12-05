#include "voo.h"
using namespace std;


Voo::Voo() {}

Voo::Voo(int lot) { //   : lotação(lot)
    vagas = lot;
}

Voo::Voo(int numVoo, int dataPartida, int duração, int lot, string origem, string destino) : lotação(lot){
    this->numVoo = numVoo;
    this->dataPartida = dataPartida;
    this->duração = duração;
    this->origem = origem;
    this->destino = destino;
    vagas = lot;
}

int Voo::getNumVoo() const {
    return this->numVoo;
}

int Voo::getDataPartida() const {
    return this->dataPartida;
}

int Voo::getDuração() const {
    return this->duração;
}

int Voo::getNumLugares() const {
    return lotação;
}

int Voo::getNumLugaresOcupados() const {
    return lotação - vagas;
}

int Voo::getVagas() {
    return vagas;
}

string Voo::getOrigem() const {
    return this->origem;
}

string Voo::getDestino() const {
    return this->destino;
}






