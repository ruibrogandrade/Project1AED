
#include <iostream>
#include <fstream>
#include <cstring>
#include "servico.h"
#include "aviao.h"
#include "Data.h"

using namespace std;
Servico::Servico() {}


Servico::Servico(char tipoServico, Data data, string nomeFuncionario, string matriculaAviao) {
    this->tipoServico=tipoServico;
    this->data=data;
    this->nomeFuncionario=nomeFuncionario;
}

char Servico::getTipoServico() const {
    return tipoServico;
}

void Servico::setTipoServico(char tipoServico) {
    this->tipoServico=tipoServico;
}

Data Servico::getData() const{
    return data;
}

void Servico::setData(Data data) {
    this->data=data;
}

string Servico::getNomeFuncionario() const {
    return nomeFuncionario;
}

void Servico::setNomeFuncionario(string nomeFuncionario) {
    this->nomeFuncionario=nomeFuncionario;
}

bool Servico::operator==(const Servico &s) const {
    return tipoServico == s.tipoServico || data == s.data || nomeFuncionario == s.nomeFuncionario;
}

void Servico::setMatriculaAviao(string matriculaAviao) {
    this->matriculaAviao=matriculaAviao;
}

string Servico::getMatriculaAviao() const{
    return matriculaAviao;
}

bool Servico::MenorQueDataAtual(Data data) {
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

void Servico::WriteServico() {
    //queue<servico> servicosPorFazer = getServicosPorFazer();
    //queue<servico> servicosFeitos = getServicosFeitos();
    ofstream file;
    file.open("servicos.txt");
    queue<Servico> tmp1 = servicosFeitos;
    queue<Servico> tmp2 = servicosPorFazer;
    for(int i = 0; i < servicosFeitos.size();i++) {
        file << tmp1.front().getTipoServico() << ',';
        if (tmp1.front().getData().getDia() < 10) file << "0" << tmp1.front().getData().getDia();
        else file << tmp1.front().getData().getDia();
        file <<'/';
        if (tmp1.front().getData().getMes() < 10) file << "0" << tmp1.front().getData().getMes();
        else file << tmp1.front().getData().getMes();
        file << "/" << tmp1.front().getData().getAno() << "," << tmp1.front().getMatriculaAviao()
             <<  "," << tmp1.front().getNomeFuncionario() <<  ",";
        tmp1.pop();
    }
    for(int i = 0; i < servicosPorFazer.size();i++) {
        file << tmp2.front().getTipoServico() << ',';
        if (tmp2.front().getData().getDia() < 10) file << "0" << tmp2.front().getData().getDia();
        else file << tmp2.front().getData().getDia();
        file <<'/';
        if (tmp2.front().getData().getMes() < 10) file << "0" << tmp2.front().getData().getMes();
        else file << tmp2.front().getData().getMes();
        file << "/" << tmp2.front().getData().getAno() << "," << tmp2.front().getMatriculaAviao()
             << "," << tmp2.front().getNomeFuncionario() <<  ",";
        tmp2.pop();
    }
    file.close();
}

void Servico::ServicoInput() {
    //queue<servico> servicosPorFazer = getServicosPorFazer();
    //queue<servico> servicosFeitos = getServicosFeitos();
    Servico tmp;
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
    matriculaAviao = (input.substr(13,19));
    nomeFuncionario = input.substr(20);
    tmp.setTipoServico(tipoServico);
    data.setDia(dia);
    data.setMes(mes);
    data.setAno(ano);
    tmp.setData(data);
    tmp.setMatriculaAviao(matriculaAviao);
    tmp.setNomeFuncionario(nomeFuncionario);
    if (MenorQueDataAtual(data)) {
        servicosFeitos.push(tmp);
    } else {
        servicosPorFazer.push(tmp);
    }
    //setServicosFeitos(servicosFeitos);
    //setServicosPorFazer(servicosPorFazer);
    WriteServico();
}

void Servico::ReadServico() {
    //queue<servico> servicosPorFazer = getServicosPorFazer();
    //queue<servico> servicosFeitos = getServicosFeitos();
    Servico tmp;
    char tipoServico;
    Data data;
    int dia;
    int mes;
    int ano;
    string nomeFuncionario;
    string matriculaAviao;
    list<Aviao>::iterator it;
    ifstream file("servicos.txt");
    string line;
    string test;
    int i = 0;
    while (getline(file, line, ',')){
        switch(i){
            case(0):
                tipoServico = line[0];
                tmp.setTipoServico(tipoServico);
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
                matriculaAviao = line;
                tmp.setMatriculaAviao(matriculaAviao);
                break;
            case(3):
                nomeFuncionario = line;
                tmp.setNomeFuncionario(nomeFuncionario);
                i=-1;
                if (MenorQueDataAtual(data)) {
                    servicosFeitos.push(tmp);
                } else {
                    servicosPorFazer.push(tmp);
                }
                break;
        }
        i++;
    }
    //setServicosFeitos(servicosFeitos);
    //setServicosPorFazer(servicosPorFazer);
}
/*
 list<Aviao>::iterator Servico::findAviao(list<Aviao> listAviao, string matriculaAviao) {
    list<Aviao>::iterator it;
    for(it = listAviao.begin(); it != listAviao.end(); it++) {
        if(it->getMatricula() == matriculaAviao) {
            return (it);
        }
    }
}
*/

void Servico::ListagemServicos() {
    std::ifstream f("servicos.txt");

    if (f.is_open())
        std::cout << f.rdbuf();
}

void Servico::ListagemParcialServicos() {
    string parametro;
    cout << "Que parametro deseja filtrar?";
    cin >> parametro;
    if (parametro == "tipoServico") {
        cout << "Que tipo de serviço deseja ver?";
        cin >> tipoServico;

    }
}