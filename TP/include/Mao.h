
#ifndef MAO
#define MAO
#include "Carta.h"
#include "Jogador.h"

class Mao
{
public:
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
    Carta * hand;
};

#endif