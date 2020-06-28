#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "validaciones.h"

#define LEN 1000

int menu();
int menuInformes();
void informeSueldos();
int menuModificaciones();

int main(void)
{
	setbuf(stdout, NULL);

	int seguir = 0;
	char confirma;
	int id = 1000;
	int flag=1;
	int order;
	int idBaja;
	int indiceModif;
	int idModif;
	int empleados =1;
	eEmployee auxEmpleado;

	eEmployee list[LEN];
	initEmployees(list, LEN);

	do
	{
		switch(menu())
		{
		case 1:
			do
			{
				flag =0;
				id ++;
				system("cls");

				printf("\n---Alta Empleados---\n");

				utn_getCadena(auxEmpleado.name, 50, 3, "Ingrese nombre: ", "\nError, ingrese nombre valido");
				normalizeStr(auxEmpleado.name);

				utn_getCadena(auxEmpleado.lastName, 50, 3, "Ingrese apellido: ", "\nError: ingrese apellido valido");
				normalizeStr(auxEmpleado.lastName);

				utn_getFlotante(&auxEmpleado.salary, 3, "Ingrese sueldo: ", "\nError: ingrese sueldo valido" , 0, 999999);

				utn_getEntero(&auxEmpleado.sector, 3, "Ingrese sector (en numero): ", "\nError, ingrese un numero de 1 a 4" , 1, 4);

				addEmployee(list ,LEN, id, auxEmpleado.name, auxEmpleado.lastName, auxEmpleado.salary, auxEmpleado.sector);

				empleados++;
			}while(flag);
			break;

		case 2:
			if(id == 1000)
			{
				printf("****No hay empleados cargados.****\n\n");
			}
			else
			{
				printf("---Modificacion Empleado---\n");
				printEmployees(list, empleados);
				utn_getEntero(&idModif, 3, "Ingrese id del empleado: ", "\nError: ingrese id valido: ", 1001, 2001);
				indiceModif = findEmployeeById(list, LEN, idModif);
				if(indiceModif >= 0)
				{
					switch(menuModificaciones())
					{
					case 1:
						utn_getCadena(list[indiceModif].name, 50, 3, "Ingrese nuevo nombre: ", "\nError, ingrese nombre valido");
						printf("Modificacion exitosa\n");
						break;

					case 2:
						utn_getCadena(list[indiceModif].lastName, 50, 3, "Ingrese nuevo apellido: ", "\nError: ingrese apellido valido");
						printf("Modificacion exitosa\n");
						break;

					case 3:
						utn_getFlotante(&list[indiceModif].salary, 3, "Ingrese nuevo sueldo: ", "\nError: ingrese sueldo valido" , 0, 999999);
						printf("Modificacion exitosa\n");
						break;

					case 4:
						utn_getEntero(&list[indiceModif].sector, 3, "Ingrese nuevo sector (en numero): ", "\nError, ingrese un numero de 1 a 4" , 1, 4);
						printf("Modificacion exitosa\n");
						break;
					}
				}
			}
			break;

		case 3:
			if(id == 1000)
			{
				printf("****No hay empleados cargados.****\n\n");
			}
			else
			{
				printf("---Baja Empleados---\n");
				printEmployees(list, empleados);
				utn_getEntero(&idBaja, 3, "Ingrese el id del empleado: ", "\nError: ingrese id valido: ", 1001, 2001);
				removeEmployee(list, LEN, idBaja);
			}
			break;

		case 4:
			if(id == 1000)
			{
				printf("****No hay empleados cargados.****\n\n");
			}
			else
			{
				if(menuInformes() ==1)
				{
					utn_getEntero(&order, 3, "Ingrese modo 1(ascendente) o 2(descendente): ", "\nError: ingrese modo valido (1 o 2): ", 1, 2);

					sortEmployees(list,LEN, order);
				}
				else if(menuInformes() ==2)
				{
					informeSueldos(list, LEN);
				}
			}
			break;

		case 5:
            seguir = 1;
		}
		system("pause");
	}while(seguir == 0);

}

int menu()
{
	int opcion;
	system("cls");

	printf("--------Gestion de empleados--------\n");
	utn_getEntero(&opcion, 3, "\n1.Altas\n2.Modificaciones\n3.Bajas\n4.Informes\n5.Salir\n\nIngrese una opcion: ", "\nError, ingrese opcion valida: ", 1, 5);

	return opcion;
}

int menuInformes()
{
	int opcion;
	system("cls");

	printf("----Informes----\n");
	utn_getEntero(&opcion, 3, "1.Listado de empleados por apellido y sector.\n2.Total y promedio de salarios\n\nIngrese una opcion: ", "\nError, ingrese opcion valida: ", 1, 2);

	return opcion;
}

void informeSueldos(eEmployee list[], int len)
{
	float total = 0;
	int contador = 0;
	float promedio;
	int cantEmpleados =0;

	system("cls");

	printf("--------Informe sueldos--------\n");

	for(int i=0; i<len; i++)
	{
		if(list[i].isEmpty == 0)
		{
			total += list[i].salary;
			contador++;
		}
	}

	promedio = total/contador;

	for(int i=0; i<len; i++)
	{
		if (list[i].isEmpty == 0 && list[i].salary > promedio)
		{
			cantEmpleados++;
		}
	}
	printf("Total sueldos: $%.2f\nPromedio: $%.2f\nCantidad de empleados que superan el promedio: %d\n", total, promedio, cantEmpleados);
}

int menuModificaciones()
{
	int opcion;
    system("cls");
	utn_getEntero(&opcion, 3, "1.Modificar nombre\n2.Modificar apellido\n3.Modificar sueldo\n4.Modificar sector\n", "\nError, ingrese una opcion valida: ", 1, 4);

	return opcion;
}
