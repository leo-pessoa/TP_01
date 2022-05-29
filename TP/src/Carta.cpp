#include <iostream>
#include "Carta.h"
#include <string>
using namespace std;

Carta::Carta(int _numero, int _naipe){
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

bool Carta::cartaEspecial(){
 if (numero == 1 || numero > 9)
		return true;
	return false;
}

int Carta::getNaipe()
{
 return naipe;
}

int Carta::getNumero()
{
 return numero;
}