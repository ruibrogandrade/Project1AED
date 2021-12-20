#include "Data.h"

/**
 * Overload do operador < para datas
 * @param d data
 * @return booleano com menor data
 */

bool Data::operator<(Data d) const{
    if(ano > d.ano) {
        if(mes > d.mes) {
            if(dia > d.dia) return true;
        }
    }
    return false;
}

/**
 * Overload do operador == para datas
 * @param d data
 * @return booleano com igualdade de datas
 */

bool Data::operator==(Data d) const {
    return ano == d.ano && mes == d.mes && dia == d.dia;
}

/**
 *Construtor padrão para datas
 */

Data::Data() {}

/**
 * Construtor com atributos para data
 * @param ano
 * @param mes
 * @param dia
 */

Data::Data(int ano, int mes, int dia) {
    this->ano = ano;
    this->mes = mes;
    this->dia = dia;
}

int Data::getDia() {
    return dia;
}

void Data::setDia(int dia) {
    this->dia=dia;
}

int Data::getMes() {
    return mes;
}

void Data::setMes(int mes) {
    this->mes=mes;
}

int Data::getAno() {
    return ano;
}

void Data::setAno(int ano) {
    this->ano=ano;
}