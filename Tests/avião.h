#ifndef AED_PROJECT1_AVIÃO_H
#define AED_PROJECT1_AVIÃO_H

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include "voo.h"

using namespace std;

class Serviço{
private:
    char tipoServiço; //'m' = manutenção && 'l' = limpeza
    int data;
    string nomeFuncionário;

public:
    bool operator == (const Serviço & s) const;

};
class Avião{
private:
    //vector<string> matrícula;
    string matrícula;
    int capacidade;
    list<Voo> listaVoo;
    queue<Serviço> serviçosPorFazer;
    queue<Serviço> serviçosJáFeitos;
public:
    Avião();
    Avião(string matrícula, int capacidade,list<Voo> listaVoo);
    //list<Voo> getListaVoo() const;
    void novoServiço(vector<Serviço> ns);
    void atualizarServiços(vector<Serviço> sf);



};

#endif //AED_PROJECT1_AVIÃO_H
