#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Aeroporto/servico.h"
#include "Aeroporto/passageiros.h"
#include "Aeroporto/Data.h"
#include "Aeroporto/aviao.h"
#include "Aeroporto/bagagem.h"

using namespace std;

void readFiles(){

}

int main(){
    Aviao a;
    a.ReadAviao();
    Voo v;
    Passageiro p;
    p.ReadBilhete();
    GestaoBagagens bg;
    bg.ReadTapete();
    return 0;
}