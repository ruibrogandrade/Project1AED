#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Aeroporto/Data.h"

using namespace std;

void checkTipoDeData() {
    string TipoDeDataClasse;
    cout << "What Type of Data do you want to Submit?" << endl;
    cin >> TipoDeDataClasse;
    if(TipoDeDataClasse == "Voo") {

    }
    if(TipoDeDataClasse == "Bagagem") {

    }
    if(TipoDeDataClasse == "Passageiro") {

    }
    if(TipoDeDataClasse == "Bilhete") {

    }
}


void ReadFiles() {
    char tiposervico;
    Data data;
    string nomeFuncionario;
    ifstream infile("servicos.txt");
    string line;
    int i = 0;
    while (getline(infile, line,','))
    {
        switch(i){
            case(0):
                tiposervico = line.c_str()[0];
                i++;
            case(1):

        }

    }
}


int main() {

    return 0;
}

