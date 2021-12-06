//
// Created by andre on 05/12/2021.
//

#include "aviao.h"
#include "servico.h"

using namespace std;

/*list<Voo> Aviao::getListaVoo() const {
    return listaVoo;
}*/

Aviao::Aviao() {
    //não sei se faz sentido criar um Aviao vazio (?)
}

Aviao::Aviao(string matricula, int capacidade, list<Voo> listaVoo) {
    this->matricula = matricula;
    this->capacidade = capacidade;
    this->listaVoo = listaVoo;
}

void Aviao::novoservico(vector<servico> ns) { //ns = novos servicos
    for(int i = 0; i < ns.size(); i++) servicos.push(ns[i]);
}

//Não faz muito sentido esta função, assim todos os servicos vão ter de ser feitos ao mesmo tempo? Como é que poderiamos só atualizar alguns?
void Aviao::atualizarservicos(vector<servico> sc) { //sf = servicos concluídos
    while(!sc.empty()){
        for(int i = 0; i < sc.size(); i++){
            if(servicosPorFazer.back() == sc[i]){
                servicosJaFeitos.push(servicosPorFazer.back());
                servicosPorFazer.pop();
                sc.erase(sc.begin() + i);
            }
        }
    }
}

bool servico::operator==(const servico &s) const {
    return tiposervico == s.tiposervico && data == s.data && nomeFuncionario == s.nomeFuncionario;
}
