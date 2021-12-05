
#include "voo.h"

using namespace std;


Voo::Voo() {}

Voo::Voo(int lot) { //   : lotacao(lot)
    vagas = lot;
}

Voo::Voo(int numVoo, int dataPartida, int duracao, int lot, string origem, string destino) : lotacao(lot){
    this->numVoo = numVoo;
    this->dataPartida = dataPartida;
    this->duracao = duracao;
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

int Voo::getduracao() const {
    return this->duracao;
}

int Voo::getNumLugares() const {
    return lotacao;
}

int Voo::getNumLugaresOcupados() const {
    return lotacao - vagas;
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
