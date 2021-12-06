#include <iostream>
#include "servico.h"
using namespace std;


servico::servico(char tiposervico, int data, std::string nomeFuncionario, bool feito) {
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

int servico::getData() {
    return data;
}

void servico::setData(string data) {
    this->data=data;
}

string servico::getNomeFuncionario() {
    return nomeFuncionario;
}

void servico::setNomeFuncionario(string nomeFuncionario) {
    this->nomeFuncionario=nomeFuncionario
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

