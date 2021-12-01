#include "voo.h"
using namespace std;

Voo::Voo() {
    //não sei se faz sentido criar um voo vazio (?)
}

Voo::Voo(int numVoo, int dataPartida, int duração, string origem, string destino) {
    this->numVoo = numVoo;
    this->dataPartida = dataPartida;
    this->duração = duração;
    this->origem = origem;
    this->destino = destino;
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

string Voo::getOrigem() const {
    return this->origem;
}

string Voo::getDestino() const {
    return this->destino;
}





