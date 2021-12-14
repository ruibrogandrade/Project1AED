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

void Aviao::novoservico(vector<servico> ns) { //ns = novos servicos
    for(int i = 0; i < ns.size(); i++) servicos.push_back(ns[i]);
}


//Os servicos que deveram ser atualizados para feitos já deverão ser filtrados antes da chamada a esta função
void Aviao::atualizarservicos(queue<servico> spf, vector<servico> sf) { //spf = servicos por fazer, sf = servicos ja feitos
    while(!spf.empty()){
        for(int i = 0; i < spf.size(); i++){
            sf.push_back(spf.front());
            spf.pop();
        }
    }
}
