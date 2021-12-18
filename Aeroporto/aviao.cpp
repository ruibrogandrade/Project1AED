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

//só fiz para o nr do voo
void Aviao::WriteVoo() {
    ofstream file;
    file.open("fileVoos");
    //list<Voo> tmp = listaVoo;
    for (auto it = listaVoo.begin(); it != listaVoo.end(); it++){
        file << (*it).getNumVoo() << endl;
    }
    file.close();
}

void Aviao::VooInput() {
    //valores para testar
    listaVoo.emplace_back(12);
    listaVoo.push_back(Voo(19));
    listaVoo.push_back(Voo(5));
}

void Aviao::ReadVoo(){
    int nrVoo;
    ifstream file("");
    string line;
    stringstream toInt(line);
    Voo v;
    while (getline(file, line, ',')){
        toInt >> nrVoo;
        v.setNumVoo(nrVoo);
    }
    file.close();
}

//só implementei para a matricula e para a capacidade
void Aviao::AviaoInput() {
    //valores para testar
    avioes.emplace_back("37-FP-45", 1500);
    avioes.push_back(Aviao("81-TM-05", 1250));
}

void Aviao::WriteAviao() {
    ofstream file;
    file.open("");
    //list<Voo> tmp = listaVoo;
    for (auto it = avioes.begin(); it != avioes.end(); it++){
        file << (*it).getMatricula() << ','<< (*it).getCapacidade() << endl;
    }
    file.close();
}

void Aviao::ReadAviao() {
    string matricula;
    int capacidade;
    //list<Voo> listaVoo;
    //vector<servico> servicos;
    ifstream file("");
    string line;
    stringstream toInt(line);
    int i = 0;
    Aviao a;
    while (getline(file, line, ';')){
        switch(i){
            case(0):
                a.matricula = line;
                break;
            case(1):
                toInt >> capacidade;
                a.capacidade = capacidade;
                i--;
                break;
        }
        i++;
        avioes.push_back(a);
    }
    file.close();
}