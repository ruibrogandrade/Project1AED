#ifndef PROJETO1_SERVICO_H
#define PROJETO1_SERVICO_H

#include "Data.h"

using namespace std;

class servico : public Data{
private:
    char tiposervico; //'m' = manutenção && 'l' = limpeza
    Data data;
    string nomeFuncionario;
    bool feito;

public:
    servico(char tiposervico, Data data, string nomeFuncionario, bool feito);
    char getTipoServico();
    void setTipoServico(char tiposervico);
    Data getData();
    void setData(Data data);
    string getNomeFuncionario();
    void setNomeFuncionario(string nomeFuncionario);
    bool getFeito();
    void setFeito(bool feito);
    bool operator == (const servico & s) const;
};

#endif //PROJETO1_SERVICO_H
