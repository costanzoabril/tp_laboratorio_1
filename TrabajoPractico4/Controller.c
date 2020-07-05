#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Drug.h"
#include "parser.h"
#include "menus.h"

#define NOMBRE_TAM 30

/** \brief Carga los datos desde el archivo data.csv (modo texto).
 * \param path char*
 * \param list LinkedList*
 * \return int 1 en caso de error, 0 en caso de exito
 */
int controller_loadFromText(char* path , LinkedList* list)
{
   int retorno = 1;

    FILE* pFile;
    pFile = fopen(path, "r");

    if(pFile != NULL)
    {
        if(!parser_DrugFromText(pFile, list))
        {
            retorno = 0;
        }
        fclose(pFile);
    }
    return retorno;
}

/** \brief Carga los datos desde el archivo data.csv (modo binario).
 * \param path char*
 * \param list LinkedList*
 * \return int 1 en caso de error, 0 en caso de exito
 */
int controller_loadFromBinary(char* path , LinkedList* list)
{
    int retorno = 1;

    FILE* pFile;
    pFile = fopen(path, "rb");

    if(pFile != NULL)
    {
        if(!parser_DrugFromBinary(pFile, list))
        {
            retorno = 0;
        }
    fclose(pFile);
    }
    return retorno;
}

/** \brief Alta de droga
 * \param path char*
 * \param list LinkedList*
 * \return int 1 en caso de error, 0 en caso de exito
 */
int controller_addDrug(LinkedList* list)
{
    int retorno = 1;
    char auxNombre[NOMBRE_TAM];
    char auxLab[NOMBRE_TAM];
    int auxPrecio;
    int nextId;

    eDrug* pDrug = drug_new();

    if(list != NULL)
    {
        if(   !utn_getCadena(auxNombre, 20, 2, "Ingrese nombre de la droga: ", "\nError\n")
           && !utn_getCadena(auxLab, 20, 2, "Ingrese laboratorio: ", "\nError\n")
           && !utn_getEntero(&auxPrecio, 2, "Ingrese precio: ", "\nError\n", 20, 3000))
        {
            nextId = drug_lastId(list) +1;

           if(   !drug_setId(pDrug, nextId)
              && !drug_setNombre(pDrug, auxNombre)
              && !drug_setLab(pDrug, auxLab)
              && !drug_setPrecio(pDrug, auxPrecio))
           {
               ll_add(list, pDrug);
               printf("Alta exitosa.\n");
           }
           else
           {
               free(pDrug);
           }
        }
        else
        {
            free(pDrug);
        }
    }
    return retorno;
}

/** \brief Listar drogas
 * \param path char*
 * \param list LinkedList*
 * \return int
 */
int controller_ListDrug(LinkedList* list)
{
   int retorno = 1;
	int tam;
	int flag=0;
	eDrug* pDrug;

	if(list != NULL)
	{
	    tam = ll_len(list);
		retorno = 0;

		system("cls");
		printf("\n  ID            Nombre              Laboratorio      Precio\n\n");

		for(int i =0; i<tam; i++)
		{
		    pDrug = (eDrug*)ll_get(list,i);
			if(pDrug != NULL)
			{
				drug_printDrug(pDrug);
				flag=1;
			}
		}

		if(flag ==0)
        {
            printf("***No hay drogas***\n\n");
        }
        printf("\n\n");
	}
	return retorno;
}

/** \brief Modificar datos
 * \param path char*
 * \param list LinkedList*
 * \return int
 */
int controller_editDrug(LinkedList* list)
{
    int seguir = 0;
    int retorno = 1;
    int id;
    int index;

    if(list != NULL)
    {
        controller_ListDrug(list);

        if(!utn_getEntero(&id, 2, "Ingrese id de la droga a modificar: ", "\nError\n", 0, drug_lastId(list)))
        {
            index = drug_SearchForId(list, id);

            do
            {
                switch(menuEdit())
                {
                    case 1:
                        if(editNombre(list, index) == 0)
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
                        if(editLab(list, index) == 0)
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
                        if(editPrecio(list, index) == 0)
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

/** \brief Baja de droga
 * \param path char*
 * \param list LinkedList*
 * \return int
 */
int controller_removeDrug(LinkedList* list)
{
    int retorno = 1;
    int id;
    char respuesta;
    int index;
    eDrug* pDrug;

    if(list != NULL)
    {
        controller_ListDrug(list);

        if(!utn_getEntero(&id, 2, "\nIngrese ID de la droga a eliminar: ", "\nError\n", 0, drug_lastId(list)))
        {
            index = drug_SearchForId(list, id);
            pDrug = ll_get(list, index);

            printf("\n  ID      Nombre      Laboratorio   Precio\n");
            drug_printDrug(pDrug);

            utn_getCadena(&respuesta, 2, 2, "\nEliminar droga? (s/n): ", "\nError\n");
            if(respuesta == 's')
            {
                ll_remove(list, index);
                if(drug_delete(pDrug) == 0)
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

/** \brief Ordenar drogas
 * \param path char*
 * \param list LinkedList*
 * \return int
 */
int controller_sortDrug(LinkedList* list)
{
   int seguir = 0;
    int retorno = 1;
    int orden;

    if(list != NULL)
    {
        do
        {
            switch(menuSort())
            {
                case 1:
                    orden = utn_getEntero(&orden, 2, "Ingrese 1 para ascedente o 0 para descendente: ", "\nError\n", 0, 1);

                    ll_sort(list, sortById, orden);

                    printf("Datos ordenados con exito.\n");
                    system("pause");
                    break;

                case 2:
                    orden = utn_getEntero(&orden, 2, "Ingrese 1 para ascedente o 0 para descendente: ", "\nError\n", 0, 1);

                    if(ll_sort(list, sortByName, orden) == 0)
                    {
                        printf("Datos ordenados con exito.\n");
                        system("pause");
                    }
                    else
                    {
                        printf("Error.\n");
                    }
                    break;

                case 3:
                    orden = utn_getEntero(&orden, 2, "Ingrese 1 para ascedente o 0 para descendente: ", "\nError\n", 0, 1);

                    if(ll_sort(list, sortByLab, orden) == 0)
                    {
                        printf("Datos ordenados con exito.\n");
                        system("pause");
                    }
                    else
                    {
                        printf("Error.\n");
                    }
                    break;

                case 4:
                    orden = utn_getEntero(&orden, 2, "Ingrese 1 para ascedente o 0 para descendente: ", "\nError\n", 0, 1);

                    if(ll_sort(list, sortByPrecio, orden) == 0)
                    {
                        printf("Datos ordenados con exito.\n");
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
            system("pause");
        }while(seguir == 0);
    }
    return retorno;
}

/** \brief Guarda los datos en el archivo data.csv (modo texto).
 * \param path char*
 * \param list LinkedList*
 * \return int
 */
int controller_saveAsText(char* path , LinkedList* list)
{
   int retorno = 1;

	FILE* pFile;
	int auxId;
	char auxNombre[NOMBRE_TAM];
	char auxLab[NOMBRE_TAM];
	float auxPrecio;
	eDrug* pDrug;

	if(list != NULL && path != NULL)
	{
		pFile = fopen(path, "w");
		if(pFile != NULL)
		{
			retorno = 0;
			for(int i = 1; i < ll_len(list); i++)
			{
				pDrug = ll_get(list, i);

				if(!drug_getId(pDrug, &auxId) &&
				   !drug_getNombre(pDrug, auxNombre) &&
				   !drug_getLab(pDrug, auxLab) &&
				   !drug_getPrecio(pDrug, &auxPrecio))
				{
					fprintf(pFile, "%d,%s,%s,%f\n", auxId, auxNombre, auxLab, auxPrecio);
				}
			}
			fclose(pFile);
		}
	}
    return retorno;
}

/** \brief Guarda los datos en el archivo data.bin (modo binario).
 * \param path char*
 * \param list LinkedList*
 * \return int
 */
int controller_saveAsBinary(char* path , LinkedList* list)
{
    int retorno = 1;
    int cant;

    FILE* pFile;

    eDrug* pDrug = (eDrug*)drug_new();

    if (path != NULL && list != NULL && pDrug != NULL && pFile != NULL)
    {
         pFile = fopen(path, "wb");

        for (int i=1; i<ll_len(list); i++)
        {
            pDrug = (eDrug*)ll_get(list, i);
            cant = fwrite(pDrug, sizeof(eDrug), 1, pFile );

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


/** \brief Reubica un elemento
 * \param LinkedList* list
 * \return int
 */
int controller_relocate(LinkedList* list)
{
	int retorno = 1;
	int id;
	int nextId;
	int index;
	eDrug* pDrug;
	int id2;
	int index2;
	char respuesta;

	if(list != NULL)
	{
		controller_ListDrug(list);
		nextId = drug_lastId(list) +1;
		utn_getEntero(&id, 2, "Ingrese ID de la droga a reubicar: ", "\nError\n", 1, nextId - 1);

		index = drug_SearchForId(list, id);
		pDrug = (eDrug*) ll_pop(list, index);

		if(index > -1 && pDrug != NULL)
		{
			printf("\n  ID            Nombre              Laboratorio      Precio\n\n");
			drug_printDrug(pDrug);

			printf("Confirma la reubicacion? s/n: ");
			fflush(stdin);
			scanf("%c", &respuesta);
			if(respuesta == 's')
			{
				controller_ListDrug(list);

				if(utn_getEntero(&id2, 2, "Luego de que droga quiere insertarlo? Ingresar ID: ", "\nError\n", 1, nextId - 1)==0)
				{
					index2 = drug_SearchForId(list, id2);
					if(index2 > -1)
					{
						ll_push(list, index2+1, pDrug);
						retorno = 0;
					}
					else
					{
						printf("Error, ID inexistente.\n\n");
						ll_push(list, index, pDrug);
					}
				}
				else
				{
					ll_push(list, index, pDrug);
				}
			}
			else if(respuesta == 'n')
            {
                printf("Reubicacion cancelada.\n");
            }
		}
		else
		{
			printf("Error, ID inexistente.\n\n");
		}
	}

	return retorno;
}
