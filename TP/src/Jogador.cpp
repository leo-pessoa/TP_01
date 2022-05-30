#include <iostream>
#include "Jogador.h"
#include <string>
using namespace std;

Jogador::Jogador()
{
	nome = "teste";
	valor = 0;
}

Jogador::Jogador(std::string _nome, double _valor)
{
	nome = _nome;
	cout << "nomeEEEEEEEEE: " << nome << endl;
	valor = _valor;
	cout << "valoreeeeeeeeEE: " << valor << endl;
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