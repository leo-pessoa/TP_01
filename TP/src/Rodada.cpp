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


Rodada::Rodada(Jogador * jogadores )
{
 for (int i = 0; i < 8; i++)
 {
  jogadores[i] = jogadores[i];
 }
}


Jogador Rodada::getWinner(int n)
{
 for (int i = 0; i < n - 1; i++)
  for (int j = 0; j < n - i - 1; j++)
   if (jogadores[j].getValor() < jogadores[j + 1].getValor())
   {
    swap(jogadores[j], jogadores[j + 1]);
   }
   else if (jogadores[j].getValor() == jogadores[j + 1].getValor())
   {
    if (desempata(jogadores[j], jogadores[j + 1]))
    {
     swap(jogadores[j], jogadores[j + 1]);
    }
   }
 return jogadores[n];
}

#define RF 10
#define SF 9
#define FK 8
#define FH 7
#define FL 6
#define ST 5
#define TK 4
#define TP 3
#define OP 2
#define HC 1

bool Rodada::desempata(Jogador j1, Jogador j2)
{

 Mao mao1 = j1.getMao();
 Mao mao2 = j2.getMao();


 if (mao1.tipoJogada() == FK)
 {
  int carta1, carta2, carta_so1, carta_so2;

  if (mao1.hand[0].mesmoNumero(mao1.hand[1]))
  {
   carta1 = mao1.hand[0].getNumero();
   carta_so1 = mao1.hand[4].getNumero();
  }
  else
  {
   carta1 = mao1.hand[4].getNumero();
   carta_so1 = mao1.hand[0].getNumero();
  }

  if (mao2.hand[0].mesmoNumero(mao2.hand[1]))
  {
   carta2 = mao2.hand[0].getNumero();
   carta_so2 = mao2.hand[4].getNumero();
  }
  else
  {
   carta2 = mao2.hand[4].getNumero();
   carta_so2 = mao2.hand[0].getNumero();
  }

  if (carta1 == carta2)
  {
   return carta_so2 > carta_so1;
  }

  return carta2 > carta1;
 }

 if (mao1.tipoJogada() == FH)
 {
  int carta1, carta2, carta_par1, carta_par2;

  if (mao1.hand[1].mesmoNumero(mao1.hand[2]))
  {
   carta1 = mao1.hand[0].getNumero();
   carta_par1 = mao1.hand[4].getNumero();
  }
  else
  {
   carta1 = mao1.hand[4].getNumero();
   carta_par1 = mao1.hand[0].getNumero();
  }

  if (mao2.hand[1].mesmoNumero(mao2.hand[2]))
  {
   carta2 = mao2.hand[0].getNumero();
   carta_par2 = mao2.hand[4].getNumero();
  }
  else
  {
   carta2 = mao2.hand[4].getNumero();
   carta_par2 = mao2.hand[0].getNumero();
  }

  if (carta1 == carta2)
  {
   return carta_par2 > carta_par1;
  }

  return carta2 > carta1;
 }

 if (mao1.tipoJogada() == FL || mao1.tipoJogada() == ST)
 {
  return mao2.hand[4].getNumero() > mao1.hand[4].getNumero();
 }
 return 0;
}