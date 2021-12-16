#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Aeroporto/servico.h"
#include "Aeroporto/Data.h"

using namespace std;
void ReadFiles(queue<servico> servicosFeitos, queue<servico> servicosPorFazer) {
    servico::ReadServico(servicosFeitos,servicosPorFazer);
}

void checkTipoDeData(queue<servico> servicosFeitos, queue<servico> servicosPorFazer) {
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
        servico::ServicoInput(servicosFeitos, servicosPorFazer);
    }
}

int main() {
    queue<servico> servicosFeitos;
    queue<servico> servicosPorFazer;
    ReadFiles(servicosFeitos, servicosPorFazer);
    checkTipoDeData(servicosFeitos, servicosPorFazer);
    return 0;
}

