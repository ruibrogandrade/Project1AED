#include <fstream>
#include <sstream>
#include "aviao.h"

using namespace std;


Aviao::Aviao() {}

Aviao::Aviao(string matricula, int capacidade, list<Voo> listaVoo) {
    this->matricula = matricula;
    this->capacidade = capacidade;
    this->listaVoo = listaVoo;
}

list<Voo> Aviao::getListaVoo() const {
    return listaVoo;
}

void Aviao::WriteVoo() {
    ofstream file;
    file.open("voo.txt");
    for(auto it = listVoos.begin(); it != listVoos.end(); it++) {
        file << (*it).getNumVoo() << ',';
        if ((*it).getDataPartida().getDia() < 10) file << "0" << (*it).getDataPartida().getDia();
        else file << (*it).getDataPartida().getDia();
        file <<'/';
        if ((*it).getDataPartida().getMes() < 10) file << "0" << (*it).getDataPartida().getMes();
        else file << (*it).getDataPartida().getMes();
        file << "/" << (*it).getDataPartida().getAno() << ',' << (*it).getDuracao() << ',' <<
        (*it).getNumLugares() << ',' << (*it).getOrigem() << ',' << (*it).getDestino() << ',' << (*it).getMatriculaAaviao();
        if (next(it) == listVoos.end()) continue;
        else file << endl;
    }
    file.close();
}

void Aviao::VooInput() {
    cout << "Quantos voos deseja adicionar? " << endl;
    cout << '>';
    int quant;
    cin >> quant;
    cout << endl;
    if (quant == 0) {cout << "Nao vai ser adicionado nenhum Voo." << endl;}
    if (quant == 1) {cout << "Vamos adicionar um novo Voo." << endl;}
    if (quant > 1){cout << "Vamos adicionar " << quant << " novos Voo." << endl; }
    cout << endl;
    while(quant != 0){
        cout << "Insira o nr de Voo: " << endl;
        cout << '>';
        int nrVoo;
        cin >> nrVoo;
        cout << "Insira a data de partida do voo no formato DD/MM/AAAA: " <<  endl;
        cout << '>';
        string data;
        cin >> data;
        Data d;
        d.setDia(stoi(data.substr(0,2)));
        d.setMes(stoi(data.substr(3,2)));
        d.setAno(stoi(data.substr(6,4)));
        cout << "Insira a duracao do Voo: " <<  endl;
        cout << '>';
        int duracao;
        cin >> duracao;
        cout << "Insira a lotacao do Voo: " <<  endl;
        cout << '>';
        int lotacao;
        cin >> lotacao;
        cout << "Insira o local de origem: " <<  endl;
        cout << '>';
        string origem;
        cin >> origem;
        cout << "Insira o local de destino: " <<  endl;
        cout << '>';
        string destino;
        cin >> destino;
        cout << "Insira a matricula do aviao que vai efetuar este voo: " <<  endl;
        cout << '>';
        string matricula;
        cin >> matricula;
        Voo v = Voo(nrVoo, d, duracao, lotacao, origem,destino, matricula);
        listVoos.push_back(v); //ver onde anda a listaVoo que ando a confundir com esta
        cout << endl;
        quant--;
        if(quant != 0) {
            cout << "(Proximo Voo)";
            cout << endl;
        }
    }
}

void Aviao::ReadVoo(){
    ifstream file("voo.txt");
    Voo v;
    Voo tmp;
    Data dataDePartida;
    int duracao;
    int dia, mes , ano, lot, numVoo;
    string origem, destino, matricula, line;
    int i = 0;
    while(getline(file,line,',')) {
        switch(i) {
            case (0):
                numVoo = stoi(line);
                tmp.setNumVoo(numVoo);
                break;
            case (1):
                dia = stoi(line.substr(0, 2));
                mes = stoi(line.substr(3, 5));
                ano = stoi(line.substr(6, 10));
                dataDePartida.setDia(dia);
                dataDePartida.setMes(mes);
                dataDePartida.setAno(ano);
                tmp.setDataPartida(dataDePartida);
                break;
            case (2):
                duracao = stoi(line);
                tmp.setDuracao(duracao); //PASSAR PARA FLOAT
                break;
            case (3):
                lot = stoi(line);
                tmp.setVagas(lot);
                tmp.setNumLugares(lot);
                break;
            case (4):
                origem = line;
                tmp.setOrigem(origem);
                break;
            case (5):
                destino = line;
                tmp.setDestino(destino);
                break;
            case (6):
                matricula = line;
                tmp.setMatriculaAviao(matricula);
                listVoos.push_back(tmp);
                i = -1;
                break;
        } i++;
    }
    file.close();

    /*
    for (auto it = listVoos.begin(); it != listVoos.end(); it++){
        cout << (*it).getNumVoo() << ',' << (*it).getDataPartida().getMes() << ',' << (*it).getDestino() << endl;
    }*/
}

void Aviao::listagemCompletaVoo() {
    cout << endl;
    ifstream file("voo.txt");
    string line;
    cout << "Conteudo do ficheiro de voos:" << endl;
    cout << endl;
    while (getline(file, line)){
        cout << line << endl;
    }
}

void Aviao::listagemIncompletaVoo() {
    cout << endl << endl;
    cout << "Escolha uma opcao para visualizar os voos:" << endl;
    cout << endl;
    cout << "1) " << "Visualizar voos com data de partida especificada." << endl;
    cout << "2) " << "Visualizar voos com uma determinada origem e destino." << endl;
    cout << "3) " << "Visualizar voos que ainda tenham bilhetes disponiveis." << endl; //???
    cout << ">";
    int escolha;
    cin >> escolha;
    ifstream file("voo.txt");
    string line;
    if(escolha == 1) {
        cout << "Defina a data de partida do voo: " << endl;
        int dia, mes, ano;
        string data;
        cin >> data;
        dia = stoi(data.substr(0, 2));
        mes = stoi(data.substr(3, 2));
        ano = stoi(data.substr(6, 4));
        cout << endl;
        cout << "Voos disponiveis a partir dessa data: " << endl;
        cout << endl;
        bool flag1 = false;
        //um upgrade que podiamos dar a isto era ordenar os voos cronologicamente por datas!
        for (auto it = listVoos.begin(); it != listVoos.end(); it++) {
            if ((*it).getDataPartida().getAno() >= ano) {
                if ((*it).getDataPartida().getMes() >= mes) {
                    if ((*it).getDataPartida().getDia() >= dia) {
                        flag1 = true;
                        cout << (*it).getNumVoo() << ',' << (*it).getDataPartida().getDia() << "/"
                             << (*it).getDataPartida().getMes() << "/" << (*it).getDataPartida().getAno()
                             << ',' << (*it).getDuracao() << ',' << (*it).getNumLugares() << ','
                             << (*it).getOrigem() << ',' << (*it).getDestino() << ',' << (*it).getMatriculaAaviao() << endl;
                    }
                }
            }
        }
        if (!flag1) cout << "---> Nao existem voos disponiveis :(" << endl;
        cout << endl << endl;
    }
    if(escolha == 2){
        cout << "Defina o local de origem: " << endl;
        cout << ">";
        string origem;
        cin >> origem;
        cout << "Defina o local de destino: " << endl;
        cout << ">";
        string destino;
        cin >> destino;
        bool flag2 = false;
        for (auto it = listVoos.begin(); it != listVoos.end(); it++){
            if((*it).getOrigem() == origem && (*it).getDestino() == destino){
                flag2 = true;
                cout << (*it).getNumVoo() << ',' << (*it).getDataPartida().getDia() << "/"
                     << (*it).getDataPartida().getMes() << "/" <<  (*it).getDataPartida().getAno()
                     << ',' << (*it).getDuracao() << ',' << (*it).getNumLugares() << ','
                     << (*it).getOrigem() << ',' << (*it).getDestino() << ',' << endl;
            }
        }
        if(!flag2) cout << "---> Nao existem voos disponiveis de " << origem << " para " << destino <<"." << endl;
        cout << endl << endl;
    }
    if (escolha == 3){
        cout << endl << endl;
        cout << "Voos com bilhetes disponiveis: " << endl;
        cout << endl;
        bool flag3 = false;
        for (auto it = listVoos.begin(); it != listVoos.end(); it++){
            if ((*it).getNumLugaresOcupados() != (*it).getVagas()){
                flag3 = true;
                cout << (*it).getNumVoo() << ',' << (*it).getDataPartida().getDia() << "/"
                     << (*it).getDataPartida().getMes() << "/" <<  (*it).getDataPartida().getAno()
                     << ',' << (*it).getDuracao() << ',' << (*it).getNumLugares() << ','
                     << (*it).getOrigem() << ',' << (*it).getDestino() << ',' << endl;
            }
        }
        if(!flag3) cout << "---> Nao existem voos com vagas disponiveis."  << endl;
        cout << endl << endl;
    }
    file.close();
}

//só implementei para a matricula e para a capacidade
void Aviao::AviaoInput() {
    cout << "Quantos avioes deseja adicionar? " << endl;
    cout << '>';
    int quant;
    cin >> quant;
    cout << endl;
    if (quant == 0) {cout << "Nao vai ser adicionado nenhum Aviao." << endl;}
    if (quant == 1) {cout << "Vamos adicionar um novo Aviao." << endl;}
    if (quant > 1){cout << "Vamos adicionar " << quant << " novos Avioes." << endl; }
    cout << endl;
    while(quant != 0){
        cout << "Insira a matricula do Aviao: " << endl;
        cout << '>';
        string matricula;
        cin >> matricula;
        cout << "Insira a capacidade do Aviao: " <<  endl;
        cout << '>';
        int capacidade;
        cin >> capacidade;
        Aviao a = Aviao(matricula, capacidade);
        listAviao.push_back(a); //ver onde anda a listaVoo que ando a confundir com esta
        cout << endl;
        quant--;
        if(quant != 0) {
            cout << "(Proximo Aviao)";
            cout << endl;
        }
    }
}

void Aviao::WriteAviao() {
    ofstream file;
    file.open("aviao.txt");
    //list<Voo> tmp = listaVoo;
    for (auto it = listAviao.begin(); it != listAviao.end(); it++){
        file << (*it).getMatricula() << ','<< (*it).getCapacidade() << ',';
        if (next(it) == listAviao.end()) continue;
        else file << endl;
    }
    file.close();
}

void Aviao::ReadAviao() {
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
                if (line.substr(0,1) == "\n") line.erase(0,1);
                a.matricula = line;
                break;
            case(1):
                capacidade = stoi(line);
                a.capacidade = capacidade;
                listAviao.push_back(a);
                i = -1;
                break;
        }
        i++;
    }
    file.close();
}

void Aviao::listagemCompletaAviao() {
    cout << endl;
    ifstream file("aviao.txt");
    string line;
    cout << "Conteudo do ficheiro de avioes:" << endl;
    cout << endl;
    while (getline(file, line)){
        cout << line << endl;
    }
}

void Aviao::listagemIncompletaAviao() {
    cout << endl << endl;
    cout << "Escolha uma opcao para visualizar os avioes:" << endl;
    cout << endl;
    cout << "1) " << "Visualizar avioes ordenados por capacidade." << endl;
    cout << "2) " << "Visualizar avioes com capacidade superior a <?>." << endl;
    //cout << "3) " << "Visualizar voos que ainda tenham bilhetes disponiveis." << endl; //???
    cout << ">";
    int escolha;
    cin >> escolha;
    ifstream file("aviao.txt");
    string line;
    if(escolha == 1) {
        bool flag = false;
        vector<Aviao> aux;
        for (auto it = listAviao.begin(); it != listAviao.end(); it++) {
            aux.push_back(*it);
        }
        for (auto it = aux.begin(); it != aux.end(); it++) {
            //Selection Sort
            if (aux.size() > 1) {
                for (int i = 0; i < aux.size(); i++) {
                    for (unsigned i = 0; i < aux.size() - 1; i++) {
                        unsigned imin = i;
                        for (int j = i + 1; j < aux.size(); j++) {
                            if (aux[j].getCapacidade() < aux[imin].getCapacidade()) {
                                imin = j;
                            }
                            swap(aux[i], aux[imin]);
                        }
                    }
                }
            }
        }
        for (auto it = aux.begin(); it != aux.end(); it++){
            flag = true;
            cout << (*it).getMatricula() << ',' << (*it).getCapacidade() << ',' << endl;
        }
        if(!flag) cout << "---> Nao existem avioes." << endl;
        cout << endl << endl;
    }
    if(escolha == 2){
        cout << "Defina a capacidade minima: " << endl;
        cout << ">";
        int capacidade;
        cin >> capacidade;
        bool flag2 = false;
        for (auto it = listAviao.begin(); it != listAviao.end(); it++){
            if((*it).getCapacidade() > capacidade){
                flag2 = true;
                cout << (*it).getMatricula() << ',' << (*it).getCapacidade() << ',' << endl;
            }
        }
        if(!flag2) cout << "---> Nao existem voos disponiveis com capacidade superior a " << capacidade << '.' << endl;
        cout << endl << endl;
    }

    file.close();
}

