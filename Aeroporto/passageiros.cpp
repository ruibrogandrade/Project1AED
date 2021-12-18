#include <fstream>
#include <sstream>
#include "passageiros.h"
#include "bilhete.h"
#include "voo.h"

Passageiro::Passageiro() {}

Passageiro::Passageiro(string nome, Bilhete b)  {
    this->nome = nome;
    bilhetes.push_back(b);
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
    vector<Bilhete> bilhetes = getBilhetes();
    bilhetes.emplace_back(14,50, 109);
    bilhetes.push_back(Bilhete(15,40, 63));
    bilhetes.push_back(Bilhete(18,75, 31));
    setBilhetes(bilhetes);
}

void Passageiro::WriteBilhete() {
    ofstream file;
    vector<Bilhete> bilhetes = getBilhetes();
    file.open("");
    for (auto it = bilhetes.begin(); it != bilhetes.end(); it++){
        file << (*it).getNumBilhete() << ',' << (*it).getQuantBagagem() << ',' <<(*it).getNumVoo() << endl;
    }
    file.close();
    setBilhetes(bilhetes);
}

void Passageiro::ReadBilhete() {
    int nrBilh, quantBag, nrVoo;
    ifstream file("passageiros.txt");
    string line;
    Bilhete b;
    vector<Bilhete> bilhetes;
    int i = 0;
    while (getline(file, line, ',')){
        switch (i) {
            case (0):
                nrBilh = stoi(line);
                b.setNumBilhete(nrBilh);
                break;
            case (1):
                quantBag = stoi(line);
                b.setQuantBagagem(quantBag);
                break;
            case (2):
                nrVoo = stoi(line);
                b.setNumVoo(nrVoo);
                bilhetes.push_back(b);
                i = -1;
                break;
        }
        i++;
    }
    file.close();
    setBilhetes(bilhetes);
}

vector<Bilhete> Passageiro::getBilhetes() const{
    return bilhetes;
}

void Passageiro::setBilhetes(vector<Bilhete> bilhetes) {
    this->bilhetes=bilhetes;
}
