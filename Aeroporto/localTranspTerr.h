#ifndef PROJETO1_LOCALTRANSPTERR_H
#define PROJETO1_LOCALTRANSPTERR_H

#include <vector>
#include <string>
#include "bst.h"

using namespace std;

class Transporte {
    string tipoTransp;
    vector<int> horario;
    int distancia;
public:
    Transporte(string tipoTransp, vector<int> horario, int distancia);
    string getTipoTransp() const;
    vector<int> getHorario() const;
    int getDistancia() const;
    void setTipoTransp(string tipoTransporte);
    void addNewHorario( int horario);
    void setDistancia(int dist);
    bool operator < (const Transporte & lt) const {
        return distancia < lt.distancia; }
    bool operator == (const Transporte & lt) const {
        return distancia == lt.distancia; }
};

class OpcoesTransporte{
    BST<Transporte> transportes;
public:
    OpcoesTransporte() : transportes(Transporte("", vector<int>, 0)){}; //como faço com a inicilizacao de horario?
    BST<Transporte> getTransportes() const;
    void readFile(ifstream& f);
    string chooseHorario(int hora, Transporte& previous, Transporte& next) const;
    bool updateHorario(Transporte t, int horaAtual, int horaNova);

};


#endif //PROJETO1_LOCALTRANSPTERR_H

