#include <stdio.h>
#include <stdlib.h>

int menu(int a, int b)
{
	int opcion;

	printf("MENU\n1.Ingresar 1er operando (A=%d).\n2.Ingresar 2do operando(B=%d).\n3.Calcular todas las operaciones.\n4.Informar resultados\n5.Salir.\n",a,b);
	scanf("%d", &opcion);

	return opcion;
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
	float division = a / b;
	return division;
}
