#ifndef PROJETO1AED_AEROPORTO_H
#define PROJETO1AED_AEROPORTO_H
#include "aviao.h"
#include <list>



class Aeroporto {
private:
    static list<Aviao> listAviao;
public:
    void addAviao(Aviao a){
        listAviao.push_back(a);
    };
    //void AviaoInput();
    void WriteAviao();
    void ReadAviao();

};


#endif //PROJETO1AED_AEROPORTO_H
