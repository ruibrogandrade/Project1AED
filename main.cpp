#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Aeroporto/servico.h"
#include "Aeroporto/data.h"

using namespace std;
/*
bool MenorQueDataAtual(Data data) {
    Data DataAtual;
    DataAtual.setDia(15);
    DataAtual.setMes(12);
    DataAtual.setAno(2021);
    if (data < DataAtual) {
        return true;
    } else {
        return false;
    }
}

void ServicoInput(queue<servico> servicosFeitos,queue<servico> servicosPorFazer) {
    servico tmp;
    string input;
    char tipoServico;
    int dia;
    int mes;
    int ano;
    Data data;
    string nomeFuncionario;
    cout << "Estrutura de Input de Servico: (C,DD/MM/YYYY,NOME)";
    cin >> input;
    tipoServico = stoi(input.substr(0,1));
    dia = stoi(input.substr(3,5));
    mes = stoi(input.substr(6,10));
    ano = stoi(input.substr(6,10));
    nomeFuncionario = stoi(input.substr(6,10));
    tmp.setTipoServico(tipoServico);
    data.setDia(dia);
    data.setMes(mes);
    data.setAno(ano);
    tmp.setData(data);
    tmp.setNomeFuncionario(nomeFuncionario);
    if (MenorQueDataAtual(data)) {
        servicosFeitos.push(tmp);
    } else {
        servicosPorFazer.push(tmp);
    }
}

void WriteServico(queue<servico> servicosFeitos, queue<servico> servicosPorFazer) {
    ofstream file;
    file.open("servicos.txt");
    for(int i = 0; i < servicosFeitos.size();i++) {
        file << servicosFeitos.front().getTipoServico() << ',' << servicosFeitos.front().getData().getDia() << "/" << servicosFeitos.front().getData().getMes() << "/"
             << servicosFeitos.front().getData().getAno() << "," << servicosFeitos.front().getNomeFuncionario() << endl;
    }
    for(int i = 0; i < servicosFeitos.size();i++) {
        file << servicosPorFazer.front().getTipoServico() << ',' << servicosPorFazer.front().getData().getDia() << "/" << servicosPorFazer.front().getData().getMes() << "/"
             << servicosPorFazer.front().getData().getAno() << "," << servicosPorFazer.front().getNomeFuncionario() << endl;
    }
    file.close();
}

void ReadServico(queue<servico> servicosFeitos, queue<servico> servicosPorFazer) {
    char tiposervico;
    servico tmp;
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
                break;
            case(1):
                dia = stoi(line.substr(0,2));
                mes = stoi(line.substr(3,5));
                ano = stoi(line.substr(6,10));
                data.setDia(dia);
                data.setMes(mes);
                data.setAno(ano);
                break;
            case(2):
                nomeFuncionario = line;
                i = 0;
                break;
        }

        i++;
        tmp.setTipoServico(tiposervico);
        tmp.setNomeFuncionario(nomeFuncionario);
        tmp.setData(data);
        if (MenorQueDataAtual(data)) {
            servicosFeitos.push(tmp);
        } else {
            servicosPorFazer.push(tmp);
        }
    }
}

void ReadFiles() {
    ReadServico(GlobalData::servicosFeitos,GlobalData::servicosPorFazer);
}

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
    if(TipoDeDataClasse == "Servico") {
        ServicoInput(GlobalData::servicosFeitos, GlobalData::servicosPorFazer);
    }
}
*/
int main() {
    /*
    ReadFiles();
    checkTipoDeData();
    WriteServico(GlobalData::servicosFeitos, GlobalData::servicosPorFazer);
     */
    return 0;
}

