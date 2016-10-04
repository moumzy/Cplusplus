#include <stdio.h>
#include <iostream>

using namespace std;

void TABLEAUECRITURE(int taille, int T[]){
	for(int i=0; i<taille; i++){
		T[i] = i;
	}
	
}

void TABLEAULECTURE(int taille, const int t[]){
		
	for(int i=0; i<taille; i++){
		cout << "la valeur est" << t[i] << '\n' ;
	}
	
	
	
}

int main(int argc, char **argv)
{
	int T[10];
	TABLEAUECRITURE(10,T);
	TABLEAULECTURE(10,T);
	return 0;
}


