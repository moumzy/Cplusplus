#include <stdio.h>
#include <iostream>

using namespace std;

void ECHANGE(int &A, int &B){
	int C;
	C = A;
	A = B;
	B = C;
}

int main(int argc, char **argv)
{
	int A,B;
	
	A = 1;
	B = 2;
	
	ECHANGE(A,B);
	
	cout << A << endl; //Affiche la variable A
	cout << B << endl;
	
	return 0;
}

