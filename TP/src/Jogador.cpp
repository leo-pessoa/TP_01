#include <iostream>
#include "Jogador.h"
#include "Mao.h"
#include "Carta.h"
#include <string>
using namespace std;

Jogador::Jogador()
{
	nome = "";
	valor = 0;
}

Jogador::Jogador(std::string _nome, double _valor, Mao _mao)
{
	nome = _nome;
	cout << "Nome criado: " << nome << endl;
	valor = _valor;
	mao = _mao;
}

Mao Jogador::getMao()
{
 return mao;
}

std::string Jogador::getNome()
{
 return nome;
}

int Jogador::getValor()
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

void Jogador::setMao(Mao _mao)
{
	mao = _mao;
}
