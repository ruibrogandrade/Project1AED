#ifndef PROJETO1_BAGAGENS_H
#define PROJETO1_BAGAGENS_H

#include "bagagem.h"
//malas por ordem deslocadas num tapete rolante
//vão para 1 carrinho
//carrinho tem c carruagens
//carruagens têm n pilhas para m malas
//carrinho.size() < c(nº carruagens); carruagem.size() < n(nªpilhas); pilhas.size() < m(nºmalas);



class gestaoBagagens {
private:
    unsigned numCarruagens;
    unsigned numPilhas;
    unsigned numMalas;

    queue<Bagagem> tapete;
    vector<carruagem> carrinho;
    vector<stack> carruagem;
    stack<Bagagem> pilha;
public:
    gestaoBagagens(unsigned c, unsigned n, unsigned m);
    void colocarMalas(); //????
    void retirarMalas(Bagagem b);
};


#endif //PROJETO1_BAGAGENS_H

/*
adiciono bagagem à fila/tapete (no voo.cpp) -> despejo fila numa carruagem enquanto não tiver cheia -> que por sua vez despeja tudo numa pilha até estar cheia
 quando pilha encher passo a proxima, quando todas as pilhas tiverem cheias então carruagem esta cheia, passo para a proxima carruagem (recursao), quando tiver tudo cheio carrinho cheio
*/