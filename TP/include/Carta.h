#ifndef CARTA
#define CARTA

class Carta
{
public:
    Carta();
    Carta(int _numero, char _naipe);
    bool mesmoNumero(Carta c);
    bool mesmoNaipe(Carta c);
    int getNumero();
    char getNaipe();
    bool cartaEspecial();

private:
    char naipe;
    int numero;
};

#endif