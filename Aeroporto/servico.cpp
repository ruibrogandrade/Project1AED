#include <iostream>
#include "servico.h"


servico::servico(char tiposervico, int data, std::string nomeFuncionario, bool feito) {
    this->tiposervico=tiposervico;
    this->data=data;
    this->nomeFuncionario=nomeFuncionario;
    this->feito=feito;
}

char servico::getTipoServico() {
    return tiposervico;
}

void servico::setTipoServico() {
    this->tiposervico=tiposervico;
}

int servico::getData() {
    return data;
}

void servico::setData() {
    this->data=data;
}

string servico::getNomeFuncionario() {
    return nomeFuncionario;
}

void servico::setNomeFuncionario() {
    this->nomeFuncionario=nomeFuncionario
}

bool servico::getFeito() {
    return feito;
}

void servico::setFeito() {
    this->feito=feito;
}

bool servico::operator==(const servico &s) const {
    return tiposervico == s.tiposervico && data == s.data && nomeFuncionario == s.nomeFuncionario;
}

