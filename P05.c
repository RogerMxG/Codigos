/*
	FIBONACCI 
	La sucesión de los primeros N numeros naturales de la
	serie de Fibonacci ingresados por el usuario.
	MODO ITERATIVO
	N=5
	0,1,1,2,3,5,8,13,21,34,55...
	
	Rogelio Manríquez Cobián
*/
#include <stdio.h>

int main (void){
	int N;
	int n=0;
	int x=1;
	int z;
	
	printf("Fibonacci de N numeros \n");
	printf ("\nEscribe el valor de N: ");
	scanf ("%ui", &N);
	
	printf("%d, %d", n, x);
	for (int i=0;i<N;i++){
		z=n+x;
		printf (" ,%d", z);
		n=x;
		x=z;
	}
	getchar ();
	return 0;	
}