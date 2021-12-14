#include "bagagens.h"

gestaoBagagens::gestaoBagagens(unsigned int c, unsigned int n, unsigned int m) : numCarruagens(c), numPilhas(n), numMalas(m){}

void gestaoBagagens::colocarMalas(){
    if(tapete.size() > numCarruagens*numMalas*numPilhas)
        throw "carrinho não pode carregar tanta bagagem";

    while(!tapete.empty()) {
        Bagagem b = tapete.front();
        int i, j;
        if (carrinho.size() < numCarruagens) {

            for (i = 0; i < carrinho.size(); i++) {

                if (carrinho[i].size() < numPilhas) {
                    vector<stack<Bagagem>> carruagem = carrinho[i];

                    for (j = 0; j < carrinho[i][j].size(); j++) {

                        if (carrinho[i][j].size() < numMalas) {
                            stack<Bagagem> pilha = carrinho[i][j];

                            pilha.push(b);
                            tapete.pop();

                        } else j++; //incrementa pilha
                    }
                } else i++; //incrementa carruagem
            }
        } //else está me a falhar qualquer coisa mas tipo eu devia passar pra proxima carruagem se uma tiver cheia
    }
}

void gestaoBagagens::retirarMalas(Bagagem b) {
    for(int i = 0; i < carrinho[i].size(); i++) {
        for(int j = 0; carrinho[i][j].size(); j++){
            if(b.getNumBilhete() == carrinho[i][j].top().getNumBilhete()){
                //devolver mala ao cliente
            }
        }
    }
}

