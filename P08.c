/*	ARREGLOS
	CALCULAR EL PROMEDIO DE LOS 
	DATOS ALMACENADOS EN UN ARREGLO
	MEDIANTE EL USO DE UN APUNTADOR
*/

#include <stdio.h>

float Promedio (int *p, int Nm);

int main (void){
	int datos[5];
	int N;
	int *ptr;
	
	//Asignacion del puntero al arreglo
	//ptr = &datos[0];
	ptr = datos;
	
	//Escribiendo el arreglo sobre el apuntador
	printf ("Numero de datos a calcular: ");
	scanf ("%i", &N );
	for (int i=0; i<N; i++)
	{
		printf("Dato [%i]: ", i);
		scanf ("%i",ptr+i); //&datos[i];
	}
	
	printf("\n");
	
	//Asignacion de los datos capturados mediante el puntero
	printf("Los datos capturados son:\n");
	for (int i=0; i<N; i++)
	{
		printf("Dato [%i]: %i\n", i, *(ptr+i));
	}
	
	//Recibe el contenido de la dirrecion del arreglo-puntero
	printf ("\nEl promedio de los datos es: %.2f", Promedio(ptr,N));
	
	printf("\n");
	getchar();
	return 0;
}

//Calcular el promedio con el apuntador
float Promedio (int *p, int Nm){
	float prom, suma=0;
	int i;
	
	for (int i=0; i<Nm; i++)
	{
		suma = suma + *(p+i);
	}
	
	prom = suma/Nm;
	
	return prom;
}