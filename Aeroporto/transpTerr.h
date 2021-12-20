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
    list<float> horario;
public:
    Transporte() : tipoTransp(""), distancia(0), horario(0){};
    Transporte(string tipoTransp, int distancia, list<float> horario);
    string getTipoTransp() const;

    int getDistancia() const;
    void setTipoTransp(string tipoTransporte);
    void addHoraExtra( int horaExtra);
    void setDistancia(int dist);
    list<float> getHorario() const;
    void setHorario(list<float> horario) {
        this->horario = horario;
    }
    bool operator < (const Transporte & lt) const {
        return distancia < lt.distancia; }
    bool operator == (const Transporte & lt) const {
        return distancia == lt.distancia; }
};

class OpcoesTransporte {
    BST<Transporte> transportes;
public:
    OpcoesTransporte() {};
    BST<Transporte> getTransportes() const;
    vector<Transporte> chooseTransporte(int dist) const;
    void updateHorario(Transporte t, float horaAtual, float horaNova);
    void WriteBST(BST<Transporte> transportes);
    void readFile();
    void print(OpcoesTransporte ot);
    void printThis();
};

#endif //PROJETO1_LOCALTRANSPTERR_H

