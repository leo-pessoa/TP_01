#include <iostream>
#include "Carta.h"
#include "Jogador.h"
#include "Mao.h"
using namespace std;

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

bool Mao::fourOfAKind(){
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

bool Mao::twoSame (){
	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++)
		 	if(hand[i].mesmoNumero(hand[j]) && i!=j)
		 		return true; 
	}
	return false;
}


bool Mao::doubleTwoSame(){
	int counter1 = 0;
	for(int i=0; i<5; i++){
	 	for(int j=0; j<5; j++){
	 		if(hand[i].mesmoNumero(hand[j]) && i!=j){
	 			counter1++;
	 		}
	 	}
 	}

	if(counter1==4||counter1==8)
		return true;

	return false;
}

bool Mao::flush(){
	if(hand[0].mesmoNaipe(hand[1]) && hand[0].mesmoNaipe(hand[2]) && hand[0].mesmoNaipe(hand[3]) && hand[0].mesmoNaipe(hand[4]))
	 	return true;
	return false;
}

bool Mao::straight(){
	if(twoSame()==true)
		return false;

	int temp = 13;
	int temp2 = 13;
	int l = 0;

	int counter1=0;

	 for(int i = 0; i<5; i++){
		 for(int j = 0; j<13; j++){
				if (j < temp)
					temp = j;
				if (j < temp2 && j > temp)
					temp2 = j;	
	 	}
	 }
	
	if(temp==0&&temp2==9)
	 temp=temp2;

	for(int i = 0; i<5; i++){
		for(int k = 0; k <5; k++){
			l= temp+k;
			if(l>12)
				l= l-13;
			if (hand[i].cartaEspecial())
				counter1++;
		}
	 }
	if(counter1==5)
		return true;
	return false;
}

bool Mao::royalFlush(){
	if(flush()==false||twoSame()==true)
		return false;

	int counter1 = 0;

	for(int i = 0; i<5; i++){
			for(int k = 0; k<5; k++){
				if (hand[k].cartaEspecial())
				{
					counter1++;
				}
			}
	}

	if(counter1==5)
		return true;

	return false;
 }

bool Mao::straightFlush(){
	if (straight() && flush())
	   return true;

	return false;
}

bool Mao::fullHouse(){
	if(threeOfAKind()==true && doubleTwoSame()==true)
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
	if (royalFlush()==true)
		return 10;
	if (straightFlush()==true)
		return 9;
	if(fourOfAKind()==true)
		return 8;
	if(fullHouse()==true)
		return 7;
	if(flush()==true)
		return 6;
	if(straight()==true)
		return 5;
	if(threeOfAKind()==true)
		return 4;
	if(doubleTwoSame()==true)
		return 3;
	if(twoSame()==true)
		return 2;

	return 1;
}