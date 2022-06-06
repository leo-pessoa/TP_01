#ifndef RODADA
#define RODADA
#include "Mao.h"
#include "Jogador.h"

class Rodada
{
public:
 Rodada();
 void setRodada(Jogador *jogadores, int n_jodadores);
 std::string getWinners(int n);
 // bool desempata(Jogador j1, Jogador j2);
 Jogador jogadores[8];
};

#endif