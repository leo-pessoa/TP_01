
#ifndef MAO
#define MAO
#include "Carta.h"
#include "Jogador.h"

class Mao
{
public:
    Mao();
    Mao(Carta *_hand);
    bool comparaMaos(Mao m1, Mao m2);
    bool threeOfAKind();
    bool fourOfAKind();
    bool onePair();
    bool twoPairs();
    bool flush();
    bool straight();
    bool fullHouse();
    bool royalStraightFlush();
    bool straightFlush();
    int maiorCarta();
    int tipoJogada();
    Carta hand[5];
};

#endif