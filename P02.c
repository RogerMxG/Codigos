/*
	SUMATORIA 
	La sumatoria de los primeros N numeros naturales
	ingresados por el usuario.
	MODO RECURSIVO
	N=5
	S(N) = N + S(N-1)
	S(5) = 5 + S(4)
	S(4) = 4 + S(3)
	S(3) = 3 + S(2)
	S(2) = 2 + S(1)
	S(1) = 1
	Rogelio Manríquez Cobián
*/
#include <stdio.h>

unsigned int SumaNumNaturales(unsigned int N);

int main (void){
	unsigned int N, suma=0;
	
	printf("Sumatoria de N numeros con Recursividad\n");
	printf ("Escribe el valor de N: ");
	scanf ("%ui", &N);
	
	suma = SumaNumNaturales(N);
	
	printf("\nLa sumatoria de los primeros (%i) numeros naturales es: %i\n", N,suma);
	return 0;
}

unsigned int SumaNumNaturales(unsigned int N){
	unsigned int suma;
	
	if (N == 1){
		return 1;
	}
	
	suma = N + SumaNumNaturales(N-1);
	
	return suma;	
}

