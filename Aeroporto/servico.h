#ifndef PROJETO1_SERVICO_H
#define PROJETO1_SERVICO_H

#include "Data.h"

using namespace std;

class servico{
private:
    char tiposervico; //'m' = manutenção && 'l' = limpeza
    Data data;
    string nomeFuncionario;

public:
    servico(){};
    servico(char tiposervico, Data data, string nomeFuncionario);
    char getTipoServico() const;
    void setTipoServico(char tiposervico);
    Data getData() const;
    void setData(Data data);
    string getNomeFuncionario() const;
    void setNomeFuncionario(string nomeFuncionario);
    bool operator == (const servico & s) const;
    static bool MenorQueDataAtual(Data data);
    static void WriteServico();
    static void ServicoInput();
    static void ReadServico();
};

#endif //PROJETO1_SERVICO_H
