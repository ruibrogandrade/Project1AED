#include "passageiros.h"
#include "voo.h"
#include "bilhete.h"

/**
 * Construtor padrão
 */

Passageiro::Passageiro() {}

/**
 * Construtor que inicializa os valores
 * @param nome nome do passageiro
 * @param bilhetes bilhetes comprados por esse passageiro
 */

Passageiro::Passageiro(string nome, Bilhete b) : Voo() {
    this->nome = nome;
    bilhetes.push_back(b);
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


void Passageiro::BilheteInput() {
    bilhetes.emplace_back(14,50, 109);
    bilhetes.push_back(Bilhete(15,40, 63));
    bilhetes.push_back(Bilhete(18,75, 31));
}

void Passageiro::WriteBilhete() {
    ofstream file;
    file.open("");
    for (auto it = bilhetes.begin(); it != bilhetes.end(); it++){
        file << (*it).getNumBilhete() << ',' << (*it).getBagagem() << ',' <<(*it).getNumVoo() << endl;
    }
    file.close();

}

void Passageiro::ReadBilhete() {
    int nrBilh, quantBag, nrVoo;
    ifstream file("");
    string line;
    stringstream toInt(line);
    Bilhete b;
    int i = 0;
    while (getline(file, line, ',')){
        switch (i) {
            case (0):
                toInt >> nrBilh;
                b.setNumBilhete(nrBilh);
                break;
            case (1):
                toInt >> quantBag;
                b.setBagagem(quantBag);
                break;
            case (2):
                toInt >> nrVoo;
                b.setNumVoo(nrVoo);
                i = -1;
                break;
        }
        i++;
        bilhetes.push_back(b);
    }
    file.close();

}