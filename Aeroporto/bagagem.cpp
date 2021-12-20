#include <iostream>
#include <fstream>
#include <sstream>
#include "bagagem.h"

using namespace std;

Bagagem::Bagagem(int nb, float p) : numBilhete(nb), peso(p) {}

int Bagagem::getNumBilhete() const {
    return this-> numBilhete;
}

float Bagagem::getPeso() const {
    return peso;
}
//------------------------------------------------------------------------------------------------------------------------------

GestaoBagagens::GestaoBagagens(){}

GestaoBagagens::GestaoBagagens(unsigned int c, unsigned int n, unsigned int m) : numCarruagens(c), numPilhas(n), numMalas(m) {}

void GestaoBagagens::colocarMalas(){

    ReadTapete();

    stack<Bagagem> pilhaBagagemVazia;
    Bagagem bagagemVazia;
    static int i = 0;
    for(int i = 0; i < numCarruagens; i++) {
        list<stack<Bagagem>> novaCarruagemVazia;
        for(int j = 0; j < numPilhas; j++) {
            novaCarruagemVazia.push_back(pilhaBagagemVazia);
            for(int k = 0; k < numMalas; k++) {
                pilhaBagagemVazia.push(bagagemVazia);
            }
        }
        carrinho.push_back(novaCarruagemVazia);
    }
    while (!tapeteInserir.empty()) {
        for (auto it = carrinho.begin(); it != carrinho.end(); it++) {
            for (auto et = (*it).begin(); et != (*it).end(); et++) {
                stack<Bagagem> st;
                while (st.size() < numMalas) {
                    if (tapeteInserir.empty()) break;
                    Bagagem b = tapeteInserir.front();
                    //cout << tapeteInserir.front().getNumBilhete() << endl;
                    st.push(b);
                    tapeteInserir.pop(); //pop deleta o front
                }
                (*et) = st;
            }
        }
        if (i == carrinho.size() - 1) break; //se o carrinho estiver cheio -> termina
    }   // a inserção de bagagem!


    cout << endl;
    list<list<stack<Bagagem>>> tmp = carrinho;
    string flag = "green";
    for (auto it = tmp.begin(); it != tmp.end(); it++) {
        for (auto et = (*it).begin(); et != (*it).end(); et++){
            if (tmp.empty()) flag = "red";
            while ((flag == "green")){
                cout << (*et).top().getNumBilhete() << ',' << (*et).top().getPeso() << ',' << endl;
                (*et).pop();
            }
        }
    }

}

void GestaoBagagens::retirarMalas(){
    Bagagem b;
    for (auto it = carrinho.begin(); it != carrinho.end(); it++){
        for(auto et = (*it).begin(); et != (*it).end(); et++){
            b = (*et).top();
            (*et).pop();
            tapeteRetirar.push(b);
        }
    }
}

void GestaoBagagens::TapeteInput() {
    cout << endl;
    cout << "Quantas bagagens deseja adicionar? " << endl;
    cout << '>';
    int quant;
    cin >> quant;
    cout << endl;
    if (quant == 0) {cout << "Nao vai ser adicionada nenhuma Bagagem ao tapete." << endl;}
    if (quant == 1) {cout << "Vamos adicionar uma nova Bagagem ao tapete." << endl;}
    if (quant > 1){cout << "Vamos adicionar " << quant << " novas Bagagens ao tapete." << endl; }
    cout << endl;
    while(quant != 0){
        cout << "Insira o numero do bilhete que esta associado a bagagem: " << endl;
        cout << '>';
        int nrBilhete;
        cin >> nrBilhete;
        cout << "Insira a o peso da bagagem: " <<  endl;
        cout << '>';
        float peso;
        cin >> peso;

        Bagagem b = Bagagem(nrBilhete, peso);
        tapeteInserir.push(b);
        cout << endl;
        quant--;
        if(quant != 0) {
            cout << "(Proxima Bagagem)";
            cout << endl;
        }
    }
    /*
    queue<Bagagem> tmp = tapeteInserir;
    while (!tmp.empty()) {
        cout << tmp.front().getNumBilhete() << ',' << tmp.front().getPeso() << endl;
        tmp.pop();
    }
     */
}

void GestaoBagagens::WriteTapete(){
    ofstream file;
    file.open("tapete.txt");
    while (!tapeteInserir.empty()){
        file << tapeteInserir.front().getNumBilhete() << ',' << tapeteInserir.front().getPeso() << ',';
        if (tapeteInserir.size() != 1) file << endl;
        tapeteInserir.pop();
    }
    file.close();
}

void GestaoBagagens::ReadTapete() {
    int nrBilh;
    float pes;
    ifstream file("tapete.txt");
    string line;
    Bagagem b;
    int i = 0;
    while (getline(file, line, ',')){
        switch (i) {
            case (0):
                nrBilh = stoi(line);
                b.setNumBilhete(nrBilh);
                break;
            case(1):
                pes = stof(line);
                b.setPeso(pes);
                tapeteInserir.push(b);
                i = -1;
                break;
        }
        i++;
    }
    file.close();
    /*
    queue<Bagagem> tmp = tapeteInserir;
    while (!tmp.empty()){
        cout << tmp.front().getNumBilhete() << ',' << tmp.front().getPeso() << endl;
        tmp.pop();
    }*/
}

void GestaoBagagens::definirCarrinho() {
    cout << endl;
    cout << "Vamos definir o tamanho do carrinho de bagagens." << endl;
    cout << endl;
    cout << "Insira o numero de carruagens do carrinho: " << endl;
    cout << '>';
    int numCarruagens;
    cin >> numCarruagens;
    this->numCarruagens = numCarruagens;
    cout << "Insira o numero de pilhas de malas por carruagem do carrinho: " << endl;
    cout << '>';
    int numPilhas;
    cin >> numPilhas;
    this->numPilhas = numPilhas;
    cout << "Insira o numero de malas que uma pilha do carrinho e capaz de suportar: " << endl;
    cout << '>';
    int numMalas;
    cin >> numMalas;
    this->numMalas = numMalas;
}







