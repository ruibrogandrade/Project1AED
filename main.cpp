#include <iostream>
#include <fstream>
#include <sstream>
#include "Aeroporto/bst.h"
#include "Aeroporto/transpTerr.h"

using namespace std;


void ReadTransporteFile(OpcoesTransporte ot) {
    ifstream f("transpTerr.txt");
    string tipoT, strDist;
    int dist;
    stringstream toInt(strDist);
    while (getline(f, tipoT)){
        getline(f, strDist);
        toInt >> dist; // Now the variable dist holds the value of strDist
        ot.getTransportes().insert(Transporte(tipoT, dist));
    }

}

void printTrans(OpcoesTransporte ot) {
    for (auto it = ot.getTransportes().begin(); it != ot.getTransportes().end(); it++) {
        cout << (*it).getTipoTransp() << endl;
        cout << (*it).getDistancia() << endl;
    }
}


int main(){
    OpcoesTransporte ot;
    ReadTransporteFile(ot);
    ot.getTransportes().insert(Transporte("bus", 4)); //não imprime nada :/
    printTrans(ot);
    //cout << "test if it works"; //isto imprime



}



