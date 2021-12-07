#ifndef AED_PROJECT1_PASSAGEIRO_H
#define AED_PROJECT1_PASSAGEIRO_H

#include <iostream>
#include <vector>
#include <list>
#include "voo.h"


class Passageiro: public Voo{
private:
    string nome;
    vector<Bilhete> bilhetes;
    int numBilhetesAdquiridos = bilhetes.size();
public:
    Passageiro();
    Passageiro(string nome, vector<Bilhete> bilhetes);
    string getNome();
    void addBilhete(string & nome, Bilhete b);

};


#endif //AED_PROJECT1_PASSAGEIRO_H
