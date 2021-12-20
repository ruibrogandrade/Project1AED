
#include <fstream>
#include "voo.h"

using namespace std;

Voo::Voo() {}

Voo::Voo(int numVoo, Data dataPartida, int duracao, int lot, string origem, string destino) {
    //ao fazermos assim o construtor de voo, estamos basicamente a incorporar o updater aqui dentro, não sei se está correto
    this->numVoo = numVoo;
    this->dataPartida = dataPartida;
    this->duracao = duracao;
    this->origem = origem;
    this->destino = destino;
    vagas = lot;
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

void Voo::ReadVoo() {
    ifstream file("voo.txt");
    string line;
    Voo v;
    int numVoo;
    Voo tmp;
    Data dataDePartida;
    int duracao;
    int dia;
    int mes;
    int ano;
    int lot;
    string origem;
    string destino;
    int i = 0;
    while(getline(file,line,',')) {
        switch(i) {
            case (0):
                numVoo = stoi(line);
                tmp.setNumVoo(numVoo);
                break;
            case (1):
                dia = stoi(line.substr(0, 2));
                mes = stoi(line.substr(3, 2));
                ano = stoi(line.substr(6, 4));
                dataDePartida.setDia(dia);
                dataDePartida.setMes(mes);
                dataDePartida.setAno(ano);
                tmp.setDataPartida(dataDePartida);
                break;
            case (2):
                duracao = stoi(line);
                tmp.setDuracao(duracao);
                break;
            case (3):
                lot = stoi(line);
                tmp.setNumLugares(lot);
                break;
            case (4):
                origem = line;
                tmp.setOrigem(origem);
                break;
            case (5):
                destino = line;
                tmp.setDestino(destino);
                listVoos.push_back(tmp);
                i = -1;
                break;
        } i++;
    }
}

void Voo::WriteVoo() {
    ofstream file;
    Voo tmp;
    file.open("voo.txt");
    for(auto it = listVoos.begin(); it != listVoos.end(); it++) {
             file << (*it).getNumVoo() << ',';
             if ((*it).getDataPartida().getDia() < 10) file << "0" << (*it).getDataPartida().getDia();
             else file << (*it).getDataPartida().getDia();
             file <<'/';
             if ((*it).getDataPartida().getMes() < 10) file << "0" << (*it).getDataPartida().getMes();
             else file << (*it).getDataPartida().getMes();
             file << "/"
             << (*it).getDataPartida().getAno() << ',' << (*it).getDuracao() << ',' << (*it).getNumLugares() << ','
             << (*it).getOrigem() << ',' << (*it).getDestino() << ',';
             if (next(it) == listVoos.end()) continue;
             else file << endl;
    }
    file.close();
}
