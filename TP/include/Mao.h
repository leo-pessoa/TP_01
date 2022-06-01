
#ifndef MAO
#define MAO
#include "Carta.h"
#include "Jogador.h"

class Mao
{
public:
    Mao();
    Mao(Carta *_hand);
    bool threeOfAKind();
    bool fourOfAKind();
    bool twoSame();
    bool doubleTwoSame();
    bool flush();
    bool straight();
    bool fullHouse();
    bool royalFlush();
    bool straightFlush();
    int maiorCarta();
    int tipoJogada();
    void setHand(Carta * _hand);
    Carta hand[5];
};

#endif