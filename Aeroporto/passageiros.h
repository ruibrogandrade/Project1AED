#ifndef PROJETO1_PASSAGEIROS_H
#define PROJETO1_PASSAGEIROS_H

#include <iostream>
#include <vector>
#include <list>
#include "voo.h"
#include "bilhete.h"


class Passageiro: public Voo{
private:
    string nome;
    static vector<Bilhete> bilhetes;
    int numBilhetesAdquiridos = bilhetes.size();
public:
    Passageiro();
    Passageiro(string nome, Bilhete b);
    string getNome();
    void addBilhete(string & nome, Bilhete b);
    static void BilheteInput();
    static void WriteBilhete();
    static void ReadBilhete();

};

#endif //PROJETO1_PASSAGEIROS_H
