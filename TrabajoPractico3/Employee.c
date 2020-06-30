#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

#define NOMBRE_TAM 20

Employee* employee_new()
{
    return (Employee*) malloc(sizeof(Employee));
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* nuevo = employee_new();

	if(nuevo != NULL)
	{
		if(employee_setId(nuevo, atoi(idStr))
            || employee_setNombre(nuevo, nombreStr)
            || employee_setHorasTrabajadas(nuevo, atoi(horasTrabajadasStr))
            || employee_setSueldo(nuevo, atoi(sueldoStr)))
		{
			employee_delete(nuevo);
			nuevo = NULL;
		}
	}
	return nuevo;
}

int employee_delete(Employee* this)
{
    int retorno = 1;
	if(this != NULL)
	{
		free(this);
		retorno = 0;
	}
	return retorno;
}

int employee_setId(Employee* this,int id)
{
    int retorno = 1;

	if(this != NULL && id >=0)
	{
		this->id = id;
		retorno = 0;
	}
	return retorno;
}

int employee_getId(Employee* this,int* id)
{
   int retorno = 1;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int retorno = 1;

	if(this != NULL && nombre != NULL && strlen(nombre) >= 3 && strlen(nombre) <20)
	{
		strcpy(this->nombre, nombre);
		retorno = 0;
		}
	return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int retorno = 1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
		retorno = 0;
	}
	return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno = 1;

	if(this != NULL && horasTrabajadas >=0)
	{
		this->horasTrabajadas = horasTrabajadas;
		retorno = 0;
	}
	return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno = 1;

	if(this != NULL && horasTrabajadas != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		retorno = 0;
	}
	return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno = 1;

	if(this != NULL && sueldo >0)
	{
		this->sueldo = sueldo;
		retorno = 0;
	}
	return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno = 1;

	if(this != NULL && sueldo != NULL)
	{
		*sueldo = this->sueldo;
		retorno = 0;
	}
	return retorno;
}

void employee_printEmployee(Employee* pEmployee)
{
	if(pEmployee != NULL)
	{
		printf("%5d    %10s    %10d    %10d\n", pEmployee->id, pEmployee->nombre, pEmployee->horasTrabajadas, pEmployee->sueldo);
	}
}

int editNombre(LinkedList* pArrayListEmployee, int index)
{
	int retorno = 1;
	char nuevoNombre[NOMBRE_TAM];
	Employee* pEmployee;

	pEmployee = ll_get(pArrayListEmployee, index);

	if(utn_getCadena(nuevoNombre, NOMBRE_TAM, 2, "\nIngrese nuevo nombre: ","\nError, reingrese nuevo nombre: ") == 0)
	{
		employee_setNombre(pEmployee, nuevoNombre);
		retorno = 0;
	}
	return retorno;
}

int editHoras(LinkedList* pArrayListEmployee, int index)
{
	int retorno = 1;
	int horas;
	Employee* pEmployee;

	pEmployee = ll_get(pArrayListEmployee, index);

	if(utn_getEntero(&horas, 2, "Ingrese horas trabajadas: ", "\nError, reingrese horas: ", 0, 999999) == 0)
	{
		employee_setHorasTrabajadas(pEmployee, horas);
		retorno = 0;
	}
	return retorno;
}

int editSueldo(LinkedList* pArrayListEmployee, int index)
{
	int retorno = 1;
	int sueldo;
	Employee* pEmployee;

	pEmployee = ll_get(pArrayListEmployee, index);

	if(utn_getEntero(&sueldo, 2, "Ingrese nuevo sueldo:  ", "\nError, reingrese sueldo (5000-100000): ", 5000, 100000) == 0)
	{
		employee_setSueldo(pEmployee, sueldo);
		retorno = 0;
	}
	return retorno;
}

int controller_lastId(LinkedList* pArrayListEmployee)
{
	Employee* pEmployee;
	int len = ll_len(pArrayListEmployee);
	int auxId;
	int lastId = -1;

	if(pArrayListEmployee != NULL)
	{
		for(int i = 0; i < len; i++)
		{
			pEmployee = (Employee*) ll_get(pArrayListEmployee,i);
			employee_getId(pEmployee, &auxId);

			if(auxId > lastId)
			{
				lastId = auxId;
			}
		}
	}
	return lastId;
}

int employee_SearchForId(LinkedList* pArrayListEmployee, int id)
{
	int retorno = 1;
	int idAux;
	Employee* pEmployee;

	for(int index = 0; index < ll_len(pArrayListEmployee); index++)
	{
		pEmployee = ll_get(pArrayListEmployee, index);

		if(employee_getId(pEmployee, &idAux) == 0 &&
		   idAux == id)
		{
			retorno = index;
			break;
		}		
	}
	return retorno;
}

int sortById(void* aux1, void* aux2)
{
    int retorno = 0;
	int id1;
	int id2;

	employee_getId(aux1, &id1);
	employee_getId(aux2, &id2);

	if(id1 > id2)
	{
		retorno = 1;
	}
	else if(id1 < id2)
	{
		retorno = -1;
	}

	return retorno;
}

int sortByName(void* aux1, void* aux2)
{
	int retorno = 0;
	char name1[NOMBRE_TAM];
	char name2[NOMBRE_TAM];

	employee_getNombre(aux1, name1);
	employee_getNombre(aux2, name2);

	if(strcmp(name1, name2) > 0)
	{
		retorno = 1;
	}
	else if(strcmp(name1, name2) < 0)
	{
		retorno = -1;
	}
	return retorno;
}

int sortByHours(void* aux1, void* aux2)
{
	int retorno = 0;
	int horas1;
	int horas2;

	employee_getHorasTrabajadas(aux1, &horas1);
	employee_getHorasTrabajadas(aux2, &horas2);

	if(horas1 > horas2)
	{
		retorno = 1;
	}
	else if(horas1 < horas2)
	{
		retorno = -1;
	}
	return retorno;
}

int sortBySalary(void* aux1, void* aux2)
{
	int retorno = 0;
	int sueldo1;
	int sueldo2;

	employee_getSueldo(aux1, &sueldo1);
	employee_getSueldo(aux2, &sueldo2);

	if(sueldo1 > sueldo2)
	{
		retorno = 1;
	}
	else if(sueldo1 < sueldo2)
	{
		retorno = -1;
	}
	return retorno;
}
