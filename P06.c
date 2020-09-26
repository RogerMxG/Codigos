/*
	FIBONACCI 
	La sucesión de los primeros N numeros naturales de la
	serie de Fibonacci ingresados por el usuario.
	MODO RECURSIVO
	N=5
	F(N) = F(N-1) + F(N-2)
	F(5) = F(4) + F(3)
	F(4) = F(3) + F(2)
	F(3) = F(2) + F(1)
	F(2) = F(1) + F(0)
	F(1) = 1
	F(0) = 0
	Rogelio Manríquez Cobián
*/
#include <stdio.h>

unsigned int Fibonacci(unsigned int N);

int main (void){
	unsigned int N;
	
	printf("Fibonacci de N numeros con Recursividad\n");
	printf ("\nEscribe el valor de N: ");
	scanf ("%ui", &N);
	
	
	for (int i=0; i<=N; i++){
		printf("%i, ",Fibonacci(i));
	}
	return 0;
}

unsigned int Fibonacci(unsigned int N){
	if (N==1 || N==0)
	{
		return N;
	}else{
		
		return Fibonacci(N-1) + Fibonacci(N-2);
	}
	
}