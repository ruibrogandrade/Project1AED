#ifndef PROJETO1AED_BAGAGEM_H
#define PROJETO1AED_BAGAGEM_H

#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <fstream>
#include <sstream>

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
    float getPeso() const;
    void setNumBilhete(int nrBilh){
        this->numBilhete = nrBilh;
    };
};


class gestaoBagagens {
private:
    unsigned numCarruagens;
    unsigned numPilhas;
    unsigned numMalas;

    static queue<Bagagem> tapeteInserir;
    static queue<Bagagem> tapeteRetirar;
    list<list<stack<Bagagem>>> carrinho; //carrinho[i] = carruagem, carrinho[i][j] = stack
public:
    gestaoBagagens(unsigned c, unsigned n, unsigned m);
    void colocarMalas();
    void retirarMalas();
    static void TapeteInput();
    static void WriteTapete();
    static void ReadTapete();
    void CarrinhoInput();
    static void WriteCarrinho();
    static void ReadCarrinho();

};


#endif //PROJETO1AED_BAGAGEM_H