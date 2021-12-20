#ifndef PROJETO1_AVIAO_H
#define PROJETO1_AVIAO_H

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include "voo.h"
#include "servico.h"

using namespace std;

class Aviao{
private:
    string matricula;
    int capacidade;
    list<Voo> listaVoo;
public:
    Aviao();
    Aviao(string matric, int cap){
        this->matricula = matric;
        this->capacidade = cap;
    };
    Aviao(string matricula, int capacidade,list<Voo> listaVoo);
    list<Voo> getListaVoo() const;
    string getMatricula() const {return matricula;};
    int getCapacidade() const {return capacidade;};
    void listagemCompletaVoos();
    void listagemIncompleta();

    void VooInput();
    void WriteVoo();
    void ReadVoo();

    void AviaoInput();
    void WriteAviao();
    void ReadAviao();

};

static list<Aviao> listAviao;

#endif //PROJETO1_AVIAO_H
