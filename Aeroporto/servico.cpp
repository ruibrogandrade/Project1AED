
#include <iostream>
#include <fstream>
#include "servico.h"
#include "aviao.h"
#include "Data.h"

using namespace std;
servico::servico() {}


servico::servico(char tiposervico, Data data, string nomeFuncionario) {
    this->tiposervico=tiposervico;
    this->data=data;
    this->nomeFuncionario=nomeFuncionario;
}

char servico::getTipoServico() const {
    return tiposervico;
}

void servico::setTipoServico(char tiposervico) {
    this->tiposervico=tiposervico;
}

Data servico::getData() const{
    return data;
}

void servico::setData(Data data) {
    this->data=data;
}

string servico::getNomeFuncionario() const {
    return nomeFuncionario;
}

void servico::setNomeFuncionario(string nomeFuncionario) {
    this->nomeFuncionario=nomeFuncionario;
}

bool servico::operator==(const servico &s) const {
    return tiposervico == s.tiposervico && data == s.data && nomeFuncionario == s.nomeFuncionario;
}


bool servico::MenorQueDataAtual(Data data) {
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

void servico::WriteServico(queue<servico> servicosFeitos, queue<servico> servicosPorFazer) {
    ofstream file;
    file.open("servicos.txt");
    queue<servico> tmp1 = servicosFeitos;
    queue<servico> tmp2 = servicosPorFazer;
    for(int i = 0; i < servicosFeitos.size();i++) {
        file << tmp1.front().getTipoServico() << ',' << tmp1.front().getData().getDia() << "/" << tmp1.front().getData().getMes() << "/"
             << tmp1.front().getData().getAno() << "," << tmp1.front().getNomeFuncionario() <<  "," << endl;
        tmp2.pop();
    }
    for(int i = 0; i < servicosPorFazer.size();i++) {
        file << tmp2.front().getTipoServico() << ',' << tmp2.front().getData().getDia() << "/" << tmp2.front().getData().getMes() << "/"
             << tmp2.front().getData().getAno() << "," << tmp2.front().getNomeFuncionario() << "," << endl;
        tmp2.pop();
    }
    file.close();
}

void servico::ServicoInput(queue<servico> servicosFeitos, queue<servico> servicosPorFazer) {
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
    tipoServico = input.c_str()[0];
    dia = stoi(input.substr(2,4));
    mes = stoi(input.substr(5,7));
    ano = stoi(input.substr(8,12));
    nomeFuncionario = input.substr(13);
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
    WriteServico();
}

void servico::ReadServico(queue<servico> servicosFeitos, queue<servico> servicosPorFazer) {
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
                tmp.setTipoServico(tiposervico);
                break;
            case(1):
                dia = stoi(line.substr(0,2));
                mes = stoi(line.substr(3,5));
                ano = stoi(line.substr(6,10));
                data.setDia(dia);
                data.setMes(mes);
                data.setAno(ano);
                tmp.setData(data);
                break;
            case(2):
                nomeFuncionario = line;
                tmp.setNomeFuncionario(nomeFuncionario);
                i = -1;
                if (MenorQueDataAtual(data)) {
                    servicosFeitos.push(tmp);
                } else {
                    servicosPorFazer.push(tmp);
                }
                break;
        }
        i++;
    }
}

