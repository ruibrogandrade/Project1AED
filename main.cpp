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
/*
void checkTipoDeData(queue<servico> servicosFeitos, queue<servico> servicosPorFazer) {
    servico s;
    string TipoDeDataClasse;
    cout << "What Type of Data do you want to Submit?" << endl;
    cin >> TipoDeDataClasse;
    if(TipoDeDataClasse == "Voo") {

    }
    if(TipoDeDataClasse == "Bagagem") {

    }
    if(TipoDeDataClasse == "Passageiro") {

    }
    if(TipoDeDataClasse == "Servico") {
        s.ServicoInput();
    }
}
*/

int MenuInicial() {
    int resposta;
    cout << "1) Criar dados novos" << endl;
    cout << "2) Ler Estruturas de Dados" << endl;
    cout << "3) Apagar dados" << endl;
    cin >> resposta;
    return resposta;
}

void CriarDadosNovos() {
    servico s;
    Aviao a;
    GestaoBagagens g;
    Passageiro p;
    string tipoDeDados;
    cout << "Que tipo de Dados é que deseja criar?" << endl;
    cin >> tipoDeDados;
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
    cout << "Que tipo de Dados é que deseja ler?" << endl;
    cin >> tipoDeDados;
    if(tipoDeDados == "Servico") {
        cout << "Total ou Parcial?";
        cin >> check;
        if (check == "Total") {
            s.ListagemServicos();
        }
        if (check == "Parcial") {
            s.ListagemParcialServicos();
        }
    }
    if(tipoDeDados == "Aviao") {
        cout << "Total ou Parcial?";
        cin >> check;
        if (check == "Total") {
            a.listagemCompletaAviao();
        }
        if (check == "Parcial") {
            a.listagemIncompletaAviao();
        }
    }
    if(tipoDeDados == "Bagagem") {
        cout << "Total ou Parcial?";
        cin >> check;
        if (check == "Total") {
            g.ListagemTotal();
        }
        if (check == "Parcial") {
            g.colocarMalas();
            g.ListagemParcial();
        }
    }
    if(tipoDeDados == "Passageiro"){
        cout << "Total ou Parcial?";
        cin >> check;
        if (check == "Total") {
            p.listagemCompleta();
        }
        if (check == "Parcial") {
            p.listagemIncompleta();
        }
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
    }
    return 0;
}

