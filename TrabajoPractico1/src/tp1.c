/*
 * tp1.c
 *
 *  Created on: 15 abr. 2020
 *      Author: Abril Costanzo
 *
 */

#include <stdio.h>
#include <stdlib.h>

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			scanf("%d",&bufferInt);
			if(bufferInt >= minimo && bufferInt <= maximo)
			{
				*pResultado = bufferInt;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}

int sumar(int a, int b)
{
	int suma = a + b;
	return suma;
}

int restar(int a, int b)
{
	int resta = a - b;
	return resta;
}

int multiplicar(int a, int b)
{
	int multiplicacion = a * b;
	return multiplicacion;
}

float dividir(float a, float b)
{
	float division;

	if(b != 0)
	{
		division = a / b;
	}
	else
	{
        division = printf("No es posible dividir por cero.");
	}
	return division;
}

