/*
	FACTORIAL 
	
	El factorial de los primeros N numeros naturales
	ingresados por el usuario.
	
	MODO ITERATIVO
	
	N=5
	1*2*3*4*5=120
	
	Rogelio Manríquez Cobián
*/

#include <stdio.h>

int main (void){
	unsigned int N, fact=1;
	
	printf("Factorial de N numeros\n");
	printf ("\nEscribe el valor de N: ");
	scanf ("%ui", &N);
	
	for (int i=2; i<=N; i++)
	{
		fact = fact * i;
	}
	
	printf("\nEl factorial de (%i) es: %i\n", N,fact);
	return 0;
}

