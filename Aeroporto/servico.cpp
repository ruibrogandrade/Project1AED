#include <iostream>
#include "servico.h"
#include "aviao.h"

using namespace std;


servico::servico(char tiposervico, Data data, std::string nomeFuncionario, bool feito) {
    this->tiposervico=tiposervico;
    this->data=data;
    this->nomeFuncionario=nomeFuncionario;
    this->feito=feito;
}

char servico::getTipoServico() {
    return tiposervico;
}

void servico::setTipoServico(char tiposervico) {
    this->tiposervico=tiposervico;
}

Data servico::getData() {
    return data;
}

void servico::setData(Data data) {
    this->data=data;
}

string servico::getNomeFuncionario() {
    return nomeFuncionario;
}

void servico::setNomeFuncionario(string nomeFuncionario) {
    this->nomeFuncionario=nomeFuncionario;
}

bool servico::getFeito() {
    return feito;
}

void servico::setFeito(bool feito) {
    this->feito=feito;
}

bool servico::operator==(const servico &s) const {
    return tiposervico == s.tiposervico && data == s.data && nomeFuncionario == s.nomeFuncionario;
}

void Aviao::novoservico(vector<servico> ns) { //ns = novos servicos
    for(int i = 0; i < ns.size(); i++) servicos.push(ns[i]);
}

void Aviao::atualizarservicos(vector<servico> sc) { //sf = servicos concluídos
    while(!sc.empty()){
        for(int i = 0; i < sc.size(); i++){
            if(sc[i].getFeito() == false) {
                sc[i].setFeito(true);
            }
        }
    }
}


