#include <fstream>
#include <sstream>
#include <iostream>
#include "bagagem.h"

/**
 * Construtor que inicializa a bagagem
 * @param nb ///numero de bilhetes
 * @param p ///peso
 */

Bagagem::Bagagem(int nb, float p) : numBilhete(nb), peso(p) {}

/**
 * Getter do numero de bilhetes
 * @return num bilhete
 */

int Bagagem::getNumBilhete() const {
    return this-> numBilhete;
}

/** Getter de peso
 * @return peso
 */

float Bagagem::getPeso() const {
    return peso;
}

/**
 * Construtor de gestor da bagagem
 * @param c numero de carruagens
 * @param n numero de pilhas
 * @param m numero de malas
 */

GestaoBagagens::GestaoBagagens(unsigned int c, unsigned int n, unsigned int m) : numCarruagens(c), numPilhas(n), numMalas(m) {}

/**
 * Colocar malas
 * \brief coloca malas do tapete para o carrinho
 */

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

/**
 * Retirar malas
 * \brief funcao que retira malas do carrinho
 */

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
                b.setPeso(pes); //o peso fica como int! :(
                tapeteInserir.push(b);
                i = -1;
                break;
        }
        i++;

    }
    file.close();
}

void GestaoBagagens::ListagemTotal() {
    std::ifstream f("tapete.txt");
    if (f.is_open())
        std::cout << f.rdbuf();
}

void GestaoBagagens::ListagemParcial() {
    string parametro;
    int num;
    float p;
    cout << "Que parâmetro deseja filtrar?" << endl;
    cin >> parametro;
    if(parametro == "numBilhete") {
        cout << "Qual o bilhete associado à bagagem?" << endl;
        cin >> num;
        list<Bagagem> bagagemAssociada;
        list<list<stack<Bagagem>>> carrinhoAux = carrinho;
        for (auto it = carrinhoAux.begin(); it != carrinhoAux.end(); it++) {
            for (auto et = (*it).begin(); et != (*it).end(); et++) {
                if ((*et).top().getNumBilhete() == num) {
                    bagagemAssociada.push_back(((*et).top()));
                    (*et).pop();
                } else ((*et).pop());
            }
        }
        cout << "O cliente tem " << bagagemAssociada.size() << "bagagens associadas.";
        }

    if(parametro == "peso") {
        cout << "Pretende encontrar bagagens com peso superior a quantos kgs?" << endl;
        cin >> p;

    list<Bagagem> bagagemPeso;
    list<list<stack<Bagagem>>> carrinhoAux2 = carrinho;
    for (auto it = carrinhoAux2.begin(); it != carrinhoAux2.end(); it++) {
        for (auto et = (*it).begin(); et != (*it).end(); et++) {
            if ((*et).top().getPeso() > p) {
                bagagemPeso.push_back(((*et).top()));
                (*et).pop();
            } else ((*et).pop());
        }
    }
        cout << "Há" << bagagemPeso.size() << "malas com peso superior a" << p << "kgs";
    }
}