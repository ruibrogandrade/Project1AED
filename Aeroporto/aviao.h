//
// Created by andre on 05/12/2021.
//

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
    string tipo;
    static list<Aviao> listAviao;
    list<Voo> listaVoo;
    queue<servico> servicos;
public:
    Aviao();
    Aviao(string matricula, int capacidade,list<Voo> listaVoo, string tipo);
    list<Voo> getListaVoo() const;
    string getMatricula() const;
    void setMatricula();
    list<Aviao> getListAviao();
    void setListAviao(list<Aviao> listAviao);
    void novoservico(servico novo);
};



#endif //PROJETO1_AVIAO_H
