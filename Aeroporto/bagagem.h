#ifndef PROJETO1AED_BAGAGEM_H
#define PROJETO1AED_BAGAGEM_H

#include <vector>
#include <stack>
#include <queue>
#include <list>

using namespace std;


class Bagagem {
    int numBilhete; //funciona como id
    float peso;
public:
    Bagagem(){
        this->numBilhete = 0;
        this->peso = 0;
    };
    Bagagem(int nb, float p);
    int getNumBilhete() const;
    void setNumBilhete(int nrBilh){
        this->numBilhete = nrBilh;
    };
    float getPeso() const;
    float setPeso(float peso) {
        this->peso = peso;
    }
};


class GestaoBagagens {
private:
    unsigned numCarruagens = 2;
    unsigned numPilhas = 3;
    unsigned numMalas = 4;

    queue<Bagagem> tapeteInserir;
    queue<Bagagem> tapeteRetirar;
    list<list<stack<Bagagem>>> carrinho;
public:
    GestaoBagagens();
    GestaoBagagens(unsigned c, unsigned n, unsigned m);
    void colocarMalas();
    void retirarMalas();
    void TapeteInput();
    void WriteTapete();
    void ReadTapete();
    void ListagemTotal();

    void ListagemParcial();
};


#endif //PROJETO1AED_BAGAGEM_H
