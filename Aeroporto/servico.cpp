
#include <iostream>
#include "servico.h"
#include "aviao.h"
#include "Data.h"

using namespace std;

/**
 * Construtor padrão para serviço
 */

servico::servico(){}

/**
 * Construtor padrão que inicializa o serviço
 * @param tiposervico tipo do serviço executado
 * @param data data de realização
 * @param nomeFuncionario nome do funcionário que realizou o serviço
 */

servico::servico(char tiposervico, Data data, string nomeFuncionario) {
    this->tiposervico=tiposervico;
    this->data=data;
    this->nomeFuncionario=nomeFuncionario;
}

/**
 * Getter do tipo de serviço
 * @return tipo de serviço
 */

char servico::getTipoServico() const {
    return tiposervico;
}

/**
 *Setter do tipo de serviço
 * @param tiposervico
 */

void servico::setTipoServico(char tiposervico) {
    this->tiposervico=tiposervico;
}

/**
 * Getter da data de realização
 * @return data
 */

 Data servico::getData() const{
    return data;
}

/**
 * Setter da data de realização
 * @param data
 */

void servico::setData(Data data) {
    this->data=data;
}

/**
 *Getter para o nome do funcionário
 * @return
 */

string servico::getNomeFuncionario() const {
    return nomeFuncionario;
}

/**
 *Setter para nome do funcionário
 * @param nomeFuncionario
 */

void servico::setNomeFuncionario(string nomeFuncionario) {
    this->nomeFuncionario=nomeFuncionario;
}

/**
 * Overload do operador == para comparar serviços
 * @param s serviço
 * @return booleano para comparar serviços
 */
bool servico::operator==(const servico &s) const {
    return tiposervico == s.tiposervico && data == s.data && nomeFuncionario == s.nomeFuncionario;
}



