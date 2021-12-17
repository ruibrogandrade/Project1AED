#ifndef PROJETO1_SERVICO_H
#define PROJETO1_SERVICO_H
#include "Data.h"
#include <queue>
#include "aviao.h"

using namespace std;

class servico{
private:
    char tiposervico; //'m' = manutenção && 'l' = limpeza
    Data data;
    string nomeFuncionario;
    queue<servico> servicosPorFazer;
    queue<servico> servicosFeitos;
    string matriculaAviao;
public:
    servico();
    servico(char tiposervico, Data data, string nomeFuncionario);
    char getTipoServico() const;
    void setTipoServico(char tiposervico);
    Data getData() const;
    void setData(Data data);
    string getNomeFuncionario() const;
    void setNomeFuncionario(string nomeFuncionario);
    string getMatriculaAviao() const;
    void setMatriculaAviao(string matriculaAviao);
    bool operator == (const servico & s) const;
    static bool MenorQueDataAtual(Data data);
    static void WriteServico(queue<servico> servicosPorFazer, queue<servico> servicosFeitos);
    static void ServicoInput(queue<servico> servicosPorFazer, queue<servico> servicosFeitos);
    static void ReadServico(queue<servico> servicosPorFazer, queue<servico> servicosFeitos);
    list<Aviao>::std::iterator findAviao(list<Aviao> listAviao, string matriculaAviao);
};

#endif //PROJETO1_SERVICO_H
