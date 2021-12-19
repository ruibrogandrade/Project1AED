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
    for(auto it = horario.begin(); it != horario.end() ; it++){
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

void OpcoesTransporte::readFile() {
    ifstream f;
    f.open("transTerr.txt");
    string tipoT, strDist, line;
    int dist, hor;
    list<int> listHor;
    Transporte t;
    int i = 0;
    while (getline(f, line, ';')){
        switch (i) {
            case (0):
                tipoT = line;
                t.setTipoTransp(tipoT);
                break;
            case (1):
                dist = stoi(line);
                t.setDistancia(dist);
                break;
            case (2):
                while(getline(f, line, ',')){
                    hor = stoi(line);
                    t.addHoraExtra(hor);
                }
                t.setHorario(listHor);
                transportes.insert(t);
                /*//é preciso eu meter por ordem?
                //--------------------------------------------------------------------------
                iteratorBST<Transporte> et;
                for (auto it = transportes.begin(); it != transportes.end();it++) {
                    if((*it).getDistancia() < dist) {
                        et = it;
                        it++;
                        if ((*it).getDistancia() > dist) { //falta fazer para o ==
                            transportes.insert(t);
                            break;
                        }
                    }
                }*/
                //---------------------------------------------------------------------------
                i = -1;
                break;
        }
        i++;
    }
    f.close();
    printThis();
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

void OpcoesTransporte::WriteBST(BST<Transporte> transportes) {
    ofstream file;
    file.open("transTerr.txt");
    for( auto it = transportes.begin(); it != transportes.end(); it++){
        file << (*it).getTipoTransp() << ',' << (*it).getDistancia() /*<< ',' << (*it).getHorario()*/ << endl;
    }
    file.close();
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

void OpcoesTransporte::printThis() {
    for (auto i = transportes.begin(); i != transportes.end(); i++) {
        cout << (*i).getTipoTransp() << endl;
        cout << (*i).getDistancia() << endl;
        for( auto it = (*i).getHorario().begin(); it != (*i).getHorario().end(); it++ ){
            cout << (*it) << endl;
        }
    }
}


