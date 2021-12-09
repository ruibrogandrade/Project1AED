
#include "voo.h"

using namespace std;


Voo::Voo() {
    this->numVoo = 0;
    this->duracao = 0;
    this->origem = ' ';
    this->destino = ' ';
    this->dataPartida = Data();
    this->vagas = lotacao;
    this->lotacao = 0;
}

Voo::Voo(int lot) { //   : lotacao(lot)
    this->vagas = lot;
    this->numVoo = 0;
    this->duracao = 0;
    this->origem = ' ';
    this->destino = ' ';
    this->dataPartida = Data();
    this->lotacao = 0;
}

Voo::Voo(int numVoo, Data dataPartida, int duracao, int lot, string origem, string destino) : lotacao(lot){
    //ao fazermos assim o construtor de voo, estamos basicamente a incorporar o updater aqui dentro, não sei se está correto
    this->numVoo = numVoo;
    this->dataPartida = dataPartida;
    this->duracao = duracao;
    this->origem = origem;
    this->destino = destino;
    vagas = lot;
}

int Voo::getNumVoo() {
    return numVoo;
}

void Voo::setNumVoo(int numVoo) {
    this->numVoo=numVoo;
}

Data Voo::getDataPartida(){
    return dataPartida;
}

void Voo::setDataPartida(Data dataPartida) {
    this->dataPartida = dataPartida;
}

int Voo::getDuracao(){
    return duracao;
}
void Voo::setDuracao(int duracao) {
    this->duracao=duracao;
}

int Voo::getNumLugares(){
    return lotacao;
}

void Voo::setNumLugares(int lotacao) {
    this->lotacao=lotacao;
}

int Voo::getNumLugaresOcupados(){
    return lotacao - vagas;
}

int Voo::getVagas() {
    return vagas;
}

void Voo::setVagas(int vagas) {
    this->vagas=vagas;
}

string Voo::getOrigem(){
    return origem;
}

void Voo::setOrigem(string origem) {
    this->origem=origem;
}

string Voo::getDestino() {
    return destino;
}

void Voo::setDestino(string destino) {
    this->destino=destino;
}
