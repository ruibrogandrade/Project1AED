#include "transpTerr.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

Transporte::Transporte(string tipoT, int dist, list<int> hor) :
        tipoTransp(tipoT), distancia(dist), horario(hor){}

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
    f.open("transTerr.txt");
    string tipoT, strDist, hor;
    int dist;
    stringstream toInt(strDist);
    list<int> listHor;
    OpcoesTransporte ot;
    while (getline(f, tipoT)){
        getline(f, strDist);
        toInt >> dist; // Now the variable dist holds the value of strDist
        while(cin >> hor){
            if(hor.substr(2,1) != ":") break;
            listHor.push_back(stoi(hor));
        }
        ot.transportes.insert(Transporte(tipoT, dist, listHor));
    }
    f.close();
    print(ot);

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
    for(it = t.getHorario().begin(); it != t.getHorario().end() ; it++){
        if ((*it) == horaAtual){
            (*it) = horaNova;
            break;
        }
    }
}

void OpcoesTransporte::print(OpcoesTransporte ot) {
    for (auto i = ot.transportes.begin(); i != ot.transportes.end(); i++) {
        cout << (*i).getTipoTransp() << endl;
        cout << (*i).getDistancia() << endl;
        for( auto it = (*i).getHorario().begin(); it != (*i).getHorario().end(); it++ ){
            cout << (*it) << endl;
        }
    }
}

