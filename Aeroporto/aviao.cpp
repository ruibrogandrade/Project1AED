#include <fstream>
#include <sstream>
#include "aviao.h"

using namespace std;



Aviao::Aviao() {
    //não sei se faz sentido criar um Aviao vazio (?)
}

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
        (*it).getNumLugares() << ',' << (*it).getOrigem() << ',' << (*it).getDestino() << ',';
        if (next(it) == listVoos.end()) continue;
        else file << endl;
    }
    file.close();
}

void Aviao::VooInput() {
    cout << "Quantos voos deseja adicionar? ";
    cout << endl;
    int quant;
    cin >> quant;
    if (quant == 0) {cout << "Nao vai ser adicionado nenhum Voo." << endl;}
    if (quant == 1) {cout << "Vamos adicionar um novo Voo." << endl;}
    if (quant > 1){cout << "Vamos adicionar " << quant << " novos Voo." << endl; }
    cout << endl;
    while(quant != 0){
        cout << "Insira o nr de Voo: ";
        int nrVoo;
        cin >> nrVoo;
        cout << "Insira a data de partida do voo no formato DD/MM/AAAA: " <<  endl;
        string data;
        cin >> data;
        Data d;
        d.setDia(stoi(data.substr(0,2)));
        d.setMes(stoi(data.substr(3,2)));
        d.setAno(stoi(data.substr(6,4)));
        cout << "Insira a duracao do Voo: " <<  endl;
        int duracao;
        cin >> duracao;
        cout << "Insira a lotacao do Voo: " <<  endl;
        int lotacao;
        cin >> lotacao;
        cout << "Insira o local de origem: " <<  endl;
        string origem;
        cin >> origem;
        cout << "Insira o local de destino: " <<  endl;
        string destino;
        cin >> destino;
        Voo v = Voo(nrVoo,d,duracao,lotacao,origem,destino);
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
    string line;
    Voo v;
    int numVoo;
    Voo tmp;
    Data dataDePartida;
    int duracao;
    int dia;
    int mes;
    int ano;
    int lot;
    string origem;
    string destino;
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
                lot = stoi(line); //por vagas tbm que ele nao faz a ligação
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

void Aviao::listagemCompletaVoos() {
    cout << endl;
    ifstream file("voo.txt");
    string line;
    cout << "Conteudo do ficheiro de voos:" << endl;
    cout << endl;
    while (getline(file, line)){
        cout << line << endl;
    }
}

void Aviao::listagemIncompleta() {
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
                             << (*it).getOrigem() << ',' << (*it).getDestino() << ',' << endl;
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
    //valores para testar
    listAviao.emplace_back("37-FP-45", 1500);
    listAviao.push_back(Aviao("81-TM-05", 1250));
}

void Aviao::WriteAviao() {
    ofstream file;
    file.open("");
    //list<Voo> tmp = listaVoo;
    for (auto it = listAviao.begin(); it != listAviao.end(); it++){
        file << (*it).getMatricula() << ','<< (*it).getCapacidade() << endl;
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