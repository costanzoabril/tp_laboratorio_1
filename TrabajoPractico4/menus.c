#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"
#include "menus.h"

/** \brief Muestra el menu de modificaciones
 * \return opcion ingresada
 */
int menuEdit()
{
    int opcion;
    system("cls");

	printf("----Menu de Modificaciones----\n");
    printf("1. Modificar nombre.\n");
    printf("2. Modificar laboratorio\n");
    printf("3. Modificar precio.\n");
    printf("4. Salir.\n");

    utn_getEntero(&opcion, 3, "Ingrese una opcion: ", "\nError\n", 1, 4);

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
    printf("3. Ordenar por laboratorio.\n");
    printf("4. Ordenar por precio.\n");
    printf("5. Salir.\n");

    utn_getEntero(&opcion, 3, "Ingrese una opcion: ", "\nError\n", 1, 5);

	return opcion;
}

/** \brief Muestra el menu principal
 * \return opcion ingresada
 */
int menu()
{
    int opcion;
    system("cls");

	printf("-------Menu Base de Datos de Drogas-------\n");
    printf("1. Cargar los datos desde el archivo.\n");
    printf("2. Alta.\n");
    printf("3. Modificacion de datos.\n");
    printf("4. Baja.\n");
    printf("5. Listar datos.\n");
    printf("6. Ordenar datos.\n");
    printf("7. Guardar los datos en el archivo.\n");
    printf("8. Crear copia de seguridad.\n");
    printf("9. Borrar lista.\n");
    printf("10. Reubicar datos.\n");
    printf("11. Salir\n");

    utn_getEntero(&opcion, 3, "Ingrese una opcion: ", "\nError\n", 1, 11);

	return opcion;
}

/** \brief Muestra el menu para borrar
 * \return opcion ingresada
 */
int menuBorrar()
{
    int opcion;
    system("cls");

    printf("----Menu Borrar----\n");
    printf("1. Borrar todos los datos de la lista.\n");
    printf("2. Borrar todos los datos y la lista incluida.\n");
    printf("3. Salir.\n");

    utn_getEntero(&opcion, 3, "Ingrese una opcion: ", "\nError\n", 1, 3);

	return opcion;
}

/** \brief Muestra el menu para copiar la lista
 * \return opcion ingresada
 */
int menuCopias()
{
    int opcion;
    system("cls");

    printf("----Menu Copiar----\n");
    printf("1. Copiar todos los datos de la lista en una nueva.\n");
    printf("2. Copiar datos seleccionados de la lista a una nueva.\n");
    printf("3. Salir.\n");

    utn_getEntero(&opcion, 3, "Ingrese una opcion: ", "\nError\n", 1, 3);

	return opcion;
}
