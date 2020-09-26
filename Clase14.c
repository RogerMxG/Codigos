/*
	ESTRUCTURAS DE DATOS ABSTRACTAS
	PILAS
*/

#include <stdio.h>
#include <stdlib.h>

//Estructuras de Datos
typedef struct{
	int *data;
	unsigned int size;
	int id;
}PILA;

//Prototipos 
PILA* CrearPila (unsigned int Tam);
char Push (PILA *p, int d);
//char Pop (PILA *p, int *d);
//char isEmpty (PILA *p);
char isFull (PILA *p);
void freePila (PILA *p);
void mostrarPILA (PILA *p);

//Funcion Main
int main (void){
	PILA *pila1;
	
	//Crear Tamaño de la PILA
	pila1 = CrearPila(5);
	
	//Agregar datos a la PILA
	if (!Push(pila1, 10)){
		printf ("\nDato no apilado, pila llena");
	}
	
	if (!Push(pila1, 20)){
		printf ("\nDato no apilado, pila llena");
	}
	
	if (!Push(pila1, 30)){
		printf ("\nDato no apilado, pila llena");
	}
	
	//Mostramos PILA
	printf ("\nLa [pila1] es: ");
	mostrarPILA (pila1);
	
	//Liberar Pila
	freePila (pila1);
	return 0;
	
}

PILA* CrearPila (unsigned int Tam){
	PILA *ptr;
	
	//Asignamos memoria a una dirección de tipo PILA
	ptr = (PILA *)malloc(sizeof(PILA));
	
	//Verificamos si se reservo memoria correctamente
	if (ptr == NULL){
		printf ("Error al asignar memoria a PILA");
		exit (0);
	}
	
	ptr->size = Tam;
	ptr->id = -1; //Verificamos que no haya algun elemento en el arrelgo
	ptr->data = (int *)malloc(sizeof(int)*Tam);
	
	
	//Verificamos si se reservo memoria correctamente dirigida a data
	if (ptr->data == NULL){
		printf ("Error al asignar memoria para el arreglo de datos de PILA");
		exit (0);
	}
	
	return ptr;
}

//Función Push
char Push (PILA *p, int d){
	
	//NO esta llena la pila?... Incrementa
	if ( !isFull(p) ){
		//Incrementar, para poner el id en la posición 0
		p->id++;
	
		//Manipular y darle la dirección a d
		*(p->data + p->id)=d;
		
		return 1;
		
	}else{
		return 0;
	}
}

//Función isFull
char isFull (PILA *p){
	
	//Verificamos si la pila esta llena
	//id llega al numero igual a pila
	if ( p->id == (p->size-1) ){
		
		return 1;
		
	}else{
		return 0;
	}
}

//Función Mostrar Pila
void mostrarPILA (PILA *p){
	int i;
	
	for (i=p->id; i>=0; i--){
		
		//Accdedemos a la estructura data para mostrar las direcciones
		printf ("\n%i", *(p->data+i) );
	}
	
}

//Función Free
void freePila (PILA *p){
	//Liberar memoria del arreglo de data
	free (p->data);
	free (p);
}

