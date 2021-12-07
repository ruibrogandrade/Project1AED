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
    //vector<string> matricula;
    string matricula;
    int capacidade;
    list<Voo> listaVoo;
    queue<servico> servicos;
public:
    Aviao();
    Aviao(string matricula, int capacidade,list<Voo> listaVoo);
    list<Voo> getListaVoo() const;
    void novoservico(vector<servico> ns);
    void atualizarservicos(vector<servico> sf);
};



#endif //PROJETO1_AVIAO_H
