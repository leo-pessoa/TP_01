#include <iostream>
#include "Carta.h"
#include "Jogador.h"
#include "Mao.h"
using namespace std;

Mao::Mao(){

}

Mao::Mao(Carta * _hand){
	for (int i = 0; i < 5; i++){
		hand[i] = _hand[i];
	}
}

// bool Mao::comparaMaos(Mao m1, Mao m2){

// }

//OK

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


// OK
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
	bool is_straight = false;
 for(int i = 1; i<5; i++){
		for (int j = 0; j<5; j++){
			if(hand[i].getNumero() == hand[0].getNumero()+i){
				is_straight = true;
			}
		}
	}
	return is_straight;
}


//OK
bool Mao::royalStraightFlush(){
	if(onePair())
		return false;

	int counter = 0;


	if (hand[0].getNumero() == 1){
		counter = 1;
	}


	for (int j=1; j<5; j++){
			if(hand[j].getNumero() == 9+j){
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

int Mao::maiorCarta(){
	int temp = 0;
	for(int i = 0; i<5; i++){
		 for(int j = 0; j<(13); j++){
			 if(j>temp)
			  temp = j;	
	 	}
	 }
	return temp;
}

int Mao::tipoJogada(){
	if (royalStraightFlush())
		return 10;
	if (straightFlush())
		return 9;
	if(fourOfAKind())
		return 8;
	if(fullHouse())
		return 7;
	if(flush())
		return 6;
	if(straight())
		return 5;
	if(threeOfAKind())
		return 4;
	if(twoPairs())
		return 3;
	if(onePair())
		return 2;
	return 1;
}