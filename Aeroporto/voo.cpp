
#include <fstream>
#include "voo.h"

using namespace std;

Voo::Voo() {}

Voo::Voo(int numVoo, Data dataPartida, int duracao, int lot, string origem, string destino, string matric) {
    this->numVoo = numVoo;
    this->dataPartida = dataPartida;
    this->duracao = duracao;
    this->lotacao = lot;
    this->origem = origem;
    this->destino = destino;
    this->vagas = lot;
    this->matriculaAviao = matric;
}

int Voo::getNumVoo() const{
    return numVoo;
}

void Voo::setNumVoo(int numVoo) {
    this->numVoo=numVoo;
}

Data Voo::getDataPartida() const{
    return dataPartida;
}

void Voo::setDataPartida(Data dataPartida) {
    this->dataPartida=dataPartida;
}

int Voo::getDuracao() const{
    return duracao;
}
void Voo::setDuracao(int duracao) {
    this->duracao=duracao;
}

int Voo::getNumLugares() const{
    return lotacao;
}

void Voo::setNumLugares(int lotacao) {
    this->lotacao=lotacao;
}

int Voo::getNumLugaresOcupados() const{
    return lotacao - vagas;
}

int Voo::getVagas() const{
    return vagas;
}

void Voo::setVagas(int vagas) {
    this->vagas=vagas;
}

string Voo::getOrigem() const{
    return origem;
}

void Voo::setOrigem(string origem) {
    this->origem=origem;
}

string Voo::getDestino() const{
    return destino;
}

void Voo::setDestino(string destino) {
    this->destino=destino;
}

string Voo::getMatriculaAaviao() {
    return matriculaAviao;
}

void Voo::setMatriculaAviao(string matricula) {
    this->matriculaAviao = matricula;
}
