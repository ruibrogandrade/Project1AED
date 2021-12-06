#ifndef PROJETO1_SERVICO_H
#define PROJETO1_SERVICO_H

class servico{
private:
    char tiposervico; //'m' = manutenção && 'l' = limpeza
    int data;
    string nomeFuncionario;
    bool feito;

public:
    servico(char tiposervico, int data, string nomeFuncionario, bool feito);
    bool operator == (const servico & s) const;
};

#endif //PROJETO1_SERVICO_H
