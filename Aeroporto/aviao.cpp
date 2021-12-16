#include "aviao.h"
#include "servico.h"

using namespace std;

/**
 * Construtor padrão de avião
 */

Aviao::Aviao() {}

/**
 *Construtor que inicializa o avião e os seus atributos
 * @param matricula parâmetro que identifica cada avião
 * @param capacidade inteiro que mostra a capacidade de passageiros de um avião
 * @param listaVoo lista que representa os voos feitos pelo avião
 * @param tipo tipo de avião
 */

Aviao::Aviao(string matricula, string tipo, int capacidade, list<Voo> listaVoo) {
    this->matricula = matricula;
    this->capacidade = capacidade;
    this->listaVoo = listaVoo;
    this->tipo = tipo;
}

/**
 * Adiciona novo serviço à lista
 * @param ns novo serviço a ser acrescentado à lista de serviços
 */

void Aviao::novoservico(vector<servico> ns) { //ns = novos servicos
    for(int i = 0; i < ns.size(); i++) servicos.push_back(ns[i]);
}

/**
 *Atualiza algum serviço da lista de serviços de um avião
 * @param spf serviços por fazer
 * @param sf serviços feitos
 */

//Os servicos que deveram ser atualizados para feitos já deverão ser filtrados antes da chamada a esta função
void Aviao::atualizarservicos(queue<servico> spf, vector<servico> sf) { //spf = servicos por fazer, sf = servicos ja feitos
    while(!spf.empty()){
        for(int i = 0; i < spf.size(); i++){
            sf.push_back(spf.front());
            spf.pop();
        }
    }
}

/**
 * Getter para retornar um plano de voos
 * @return lista de voos
 */

list<Voo> Aviao::getListaVoo() const {
    return listaVoo;
}
