#include "aviao.h"
#include "servico.h"

using namespace std;

list<Voo> Aviao::getListaVoo() const {
    return listaVoo;
}

Aviao::Aviao() {
    //não sei se faz sentido criar um Aviao vazio (?)
}

Aviao::Aviao(string matricula, int capacidade, list<Voo> listaVoo, string tipo) {
    this->matricula = matricula;
    this->capacidade = capacidade;
    this->listaVoo = listaVoo;
}

void Aviao::novoservico(servico novo) { //ns = novos servicos
    servicos.push(novo);
}


//Os servicos que deveram ser atualizados para feitos já deverão ser filtrados antes da chamada a esta função
/*
void Aviao::atualizarservicos(queue<servico> spf, vector<servico> sf) { //spf = servicos por fazer, sf = servicos ja feitos
    while(!spf.empty()){
        for(int i = 0; i < spf.size(); i++){
            sf.push_back(spf.front());
            spf.pop();
        }
    }
}
*/

string Aviao::getMatricula() const {
    return matricula;
}

void Aviao::setMatricula() {
    this->matricula=matricula;
}

list<Aviao> Aviao::getListAviao() {
    return listAviao;
}

void Aviao::setListAviao(list<Aviao> listAviao) {
    this->listAviao=listAviao;
}
