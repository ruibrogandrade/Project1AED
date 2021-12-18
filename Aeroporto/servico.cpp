#include <iostream>
#include <fstream>
#include "servico.h"
#include "aviao.h"
#include "Data.h"

using namespace std;

/*
Servico::Servico(char tiposervico, Data data, string nomeFuncionario, string matriculaAviao) {
    this->tiposervico=tiposervico;
    this->data=data;
    this->nomeFuncionario=nomeFuncionario;
}

char Servico::getTipoServico() const{
    return tiposervico;
}

void Servico::setTipoServico(char tiposervico) {
    this->tiposervico=tiposervico;
}

Data Servico::getData() const{
    return data;
}

void Servico::setData(Data data) {
    this->data=data;
}

string Servico::getNomeFuncionario() const{
    return nomeFuncionario;
}

void Servico::setNomeFuncionario(string nomeFuncionario) {
    this->nomeFuncionario=nomeFuncionario;
}

void Servico::setMatriculaAviao(string matriculaAviao) {
    this->matriculaAviao=matriculaAviao;
}

string Servico::getMatriculaAviao() const{
    return matriculaAviao;
}

bool Servico::operator==(const Servico &s) const {
    return tiposervico == s.tiposervico && data == s.data && nomeFuncionario == s.nomeFuncionario;
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

list<Aviao>::iterator Servico::findAviao(list<Aviao> listAviao, string matriculaAviao) {
    list<Aviao>::iterator it;
    for(it = listAviao.begin(); it != listAviao.end(); it++) {
        if(it->getMatricula() == matriculaAviao) {
            return (it);
        }
    }
}

void Servico::setServicosPorFazer(queue<Servico> servicosPorFazer) {
    this->servicosPorFazer=servicosPorFazer;
}

queue<Servico> Servico::getServicosPorFazer() const{
    return servicosPorFazer;
}

void Servico::setServicosFeitos(queue<Servico> servicosFeitos) {
    this->servicosFeitos=servicosFeitos;
}

queue<Servico> Servico::getServicosFeitos()  const{
    return servicosFeitos;
}

void Servico::WriteServico() {
    queue<Servico> servicosPorFazer = getServicosPorFazer();
    queue<Servico> servicosFeitos = getServicosFeitos();
    ofstream file;
    file.open("servicos.txt");
    queue<Servico> tmp1 = servicosFeitos;
    queue<Servico> tmp2 = servicosPorFazer;
    for(int i = 0; i < servicosFeitos.size();i++) {
        file << tmp1.front().getTipoServico() << ',' << tmp1.front().getData().getDia() << "/" << tmp1.front().getData().getMes() << "/"
             << tmp1.front().getData().getAno() << "," << tmp1.front().getMatriculaAviao() <<  "," << tmp1.front().getNomeFuncionario() << "," << endl;
        tmp1.pop();
    }
    for(int i = 0; i < servicosPorFazer.size();i++) {
        file << tmp2.front().getTipoServico() << ',' << tmp2.front().getData().getDia() << "/" << tmp2.front().getData().getMes() << "/"
             << tmp2.front().getData().getAno() << "," << tmp2.front().getMatriculaAviao() << "," << tmp2.front().getNomeFuncionario() << "," << endl;
        tmp2.pop();
    }
    file.close();
}

void Servico::ServicoInput() {
    queue<Servico> servicosPorFazer = getServicosPorFazer();
    queue<Servico> servicosFeitos = getServicosFeitos();
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
    setServicosFeitos(servicosFeitos);
    setServicosPorFazer(servicosPorFazer);
    WriteServico();
}

void Servico::ReadServico() {
    queue<Servico> servicosPorFazer = getServicosPorFazer();
    queue<Servico> servicosFeitos = getServicosFeitos();
    Aviao a;
    list<Aviao> listAviao = a.getListAviao();
    char tiposervico;
    Servico tmp;
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
                i++;
                break;
            case(3):
                matriculaAviao = stoi(line);
                tmp.setMatriculaAviao(matriculaAviao);
                i=-1;
                if (MenorQueDataAtual(data)) {
                    servicosFeitos.push(tmp);
                } else {
                    servicosPorFazer.push(tmp);
                }
                it = findAviao(listAviao, matriculaAviao);
                it->novoservico(tmp);
                break;
        }
        i++;
    }
    setServicosFeitos(servicosFeitos);
    setServicosPorFazer(servicosPorFazer);
}

*/