#include <fstream>
#include <sstream>
#include "aeroporto.h"

/*
//só implementei para a matricula e para a capacidade
void Aeroporto::AviaoInput() {
    //valores para testar
    listAviao.emplace_back("37-FP-45", 1500);
    listAviao.push_back(Aviao("81-TM-05", 1250));
}*/
/*
void Aeroporto::WriteAviao() {
    ofstream file;
    file.open("");
    for (auto it = listAviao.begin(); it != listAviao.end(); it++){
        file << (*it).getMatricula() << ','<< (*it).getCapacidade() << endl;
    }
    file.close();
}
*/
void Aeroporto::ReadAviao() {
    string matricula;
    int capacidade;
    //list<Voo> listaVoo;
    ifstream file("aviao.txt");
    string line;
    int i = 0;
    Aviao a;
    while (getline(file, line, ',')){
        switch(i){
            case(0):
                a.getMatricula() = line;
                break;
            case(1):
                capacidade = stoi(line);

                i = -1;
                break;
        }
        i++;
    }
    file.close();
}


