#include <stdio.h>
#include <stdlib.h>
#include "calculadora.h"

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
	int flag = 0;
	int flag2 = 0;
	int flag3 = 0;

	do{
            system("cls");
		respuesta = utn_getNumero(&opcion,"MENU\n1.Ingresar 1er operando (A=x).\n2.Ingresar 2do operando(B=x).\n3.Calcular todas las operaciones.\n4.Informar resultados\n5.Salir.\n","Errror, no es una opcion valida",1,5,2);

			if(respuesta == 0)
			{
				switch(opcion)
				{
				case 1:
					utn_getNumero(&primerOperando, "Ingrese el 1er operando: ", "\nError, reingrese: ",0, 9999999, 2);
					flag = 1;
				break;

				case 2:
					if(flag == 1)
					{
					utn_getNumero(&segundoOperando, "Ingrese el 2do operando: ", "\nError, reingrese: ",0, 9999999, 2);
					flag2 = 1;
					}
					else
					{
						printf("Debe ingresar el primer operando primero.\n");
						system("pause");
					}
				break;

				case 3:
					if(flag == 1 && flag2 == 1)
					{
					    flag3 = 1;
                        suma = sumar(primerOperando, segundoOperando);
                        resta = restar(primerOperando, segundoOperando);
                        multiplicacion = multiplicar(primerOperando, segundoOperando);
                        division = dividir(primerOperando, segundoOperando);

                        printf("Calculos realizados con exito.\n");
                        system("pause");
					}
					else
					{
						printf("Debe ingresar los operandos primero.\n");
						system("pause");
					}

				break;

				case 4:
					if(flag == 1 && flag2 == 1 && flag3 ==1)
					{
                        printf("La suma es: %d", suma);
                        printf("\nLa resta es: %d", resta);
                        printf("\nLa multiplicacion es: %d", multiplicacion);
                        printf("\nLa division es : %d\n", division);
                        system("pause");
					}
					else
					{
						printf("Debe ingresar los operandos y calcularlos primero.\n");
						system("pause");
					}
				break;
				}
			}
	}while(opcion != 5);

    return EXIT_SUCCESS;
}
