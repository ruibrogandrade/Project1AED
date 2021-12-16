//
// Created by barba on 07/12/2021.
//

#include "Data.h"

/**
 *Overload do operador < para comparar datas
 * @param d data
 * @return booleano para comparar datas
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
 * Overload do operador == para comparar datas
 * @param d data
 * @return booleano para ver a igualdade das datas
 */

bool Data::operator==(Data d) const {
    return ano == d.ano && mes == d.mes && dia == d.dia;
}

/**
 * Construtor padrão de data
 */

Data::Data() {}

/**
 * Construtor de data que inicializa a data
 * @param ano ano
 * @param mes mês
 * @param dia dia
 */

Data::Data(int ano, int mes, int dia) {
    this->ano = ano;
    this->mes = mes;
    this->dia = dia;
}

/**
 * Getter do dia
 * @return dia
 */

int Data::getDia() {
    return dia;
}

/**
 * Setter do dia
 * @param dia
 */

void Data::setDia(int dia) {
    this->dia=dia;
}

/**
 * Getter do mês
 * @return mês
 */

int Data::getMes() {
    return mes;
}

/**
 * Setter mês
 * @param mes
 */

void Data::setMes(int mes) {
    this->mes=mes;
}

/**
 * Getter ano
 * @return
 */

int Data::getAno() {
    return ano;
}

/**
 * Setter ano
 * @param ano
 */

void Data::setAno(int ano) {
    this->ano=ano;
}
