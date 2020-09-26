/*
	FACTORIAL 
	El factorial de los primeros N numeros naturales
	ingresados por el usuario.
	MODO RECURSIVO
	N=5
	F(N) = N * F(N-1)
	F(5) = 5 * F(4) -> 120
	F(4) = 4 * F(3)
	F(3) = 3 * F(2)
	F(2) = 2 * F(1)
	F(1)
	Rogelio Manríquez Cobián
*/
#include <stdio.h>

unsigned FactNumNaturales(unsigned int N);

int main (void){
	unsigned int N, fact=1;
	
	printf("Factorial de N numeros con Recursividad\n");
	printf ("\nEscribe el valor de N: ");
	scanf ("%ui", &N);
	
	int resultado = FactNumNaturales(N);
	
	printf("\nEl factorial de (%i) es: %i\n", N,resultado);
	return 0;
}

unsigned FactNumNaturales(unsigned int N){
	unsigned int resultado;
	
	if (N==1)
	{
		return 1;
	}
	
	resultado = N * FactNumNaturales(N-1);
	
	return resultado;
}