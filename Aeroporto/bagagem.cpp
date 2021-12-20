#include <fstream>
#include <sstream>
#include "bagagem.h"


Bagagem::Bagagem(int nb, float p) : numBilhete(nb), peso(p) {}

int Bagagem::getNumBilhete() const {
    return this-> numBilhete;
}

float Bagagem::getPeso() const {
    return peso;
}
//------------------------------------------------------------------------------------------------------------------------------

GestaoBagagens::GestaoBagagens(unsigned int c, unsigned int n, unsigned int m) : numCarruagens(c), numPilhas(n), numMalas(m) {}

void GestaoBagagens::colocarMalas(){
    stack<Bagagem> pilhaBagagemVazia;
    Bagagem bagagemVazia;
    static int i = 0;

    for(int i = 0; i < numCarruagens; i++) {
        list<stack<Bagagem>> novaCarruagemVazia;
        for(int j = 0; j < numPilhas; j++) {
            novaCarruagemVazia.push_back(pilhaBagagemVazia);
            for(int k = 0; k < numMalas; k++) {
                pilhaBagagemVazia.push(bagagemVazia);
            }
        }
        carrinho.push_back(novaCarruagemVazia);
    }

    while (!tapeteInserir.empty()) {
        for (auto it = carrinho.begin(); it != carrinho.end(); it++) {
            for (auto et = (*it).begin(); et != (*it).end(); et++) {
                stack<Bagagem> st;
                while (st.size() < numMalas) {
                    if (tapeteInserir.empty()) break;
                    Bagagem b = tapeteInserir.front();
                    //cout << tapeteInserir.front().getNumBilhete() << endl;
                    st.push(b);
                    tapeteInserir.pop(); //pop deleta o front
                }
                (*et) = st;
            }
        }
        if (i == carrinho.size() - 1) break; //se o carrinho estiver cheio -> termina
    }   // a inserção de bagagem!
}

void GestaoBagagens::retirarMalas(){
    Bagagem b;
    for (auto it = carrinho.begin(); it != carrinho.end(); it++){
        for(auto et = (*it).begin(); et != (*it).end(); et++){
            b = (*et).top();
            (*et).pop();
            tapeteRetirar.push(b);
        }
    }
}

void GestaoBagagens::TapeteInput() {
    //valores para testar
    tapeteInserir.push(Bagagem(12,30));
    tapeteInserir.push(Bagagem(13,20));
    tapeteInserir.push(Bagagem(14,45));
}

void GestaoBagagens::WriteTapete() {
    ofstream file;
    file.open("");
    while (!tapeteInserir.empty()){
        file << tapeteInserir.front().getNumBilhete() << ',' << tapeteInserir.front().getPeso() << ','  << endl;
        tapeteInserir.pop();
    }
    file.close();
}

void GestaoBagagens::ReadTapete() {
    int nrBilh;
    float pes;
    ifstream file("tapete.txt");
    string line;
    Bagagem b;
    int i = 0;
    while (getline(file, line, ',')){
        switch (i) {
            case (0):
                nrBilh = stoi(line);
                b.setNumBilhete(nrBilh);
                break;
            case(1):
                pes = stof(line);
                b.setPeso(pes);
                tapeteInserir.push(b);
                i = -1;
                break;
        }
        i++;

    }
    file.close();
}







