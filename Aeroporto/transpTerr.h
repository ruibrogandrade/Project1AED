#ifndef PROJETO1_LOCALTRANSPTERR_H
#define PROJETO1_LOCALTRANSPTERR_H

#include <vector>
#include <string>
#include <list>
#include "bst.h"

using namespace std;

class Transporte {
    string tipoTransp;
    int distancia;
public:
    list<int> horario; //pus no public para a class OpcoesTransporte conseguir aceder
    Transporte(string tipoTransp, int distancia);
    string getTipoTransp() const;
    list<int> getHorario() const;
    int getDistancia() const;
    void setTipoTransp(string tipoTransporte);
    void addHoraExtra( int horaExtra);
    void setDistancia(int dist);
    bool operator < (const Transporte & lt) const {
        return distancia < lt.distancia; }
    bool operator == (const Transporte & lt) const {
        return distancia == lt.distancia; }
};

class OpcoesTransporte {
    BST<Transporte> transportes;
public:
    OpcoesTransporte() : transportes(Transporte("", 0)){};
    BST<Transporte> getTransportes() const;
    void readFile(ifstream& f);
    vector<Transporte> chooseTransporte(int dist) const;
    void updateHorario(Transporte t, int horaAtual, int horaNova);
};


#endif //PROJETO1_LOCALTRANSPTERR_H

