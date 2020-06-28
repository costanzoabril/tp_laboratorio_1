/*
 ============================================================================
 Name        : TrabajoPractico1.c
 Author      : Abril Costanzo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "tp1.h"

int main()
{

	int opcion;
	int respuesta;
	int primerOperando;
	int segundoOperando;
	int resta;
	int suma;
	int multiplicacion;
	int division;

	do{
		respuesta = utn_getNumero(&opcion,"MENU\n1.Ingresar 1er operando (A=x).\n2.Ingresar 2do operando(B=x).\n3.Calcular todas las operaciones.\n4.Informar resultados\n5.Salir.\n","Errror, no es una opcion valida",1,5,2);

			if(respuesta == 0)
			{
				switch(opcion)
				{
				case 1:
					printf("Ingrese el 1er operando: ");
					scanf("%d", &primerOperando);
				break;

				case 2:
					printf("Ingrese el 2do operando: ");
					scanf("%d", &segundoOperando);
				break;

				case 3:
					suma = sumar(primerOperando, segundoOperando);
					resta = restar(primerOperando, segundoOperando);
					multiplicacion = multiplicar(primerOperando, segundoOperando);
					division = dividir(primerOperando, segundoOperando);

				break;

				case 4:
					printf("La suma es: %d", suma);
					printf("La resta es: %d", resta);
					printf("La multiplicacion es: %d", multiplicacion);
					printf("La division es : %d", division);
				break;
				}
			}
	}while(opcion != 5);

return EXIT_SUCCESS;
}
