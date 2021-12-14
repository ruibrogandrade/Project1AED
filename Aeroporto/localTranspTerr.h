#ifndef PROJETO1_LOCALTRANSPTERR_H
#define PROJETO1_LOCALTRANSPTERR_H

#include <vector>
#include <string>

using namespace std;

class localTranspTerr {
    string tipoTransp;
    vector<int> horario;
    int distancia;
public:
    localTranspTerr(string tipoTransp, vector<int> horario, int distancia);


};


#endif //PROJETO1_LOCALTRANSPTERR_H
class WordMean {
    string word;
    string meaning;
public:
    WordMean(string w, string m);
    string getWord() const;
    string getMeaning() const;
    void setMeaning(string m);
    void setWord(string w);
    bool operator < (const WordMean & w) const {
        return word < w.word; }
    bool operator == (const WordMean & w) const {
        return word == w.word; }
};