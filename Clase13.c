#include <stdio.h>
#include <stdlib.h> //Librería para usar los apartados de memoria dinamica 


//Declaramos nuestra estructura con el nombre Matriz
typedef struct{
	//Datos tipo Flotantes

	float *data; 
	//Apuntador en cual se almacenerá la dirección de un arreglo de datos bidimensionales

	//Declarar variables para renglones y columnas
	unsigned int nRen; //No. renglones
	unsigned int nCol; //No. columnas
	
}Matriz;

//Prototipos de Funciones
Matriz* rcCrearMatriz (unsigned int nRen, unsigned int nCol); 
//Reserva la memoria necesaria para almacenar una matriz

void rcCapturaMatriz(Matriz *p);
//Captura los datos en la matriz apuntada por "p"

void rcMostarMatriz(Matriz *p);
//Manda a mostrar la matriz apuntada por "p"

void rcEliminarMatriz (Matriz *p);
//Liberar la memoria reservada 

Matriz* sumaMatrices (Matriz *a, Matriz *b);
//Suma A + B

Matriz* multiplicaMatrices (Matriz *a, Matriz *b);
//Multiplica A*B

int main (void){
	Matriz *a, *b, *c, *d;
	
	unsigned int ren, col;

	printf ("Numero de renglones: ");
	scanf ("%u", &ren); fflush (stdin);
	
	printf ("Numero de columnas: ");
	scanf ("%u", &col); fflush (stdin);
	
	printf ("\nMATRIZ [A]\n");
	a = rcCrearMatriz(ren,col);
	rcCapturaMatriz(a);
	
	printf("\nLa matriz [A] capturada es: \n");
	rcMostarMatriz(a);
	
	printf ("\n\nMATRIZ [B]\n");
	b = rcCrearMatriz(ren,col);
	rcCapturaMatriz(b);
	
	printf("\nLa matriz [B] capturada es: \n");
	rcMostarMatriz(b);
	
	//Suma
	c = sumaMatrices(a,b);
	printf("\n\nLa matriz [A]+[B] es igual: \n");
	rcMostarMatriz(c);
	
	//Multiplicar
	d = multiplicaMatrices(a,b);
	printf("\n\nLa matriz [A]*[B] es igual: \n");
	rcMostarMatriz(d);
	
	
	//Eliminar Matriz
	rcEliminarMatriz(a);
	rcEliminarMatriz(b);
	rcEliminarMatriz(c);
	rcEliminarMatriz(d);
	
	printf ("\n\nPresione <ENTER> para salir");
	
	getchar ();
	return 0;
}

//Multiplicar
Matriz* multiplicaMatrices (Matriz *a, Matriz *b){
	Matriz *res;
	unsigned int i, j, z;

	res = rcCrearMatriz(a->nCol, b->nRen);
	
	//Si el dato de nRen es diferente al dato de nCol no se podra realizar la matriz
	//Ya que para realizar la multiplacacion de matrices necesitamos que el ultimo
	//dato de nRen y nCol sean iguales para realizar el producto
	if (a->nRen != b->nCol){
		
		printf ("\n\nNo se puede realizar la multiplacacion de matrices\n\n");
		exit (0);
		
	}else{
		for (i=0; i<res->nRen; i++)
		{
			for (j=0; j<res->nCol; j++)
			{
				*(res->data + i*res->nCol + j) = 0;
				for (z=0; z<res->nCol; z++)
				{
					*(res->data + i*res->nCol + j) += (*(a->data + i*a->nRen + z)) * (*(b->data + z*b->nCol + j));
				}
			}
		}
	}
	
	return res;
	
}

//Suma Matrices
Matriz* sumaMatrices (Matriz *a, Matriz *b){
	Matriz *resultado;
	unsigned int i, j;
	
	resultado = rcCrearMatriz(a->nRen, a->nCol);
	
	for (i=0; i<resultado->nRen; i++)
	{
		for (j=0; j<resultado->nCol; j++)
		{
			//Se recorre toda la matriz para ir sumando columna-columna
			*(resultado->data + i*resultado->nCol + j) = *(a->data + i*a->nCol + j) + *(b->data + i*b->nCol + j);
		}
	}
	return resultado;
}

//Liberar Memoria 
void rcEliminarMatriz (Matriz *p){
	//Eliminamos memoria de los datos contenidos en la Matriz
	free (p->data);
	free (p);
}

//Mostrar Matriz
void rcMostarMatriz(Matriz *p){
	
	//Recorrer renglones y columnas
	unsigned int i, j;
	
	for (i=0; i<p->nRen; i++)
	{
		printf ("\n");
		for (j=0; j<p->nCol; j++)
		{
			printf("%g ", *(p->data + i*p->nCol + j));
			//Dirección correspondiente del almacenado en i y j
		}
	}
}
	

//Capturar Matriz
void rcCapturaMatriz(Matriz *p){
	
	//Recorrer renglones y columnas
	unsigned int i, j;
	
	for (i=0; i<p->nRen; i++)
	{
		for (j=0; j<p->nCol; j++)
		{
			printf("Dato [%u][%u]: ", i, j);
			scanf("%f", p->data + i*p->nCol + j); fflush (stdin);
			//Dirección correspondiente del almacenado en i y j
		}
	}
}

//Crear Matriz
Matriz* rcCrearMatriz (unsigned int nRen, unsigned int nCol){
	Matriz *ptr; //Declarar nuestra variable en forma de apuntador
	
	//Almacena datos de estructura Matriz de manera dinámica.
	ptr = (Matriz *)malloc(sizeof(Matriz));
	
	//Verificar si se almacenó la memoria
	if (ptr == NULL){
		printf ("Error al asginar memoria para la estructura [Matriz]");
		exit (0);
	}
	
	ptr->nRen = nRen;
	ptr->nCol = nCol;
	ptr->data = (float *)malloc(nRen*nCol*sizeof(float));
	
	
	return ptr;
}


