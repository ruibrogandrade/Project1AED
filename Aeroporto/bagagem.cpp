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

gestaoBagagens::gestaoBagagens(unsigned int c, unsigned int n, unsigned int m) : numCarruagens(c), numPilhas(n), numMalas(m) {}

//função para listas (ainda nao comecei a fazer)
void gestaoBagagens::colocarMalas(){
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
/*//funçao para vetores
void gestaoBagagens::colocarMalas() {
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
}*/

//funçao para listas
void gestaoBagagens::retirarMalas(){
    Bagagem b;
    for (auto it = carrinho.begin(); it != carrinho.end(); it++){
        for(auto et = (*it).begin(); et != (*it).end(); et++){
            b = (*et).top();
            (*et).pop();
            tapeteRetirar.push(b);
        }
    }
}
/*//função para vetores, mas nao vi se esta estava certa
void gestaoBagagens::retirarMalas(Bagagem b) { //provavelmete não esta bem tbm => REVER
    for (int i = 0; i < carrinho[i].size(); i++) {
        for (int j = 0; carrinho[i][j].size(); j++) {
            if (b.getNumBilhete() == carrinho[i][j].top().getNumBilhete()) {
                //devolver mala ao cliente
            }
        }
    }
}*/

void gestaoBagagens::TapeteInput() {
    //valores para testar
    tapeteInserir.push(Bagagem(12,30));
    tapeteInserir.push(Bagagem(13,20));
    tapeteInserir.push(Bagagem(14,45));
}

void gestaoBagagens::WriteTapete() {
    ofstream file;
    file.open("");
    while (!tapeteInserir.empty()){
        file << tapeteInserir.front().getNumBilhete() << ',' << tapeteInserir.front().getPeso() << ','  << endl;
        tapeteInserir.pop();
    }
    file.close();
}

void gestaoBagagens::ReadTapete() {
    int nrBilh;
    float pes;
    ifstream file("");
    string line;
    stringstream toInt(line);
    Bagagem b;
    int i = 0;
    while (getline(file, line, ',')){
        switch (i) {
            case (0):
                toInt >> nrBilh;
                b.setNumBilhete(nrBilh);
                break;
            case(1):
                toInt >> pes;
                b.setNumBilhete(pes);
                i = -1;
                break;
        }
        i++;
        tapeteInserir.push(b);
    }
    file.close();
}

void gestaoBagagens::CarrinhoInput() {
    colocarMalas();
}

void gestaoBagagens::WriteCarrinho() {
    retirarMalas();

}

void gestaoBagagens::ReadCarrinho() {

}






