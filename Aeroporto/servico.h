#ifndef PROJETO1_SERVICO_H
#define PROJETO1_SERVICO_H

using namespace std;

class servico{
private:
    char tiposervico; //'m' = manutenção && 'l' = limpeza
    string data;
    string nomeFuncionario;
    bool feito;

public:
    servico(char tiposervico, int data, string nomeFuncionario, bool feito);
    char getTipoServico();
    void setTipoServico(char tiposervico);
    int getData();
    void setData(string data);
    string getNomeFuncionario();
    void setNomeFuncionario(string nomeFuncionario);
    bool getFeito();
    void setFeito(bool feito);
    bool operator == (const servico & s) const;
};

#endif //PROJETO1_SERVICO_H
