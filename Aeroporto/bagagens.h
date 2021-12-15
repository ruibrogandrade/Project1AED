#ifndef PROJETO1_BAGAGENS_H
#define PROJETO1_BAGAGENS_H

#include "bagagem.h"
#include <stack>
#include <queue>
#include <list>

using namespace std;


class gestaoBagagens {
private:
    unsigned numCarruagens;
    unsigned numPilhas;
    unsigned numMalas;

    queue<Bagagem> tapete;
    list<list<stack<Bagagem>>> carrinho;

public:
    gestaoBagagens(unsigned c, unsigned n, unsigned m);
    void colocarMalas(); //????
    void retirarMalas(Bagagem b);
};

#endif //PROJETO1_BAGAGENS_H
