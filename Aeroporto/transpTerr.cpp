#include "transpTerr.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

Transporte::Transporte(string tipoT, int dist) :
        tipoTransp(tipoT), distancia(dist){}

string Transporte::getTipoTransp() const {
    return this->tipoTransp;
}

list<int> Transporte::getHorario() const {
    return horario;
}

int Transporte::getDistancia() const {
    return distancia;
}

void Transporte::setTipoTransp(string tipoTransporte) {
    this->tipoTransp = tipoTransporte;
}

void Transporte::addHoraExtra(int horaExtra) {
    list<int>::iterator it;
    for(it = horario.begin(); it != horario.end() ; it++){
        if ((*it) < horaExtra){
            it++;
            if ((*it) > horaExtra && it != horario.end()){
                it--;
                horario.insert(it, horaExtra);
                break;
            }
            if (it == horario.end())
                horario.push_back(horaExtra);
        }
    }
}

void Transporte::setDistancia(int dist) {
    this->distancia = dist;
}



//--------------------------------------------------------------------------------------



BST<Transporte> OpcoesTransporte::getTransportes() const {
    return transportes;
}

void OpcoesTransporte::readFile(ifstream& f) {
    //nao sei se tenho de fazer isto do nome do ficheiro ou nao
    string filename;
    cout << "Enter file name: " << endl,
    cin >> filename;
    f.open(filename);
    string tipoT, strDist;
    int dist;
    stringstream toInt(strDist);
    while (getline(f, tipoT)){
        getline(f, strDist);
        toInt >> dist; // Now the variable dist holds the value of strDist
        transportes.insert(Transporte(tipoT, dist));
    }
    f.close();
}

//Transporte OpcoesTransporte::chooseTransporte retorna os transportes que
// se encontram disponiveis para o utente que estejam a pelo menos dist do aeroporto
vector<Transporte> OpcoesTransporte::chooseTransporte(int dist) const {
    vector<Transporte> opcoes;
    for (auto it = transportes.begin(); it != transportes.end(); it++){
        if(dist <= (*it).getDistancia()){
            opcoes.push_back((*it));
        }
    }
    return opcoes;
}

void OpcoesTransporte::updateHorario(Transporte t, int horaAtual, int horaNova) {
    list<int>::iterator it;
    for(it = t.horario.begin(); it != t.horario.end() ; it++){
        if ((*it) == horaAtual){
            (*it) = horaNova;
            break;
        }
    }
}

