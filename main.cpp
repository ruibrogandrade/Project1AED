#include <iostream>
#include <fstream>
#include <sstream>
#include "Aeroporto/bst.h"
#include "Aeroporto/transpTerr.h"

using namespace std;

void ReadTransporteFile(BST<Transporte> transportes) {
    ifstream f("transpTerr.txt");
    string tipoT, strDist;
    int dist;
    stringstream toInt(strDist);
    while (getline(f, tipoT)){
        getline(f, strDist);
        toInt >> dist; // Now the variable dist holds the value of strDist
        transportes.insert(Transporte(tipoT, dist));
    }
}

void ReadFiles(BST<Transporte> transportes) {
    ReadTransporteFile(transportes);
}

int main(){
    BST<Transporte> transportes;
    ReadFiles(transportes);
}

