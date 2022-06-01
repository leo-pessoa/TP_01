#include <iostream>
#include "Jogador.h"
#include <string>
using namespace std;

Jogador::Jogador()
{
	nome = "";
	valor = 0;
}

Jogador::Jogador(std::string _nome, double _valor)
{
	nome = _nome;
	cout << "Nome criado: " << nome << endl;
	valor = _valor;
	Mao mao;
	Carta carta(0, 'a');

	for	(int i = 0; i < 5; i++)
		mao.hand[i] = carta;

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
 mao = _mao;

 for (int l = 0; l < 5; l++)
 {
		printf("Carta na mao: %d %c\n", mao.hand[l].getNumero(), mao.hand[l].getNaipe());
 }

 for (int l = 0; l < 5; l++)
 {
		printf("Carta na mao 2222: %d %c\n", _mao.hand[l].getNumero(), _mao.hand[l].getNaipe());
 }
}