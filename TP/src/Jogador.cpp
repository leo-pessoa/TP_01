#include <iostream>
#include "Jogador.h"
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

	int n = sizeof(mao.hand)/sizeof(mao.hand[0]);

		for (int i = 0; i < n - 1; i++)
			for (int j = 0; j < n - i - 1; j++)
				if (mao.hand[j].getNumero() > mao.hand[j + 1].getNumero())
					swap(mao.hand[j], mao.hand[j + 1]);
}

Mao Jogador::getMao()
{
 return mao;
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

void Jogador::setMao(Mao _mao)
{

 int n = sizeof(_mao.hand) / sizeof(_mao.hand[0]);

 for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (_mao.hand[j].getNumero() > _mao.hand[j + 1].getNumero())
				swap(_mao.hand[j], _mao.hand[j + 1]);
	mao = _mao;
}
