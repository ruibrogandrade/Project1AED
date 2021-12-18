#ifndef PROJETO1_AVIAO_H
#define PROJETO1_AVIAO_H

#include <iostream>
#include <vector>
#include <fstream>
#include <list>
#include <queue>
#include "voo.h"
#include "servico.h"
#include <sstream>

using namespace std;

class Aviao{
private:
    string matricula;
    int capacidade;
    string tipo;
    static list<Voo> listaVoo;
    vector<servico> servicos;
public:
    Aviao();
    Aviao(string matricula, string tipo, int capacidade, list<Voo> listaVoo);
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
