#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Aeroporto/servico.h"
#include "Aeroporto/Data.h"
#include "Aeroporto/passageiros.h"
#include "Aeroporto/bagagem.h"

using namespace std;

int main();

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
    cout << '>';
    cin >> tipoDeDados;
    cout << endl;
    if(tipoDeDados == "Servico") {
        s.ServicoInput();
        s.WriteServico();
        s.ListagemServicos();
        main();
    }
    if(tipoDeDados == "Aviao") {
        a.AviaoInput();
        a.WriteAviao();
        a.listagemCompletaAviao();
        main();
    }
    if(tipoDeDados == "Bagagem") {
        g.TapeteInput();
        g.WriteTapete();
        g.ListagemTotal();
        main();
    }
    if(tipoDeDados == "Passageiro"){
        p.BilheteInput();
        p.WriteBilhete();
        p.listagemCompleta();
        main();
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
    cout << '>';
    cin >> tipoDeDados;
    cout << endl;
    if(tipoDeDados == "Servico") {
        cout << "Total ou Parcial?";
        cout << '>';
        cin >> check;
        cout << endl;
        if (check == "Total") {
            s.ListagemServicos();
            main();
        }
        if (check == "Parcial") {
            s.ListagemParcialServicos();
            main();
        }
    }
    if(tipoDeDados == "Aviao") {
        cout << "Total ou Parcial?";
        cout << '>';
        cin >> check;
        cout << endl;
        if (check == "Total") {
            a.listagemCompletaAviao();
            main();
        }
        if (check == "Parcial") {
            a.listagemIncompletaAviao();
            main();
        }
    }
    if(tipoDeDados == "Bagagem") {
        cout << "Total ou Parcial?";
        cout << '>';
        cin >> check;
        cout << endl;
        if (check == "Total") {
            g.ListagemTotal();
            main();
        }
        if (check == "Parcial") {
            g.colocarMalas();
            g.ListagemParcial();
            main();
        }
    }
    if(tipoDeDados == "Passageiro"){
        cout << "Total ou Parcial?";
        cout << '>';
        cin >> check;
        cout << endl;
        if (check == "Total") {
            p.listagemCompleta();
            main();
        }
        if (check == "Parcial") {
            p.listagemIncompleta();
            main();
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
    cout << '>';
    cin >> tipo;
    cout << endl;
    if (tipo == "Servico") {
        s.ApagarServicos();
        s.WriteServico();
        main();
    }
    if (tipo == "Aviao"){
        a.deleteAviao();
        a.WriteAviao();
        main();
    }
    if (tipo == "Bagagem") {
        g.colocarMalas();
        g.deleteBagagens();
        g.WriteTapete();
        main();
    }
    if (tipo == "Passageiro") {
        p.ApagarPassageiro();
        p.WriteBilhete();
        main();
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

