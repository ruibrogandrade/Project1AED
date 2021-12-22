
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
    DataAtual.setAno(2019);
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
    string matricula;
    int dia;
    int mes;
    int ano;
    Data data;
    string strdata;
    string nomeFuncionario;
    /*
    cout << "Estrutura de Input de Servico: (C,DD/MM/YYYY,MatriculaAviao,Nome de Funcionário)";
    cin >> input;
    tipoServico = input.c_str()[0];
    dia = stoi(input.substr(2,2));
    mes = stoi(input.substr(5,2));
    ano = stoi(input.substr(8,4));
    matriculaAviao = (input.substr(13,6));
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
*/
    cout << "Quantos servicos deseja inserir" << endl;
    cout << '>';
    int quant;
    cin >> quant;
    cout << endl;
    if (quant == 0) { cout << "Nao vai ser adicionado nenhum Servico." << endl;}
    if (quant == 1) {cout << "Vamos adicionar um novo Servico." << endl;}
    if (quant > 1) {cout << "Vamos adicionar " << quant << " novos Servico." << endl;}
    cout << endl;
    while(quant != 0){
        cout << "Insira o código de Servico: " << endl;
        cout << '>';
        cin >> tipoServico;
        cout << "Insira a data do Servico: " <<  endl;
        cout << '>';
        cin >> strdata;
        dia = stoi(strdata.substr(0,2));
        mes = stoi(strdata.substr(3,2));
        ano = stoi(strdata.substr(6,4));
        data.setDia(dia);
        data.setMes(mes);
        data.setAno(ano);
        cout << "Insira a matricula do Aviao " <<  endl;
        cout << '>';
        cin >> matricula;
        cout << "Insira o nome do Funcionário " <<  endl;
        cout << '>';
        cin >> nomeFuncionario;
        tmp.setTipoServico(tipoServico);
        tmp.setData(data);
        tmp.setMatriculaAviao(matricula);
        tmp.setNomeFuncionario(nomeFuncionario);
        if (MenorQueDataAtual(data)) {
            servicosFeitos.push(tmp);
        } else {
            servicosPorFazer.push(tmp);
        }
        cout << endl;
        quant--;
        if(quant != 0) {
            cout << "(Proximo Servico)";
            cout << endl;
        }
    }
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
    cout << '>';
    cin >> parametro;
    cout << endl;
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
        tmp1 = servicosFeitos;
        tmp2 = servicosPorFazer;
        vector<servico> satisfaz;
        string nome;
        cout << "Que Funcionario deseja ver?";
        cout << '>';
        cin >> nome;
        cout << endl;
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
        vector<servico> satisfaz;
        tmp1 = servicosFeitos;
        tmp2 = servicosPorFazer;
        string matricula;
        cout << "Que Matricula de aviao deseja ver?";
        cout << '>';
        cin >> matricula;
        cout << endl;
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
    if (parametro == "Data") {
        vector<servico> satisfaz;
        tmp1 = servicosFeitos;
        tmp2 = servicosPorFazer;
        int dia;
        int mes;
        int ano;
        string strData;
        Data data;
        cout << "Quer serviços a partir de que data?";
        cout << '>';
        cin >> strData;
        cout << endl;
        dia = stoi(strData.substr(0,2));
        mes = stoi(strData.substr(3,2));
        ano = stoi(strData.substr(6,4));
        data.setDia(dia);
        data.setMes(mes);
        data.setAno(ano);

        for (int i = 0; i < servicosFeitos.size(); i++) {
            if (data < tmp1.front().getData()) {
                satisfaz.push_back(tmp1.front());
            }
            tmp1.pop();
        }
        for (int i = 0; i < servicosPorFazer.size(); i++) {
            if (data < tmp2.front().getData()) {
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

void servico::ApagarServicos() {
    string parametro;
    string tipo;
    cout << "Que parametro deseja apagar?";
    cout << '>';
    cin >> parametro;
    cout << endl;
    vector<servico> apagar;
    queue<servico> tmp1 = servicosFeitos;
    queue<servico> tmp2 = servicosPorFazer;
    vector<servico> juntar;
    if (parametro == "tipoServico") {
        cout << "Que tipo de serviço deseja apagar?";
        cout << '>';
        cin >> tipo;
        cout << endl;
        for (int i = 0; i < servicosFeitos.size(); i++) {
            juntar.push_back(tmp1.front());
            tmp1.pop();
        }
        for (int i = 0; i < servicosPorFazer.size(); i++) {
            juntar.push_back(tmp2.front());
            tmp2.pop();
        }

        for (int i = 0; i < juntar.size(); i++) {
            if (juntar[i].getTipoServico() == tipo) {
                juntar.erase(juntar.begin() + i);
                apagar.push_back(juntar[i]);
            }
        }

        //Selection Sort
        if (juntar.size() > 1) {
            for (int i = 0; i < juntar.size(); i++) {
                for (unsigned i = 0; i < juntar.size() - 1; i++) {
                    unsigned imin = i;
                    for (int j = i + 1; j < juntar.size(); j++)
                        if (juntar[j].getData() < juntar[imin].getData())
                            imin = j;
                    swap(juntar[i], juntar[imin]);
                }
            }
        }

        for (int i = 0; i < juntar.size(); i++) {
            if (MenorQueDataAtual(juntar[i].getData())) {
                servicosFeitos.push(juntar[i]);
            } else {
                servicosPorFazer.push(juntar[i]);
            }
        }

        int size = apagar.size();
        for (int i = 0; i < size; i++) {
            cout << apagar.front().getTipoServico() << ',';
            if (apagar.front().getData().getDia() < 10) cout << "0" << apagar.front().getData().getDia();
            else cout << apagar.front().getData().getDia();
            cout << '/';
            if (apagar.front().getData().getMes() < 10) cout << "0" << apagar.front().getData().getMes();
            else cout << apagar.front().getData().getMes();
            cout << "/" << apagar.front().getData().getAno() << "," << apagar.front().getMatriculaAviao() << ","
                 << apagar.front().getNomeFuncionario() << ",";
            apagar.erase(apagar.begin());
            if (apagar.empty()) continue;
            else cout << endl;
        }
    }

    if (parametro == "nomeFuncionario") {
        tmp1 = servicosFeitos;
        tmp2 = servicosPorFazer;
        vector<servico> satisfaz;
        string nome;
        cout << "Que Funcionario deseja apagar?";
        cout << '>';
        cin >> nome;
        cout << endl;
        vector<servico> apagar;
        queue<servico> tmp1 = servicosFeitos;
        queue<servico> tmp2 = servicosPorFazer;
        vector<servico> juntar;
        for (int i = 0; i < servicosFeitos.size(); i++) {
            juntar.push_back(tmp1.front());
            tmp1.pop();
        }
        for (int i = 0; i < servicosPorFazer.size(); i++) {
            juntar.push_back(tmp2.front());
            tmp2.pop();
        }

        for (int i = 0; i < juntar.size(); i++) {
            if (juntar[i].getNomeFuncionario() == nome) {
                juntar.erase(juntar.begin() + i);
                apagar.push_back(juntar[i]);
            }
        }

        //Selection Sort
        if (juntar.size() > 1) {
            for (int i = 0; i < juntar.size(); i++) {
                for (unsigned i = 0; i < juntar.size() - 1; i++) {
                    unsigned imin = i;
                    for (int j = i + 1; j < juntar.size(); j++)
                        if (juntar[j].getData() < juntar[imin].getData())
                            imin = j;
                    swap(juntar[i], juntar[imin]);
                }
            }
        }

        for (int i = 0; i < juntar.size(); i++) {
            if (MenorQueDataAtual(juntar[i].getData())) {
                servicosFeitos.push(juntar[i]);
            } else {
                servicosPorFazer.push(juntar[i]);
            }
        }

        int size = apagar.size();
        for (int i = 0; i < size; i++) {
            cout << apagar.front().getTipoServico() << ',';
            if (apagar.front().getData().getDia() < 10) cout << "0" << apagar.front().getData().getDia();
            else cout << apagar.front().getData().getDia();
            cout << '/';
            if (apagar.front().getData().getMes() < 10) cout << "0" << apagar.front().getData().getMes();
            else cout << apagar.front().getData().getMes();
            cout << "/" << apagar.front().getData().getAno() << "," << apagar.front().getMatriculaAviao() << ","
                 << apagar.front().getNomeFuncionario() << ",";
            apagar.erase(apagar.begin());
            if (apagar.empty()) continue;
            else cout << endl;
        }
    }

    if (parametro == "matriculaAviao") {
        vector<servico> satisfaz;
        tmp1 = servicosFeitos;
        tmp2 = servicosPorFazer;
        string matricula;
        cout << "Que Matricula de aviao deseja apagar?";
        cout << '>';
        cin >> matricula;
        cout << endl;
        vector<servico> apagar;
        queue<servico> tmp1 = servicosFeitos;
        queue<servico> tmp2 = servicosPorFazer;
        vector<servico> juntar;
        for (int i = 0; i < servicosFeitos.size(); i++) {
            juntar.push_back(tmp1.front());
            tmp1.pop();
        }
        for (int i = 0; i < servicosPorFazer.size(); i++) {
            juntar.push_back(tmp2.front());
            tmp2.pop();
        }

        for (int i = 0; i < juntar.size(); i++) {
            if (juntar[i].getMatriculaAviao() == matricula) {
                juntar.erase(juntar.begin() + i);
                apagar.push_back(juntar[i]);
            }
        }

        //Selection Sort
        if (juntar.size() > 1) {
            for (int i = 0; i < juntar.size(); i++) {
                for (unsigned i = 0; i < juntar.size() - 1; i++) {
                    unsigned imin = i;
                    for (int j = i + 1; j < juntar.size(); j++)
                        if (juntar[j].getData() < juntar[imin].getData())
                            imin = j;
                    swap(juntar[i], juntar[imin]);
                }
            }
        }

        for (int i = 0; i < juntar.size(); i++) {
            if (MenorQueDataAtual(juntar[i].getData())) {
                servicosFeitos.push(juntar[i]);
            } else {
                servicosPorFazer.push(juntar[i]);
            }
        }

        int size = apagar.size();
        for (int i = 0; i < size; i++) {
            cout << apagar.front().getTipoServico() << ',';
            if (apagar.front().getData().getDia() < 10) cout << "0" << apagar.front().getData().getDia();
            else cout << apagar.front().getData().getDia();
            cout << '/';
            if (apagar.front().getData().getMes() < 10) cout << "0" << apagar.front().getData().getMes();
            else cout << apagar.front().getData().getMes();
            cout << "/" << apagar.front().getData().getAno() << "," << apagar.front().getMatriculaAviao() << ","
                 << apagar.front().getNomeFuncionario() << ",";
            apagar.erase(apagar.begin());
            if (apagar.empty()) continue;
            else cout << endl;
        }
    }
    if (parametro == "Data") {
        vector<servico> satisfaz;
        tmp1 = servicosFeitos;
        tmp2 = servicosPorFazer;
        int dia;
        int mes;
        int ano;
        string strData;
        Data data;
        cout << "Quer apagar serviços a partir de que data?";
        cout << '>';
        cout << endl;
        cin >> strData;
        dia = stoi(strData.substr(0, 2));
        mes = stoi(strData.substr(3, 2));
        ano = stoi(strData.substr(6, 4));
        data.setDia(dia);
        data.setMes(mes);
        data.setAno(ano);
        vector<servico> apagar;
        queue<servico> tmp1 = servicosFeitos;
        queue<servico> tmp2 = servicosPorFazer;
        vector<servico> juntar;
        for (int i = 0; i < servicosFeitos.size(); i++) {
            juntar.push_back(tmp1.front());
            tmp1.pop();
        }
        for (int i = 0; i < servicosPorFazer.size(); i++) {
            juntar.push_back(tmp2.front());
            tmp2.pop();
        }

        for (int i = 0; i < juntar.size(); i++) {
            if (MenorQueDataAtual(juntar[i].getData())) {
                juntar.erase(juntar.begin() + i);
                apagar.push_back(juntar[i]);
            }
        }

        //Selection Sort
        if (juntar.size() > 1) {
            for (int i = 0; i < juntar.size(); i++) {
                for (unsigned i = 0; i < juntar.size() - 1; i++) {
                    unsigned imin = i;
                    for (int j = i + 1; j < juntar.size(); j++)
                        if (juntar[j].getData() < juntar[imin].getData())
                            imin = j;
                    swap(juntar[i], juntar[imin]);
                }
            }
        }

        for (int i = 0; i < juntar.size(); i++) {
            if (MenorQueDataAtual(juntar[i].getData())) {
                servicosFeitos.push(juntar[i]);
            } else {
                servicosPorFazer.push(juntar[i]);
            }
        }

        int size = apagar.size();
        for (int i = 0; i < size; i++) {
            cout << apagar.front().getTipoServico() << ',';
            if (apagar.front().getData().getDia() < 10) cout << "0" << apagar.front().getData().getDia();
            else cout << apagar.front().getData().getDia();
            cout << '/';
            if (apagar.front().getData().getMes() < 10) cout << "0" << apagar.front().getData().getMes();
            else cout << apagar.front().getData().getMes();
            cout << "/" << apagar.front().getData().getAno() << "," << apagar.front().getMatriculaAviao() << ","
                 << apagar.front().getNomeFuncionario() << ",";
            apagar.erase(apagar.begin());
            if (apagar.empty()) continue;
            else cout << endl;
        }
    }
}