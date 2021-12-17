#include <fstream>
#include <sstream>
#include "passageiros.h"
//#include "voo.h"

Passageiro::Passageiro() {}

Passageiro::Passageiro(string nome, vector<Bilhete> bilhetes) : Voo() {
    this->nome = nome;
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
