#include <iostream>
#include <string>
#include "Jogador.h"
#include "Mao.h"
#include "Carta.h"
#include "Rodada.h"
using namespace std;

Rodada::Rodada()
{
}

void Rodada::setRodada(Jogador * _jogadores, int n_jogadores)
{
 for (int i = 0; i < n_jogadores; i++) {
  jogadores[i] = _jogadores[i];
 }
}

#define RSF 100000
#define SF 90000
#define FK 80000
#define FH 70000
#define F 60000
#define S 50000
#define TK 40000
#define TP 30000
#define OP 20000
#define HC 10000

std::string Rodada::getWinners(int n)
{

std::string vencedores = "";

  int i, j;
  for (i = 0; i < n - 1; i++){
    for (j = 0; j < n - i - 1; j++) {
      if (jogadores[j].getMao().tipoJogada() > jogadores[j + 1].getMao().tipoJogada()) {
        swap(jogadores[j], jogadores[j + 1]);
      }
    }
  }

  for (int i = n-1; i >= 0; i--) {
    if(jogadores[i].getMao().tipoJogada() == jogadores[n - 1].getMao().tipoJogada()) {
        vencedores += jogadores[i].getNome() + "\n";
    }
  }
  
  return vencedores;
}