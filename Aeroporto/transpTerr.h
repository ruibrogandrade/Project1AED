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
    list<int> horario;
public:
    Transporte() : tipoTransp(""), distancia(0), horario(0){};
    Transporte(string tipoTransp, int distancia, list<int> horario);
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
    OpcoesTransporte() : transportes(Transporte()){};
    BST<Transporte> getTransportes() const;
    static void readFile(); //tornei static para conseguir aceder atraves do main.cpp
    vector<Transporte> chooseTransporte(int dist) const;
    void updateHorario(Transporte t, int horaAtual, int horaNova);
    static void WriteBST(BST<Transporte> transportes);
    static void print(OpcoesTransporte ot);
};

#endif //PROJETO1_LOCALTRANSPTERR_H

