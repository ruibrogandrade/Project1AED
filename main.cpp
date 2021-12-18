#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Aeroporto/servico.h"
#include "Aeroporto/Data.h"

using namespace std;
void ReadFiles() {
    Aviao a;
    a.ReadAviao();
}
/*
void checkTipoDeData(queue<servico> servicosFeitos, queue<servico> servicosPorFazer) {
    servico s;
    string TipoDeDataClasse;
    cout << "What Type of Data do you want to Submit?" << endl;
    cin >> TipoDeDataClasse;
    if(TipoDeDataClasse == "Voo") {

    }
    if(TipoDeDataClasse == "Bagagem") {

    }
    if(TipoDeDataClasse == "Passageiro") {

    }
    if(TipoDeDataClasse == "Servico") {
        s.ServicoInput();
    }
}
*/
int main() {
    ReadFiles();
    return 0;
}

