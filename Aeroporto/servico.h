#ifndef PROJETO1_Servico_H
#define PROJETO1_Servico_H
#include "Data.h"
#include <queue>
#include "aviao.h"

using namespace std;

class Servico{
private:
    char tipoServico; //'m' = manutenção && 'l' = limpeza
    Data data;
    string nomeFuncionario;
    string matriculaAviao;
public:
    Servico();
    Servico(char tipoServico, Data data, string nomeFuncionario, string matriculaAviao);
    char getTipoServico() const;
    void setTipoServico(char tipoServico);
    Data getData() const;
    void setData(Data data);
    string getNomeFuncionario() const;
    void setNomeFuncionario(string nomeFuncionario);
    string getMatriculaAviao() const;
    void setMatriculaAviao(string matriculaAviao);
    //void setServicosPorFazer(queue<Servico> ServicosFeitos);
    //queue<Servico> getServicosPorFazer() const;
    //void setServicosFeitos(queue<Servico> ServicosFeitos);
    //queue<Servico> getServicosFeitos() const;
    bool operator == (const Servico & s) const;
    static bool MenorQueDataAtual(Data data);
    void WriteServico();
    void ServicoInput();
    void ReadServico();
    void ListagemServicos();
    void ListagemParcialServicos();
};

static queue<Servico> servicosFeitos;
static queue<Servico> servicosPorFazer;

#endif //PROJETO1_Servico_H
