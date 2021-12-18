#include "bagagem.h"

Bagagem::Bagagem(int nb, float p) : numBilhete(nb), peso(p) {}

int Bagagem::getNumBilhete() const {
    return this-> numBilhete;
}

float Bagagem::getPeso() const {
    return peso;
}

gestaoBagagens::gestaoBagagens(unsigned int c, unsigned int n, unsigned int m) : numCarruagens(c), numPilhas(n), numMalas(m) {}

void gestaoBagagens::colocarMalas() {
    if (tapete.size() > numCarruagens * numMalas * numPilhas)
        throw "carrinho não pode carregar tanta bagagem";
    //se lançar a exceção executa o código a seguir?
    static int i = 0;
    while (!tapete.empty()) {
        for (i = 0; i < carrinho.size(); i++) {
            for (int j = 0; j < numPilhas; j++) {
                stack<Bagagem> st = carrinho[i][j];
                while (st.size() < numMalas) {
                    Bagagem b = tapete.front();
                    st.push(b);
                    tapete.pop(); //pop deleta o front
                }
            }
        }
        if (i == carrinho.size() - 1) break; //se o carrinho estiver cheio -> termina
    }                                        // a inserção de bagagem!
}

void gestaoBagagens::retirarMalas(Bagagem b) { //provavelmete não esta bem tbm => REVER
    for (int i = 0; i < carrinho[i].size(); i++) {
        for (int j = 0; carrinho[i][j].size(); j++) {
            if (b.getNumBilhete() == carrinho[i][j].top().getNumBilhete()) {
                //devolver mala ao cliente
            }
        }
    }
}