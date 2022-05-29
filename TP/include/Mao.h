
#ifndef MAO
#define MAO
#include "Carta.h"

class Mao
{
public:
    Mao(int _numero, int _naipe);
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
    
private:
    Carta hand[5];
};

#endif