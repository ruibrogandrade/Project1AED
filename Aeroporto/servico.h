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
    string matriculaAviao;
    queue<servico> servicosFeitos;
    queue<servico> servicosPorFazer;
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
    void setServicosPorFazer(queue<servico> servicosFeitos);
    queue<servico> getServicosPorFazer() const;
    void setServicosFeitos(queue<servico> servicosFeitos);
    queue<servico> getServicosFeitos() const;
    bool operator == (const servico & s) const;
    static bool MenorQueDataAtual(Data data);
    void WriteServico();
    void ServicoInput();
    void ReadServico();
    list<Aviao>::std::iterator findAviao(list<Aviao> listAviao, string matriculaAviao);
};

#endif //PROJETO1_SERVICO_H
