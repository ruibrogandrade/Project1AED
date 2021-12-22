#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Aeroporto/servico.h"
#include "Aeroporto/Data.h"
#include "Aeroporto/passageiros.h"
#include "Aeroporto/bagagem.h"

using namespace std;
void ReadFiles() {
    servico s;
    s.ReadServico();
    Aviao a;
    a.ReadAviao();
    a.ReadVoo();
    GestaoBagagens g;
    g.ReadTapete();
    Passageiro p;
    p.ReadBilhete();
}

int MenuInicial() {
    int resposta;
    cout << endl << endl;
    cout << "-----------MENU-------------" << endl;
    cout << "1) Criar dados novos" << endl;
    cout << "2) Ler Estruturas de Dados" << endl;
    cout << "3) Apagar dados" << endl;
    cout << "0) exit" << endl;
    cout << '>';
    cin >> resposta;
    cout << endl;
    return resposta;
}

void CriarDadosNovos() {
    servico s;
    Aviao a;
    GestaoBagagens g;
    Passageiro p;
    string tipoDeDados;
    cout << "Que tipo de Dados e que deseja criar?" << endl;
    cin >> tipoDeDados;
    if(tipoDeDados == "Servico") {
        s.ServicoInput();
        s.WriteServico();
        s.ListagemServicos();
        MenuInicial();
    }
    if(tipoDeDados == "Aviao") {
        a.AviaoInput();
        a.WriteAviao();
        a.listagemCompletaAviao();
        MenuInicial();
    }
    if(tipoDeDados == "Bagagem") {
        g.TapeteInput();
        g.WriteTapete();
        g.ListagemTotal();
        MenuInicial();
    }
    if(tipoDeDados == "Passageiro"){
        p.BilheteInput();
        p.WriteBilhete();
        p.listagemCompleta();
        MenuInicial();
    }
}

void LerDados() {
    servico s;
    Aviao a;
    GestaoBagagens g;
    Passageiro p;
    string check;
    string tipoDeDados;
    cout << "Que tipo de Dados e que deseja ler?" << endl;
    cin >> tipoDeDados;
    if(tipoDeDados == "Servico") {
        cout << "Total ou Parcial?";
        cin >> check;
        if (check == "Total") {
            s.ListagemServicos();
            MenuInicial();
        }
        if (check == "Parcial") {
            s.ListagemParcialServicos();
            MenuInicial();
        }
    }
    if(tipoDeDados == "Aviao") {
        cout << "Total ou Parcial?";
        cin >> check;
        if (check == "Total") {
            a.listagemCompletaAviao();
            MenuInicial();
        }
        if (check == "Parcial") {
            a.listagemIncompletaAviao();
            MenuInicial();
        }
    }
    if(tipoDeDados == "Bagagem") {
        cout << "Total ou Parcial?";
        cin >> check;
        if (check == "Total") {
            g.ListagemTotal();
            MenuInicial();
        }
        if (check == "Parcial") {
            g.colocarMalas();
            g.ListagemParcial();
            MenuInicial();
        }
    }
    if(tipoDeDados == "Passageiro"){
        cout << "Total ou Parcial?";
        cin >> check;
        if (check == "Total") {
            p.listagemCompleta();
            MenuInicial();
        }
        if (check == "Parcial") {
            p.listagemIncompleta();
            MenuInicial();
        }
    }
}

void ApagarDados() {
    servico s;
    Aviao a;
    GestaoBagagens g;
    Passageiro p;
    string tipo;
    cout << "Que Tipo de Dados deseja Apagar?" << endl;
    cin >> tipo;
    if (tipo == "Servico") {
        s.ApagarServicos();
        s.WriteServico();
        MenuInicial();
    }
    if (tipo == "Aviao"){
        a.deleteAviao();
        a.WriteAviao();
        MenuInicial();
    }
    if (tipo == "Bagagem") {
        g.colocarMalas();
        g.deleteBagagens();
        g.WriteTapete();
        MenuInicial();
    }
    if (tipo == "Passageiro") {
        p.ApagarPassageiro();
        p.WriteBilhete();
        MenuInicial();
    }
}


int main() {
    ReadFiles();

    int opcao;
    opcao = MenuInicial();
    switch(opcao) {
        case(1):
            CriarDadosNovos();
            break;
        case(2):
            LerDados();
            break;
        case(3):
            ApagarDados();
            break;
        case(0):
            exit(0);
    }
    return 0;
}

