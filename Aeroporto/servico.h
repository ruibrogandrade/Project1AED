#ifndef PROJETO1_SERVICO_H
#define PROJETO1_SERVICO_H

#include "Data.h"
#include "aviao.h"
#include <queue>
/*
using namespace std;

class Servico{
private:
    char tiposervico; //'m' = manutenção && 'l' = limpeza
    Data data;
    string nomeFuncionario;
    string matriculaAviao;
    queue<Servico> servicosPorFazer;
    queue<Servico> servicosFeitos;

public:
    Servico(){};
    Servico(char tiposervico, Data data, string nomeFuncionario, string matriculaAviao); //new
    char getTipoServico() const;
    void setTipoServico(char tiposervico);
    Data getData() const;
    void setData(Data data);
    string getNomeFuncionario() const;
    void setNomeFuncionario(string nomeFuncionario);
    string getMatriculaAviao() const; //new
    void setMatriculaAviao(string matriculaAviao); //new
    void setServicosPorFazer(queue<Servico> servicosFeitos); //new
    queue<Servico> getServicosPorFazer() const; //new
    void setServicosFeitos(queue<Servico> servicosFeitos); //new
    queue<Servico> getServicosFeitos() const; //new
    bool operator == (const Servico & s) const;
    static bool MenorQueDataAtual(Data data);
    static void WriteServico();
    void ServicoInput();
    static void ReadServico();
    list<Aviao>::iterator findAviao(list<Aviao> listAviao, string matriculaAviao); //new
};
 */

#endif //PROJETO1_SERVICO_H
