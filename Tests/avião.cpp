#include "avião.h"
using namespace std;

/*list<Voo> Avião::getListaVoo() const {
    return listaVoo;
}*/

Avião::Avião() {
    //não sei se faz sentido criar um avião vazio (?)
}

Avião::Avião(string matrícula, int capacidade, list<Voo> listaVoo) {
    this->matrícula = matrícula;
    this->capacidade = capacidade;
    this->listaVoo = listaVoo;
}

void Avião::novoServiço(vector<Serviço> ns) { //ns = novos serviços
    for(int i = 0; i < ns.size(); i++) serviçosPorFazer.push(ns[i]);
}

void Avião::atualizarServiços(vector<Serviço> sc) { //sf = serviços concluídos
    while(!sc.empty()){
        for(int i = 0; i < sc.size(); i++){
            if(serviçosPorFazer.back() == sc[i]){
                serviçosJáFeitos.push(serviçosPorFazer.back());
                serviçosPorFazer.pop();
                sc.erase(sc.begin() + i);
            }
        }
    }
}

bool Serviço::operator==(const Serviço &s) const {
    return tipoServiço == s.tipoServiço && data == s.data && nomeFuncionário == s.nomeFuncionário;
}
