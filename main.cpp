#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Aeroporto/servico.h"
#include "Aeroporto/passageiros.h"
#include "Aeroporto/Data.h"
#include "Aeroporto/aviao.h"
#include "Aeroporto/bagagem.h"
#include "Aeroporto/transpTerr.h"
#include "Aeroporto/bst.h"

using namespace std;

void readFiles(){

}

int main(){
    /*Aviao a;
    a.ReadAviao();
    Voo v;
    Passageiro p;
    p.ReadBilhete();
    GestaoBagagens g;
    g.ReadTapete();
*///se comentar as 2 linhas seguintes, não há erros
    OpcoesTransporte o;
    o.readFile();

    return 0;
}