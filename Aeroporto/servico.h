#ifndef PROJETO1_SERVICO_H
#define PROJETO1_SERVICO_H
#include "Data.h"
#include <queue>
#include "aviao.h"

using namespace std;

class servico{
private:
    string tiposervico; //'m' = manutenção && 'l' = limpeza
    Data data;
    string nomeFuncionario;
    string matriculaAviao;
public:
    servico();
    servico(char tiposervico, Data data, string nomeFuncionario, string matriculaAviao);
    string getTipoServico() const;
    void setTipoServico(string tiposervico);
    Data getData() const;
    void setData(Data data);
    string getNomeFuncionario() const;
    void setNomeFuncionario(string nomeFuncionario);
    string getMatriculaAviao() const;
    void setMatriculaAviao(string matriculaAviao);
    //void setServicosPorFazer(queue<servico> servicosFeitos);
    //queue<servico> getServicosPorFazer() const;
    //void setServicosFeitos(queue<servico> servicosFeitos);
    //queue<servico> getServicosFeitos() const;
    bool operator == (const servico & s) const;
    static bool MenorQueDataAtual(Data data);
    void WriteServico();
    void ServicoInput();
    void ReadServico();
    void ListagemServicos();
    void ListagemParcialServicos();

    void ApagarServicos();
};

static queue<servico> servicosFeitos;
static queue<servico> servicosPorFazer;
#endif //PROJETO1_SERVICO_H
