#include <iostream>
#include "Carta.h"
#include "Jogador.h"
#include "Mao.h"
using namespace std;

Mao::Mao(){

}

Mao::Mao(Carta * _hand){
 int i, j;
	int n = 5;
 for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (_hand[j] > _hand[j + 1])
				swap(_hand[j], _hand[j + 1]);

for (int i = 0; i < 5; i++) {
	hand[i] = _hand[i];
}
}


bool Mao::threeOfAKind(){
	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++){
		 	for(int l=0; l<5; l++){
		 		if((hand[i].mesmoNumero(hand[j]) && hand[i].mesmoNumero(hand[l])) && (i!=j && i!=l && j!=l))
		 		return true; 
			}
		}
	}
	return false;
}


// OK]
bool Mao::fourOfAKind()
{
 for(int i=0; i<5; i++){
		for(int j=0; j<5; j++){
		 	for(int l=0; l<5; l++){
				for(int k=0; k<5;k++){
		 			if((hand[i].mesmoNumero(hand[j]) && hand[i].mesmoNumero(hand[l]) && hand[i].mesmoNumero(hand[k])) && (i!=j && i!=l && j!=l && i!=k && l!=k && j!=k))
		 			return true;
				} 
			}
		}
	}
	return false;
}

//OK

bool Mao::onePair (){
	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++)
		 	if(hand[i].mesmoNumero(hand[j]) && i!=j)
		 		return true; 
	}
	return false;
}

//OK

bool Mao::twoPairs(){
	int counter1 = 0;
	for(int i=0; i<5; i++){
	 	for(int j=0; j<5; j++){
	 		if(hand[i].mesmoNumero(hand[j]) && i!=j){
	 			counter1++;
	 		}
	 	}
 	}

	if(counter1==4 || counter1==8)
		return true;

	return false;
}


//OK

bool Mao::flush(){
	if(hand[0].mesmoNaipe(hand[1]) && hand[0].mesmoNaipe(hand[2]) && hand[0].mesmoNaipe(hand[3]) && hand[0].mesmoNaipe(hand[4]))
	 	return true;
	return false;
}


//OK
bool Mao::straight(){
	if(onePair()==true)
		return false;
	int counter = 0;
		for (int i = 1; i < 5; i++) {
				if (hand[i].getNumero() == hand[0].getNumero() + i) {
					counter++;
			}
 }
 return counter == 4;
}


//OK
bool Mao::royalStraightFlush(){
	if(onePair())
		return false;

	int counter = 0;

	if (hand[4].getNumero() == 1){
		counter = 1;
	}


	for (int j=0; j<4; j++){
			if(hand[j].getNumero() == 10+j){
				counter++;
			}
	}

	if(counter==5 && flush()==true)
		return true;

	return false;
 }


//OK
bool Mao::straightFlush(){
	if (straight() && flush())
	   return true;

	return false;
}

//OK
bool Mao::fullHouse(){
	if(threeOfAKind()==true && twoPairs()==true)
		return true;
	
	else
		return false;
}

int Mao::tipoJogada(){

	if (royalStraightFlush()){
		return 100000;
	}
	if (straightFlush()){

		return 90000;
 }
	if(fourOfAKind()){

		int carta1, carta_so1;
		if (hand[0].mesmoNumero(hand[1]))
		{
			carta1 = hand[0].getNumero();
			carta_so1 = hand[4].getNumero();
		}
		else
		{
			carta1 = hand[4].getNumero();
			carta_so1 = hand[0].getNumero();
		}

		return 80000 + carta1*14 + carta_so1;
 }
	if(fullHouse()){

		int carta1, carta_par1;

		if (hand[1].mesmoNumero(hand[2])) {
			carta1 = hand[0].getNumero();
			carta_par1 = hand[4].getNumero();
		} else
		{
			carta1 = hand[4].getNumero();
			carta_par1 = hand[0].getNumero();
		}

		return 70000 + 14*carta1 + carta_par1;
 }
	if(flush()){

		int carta1 = hand[4].getNumero();
		return 60000 + carta1;
 }
	if(straight()){
		int maior1 = 0;

		for (int i = 0; i < 5; i++)
		{
			if (hand[i].getNumero() > maior1)
				maior1 = hand[i].getNumero();
		}

		return 50000 + maior1;
 }
	if(threeOfAKind()){
		int tripla_indices[3];
		int maior = 0;
		int tripla;

		for (int i = 0; i < 5; i++)
		{
			if((hand[i].getNumero() == (hand[i+1].getNumero() == hand[i+2].getNumero()))) {
				tripla = hand[i].getNumero();
				tripla_indices[0] = i;
				tripla_indices[1] = i+1;
				tripla_indices[2] = i+2;
			}
		}

		for (int i = 0; i < 5; i++) {
			if ((i != tripla_indices[0]) && (i != tripla_indices[1]) && (i != tripla_indices[2]) && (hand[i].getNumero() > maior))
			{
				maior = hand[i].getNumero();
			}
		}

			return 40000 + tripla * 14 + maior;
 }


	if(twoPairs()){

		int par_menor, par_maior, avulsa;
		if (hand[0].mesmoNumero(hand[1])) {
			if (hand[2].mesmoNumero(hand[3])) 	{
			par_menor = hand[0].getNumero();
			par_maior = hand[2].getNumero();
			avulsa = hand[4].getNumero();
		}
		else if (hand[3].mesmoNumero(hand[4])) {
			par_menor = hand[0].getNumero();
			par_maior = hand[4].getNumero();
			avulsa = hand[2].getNumero();
		}
 }
	else {
		par_maior = hand[4].getNumero();
		par_menor = hand[1].getNumero();
		avulsa = hand[0].getNumero();
 }
		return 30000 + par_maior * 200 + par_menor * 14 +  avulsa ;
}


	if(onePair()){
		int par, maior = 0;
		for (int i = 0; i < 5; i++)
		{
			if ((hand[i].getNumero() == hand[i + 1].getNumero())) {
				par = hand[i].getNumero();
			} else {
				if (hand[i].getNumero() > maior) {
					maior  = hand[i].getNumero();
				}
			}
		}

		return 20000 + par*14 + maior;
 }

 int maior1 = 0;

 for (int i = 0; i < 5; i++)
 {
		if (hand[i].getNumero() > maior1)
			maior1 = hand[i].getNumero();
 }

 return 10000 + maior1;
}