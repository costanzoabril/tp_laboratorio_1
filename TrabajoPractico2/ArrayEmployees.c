#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "validaciones.h"

int initEmployees(eEmployee list[], int len)
{
	int retorno = -1;
	for(int i=0; i<len; i++)
		{
			list[i].isEmpty =1;
			retorno =0;
		}
	return retorno;
}

int addEmployee(eEmployee list[], int len, int id, char name[],char lastName[],float salary,int sector)
{
	int retorno = -1;
	for(int i=0; i<len; i++)
	{
		if(list[i].isEmpty)
		{
			list[i].isEmpty = 0;
			list[i].id = id;
			strcpy(list[i].name, name);
			strcpy(list[i].lastName, lastName);
			list[i].salary = salary;
			list[i].sector = sector;

			retorno=0;
			break;
		}
	}
	return retorno;
}


int findEmployeeById(eEmployee list[], int len,int id)
{
	int indice = -1;
	for(int i=0; i<len; i++)
	{
		if(list[i].isEmpty == 0 && list[i].id == id)
		{
			indice = i;
			break;
		}
	}
	return indice;
}

int removeEmployee(eEmployee list[], int len, int id)
{
	int retorno =-1;
	int indice= findEmployeeById(list, len, id);

	if(list[indice].isEmpty == 0)
	{
		list[indice].isEmpty = 1;
		printf("Baja exitosa\n");
		retorno=0;
	}
	return retorno;
}


int sortEmployees(eEmployee list[], int len, int order)
{
	int retorno =-1;
	eEmployee auxEmpleado;

	if(order ==1)
	{
	for(int i=0; i<len -1; i++)
	{
		for(int j= i+1; j<len; j++)
		{
			if(list[i].sector > list[j].sector)
			{
				auxEmpleado = list[i];
				list[i] = list[j];
				list[j] = auxEmpleado;
			}
			else if(list[i].sector == list[j].sector && strcmp(list[i].lastName, list[j].lastName) >0)
			{
				auxEmpleado = list[i];
				list[i] = list[j];
				list[j] = auxEmpleado;
			}
		}
	}
	printEmployees(list, len);
	return 0;
	}
	else if(order ==2)
	{
	for(int i=0; i<len -1; i++)
	{
		for(int j= i+1; j<len; j++)
		{
			if(list[i].sector < list[j].sector)
			{
				auxEmpleado = list[i];
				list[i] = list[j];
				list[j] = auxEmpleado;
			}
			else if(list[i].sector == list[j].sector && strcmp(list[i].lastName, list[j].lastName) <0)
			{
				auxEmpleado = list[i];
				list[i] = list[j];
				list[j] = auxEmpleado;
			}
		}
	}
	printEmployees(list, len);
	return 0;
	}
	return retorno;
}

int printEmployees(eEmployee list[], int lenght)
{
	int retorno =-1;

	system("cls");

	printf("--------------Listado de Empleados---------------\n");
	printf("  Id      Nombre    Apellido   Sueldo      Sector\n\n");

	for(int i=0; i<lenght; i++)
	{
		if(list[i].isEmpty == 0)
		{
			printf(" %4d%10s   %10s  %6.2f%10d\n\n", list[i].id, list[i].name, list[i].lastName, list[i].salary, list[i].sector);
			retorno=0;
		}
	}
	return retorno;
}
