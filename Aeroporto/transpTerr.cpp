#include "transpTerr.h"

Transporte::Transporte(string tipoT, list<int> hor, int dist) :
        tipoTransp(tipoT), horario(hor), distancia(dist){}

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

//falta ver como fazer os ficheiros
void OpcoesTransporte::readFile(ifstream &f) {
    //...
}
//exemplo de como lidar com files:
/*void Dictionary::readFile(ifstream &f) {
    string fst, sec;
    while(getline(f,fst)){
        getline(f,sec);
        words.insert(WordMean(fst,sec));
    }
}*/

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

