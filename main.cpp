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


void ReadServico() {
    char tiposervico;
    Data data;
    int dia;
    int mes;
    int ano;
    string nomeFuncionario;
    ifstream file("servicos.txt");
    string line;
    string test;
    int i = 0;
    while (getline(file, line, ','))
    {
        switch(i){
            case(0):
                tiposervico = line.c_str()[0];
                cout << tiposervico;
                break;
            case(1):
                dia = stoi(line.substr(0,2));
                mes = stoi(line.substr(3,5));
                ano = stoi(line.substr(6,10));
                data.setDia(dia);
                data.setMes(mes);
                data.setAno(ano);
                cout << dia << mes << ano;
                break;
            case(2):
                nomeFuncionario = line;
                cout << line;
                i = 0;
                break;
        }
        i++;
    }
}

void ReadFiles() {
    ReadServico();
}


int main() {
    ReadFiles();
    return 0;
}
