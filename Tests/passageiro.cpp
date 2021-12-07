#include "passageiro.h"
//#include "voo.h"

Passageiro::Passageiro() {}

Passageiro::Passageiro(string nome, vector<Bilhete> bilhetes) : Voo() {
    this-> nome = nome;
    this->bilhetes = bilhetes;
}

string Passageiro::getNome() {
    return nome;
}

void Passageiro::addBilhete(string & nome, Bilhete b) {
    Voo v; //como adicionar outro bilhete à mesma pessoa?
    if (v.getVagas() != 0){
        Passageiro p;
        p.nome = nome;
        bilhetes.push_back(b);
        vagas--;
    }


}

