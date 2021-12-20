#include <fstream>
#include <sstream>
#include "aviao.h"

using namespace std;

/**
 * Aviao
 * \brief construtor padrão
 */

Aviao::Aviao() {}

/**
 *Aviao com parâmetros
 * \brief construtor que inicializa os atributos
 * @param matricula
 * @param capacidade
 * @param listaVoo
 */

Aviao::Aviao(string matricula, int capacidade, list<Voo> listaVoo) {
    this->matricula = matricula;
    this->capacidade = capacidade;
    this->listaVoo = listaVoo;
}

/**
 * getListaVoo
 * \brief getter para voo
 * @return lista de voos
 */

list<Voo> Aviao::getListaVoo() const {
    return listaVoo;
}

//só fiz para o nr do voo
void Aviao::WriteVoo() {
    ofstream file;
    file.open("fileVoos");
    //list<Voo> tmp = listaVoo;
    for (auto it = listaVoo.begin(); it != listaVoo.end(); it++){
        file << (*it).getNumVoo() << endl;
    }
    file.close();
}
/*
void Aviao::VooInput() {
    //valores para testar
    listaVoo.emplace_back(12);
    listaVoo.push_back(Voo(19));
    listaVoo.push_back(Voo(5));
}
*/
void Aviao::ReadVoo(){
    int nrVoo;
    ifstream file("");
    string line;
    stringstream toInt(line);
    Voo v;
    while (getline(file, line, ',')){
        toInt >> nrVoo;
        v.setNumVoo(nrVoo);
    }
    file.close();
}

//só implementei para a matricula e para a capacidade
void Aviao::AviaoInput() {
    //valores para testar
    listAviao.emplace_back("37-FP-45", 1500);
    listAviao.push_back(Aviao("81-TM-05", 1250));
}

void Aviao::WriteAviao() {
    ofstream file;
    file.open("");
    for (auto it = listAviao.begin(); it != listAviao.end(); it++){
        file << (*it).getMatricula() << ','<< (*it).getCapacidade() << "," << endl;
    }
    file.close();
}

void Aviao::ReadAviao() {
    string matricula;
    int capacidade;
    //list<Voo> listaVoo;
    ifstream file("aviao.txt");
    string line;
    int i = 0;
    Aviao a;
    while (getline(file, line, ',')){
        switch(i){
            case(0):
                a.matricula = line;
                break;
            case(1):
                capacidade = stoi(line);
                a.capacidade = capacidade;
                listAviao.push_back(a);
                i = -1;
                break;
        }
        i++;
    }
    file.close();
}
