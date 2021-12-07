#include "bagagens.h"

gestaoBagagens::gestaoBagagens(unsigned int c, unsigned int n, unsigned int m) : numCarruagens(c), numPilhas(n), numMalas(m){}

void gestaoBagagens::colocarMalas() {
    if(tapete.size() > numCarruagens*numMalas*numPilhas ) throw "carrinho cheio";
    int i, j;
    while(!tapete.empty()) {
        if(carrinho.size() < numCarruagens) {
            if(carruagem[i].size() < numPilhas) {
                if(pilha[j].size() < numMalas) {
                    pilha[j].push(tapete.front())
                    tapete.pop();
                }
                else{
                    j++;
                }
            }
            else {
                int i++;
            }
        }
    }
}
