#include "Data.h"

bool Data::operator<(Data d) const{
    if(ano > d.ano) {
        if(mes > d.mes) {
            if(dia > d.dia) return true;
        }
    }
    return false;
}

bool Data::operator==(Data d) const {
    return ano == d.ano && mes == d.mes && dia == d.dia;
}

Data::Data() {}

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