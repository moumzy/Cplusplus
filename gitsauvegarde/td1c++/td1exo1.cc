#include <stdio.h>
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
	//A
	int const tailletableau(10);
	int tableau[tailletableau];
	int* p;
	int i,j;
	p = tableau;
	
	for(i=0;i<10;i++){	
	tableau[i] = i+1;
	}
	
	for(j=0;j<10;j++){
		cout << p[j] << endl;
		
	}
	
	for(i=0;i<10;i++){
		cout << tableau[i] << endl;
	}
	
	//B
	
	char** A = new char*[3];
	
		
		A[1] =  "machin";
		A[2] =  "chose";
	
	
	for(i =0 ; i<3; i++){
		cout << A[i] << endl;
	A++;
	}

	delete[] (A-3);
	
	return 0;
}

