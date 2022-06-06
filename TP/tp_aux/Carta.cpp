#include <iostream>
#include "Carta.h"
#include <string>
using namespace std;

Carta::Carta()
{
}

Carta::Carta(int _numero, char _naipe){
	numero = _numero;
	naipe = _naipe;
}

bool Carta::mesmoNumero(Carta c){
	if(numero==c.numero)
		return true;
	return false;
}

bool Carta::mesmoNaipe(Carta c){
	if(naipe==c.naipe)
		return true;
	return false;
}

char Carta::getNaipe()
{
 return naipe;
}

int Carta::getNumero()
{
 return numero;
}

bool operator>(Carta &c1,  Carta &c2)
{
 if (c1.getNumero() == 1 && c2.getNumero() != 1) {
		return true;
 }
 else if (c2.getNumero() == 1 && c1.getNumero() != 1) {
		return false;
	}
	return c1.getNumero()>c2.getNumero();
}