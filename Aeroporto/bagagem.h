#ifndef PROJETO1AED_BAGAGEM_H
#define PROJETO1AED_BAGAGEM_H

#include <vector>
#include <stack>
#include <queue>

using namespace std;


class Bagagem {
    int numBilhete; //funciona como id
    float peso;
public:
    Bagagem(int nb, float p);
    int getNumBilhete() const;
    float getPeso() const;
};


class gestaoBagagens {
private:
    unsigned numCarruagens;
    unsigned numPilhas;
    unsigned numMalas;

    queue<Bagagem> tapete;
    vector<vector<stack<Bagagem>>> carrinho; //carrinho[i] = carruagem, carrinho[i][j] = stack

public:
    gestaoBagagens(unsigned c, unsigned n, unsigned m);
    void colocarMalas(); //????
    void retirarMalas(Bagagem b);
};


#endif //PROJETO1AED_BAGAGEM_H
