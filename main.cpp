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

void ReadFiles(OpcoesTransporte ot) {
    ReadTransporteFile(ot);
}

int main(){
    OpcoesTransporte ot;
    ReadFiles(ot);
}

