/*
#include "bagagens.h"

gestaoBagagens::gestaoBagagens(unsigned int c, unsigned int n, unsigned int m) : numCarruagens(c), numPilhas(n), numMalas(m){}

void gestaoBagagens::colocarMalas() {
    if(tapete.size() > numCarruagens*numMalas*numPilhas ) throw "carro cheio";
//?? avancar para a proxima cena quando ficar cheio?
    while(!tapete.empty()) {
        while(carrinho.size() < numCarruagens) {
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
*/