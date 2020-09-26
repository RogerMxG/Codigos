#include <stdio.h>

int main (void){
	int x;
	float z=-1.5;
	char c;
	float *puntero;
	
	puntero = &z;
	
	printf ("El valor de z es %f",z);
	
	*puntero = 3.1416;
	
	printf ("\nEl valor de z es %f\n",z);
	
	
	getchar();
	return 0;
}