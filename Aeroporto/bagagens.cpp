#include "bagagens.h"

gestaoBagagens::gestaoBagagens(unsigned int c, unsigned int n, unsigned int m) : numCarruagens(c), numPilhas(n), numMalas(m) {}

void gestaoBagagens::colocarMalas() {

    for(int i = 0; i < numCarruagens; i++) {
        list<stack<Bagagem>> novaCarruagemVazia;
        carrinho.push_back(novaCarruagemVazia);
    }

    for(int i = 0; i < numPilhas; i++) {
        stack<Bagagem> novaPilhaVazia;
        for(auto it = carrinho.begin(); it != carrinho.end(); it++) {
            (*it).push_back(novaPilhaVazia);
        }
    }

    for(auto it = carrinho.begin(); it != carrinho.end(); it++) {
        for(auto et = (*it).begin(); et != (*it).end(); et++) {
            (*et).push(tapete.front());
            tapete.pop();
        }
    }
}

void gestaoBagagens::retirarMalas(Bagagem b) {
    for(auto it = carrinho.begin(); it != carrinho.end(); it++) {
        for(auto et = (*it).begin(); et != (*it).end(); et++) {
            if((*et).top().getNumBilhete() == b.getNumBilhete()) {
                (*et).pop(); //retirar mala
            }
        }
    }
}


/*
void gestaoBagagens::colocarMalas(){
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
                        }
                    }
                }
            }
        }
    }
}

void gestaoBagagens::colocarMalas() {
    int i = 0;
    while (!tapete.empty()) {
        for (i = 0; i < carrinho.size(); i++) {
            for (int j = 0; j < numPilhas; j++) {
                stack<Bagagem> st = carrinho[i][j];
                while (st.size() < numMalas) {
                    Bagagem b = tapete.front();
                    st.push(b);
                    tapete.pop();
                }
            }
        }
        if (i == carrinho.size() - 1) break; //se o carrinho estiver cheio -> termina
    }
}
*/
/*
void gestaoBagagens::retirarMalas(Bagagem b) {
    for(int i = 0; i < carrinho[i].size(); i++) {
        for(int j = 0; carrinho[i][j].size(); j++){
            if(b.getNumBilhete() == carrinho[i][j].top().getNumBilhete()){
                //devolver mala ao cliente
            }
        }
    }
}
*/
