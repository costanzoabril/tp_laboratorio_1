#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

int menu();

int main()
{
    int seguir = 0;
    int flag = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
        switch(menu())
        {
            case 1:
               if(controller_loadFromText("data.csv",listaEmpleados))
               {
                   printf("Problemas al cargar los empleados.\n");
               }
               else
               {
                   printf("Empleados cargados correctamente.\n");
                   flag = 1;
               }
                break;
            case 2:
                if(controller_loadFromBinary("data.bin", listaEmpleados))
                {
                    printf("Problemas al cargar los empleados.\n");
                }
                else
                {
                    printf("Empleados cargados correctamente.\n");
                    flag = 1;
                }
                break;
            case 3:
                if(!controller_addEmployee(listaEmpleados))
                {
                    printf("\nEmpleado agregado con exito.\n\n");
                }
                break;
            case 4:
                if(flag == 1)
                {
                    controller_editEmployee(listaEmpleados);
                }
                else
                {
                    printf("No hay empleados cargados.\n");
                }
                break;
            case 5:
                if(flag == 1)
                {
                    controller_removeEmployee(listaEmpleados);
                }
                else
                {
                    printf("No hay empleados cargados.\n");
                }
                break;
            case 6:
                 if(flag == 1)
                {
                    controller_ListEmployee(listaEmpleados);
                }
                else
                {
                    printf("No hay empleados cargados.\n");
                }
                break;
            case 7:
                if(flag == 1)
                {
                    controller_sortEmployee(listaEmpleados);
                }
                else
                {
                    printf("No hay empleados cargados.\n");
                }
                break;
            case 8:
                if(flag == 1)
                {
                    if(!controller_saveAsText("data.csv", listaEmpleados))
                    {
                        printf("\nListado en texto realizado con exito.\n\n");
                    }
                    else
                    {
                        printf("Problema para guardar los empleados.\n");
                    }
                }
                else
                {
                    printf("Debe cargar los datos primero.\n");
                }
                break;
            case 9:
                if(flag == 1)
                {
                     if(!controller_saveAsBinary("data.bin", listaEmpleados))
                    {
                        printf("\nListado en binario realizado con exito.\n\n");
                    }
                    else
                    {
                        printf("Problema para guardas los empleados.\n");
                    }
                }
                else
                {
                    printf("Debe cargar los datos primero.\n");
                }
                break;
            case 10:
                seguir = 1;
                break;
        }
        system("pause");
    }while(seguir == 0);
    return 0;
}

/** \brief Muestra el menu
 * \return opcion ingresada
 */
int menu()
{
    int opcion;
    system("cls");

	printf("----Menu----\n");
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
    printf("3. Alta de empleado.\n");
    printf("4. Modificar datos de empleado.\n");
    printf("5. Baja de empleado.\n");
    printf("6. Listar empleados.\n");
    printf("7. Ordenar empleados.\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
    printf("10. Salir.\n\n");

    utn_getEntero(&opcion, 3, "Ingrese una opcion: ", "\nError, ingrese opcion valida: ", 1, 10);

	return opcion;
}
