
#include <iostream>
#include <fstream>
#include "servico.h"
#include "aviao.h"
#include "Data.h"

using namespace std;
servico::servico() {}


servico::servico(char tiposervico, Data data, string nomeFuncionario, string matriculaAviao) {
    this->tiposervico=tiposervico;
    this->data=data;
    this->nomeFuncionario=nomeFuncionario;
}

string servico::getTipoServico() const {
    return tiposervico;
}

void servico::setTipoServico(string tiposervico) {
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
    return tiposervico == s.tiposervico || data == s.data || nomeFuncionario == s.nomeFuncionario;
}

void servico::setMatriculaAviao(string matriculaAviao) {
    this->matriculaAviao=matriculaAviao;
}

string servico::getMatriculaAviao() const{
    return matriculaAviao;
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

void servico::WriteServico() {
    //queue<servico> servicosPorFazer = getServicosPorFazer();
    //queue<servico> servicosFeitos = getServicosFeitos();
    ofstream file;
    file.open("servicos.txt");
    queue<servico> tmp1 = servicosFeitos;
    queue<servico> tmp2 = servicosPorFazer;
    for(int i = 0; i < servicosFeitos.size();i++) {
        file << tmp1.front().getTipoServico() << ',';
        if (tmp1.front().getData().getDia() < 10) file << "0" << tmp1.front().getData().getDia();
        else file << tmp1.front().getData().getDia();
        file <<'/';
        if (tmp1.front().getData().getMes() < 10) file << "0" << tmp1.front().getData().getMes();
        else file << tmp1.front().getData().getMes();
        file << "/"
        << tmp1.front().getData().getAno() << "," << tmp1.front().getMatriculaAviao() <<  "," << tmp1.front().getNomeFuncionario() <<  ",";
        tmp1.pop();
        if (tmp1.empty() && tmp2.empty()) continue;
        else file << endl;
    }
    for(int i = 0; i < servicosPorFazer.size();i++) {
        file << tmp2.front().getTipoServico() << ',';
        if (tmp2.front().getData().getDia() < 10) file << "0" << tmp2.front().getData().getDia();
        else file << tmp2.front().getData().getDia();
        file <<'/';
        if (tmp2.front().getData().getMes() < 10) file << "0" << tmp2.front().getData().getMes();
        else file << tmp2.front().getData().getMes();
        file << "/"
        << tmp2.front().getData().getAno() << "," << tmp2.front().getMatriculaAviao() << "," << tmp2.front().getNomeFuncionario() <<  ",";
        tmp2.pop();
        if (tmp2.empty()) continue;
        else file << endl;
    }
    file.close();
}

void servico::ServicoInput() {
    //queue<servico> servicosPorFazer = getServicosPorFazer();
    //queue<servico> servicosFeitos = getServicosFeitos();
    servico tmp;
    string input;
    string tipoServico;
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

void servico::ReadServico() {
    //queue<servico> servicosPorFazer = getServicosPorFazer();
    //queue<servico> servicosFeitos = getServicosFeitos();
    string tiposervico;
    servico tmp;
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
                if (line.substr(0,1) == "\n") line.erase(0,1);
                tiposervico = line;
                tmp.setTipoServico(tiposervico);
                break;
            case(1):
                dia = stoi(line.substr(0,2));
                mes = stoi(line.substr(3,2));
                ano = stoi(line.substr(6,4));
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

void servico::ListagemServicos() {
    std::ifstream f("servicos.txt");

    if (f.is_open())
        std::cout << f.rdbuf();
}


void servico::ListagemParcialServicos() {
    string parametro;
    string tipo;
    cout << "Que parametro deseja filtrar?";
    cin >> parametro;
    vector<servico> satisfaz;
    queue<servico> tmp1 = servicosFeitos;
    queue<servico> tmp2 = servicosPorFazer;
    if (parametro == "tipoServico") {
        cout << "Que tipo de serviço deseja ver?";
        cin >> tipo;
        for (int i = 0; i < servicosFeitos.size(); i++) {
            if (tmp1.front().getTipoServico() == tipo) {
                satisfaz.push_back(tmp1.front());
            }
            tmp1.pop();
        }
        for (int i = 0; i < servicosPorFazer.size(); i++) {
            if (tmp2.front().getTipoServico() == tipo) {
                satisfaz.push_back(tmp2.front());
            }
            tmp2.pop();
        }

        //Selection Sort
        if (satisfaz.size() > 1) {
            for (int i = 0; i < satisfaz.size(); i++) {
                for (unsigned i = 0; i < satisfaz.size() - 1; i++) {
                    unsigned imin = i;
                    for (int j = i + 1; j < satisfaz.size(); j++)
                        if (satisfaz[j].getData() < satisfaz[imin].getData())
                            imin = j;
                    swap(satisfaz[i], satisfaz[imin]);
                }
            }
        }

        int size = satisfaz.size();
        for(int i = 0; i < size; i++) {
            cout << satisfaz.front().getTipoServico() << ',';
            if (satisfaz.front().getData().getDia() < 10) cout << "0" << satisfaz.front().getData().getDia();
            else cout << satisfaz.front().getData().getDia();
            cout << '/';
            if (satisfaz.front().getData().getMes() < 10) cout << "0" << satisfaz.front().getData().getMes();
            else cout << satisfaz.front().getData().getMes();
            cout << "/" << satisfaz.front().getData().getAno() << "," << satisfaz.front().getMatriculaAviao() << ","
            << satisfaz.front().getNomeFuncionario() << ",";
            satisfaz.erase(satisfaz.begin());
            if (satisfaz.empty()) continue;
            else cout << endl;
        }
    }

    if (parametro == "nomeFuncionario") {
        string nome;
        cout << "Que Funcionario deseja ver?";
        cin >> nome;
        for (int i = 0; i < servicosFeitos.size(); i++) {
            if (tmp1.front().getNomeFuncionario() == nome) {
                satisfaz.push_back(tmp1.front());
            }
            tmp1.pop();
        }
        for (int i = 0; i < servicosPorFazer.size(); i++) {
            if (tmp2.front().getNomeFuncionario() == nome) {
                satisfaz.push_back(tmp2.front());
            }
            tmp2.pop();
        }

        //Selection Sort
        if (satisfaz.size() > 1) {
            for (int i = 0; i < satisfaz.size(); i++) {
                for (unsigned i = 0; i < satisfaz.size() - 1; i++) {
                    unsigned imin = i;
                    for (int j = i + 1; j < satisfaz.size(); j++)
                        if (satisfaz[j].getData() < satisfaz[imin].getData())
                            imin = j;
                    swap(satisfaz[i], satisfaz[imin]);
                }
            }
        }

        int size = satisfaz.size();
        for(int i = 0; i < size; i++) {
            cout << satisfaz.front().getTipoServico() << ',';
            if (satisfaz.front().getData().getDia() < 10) cout << "0" << satisfaz.front().getData().getDia();
            else cout << satisfaz.front().getData().getDia();
            cout << '/';
            if (satisfaz.front().getData().getMes() < 10) cout << "0" << satisfaz.front().getData().getMes();
            else cout << satisfaz.front().getData().getMes();
            cout << "/" << satisfaz.front().getData().getAno() << "," << satisfaz.front().getMatriculaAviao() << ","
                 << satisfaz.front().getNomeFuncionario() << ",";
            satisfaz.erase(satisfaz.begin());
            if (satisfaz.empty()) continue;
            else cout << endl;
        }
    }

    if (parametro == "matriculaAviao") {
        string matricula;
        cout << "Que Funcionario deseja ver?";
        cin >> matricula;
        for (int i = 0; i < servicosFeitos.size(); i++) {
            if (tmp1.front().getMatriculaAviao() == matricula) {
                satisfaz.push_back(tmp1.front());
            }
            tmp1.pop();
        }
        for (int i = 0; i < servicosPorFazer.size(); i++) {
            if (tmp2.front().getMatriculaAviao() == matricula) {
                satisfaz.push_back(tmp2.front());
            }
            tmp2.pop();
        }

        //Selection Sort
        if (satisfaz.size() > 1) {
            for (int i = 0; i < satisfaz.size(); i++) {
                for (unsigned i = 0; i < satisfaz.size() - 1; i++) {
                    unsigned imin = i;
                    for (int j = i + 1; j < satisfaz.size(); j++)
                        if (satisfaz[j].getData() < satisfaz[imin].getData())
                            imin = j;
                    swap(satisfaz[i], satisfaz[imin]);
                }
            }
        }

        int size = satisfaz.size();
        for(int i = 0; i < size; i++) {
            cout << satisfaz.front().getTipoServico() << ',';
            if (satisfaz.front().getData().getDia() < 10) cout << "0" << satisfaz.front().getData().getDia();
            else cout << satisfaz.front().getData().getDia();
            cout << '/';
            if (satisfaz.front().getData().getMes() < 10) cout << "0" << satisfaz.front().getData().getMes();
            else cout << satisfaz.front().getData().getMes();
            cout << "/" << satisfaz.front().getData().getAno() << "," << satisfaz.front().getMatriculaAviao() << ","
                 << satisfaz.front().getNomeFuncionario() << ",";
            satisfaz.erase(satisfaz.begin());
            if (satisfaz.empty()) continue;
            else cout << endl;
        }
    }
}



/*
void servico::setServicosPorFazer(queue<servico> servicosPorFazer) {
    this->servicosPorFazer=servicosPorFazer;
}

queue<servico> servico::getServicosPorFazer() const{
    return servicosPorFazer;
}

void servico::setServicosFeitos(queue<servico> servicosFeitos) {
    this->servicosFeitos=servicosFeitos;
}

queue<servico> servico::getServicosFeitos()  const{
    return servicosFeitos;
}
*/