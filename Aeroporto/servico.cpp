#include <iostream>
#include "servico.h"
#include "aviao.h"
#include "Data.h"

using namespace std;


servico::servico(char tiposervico, int data, string nomeFuncionario) {
    this->tiposervico=tiposervico;
    this->data=data;
    this->nomeFuncionario=nomeFuncionario;
}

char servico::getTipoServico() const {
    return tiposervico;
}

void servico::setTipoServico(char tiposervico) {
    this->tiposervico=tiposervico;
}

Data servico::getData() const{
    return data;
}

void servico::setData(Data data) {
    this->data=data;
}

string servico::getNomeFuncionario() const {
    return nomeFuncionario;
}

void servico::setNomeFuncionario(string nomeFuncionario) {
    this->nomeFuncionario=nomeFuncionario;
}

bool servico::operator==(const servico &s) const {
    return tiposervico == s.tiposervico && data == s.data && nomeFuncionario == s.nomeFuncionario;
}



