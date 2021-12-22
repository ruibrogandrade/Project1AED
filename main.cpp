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
    cout << endl;
    cout << "-----------MENU-------------" << endl;
    cout << "1) Criar dados novos" << endl;
    cout << "2) Ler Estruturas de Dados" << endl;
    cout << "3) Apagar dados" << endl;
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
    }
    if(tipoDeDados == "Aviao") {
        a.AviaoInput();
        a.WriteAviao();
        a.listagemCompletaAviao();
    }
    if(tipoDeDados == "Bagagem") {
        g.TapeteInput();
        g.colocarMalas(); //prof pfv acrescente isto no seu codigo :D
        g.WriteTapete();
        g.ListagemTotal();
    }
    if(tipoDeDados == "Passageiro"){
        p.BilheteInput();
        p.WriteBilhete();
        p.listagemCompleta();
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
        }
        if (check == "Parcial") {
            s.ListagemParcialServicos();
        }
    }
    if(tipoDeDados == "Aviao") {
        cout << "Total ou Parcial?" << endl;
        cout << '>';
        cin >> check;
        cout << endl;
        if (check == "Total") {
            a.listagemCompletaAviao();
        }
        if (check == "Parcial") {
            a.listagemIncompletaAviao();
        }
    }
    if(tipoDeDados == "Bagagem") {
        cout << "Total ou Parcial?" << endl;
        cout << '>';
        cin >> check;
        cout << endl;
        if (check == "Total") {
            g.ListagemTotal();
        }
        if (check == "Parcial") {
            g.colocarMalas();
            g.ListagemParcial();
        }
    }
    if(tipoDeDados == "Passageiro"){
        cout << "Total ou Parcial?" << endl;
        cout << '>';
        cin >> check;
        cout << endl;
        if (check == "Total") {
            p.listagemCompleta();
        }
        if (check == "Parcial") {
            p.listagemIncompleta();
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
    if (tipo == "Servico") {
        s.ApagarServicos();
        s.WriteServico();
    }
    if (tipo == "Aviao"){
        a.deleteAviao();
        a.WriteAviao();
    }
    if (tipo == "Bagagem") {
        g.colocarMalas();
        g.deleteBagagens();
        g.WriteTapete();
    }
    if (tipo == "Passageiro") {
        p.ApagarPassageiro();
        p.WriteBilhete();
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
    }
    return 0;
}

