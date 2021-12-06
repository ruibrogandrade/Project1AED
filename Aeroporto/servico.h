#ifndef PROJETO1_SERVICO_H
#define PROJETO1_SERVICO_H

using namespace std;

class servico{
private:
    char tiposervico; //'m' = manutenção && 'l' = limpeza
    int data;
    string nomeFuncionario;
    bool feito;

public:
    servico(char tiposervico, int data, string nomeFuncionario, bool feito);
    char getTipoServico();
    void setTipoServico();
    int getData();
    void setData();
    string getNomeFuncionario();
    void setNomeFuncionario();
    bool getFeito();
    void setFeito();
    bool operator == (const servico & s) const;
};

#endif //PROJETO1_SERVICO_H
