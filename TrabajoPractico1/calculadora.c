#include <stdio.h>
#include <stdlib.h>

/** \brief Obtiene y valida un numero
 *
 * \param int* pResultado
 * \param char* mensaje
 * \param char* mensajeError
 * \param int minimo
 * \param int maximo
 * \param int reintentos
 * \return -1 en caso de error, 0 en caso de exito
 *
 */
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

/** \brief Suma dos numeros
 *
 * \param int a
 * \param int b
 * \return resultado
 *
 */
int sumar(int a, int b)
{
	int suma = a + b;
	return suma;
}

/** \brief Resta dos numeros
 *
 * \param int a
 * \param int b
 * \return resultado
 *
 */
int restar(int a, int b)
{
	int resta = a - b;
	return resta;
}


/** \brief Multiplica dos numeros
 *
 * \param int a
 * \param int b
 * \return resultado
 *
 */
int multiplicar(int a, int b)
{
	int multiplicacion = a * b;
	return multiplicacion;
}

/** \brief Divide dos numeros
 *
 * \param int a
 * \param int b
 * \return resultado
 *
 */
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
