#include "aviao.h"

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
    for(int i = 0; i < ns.size(); i++) servicosPorFazer.push(ns[i]);
}

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