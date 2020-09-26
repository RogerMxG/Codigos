/*
	Tarea 03:Arreglos
	Realizar la captura de datos de un arreglo y mostrarlo en pantalla.
	Copiarlos datos del arreglo en otro,de tal forma que queden en orden invertido y mostrar el resultado en pantalla.
	Por ejemplo:
	Arreglo1:
	10
	20
	30
	40
	50

	Arreglo2:
	50
	40
	30
	20
	10
NOTA: Para la codificación del programa crear los arreglos de forma dinámica y manipular los arreglos utilizando apuntadores.

*/

#include <stdio.h>
#include <stdlib.h>

int main (void){
	int nD;
	int *ptr1;
	int *ptr2;

	//Escribiendo el arreglo sobre el apuntador
	printf ("Numero de datos a calcular: ");
	scanf ("%i", &nD);

	//Declaración de arreglos en forma dinámica
	//apuntador a un entero hacia ptr1 y ptr2
	ptr1 = (int *)malloc(nD*sizeof(int)); //malloc asginación de memoria
	ptr2 = (int *)malloc(nD*sizeof(int));

	//Ver si se asignó correctamente la memoria
	if (ptr1 == NULL && ptr2 == NULL){

		printf ("Error al asignar memoria\n");
		exit (0); //salir del programa exit (0); = return 0;
	}

	//Capturar datos
	for (int i=0; i<nD; i++)
	{
		printf("Dato [%i]: ", i);
		scanf ("%i",ptr1+i); //&datos[i];
	}

	//Invertir datos
	for (int i=0; i<nD; i++)
	{
		*(ptr2+i) = *(ptr1+nD-i-1);
	}

	printf("\n");

	//Asignacion de los datos capturados mediante el puntero ptr1
	printf("Los datos capturados son:\n");
	for (int i=0; i<nD; i++)
	{
		printf("Dato [%i]: %i\n", i, *(ptr1+i));
	}

	printf("\n");

	//Mostrar datos invertidos del puntero ptr2
	for (int i=0; i<nD; i++)
	{
		printf("Dato [%i]: %i\n", i, *(ptr2+i));

	}

	//Eliminar la memoria dinámica
	free(ptr1);
	free(ptr2);
	getchar();
	return 0;
}