#include <fstream>
#include <sstream>
#include <iostream>
#include "bagagem.h"


Bagagem::Bagagem(int nb, float p) : numBilhete(nb), peso(p) {}

int Bagagem::getNumBilhete() const {
    return this-> numBilhete;
}

float Bagagem::getPeso() const {
    return peso;
}

GestaoBagagens::GestaoBagagens(unsigned int c, unsigned int n, unsigned int m) : numCarruagens(c), numPilhas(n), numMalas(m) {}

//função para listas
void GestaoBagagens::colocarMalas(){
    static int i = 0;
    while (!tapeteInserir.empty()) {
        for (auto it = carrinho.begin(); it != carrinho.end(); it++) {
            for (auto et = (*it).begin(); et != (*it).end(); et++) {
                stack<Bagagem> st = (*et);
                while (st.size() < numMalas) {
                    Bagagem b = tapeteInserir.front();
                    st.push(b);
                    tapeteInserir.pop(); //pop deleta o front
                }
            }
        }
        if (i == carrinho.size() - 1) break; //se o carrinho estiver cheio -> termina
    }                                        // a inserção de bagagem!
}
//funçao para vetores
/*
void GestaoBagagens::colocarMalas() {
    if (tapeteInserir.size() > numCarruagens * numMalas * numPilhas)
        throw "carrinho não pode carregar tanta bagagem";
    //se lançar a exceção executa o código a seguir?
    static int i = 0;
    while (!tapeteInserir.empty()) {
        for (i = 0; i < tapeteInserir.size(); i++) {
            for (int j = 0; j < numPilhas; j++) {
                stack<Bagagem> st = carrinho[i][j];
                while (st.size() < numMalas) {
                    Bagagem b = tapeteInserir.front();
                    st.push(b);
                    tapeteInserir.pop(); //pop deleta o front
                }
            }
        }
        if (i == carrinho.size() - 1) break; //se o carrinho estiver cheio -> termina
    }                                        // a inserção de bagagem!
}
*/
//funçao para listas
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
//função para vetores, mas nao vi se esta estava certa
/*
void GestaoBagagens::retirarMalas(Bagagem b) { //provavelmente não esta bem tbm => REVER
    for (int i = 0; i < carrinho[i].size(); i++) {
        for (int j = 0; carrinho[i][j].size(); j++) {
            if (b.getNumBilhete() == carrinho[i][j].top().getNumBilhete()) {
                //devolver mala ao cliente
            }
        }
    }
}*/

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
                b.setPeso(pes); //o peso fica como int! :(
                tapeteInserir.push(b);
                i = -1;
                break;
        }
        i++;

    }
    file.close();

    for(int i = 0; i < 2; i++){
        cout << tapeteInserir.front().getPeso() << endl;
        tapeteInserir.pop();
    }
}

void GestaoBagagens::CarrinhoInput() {
    //colocarMalas();
}

void GestaoBagagens::WriteCarrinho() {
    //retirarMalas();
}

void GestaoBagagens::ReadCarrinho() {


}






