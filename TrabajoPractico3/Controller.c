#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

#define NOMBRE_TAM 20

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
   int retorno = 1;

    FILE* pFile;
    pFile = fopen(path, "r");

    if(pFile != NULL)
    {
        if(!parser_EmployeeFromText(pFile, pArrayListEmployee))
        {
            retorno = 0;
        }

        fclose(pFile);
    }
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = 1;

    FILE* pFile;
    pFile = fopen(path, "rb");

    if(pFile != NULL)
    {
        if(!parser_EmployeeFromBinary(pFile, pArrayListEmployee))
        {
            retorno = 0;
        }

    fclose(pFile);
    }
    return retorno;
}

/** \brief Alta de empleados
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 1;
    char auxNombre[NOMBRE_TAM];
    int auxHoras;
    int auxSueldo;
    int nextId;

    Employee* pEmployee = employee_new();

    if(pArrayListEmployee != NULL)
    {
        if(   !utn_getCadena(auxNombre, 20, 2, "Ingrese nombre: ", "\nError, reingrese nombre: ")
           && !utn_getEntero(&auxHoras, 2, "Ingrese horas trabajadas: ", "\nError, reingrese horas trabajadas: ", 0, 99999)
           && !utn_getEntero(&auxSueldo, 2, "Ingrese sueldo: ", "\nError, reingrese sueldo: ", 5000, 100000))
        {
            nextId = controller_lastId(pArrayListEmployee) +1;

           if(   !employee_setId(pEmployee, nextId)
              && !employee_setNombre(pEmployee, auxNombre)
              && !employee_setHorasTrabajadas(pEmployee, auxHoras)
              && !employee_setSueldo(pEmployee, auxSueldo))
           {
               ll_add(pArrayListEmployee, pEmployee);
               printf("Alta exitosa.\n");
           }
           else
           {
               free(pEmployee);
           }
        }
        else
        {
            free(pEmployee);
        }
    }
    return retorno;
}

/** \brief Modificar datos de empleado
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int seguir = 0;
    int retorno = 1;
    int id;
    int index;
    Employee* pEmployee;

    if(pArrayListEmployee != NULL)
    {
        controller_ListEmployee(pArrayListEmployee);

        if(!utn_getEntero(&id, 2, "Ingrese id del empleado a modificar: ", "\nError, reingrese id: ", 0, controller_lastId(pArrayListEmployee)))
        {
            index = employee_SearchForId(pArrayListEmployee, id);

            do
            {
                switch(menuEdit())
                {
                    case 1:
                        if(editNombre(pArrayListEmployee, index) == 0)
                        {
                            printf("Modificacion exitosa.\n");
                            system("pause");
                        }
                        else
                        {
                            printf("Error.\n");
                        }
                        break;

                    case 2:
                        if(editHoras(pArrayListEmployee, index) == 0)
                        {
                            printf("Modificacion exitosa.\n");
                            system("pause");
                        }
                        else
                        {
                            printf("Error.\n");
                        }
                        break;

                    case 3:
                        if(editSueldo(pArrayListEmployee, index) == 0)
                        {
                            printf("Modificacion exitosa.\n");
                            system("pause");
                        }
                        else
                        {
                            printf("Error.\n");
                        }
                        break;

                    case 4:
                        seguir = 1;
                        break;
                }
            }while(seguir == 0);
        }
    }

    return retorno;
}

/** \brief Baja de empleado
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 1;
    int id;
    char respuesta;
    int index;
    Employee* pEmployee;

    if(pArrayListEmployee != NULL)
    {
        controller_ListEmployee(pArrayListEmployee);

        if(!utn_getEntero(&id, 2, "\nIngrese ID del empleado a eliminar: ", "\nError, reingrese ID: ", 0, controller_lastId(pArrayListEmployee)))
        {
            index = employee_SearchForId(pArrayListEmployee, id);
            pEmployee = ll_get(pArrayListEmployee, index);

            printf("\n  ID         Nombre      Horas trabajadas  Sueldo\n");
            employee_printEmployee(pEmployee);

            utn_getCadena(&respuesta, 2, 2, "\nEliminar empleado? (s/n): ", "Error, reingrese (s/n): ");
            if(respuesta == 's')
            {
                ll_remove(pArrayListEmployee, index);
                if(employee_delete(pEmployee) == 0)
                {
                    printf("Baja exitosa.\n");
                    retorno = 0;
                }
            }
            else if(respuesta == 'n')
            {
                printf("Baja cancelada.\n");
            }
        }
    }
    return retorno;
}

/** \brief Listar empleados
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
   int retorno = 1;
	int tam;
	int flag=0;
	Employee* pEmployee;

	if(pArrayListEmployee != NULL)
	{
	    tam = ll_len(pArrayListEmployee);
		retorno = 0;

		system("cls");
		printf("\n  ID   Nombre     Horas Trabajadas   Sueldo\n\n");

		for(int i =0; i<tam; i++)
		{
		    pEmployee = (Employee*)ll_get(pArrayListEmployee,i);
			if(pEmployee != NULL)
			{
				employee_printEmployee(pEmployee);
				flag=1;
			}
		}

		if(flag ==0)
        {
            printf("***No hay empleados***\n\n");
        }
        printf("\n\n");
	}
	return retorno;
}

/** \brief Ordenar empleados
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
   int seguir = 0;
    int retorno = 1;
    int id;
    int index;
    int orden;
    Employee* pEmployee;

    if(pArrayListEmployee != NULL)
    {
        do
        {
            switch(menuSort())
            {
                case 1:
                    orden = utn_getEntero(&orden, 2, "Ingrese 1 para ascedente o 0 para descendente: ", "\nError, reingrese: ", 0, 1);

                    ll_sort(pArrayListEmployee, sortById, orden);

                    printf("Empleados ordenados con exito.\n");
                    system("pause");
                    break;

                case 2:
                    orden = utn_getEntero(&orden, 2, "Ingrese 1 para ascedente o 0 para descendente: ", "\nError, reingrese: ", 0, 1);

                    if(ll_sort(pArrayListEmployee, sortByName, orden) == 1)
                    {
                        printf("Empleados ordenados con exito.\n");
                        system("pause");
                    }
                    else
                    {
                        printf("Error.\n");
                    }
                    break;

                case 3:
                    orden = utn_getEntero(&orden, 2, "Ingrese 1 para ascedente o 0 para descendente: ", "\nError, reingrese: ", 0, 1);

                    if(ll_sort(pArrayListEmployee, sortByHours, orden) == 1)
                    {
                        printf("Empleados ordenados con exito.\n");
                        system("pause");
                    }
                    else
                    {
                        printf("Error.\n");
                    }
                    break;

                case 4:
                    orden = utn_getEntero(&orden, 2, "Ingrese 1 para ascedente o 0 para descendente: ", "\nError, reingrese: ", 0, 1);

                    if(ll_sort(pArrayListEmployee, sortBySalary, orden) == 1)
                    {
                        printf("Empleados ordenados con exito.\n");
                        system("pause");
                    }
                    else
                    {
                        printf("Error.\n");
                    }
                    break;
                case 5:
                    seguir = 1;
                    break;
            }
        }while(seguir == 0);
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
   int retorno = 1;

	FILE* pFile;
	int auxId;
	char auxNombre[NOMBRE_TAM];
	int auxHoras;
	int auxSueldo;
	Employee* pEmployee;

	if(pArrayListEmployee != NULL && path != NULL)
	{
		pFile = fopen(path, "w");
		if(pFile != NULL)
		{
			retorno = 0;
			for(int i = 1; i < ll_len(pArrayListEmployee); i++)
			{
				pEmployee = ll_get(pArrayListEmployee, i);

				if(!employee_getId(pEmployee, &auxId) &&
				   !employee_getNombre(pEmployee, auxNombre) &&
				   !employee_getHorasTrabajadas(pEmployee, &auxHoras) &&
				   !employee_getSueldo(pEmployee, &auxSueldo))
				{
					fprintf(pFile, "%d,%s,%d,%d\n", auxId, auxNombre, auxHoras, auxSueldo);
				}
			}
			fclose(pFile);
		}
	}

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.bin (modo binario).
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = 1;
    int cant;

    FILE* pFile;

    Employee* pEmployee = (Employee*)employee_new();

    if (path != NULL && pArrayListEmployee != NULL && pEmployee != NULL && pFile != NULL)
    {
         pFile = fopen(path, "wb");

        for (int i=1; i<ll_len(pArrayListEmployee); i++)
        {
            pEmployee = (Employee*)ll_get(pArrayListEmployee, i);
            cant = fwrite(pEmployee, sizeof(Employee), 1, pFile );

            if (cant<1)
            {
                return 1;
            }
        }
        fclose(pFile);
        retorno = 0;
    }
    return retorno;
}

/** \brief Muestra el menu de modificaciones
 * \return opcion ingresada
 */
int menuEdit()
{
    int opcion;
    system("cls");

	printf("----Menu de Modificaciones----\n");
    printf("1. Modificar nombre.\n");
    printf("2. Modificar horas trabajadas.\n");
    printf("3. Modificar sueldo.\n");
    printf("4. Salir.\n");

    utn_getEntero(&opcion, 3, "Ingrese una opcion: ", "\nError, ingrese opcion valida: ", 1, 4);

	return opcion;
}

/** \brief Muestra el menu de ordenamiento
 * \return opcion ingresada
 */
int menuSort()
{
    int opcion;
    system("cls");

	printf("----Menu de Ordenamiento----\n");
	printf("1. Ordenar por id.\n");
    printf("2. Ordenar por nombre.\n");
    printf("3. Ordenar por horas trabajadas.\n");
    printf("4. Ordenar por sueldo.\n");
    printf("5. Salir.\n");

    utn_getEntero(&opcion, 3, "Ingrese una opcion: ", "\nError, ingrese opcion valida: ", 1, 5);

	return opcion;
}
