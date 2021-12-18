#include <fstream>
#include <sstream>
#include "aviao.h"
#include "servico.h"

using namespace std;


Aviao::Aviao() {
    //não sei se faz sentido criar um Aviao vazio (?)
}

Aviao::Aviao(string matricula, int capacidade, list<Voo> listaVoo, string tipo) {
    this->matricula = matricula;
    this->capacidade = capacidade;
    this->listaVoo = listaVoo;
    //string tipo nao é usada?!
}

list<Voo> Aviao::getListaVoo() const {
    return listaVoo;
}

void Aviao::novoservico(Servico novo) { //ns = novos servicos
    servicos.push(novo);
}

/*void Aviao::atualizarservicos(vector<servico> sc) { //sf = servicos concluídos
    while(!sc.empty()){
        for(int i = 0; i < sc.size(); i++){
            if(sc[i].getFeito() == false) {
                sc[i].setFeito(true);
            }
        }
    }
}
void Aviao::atualizarservicos(queue<servico> spf, vector<servico> sf) { //spf = servicos por fazer, sf = servicos ja feitos
    while(!spf.empty()){
        for(int i = 0; i < spf.size(); i++){
            sf.push_back(spf.front());
            spf.pop();
        }
    }
}*/

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
    listAviao.emplace_back("37-FP-45", 1500);
    listAviao.push_back(Aviao("81-TM-05", 1250));
}

void Aviao::WriteAviao() {
    ofstream file;
    file.open("");
    //list<Voo> tmp = listaVoo;
    for (auto it = listAviao.begin(); it != listAviao.end(); it++){
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
        listAviao.push_back(a);
    }
    file.close();
}

list<Aviao> Aviao::getListAviao() const {
    return listAviao;
}

void Aviao::setListAviao() {
    this->listAviao=listAviao;
}

