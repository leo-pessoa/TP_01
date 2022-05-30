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
    void set(std::string _nome, double _valor, Mao _mao);
    bool mesmoJogador(std::string _nome);

private:
    std::string nome;
    double valor;
    Mao mao;
};

#endif