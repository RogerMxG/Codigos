/*
	ESTRUCTURAS DE DATOS
	Una estructura es una agrupación de datos de
	diferente tipo que tienen un nombre común.
	
	SINTAXIS para la declaración de la estructura:
	
	typedef struct {
		tipo_de_dato Nombre1;
		tipo_de_dato Nombre2;
		...
		tipo_de_dato NombreN;
		
	}Nombre_De_La_Estrucura;
	
		Nombre_De_La_Estrucura variable1;
*/

/*
	Implementar un programa que realice las operaciones
	aritméticas básicas (+,-,*,/) de dos números
	complejos, utilizando estructuras de datos y funciones.

*/
#include <stdio.h>
#include <math.h>

//Declaración de la estructura

typedef struct {
	float real;
	float imga;
	
}num_Complejo;

//Esta función regresa una estructura referente a num_Complejo
num_Complejo Captura_numComplejo();

void muestra_numComplejo(num_Complejo *w);

num_Complejo sumaComplejo (num_Complejo *w, num_Complejo *z);
num_Complejo restaComplejo (num_Complejo *w, num_Complejo *z);
num_Complejo producComplejo (num_Complejo *w, num_Complejo *z);
num_Complejo diviComplejo (num_Complejo *w, num_Complejo *z);

int main (void){
	
	num_Complejo z1, z2, r;
	
	//Pedimos Ingresar los datos
	printf ("\nIngrese el numero z1: ");
	z1 = Captura_numComplejo();
	
	printf ("\nIngrese el numero z2: ");
	z2 = Captura_numComplejo();
	
	//Mostramos los datos capturados 
	printf ("\nLos numeros capturado son: ");
	muestra_numComplejo(&z1);
	printf ("\n");	
	muestra_numComplejo(&z2);
	
	//Mostrar Operaciones Aritmeticas
	r = sumaComplejo (&z1,&z2);
	printf ("\n\nLa suma es:");
	muestra_numComplejo(&r);
	
	r = restaComplejo(&z1,&z2);
	printf("\n\nLa resta es: ");
	muestra_numComplejo(&r);
	
	r = producComplejo(&z1,&z2);
	printf("\n\nEl producto es: ");
	muestra_numComplejo(&r);
	
	r = diviComplejo(&z1,&z2);
	printf("\n\nLa division es: ");
	muestra_numComplejo(&r);
	
	getchar ();
	return 0;
}

//Función para la División de Numero Complejo
num_Complejo diviComplejo (num_Complejo *w, num_Complejo *z){
	num_Complejo divi;
	
	divi.real= ((w->real * z->real) + (w->imga * z->imga)) / (pow(z->real, 2) + pow(z->imga, 2));
	divi.imga= ((w->imga * z->real) - (w->real * z->imga)) / (pow(z->real, 2) + pow(z->imga, 2));
	
	return divi;
}

//Función para la Multiplicación de Numero Complejo
num_Complejo producComplejo (num_Complejo *w, num_Complejo *z){
	num_Complejo produc;
	
	produc.real = (w->real * z->real) - (w->imga * z->imga);
	produc.imga = (w->real * z->imga) + (w->imga * z->real);
	
	return produc;
}

//Función para la Suma de Numero Complejo
num_Complejo sumaComplejo (num_Complejo *w, num_Complejo *z){
	num_Complejo suma;
	
	suma.real = w->real + z->real;
	suma.imga = w->imga + z->imga;
	
	return (suma);
}

//Función para la Diferencia de Numero Complejo
num_Complejo restaComplejo (num_Complejo *w, num_Complejo *z){
	num_Complejo resta;
	
	resta.real = w->real - z->real;
	resta.imga = w->imga - z->imga;
	
	return (resta);
}

//Mostrar los datos capturados
void muestra_numComplejo(num_Complejo *w){
	if (w->imga < 0){
		printf ("\n%2.1f %2.1f i", w->real, w->imga);
	}else{
		printf ("\n%2.1f + %2.1f i", w->real, w->imga);
	}	
}

//Capturar los datos ingresados
num_Complejo Captura_numComplejo(){
	num_Complejo w;
	
	printf ("\nReal: ");
	scanf ("%f", &w.real); fflush (stdin);
	
	printf ("Imaginaria: ");
	scanf ("%f", &w.imga); fflush (stdin);
	
	return w;
}

