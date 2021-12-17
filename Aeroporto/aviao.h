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
    static list<Voo> listaVoo;
    vector<servico> servicos;
public:
    Aviao();
    Aviao(string matric, int cap){
        this->matricula = matric;
        this->capacidade = cap;
    };
    Aviao(string matricula, int capacidade,list<Voo> listaVoo);
    static list<Aviao> avioes;
    list<Voo> getListaVoo() const;
    string getMatricula() const {return matricula;};
    int getCapacidade() const {return capacidade;};
    void novoservico(vector<servico> ns);
    //void atualizarservicos(vector<servico> sf);
    void atualizarservicos(queue<servico> spf, vector<servico> sf);
    static void VooInput();
    static void WriteVoo();
    static void ReadVoo();
    static void AviaoInput();
    static void WriteAviao();
    static void ReadAviao();

};

#endif //PROJETO1_AVIAO_H
