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
    friend bool operator>(Carta &c1, Carta &c2);
private:
    char naipe;
    int numero;
};
#endif