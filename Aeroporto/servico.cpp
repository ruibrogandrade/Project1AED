#include <iostream>
#include "servico.h"
using namespace std;


servico::servico(char tiposervico, int data, std::string nomeFuncionario, bool feito) {
    this->tiposervico=tiposervico;
    this->nomeFuncionario=nomeFuncionario;
    this->feito=feito;
}

char servico::getTipoServico() const{
    return tiposervico;
}

void servico::setTipoServico(char tiposervico) {
    this->tiposervico=tiposervico;
}

string servico::getNomeFuncionario() const{
    return nomeFuncionario;
}

void servico::setNomeFuncionario(string nomeFuncionario) {
    this->nomeFuncionario=nomeFuncionario
}

bool servico::getFeito() const{
    return feito;
}

void servico::setFeito(bool feito) {
    this->feito=feito;
}

bool servico::operator==(const servico &s) const {
    return tiposervico == s.tiposervico && data == s.data && nomeFuncionario == s.nomeFuncionario;
}

