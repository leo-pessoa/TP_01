#include <iostream>
#include "Jogador.h"
#include <string>
using namespace std;

Jogador::Jogador()
{

}


Jogador::Jogador(std::string _nome, double _valor, Mao _mao)
{
	nome = _nome;
	valor = _valor;
	mao = _mao;
}

std::string Jogador::getNome()
{
 return nome;
}

double Jogador::getValor()
{
 return valor;
}

bool Jogador::mesmoJogador(std::string _nome)
{
	if(nome == _nome)
		return true;
	return false;
}

void Jogador::setValor(int _valor)
{
 valor = _valor;
}