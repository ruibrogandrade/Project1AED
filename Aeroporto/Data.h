//
// Created by barba on 07/12/2021.
//

#ifndef PROJETO1_DATA_H
#define PROJETO1_DATA_H


class Data{
private:
    int ano, mes, dia;
public:
    Data();
    Data(int ano, int mes, int dia);
    int getDia();
    void setDia(int day);
    int getMes();
    void setMes(int mes);
    int getAno();
    void setAno(int ano);
    bool operator < (Data d) const;
    bool operator == (Data d) const;

};


#endif //PROJETO1_DATA_H
