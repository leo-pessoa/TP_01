#ifndef JOGADOR
#define JOGADOR
#include "Mao.h"

class Jogador
{
public:
    Jogador();
    Jogador(std::string _nome, double _valor, Mao _mao);
    std::string getNome();
    double getValor();
    void setValor(int _valor);
    void setMao(Mao mao);
    bool mesmoJogador(std::string _nome);
    void orderMao(Mao _mao);
    Mao getMao();
    bool desempata(Jogador jog1, Jogador jog2);
private:
    std::string nome;
    double valor;
    Mao mao;
};

#endif