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
    cout << "Quantos bilhetes deseja adicionar? ";
    cout << endl;
    int quant;
    cin >> quant;
    if (quant == 0) { cout << "Nao vai ser adicionado nenhum bilhete." << endl;}
    if (quant == 1) {cout << "Vamos adicionar um novo Bilhete." << endl;}
    if (quant > 1) {cout << "Vamos adicionar " << quant << " novos Bilhetes." << endl;}
    cout << endl;
    while(quant != 0){
        cout << "Insira o nr de Bilhete: " << endl;
        int nrBilhete;
        cin >> nrBilhete;
        cout << "Insira o numero de bagagens associadas ao Bilhete: " <<  endl;
        int nrBagagens;
        cin >> nrBagagens;
        cout << "Insira o numero do Voo associado ao Bilhete: " <<  endl;
        int nrVoo;
        cin >> nrVoo;
        Bilhete b = Bilhete(nrBilhete, nrBagagens, nrVoo);
        bilhetes.push_back(b);
        cout << endl;
        quant--;
        if(quant != 0) {
            cout << "(Proximo Bilhete)";
            cout << endl;
        }
    }
}

void Passageiro::WriteBilhete() {
    ofstream file;
    file.open("passageiros.txt");
    for (auto it = bilhetes.begin(); it != bilhetes.end(); it++){
        file << (*it).getNumBilhete() << ',' << (*it).getQuantBagagem() << ',' << (*it).getNumVoo() << ',';
        if (next(it) == bilhetes.end()) continue;
        else file << endl;
    }
    file.close();
}

void Passageiro::ReadBilhete() {
    int nrBilh, quantBag, nrVoo;
    ifstream file("passageiros.txt");
    string line;
    Bilhete b;
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
    /*
    for(auto it = bilhetes.begin(); it != bilhetes.end(); it++){
        cout << (*it).getNumBilhete() << ',' << (*it).getQuantBagagem() << ',' << (*it).getNumVoo() << endl;
    }*/
}

vector<Bilhete> Passageiro::getBilhetes() const{
    return bilhetes;
}

void Passageiro::setBilhetes(vector<Bilhete> bilhetes) {
    this->bilhetes=bilhetes;
}
