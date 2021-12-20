
#include "voo.h"

using namespace std;

/**
 * Construtor padrão de voo
 */

Voo::Voo() {}

/**
 * Construtor que cria um voo com os seus atributos
 * @param numVoo número que identifica um voo
 * @param dataPartida data de partida do voo
 * @param duracao duração do voo
 * @param lot lotação do voo
 * @param origem ponto de partida de um voo
 * @param destino ponto de chegada de um voo
 */

Voo::Voo(int numVoo, Data dataPartida, int duracao, int lot, string origem, string destino) {
    //ao fazermos assim o construtor de voo, estamos basicamente a incorporar o updater aqui dentro, não sei se está correto
    this->numVoo = numVoo;
    this->dataPartida = dataPartida;
    this->duracao = duracao;
    this->origem = origem;
    this->destino = destino;
    vagas = lot;
}

/**
 *Getter que retorna número do voo
 * @return número do voo
 */

int Voo::getNumVoo() const{
    return numVoo;
}

/**
 * Setter para o número do voo
 * @param numVoo
 */

void Voo::setNumVoo(int numVoo) {
    this->numVoo=numVoo;
}

/**
 * Getter para a data de partida do voo
 * @return data de Partida
 */

Data Voo::getDataPartida() const{
    return dataPartida;
}

/**
 *Setter para a data de partida
 * @param dataPartida
 */

void Voo::setDataPartida(Data dataPartida) {
    this->dataPartida=dataPartida;
}
/**
 * Getter de duração do voo
 * @return duração
 */

int Voo::getDuracao() const{
    return duracao;
}

/**
 * Setter para a duração do voo
 * @param duracao
 */

void Voo::setDuracao(int duracao) {
    this->duracao=duracao;
}

/**
 *Getter para o número de lugares do voo
 * @return lotação
 */

int Voo::getNumLugares() const{
    return lotacao;
}

/**
 *Setter para o número de lugares do voo
 * @param lotacao
 */

void Voo::setNumLugares(int lotacao) {
    this->lotacao=lotacao;
}

/**
 *Getter para número de lugares ocupados
 * @return lugares ocupados
 */

int Voo::getNumLugaresOcupados() const {
    return lotacao - vagas;
}

/**
 *Getter para vagas livres no voo
 * @return
 */

int Voo::getVagas() const{
    return vagas;
}

/**
 * Setter para vagas livres do voo
 * @param vagas
 */

void Voo::setVagas(int vagas) {
    this->vagas=vagas;
}

/**
 * Getter da origem do voo
 * @return origem
 */

string Voo::getOrigem() const{
    return origem;
}

/**
 *Setter para a origem do voo
 * @param origem
 */

void Voo::setOrigem(string origem) {
    this->origem=origem;
}

/**
 * Getter para o destino do voo
 * @return destino do voo
 */

string Voo::getDestino() const{
    return destino;
}

/**
 *Setter para o destino do voo
 * @param destino
 */

void Voo::setDestino(string destino) {
    this->destino=destino;
}

/*
 void Servico::WriteServico() {
    queue<Servico> servicosPorFazer = getServicosPorFazer();
    queue<Servico> servicosFeitos = getServicosFeitos();
    ofstream file;
    file.open("servicos.txt");
    queue<Servico> tmp1 = servicosFeitos;
    queue<Servico> tmp2 = servicosPorFazer;
    for(int i = 0; i < servicosFeitos.size();i++) {
        file << tmp1.front().getTipoServico() << ',' << tmp1.front().getData().getDia() << "/" << tmp1.front().getData().getMes() << "/"
             << tmp1.front().getData().getAno() << "," << tmp1.front().getMatriculaAviao() <<  "," << tmp1.front().getNomeFuncionario() << "," << endl;
        tmp1.pop();
    }
    for(int i = 0; i < servicosPorFazer.size();i++) {
        file << tmp2.front().getTipoServico() << ',' << tmp2.front().getData().getDia() << "/" << tmp2.front().getData().getMes() << "/"
             << tmp2.front().getData().getAno() << "," << tmp2.front().getMatriculaAviao() << "," << tmp2.front().getNomeFuncionario() << "," << endl;
        tmp2.pop();
    }
    file.close();
}

 */

void Voo::WriteVoo() {
    ofstream file;
    Voo tmp;
    file.open("voo.txt");
    file << tmp.getNumVoo() << ',' << tmp.getDataPartida().getDia() << '/' << tmp.getDataPartida().getMes() << "/"
    << tmp.getDataPartida().getAno() << ',' << tmp.getDuracao() << ',' << tmp.getNumLugares() << ',' << tmp.getOrigem() << ',' << tmp.getDestino() << ',';
    file.close();
}


void Voo::ReadVoo() {
    ifstream file("servicos.txt");
    string line;
    Voo v;
    int numVoo;
    Voo tmp;
    Data dataDePartida;
    int duracao;
    int dia;
    int mes;
    int ano;
    int lot;
    string origem;
    string destino;
    int i = 0;
    while(getline(file,line,',')) {
        switch(i) {
            case (0):
                numVoo = stoi(line);
                tmp.setNumVoo(numVoo);
                break;
            case (1):
                dia = stoi(line.substr(0, 2));
                mes = stoi(line.substr(3, 5));
                ano = stoi(line.substr(6, 10));
                dataDePartida.setDia(dia);
                dataDePartida.setMes(mes);
                dataDePartida.setAno(ano);
                tmp.setDataPartida(dataDePartida);
                break;
            case (2):
                duracao = stoi(line);
                tmp.setDuracao(duracao);
                break;
            case (3):
                lot = stoi(line);
                tmp.setVagas(lot);
                break;
            case (4):
                origem = stoi(line);
                tmp.setOrigem(origem);
                break;
            case (5):
                destino = stoi(line);
                tmp.setDestino(destino);
                break;
        } i++;
    }
}




