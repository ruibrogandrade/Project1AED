#include "passageiros.h"
#include "voo.h"

/**
 * Construtor padrão
 */

Passageiro::Passageiro() {}

/**
 * Construtor que inicializa os valores
 * @param nome nome do passageiro
 * @param bilhetes bilhetes comprados por esse passageiro
 */

Passageiro::Passageiro(string nome, vector<Bilhete> bilhetes) : Voo() {
    this->nome = nome;
    this->bilhetes = bilhetes;
}
 /**
  * Getter do nome do passageiro
  * @return nome do passageiro
  */

string Passageiro::getNome() {
    return nome;
}

/**
 * Adiciona um bilhete a um passageiro que o compre
 * @param nome nome do passageiro
 * @param b bilhete
 */

void Passageiro::addBilhete(string & nome, Bilhete b) {
    Voo v; //como adicionar outro bilhete à mesma pessoa?
    if (v.getVagas() != 0){
        Passageiro p;
        p.nome = nome;
        bilhetes.push_back(b);
        vagas--;
    }
}