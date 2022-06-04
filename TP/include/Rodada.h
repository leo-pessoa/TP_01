#ifndef RODADA
#define RODADA
#include "Mao.h"
#include "Jogador.h"

class Rodada
{
public:
 Rodada();
 Rodada(Jogador * jogadores);
 Jogador getWinner(int n);
 bool desempata(Jogador j1, Jogador j2);
private:
 Jogador jogadores[8];
};

#endif