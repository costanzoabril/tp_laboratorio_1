#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo texto).
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno = 1;
    char buffer[4][128];
    Employee* nuevoEmpleado = NULL;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n",buffer[0], buffer[1], buffer[2], buffer[3]);
        while(!feof(pFile))
        {
            if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]",buffer[0], buffer[1], buffer[2], buffer[3])==4)
            {
                nuevoEmpleado = employee_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);

                 if (nuevoEmpleado != NULL)
                {
                    ll_add(pArrayListEmployee, nuevoEmpleado);
                    retorno = 0;
                }
            }
            else
            {
                break;
            }
        }
    }
    return retorno;
}


/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo binario).
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
	Employee* pEmployee;

	if(pFile != NULL)
	{
		do
		{
			pEmployee = employee_new();
			if(fread(pEmployee, sizeof(Employee), 1, pFile) == 1)
			{
				ll_add(pArrayListEmployee, pEmployee);
				retorno = 0;
			}
		}while(!feof(pFile));
	}
    return retorno;
}
