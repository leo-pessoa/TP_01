#ifndef CARTA
#define CARTA

class Carta
{
public:
    Carta();
    Carta(int _numero, int _naipe);
    bool mesmoNumero(Carta c);
    bool mesmoNaipe(Carta c);
    int getNumero();
    int getNaipe();
    bool cartaEspecial();

private:
    char naipe;
    char numero;
};

#endif