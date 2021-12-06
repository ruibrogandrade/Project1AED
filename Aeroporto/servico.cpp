#include <iostream>
#include "servico.h"


servico::servico(char tiposervico, int data, std::string nomeFuncionario, bool feito) {

}



bool servico::operator==(const servico &s) const {
    return tiposervico == s.tiposervico && data == s.data && nomeFuncionario == s.nomeFuncionario;
}

