#ifndef PROJETO1_DATA_H
#define PROJETO1_DATA_H


class Data{
private:
    int ano, mes, dia;
public:
    Data();
    Data(int ano, int mes, int dia);
    int getDia();
    void setDia(int dia);
    int getMes();
    void setMes(int mes);
    int getAno();
    void setAno(int ano);
    bool compararMenor(Data d, Data d2) const;
    bool operator <(Data d) const;
    bool operator == (Data d) const;

};


#endif //PROJETO1_DATA_H
