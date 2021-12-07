#include "aviao.h"
#include "servico.h"

using namespace std;

list<Voo> Aviao::getListaVoo() const {
    return listaVoo;
}

Aviao::Aviao() {
    //não sei se faz sentido criar um Aviao vazio (?)
}

Aviao::Aviao(string matricula, int capacidade, list<Voo> listaVoo) {
    this->matricula = matricula;
    this->capacidade = capacidade;
    this->listaVoo = listaVoo;
}


