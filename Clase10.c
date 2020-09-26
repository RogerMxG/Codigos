/*
	CADENAS
	Implementar un programa en lenguaje C que reciba una frase
	y entregue como resultado una tabla como la siguiente:
	
	"Saludos a todos los presentes"
	
	PALABRAS			NO. CARACTERES
	Saludos						7
	a							1
	todos						5
	los 						3
	presentes 					9
	
	TOTAL DE PALABRAS = 5
	TOTAL DE CARACTERES = 25
*/

#include <stdio.h>

int main (void){
	char frase[200];
	unsigned int id;
	unsigned int contador_Palabras=0;
	unsigned int contador_CaracteresPalabras;
	unsigned int total_Caracteres=0;;
	
	printf("Esriba una frase: " );
	scanf("%[^\n]s", frase); fflush(stdin);
	
	id = 0;
	printf("PALABRAS     No. CARACTERES\n");
	//Encontrar una palabra en especifico
	while(frase[id] != '\0'){
		
		//Empieza a brincar los espacios que hay en la frase
		while (frase[id] == ' '){
			id++; //Sumamos el indice para volver al ciclo
		}
		contador_Palabras++; //Contamos cada palabra que encontramos
		
		//Recorrer el arreglo hasta encontrar el siguiente espacio
		contador_CaracteresPalabras=0;
		while (frase[id] != ' ' && frase[id] != '\0'){
			
			printf("%c", frase[id]);
			
			contador_CaracteresPalabras++; //Contamos cada caracter de la palabra
			id ++; //Sumamos el indice para volver al ciclo
		}
		printf("\t      %u \n", contador_CaracteresPalabras);
		total_Caracteres += contador_CaracteresPalabras;
	}
	
	printf("\n%s", frase);
	printf ("\nEl total de palabras es: %u", contador_Palabras);
	printf ("\nEl total de caracteres es: %u", total_Caracteres);
	
	printf("\n\nPresiona <ENTER> para salir");

	getchar ();
	return 0;
}