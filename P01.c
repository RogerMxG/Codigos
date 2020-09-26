/*
	SUMATORIA
	
	La sumatoria de los primeros N numeros naturales
	ingresados por el usuario.
	
	MODO ITERATIVO
	
	N=5
	1+2+3+4+5 = 15
	
	Rogelio Manríquez Cobián
*/

#include <stdio.h>

int main (void){
	
	unsigned int n, suma=0;
	
	printf("Sumatoria de N numeros\n");
	printf("Ingrese el N valor del numero: ");
	scanf("%d",&n);
	
	for (int i=1; i<=n; i++)
	{
		suma = suma + i;
	}
	
	printf("La sumatoria de los primeros (%d) numeros naturales es: %d",n, suma);
		
	return 0;
}