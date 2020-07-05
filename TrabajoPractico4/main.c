#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Drug.h"
#include "menus.h"

int main()
{
    int seguir = 0;
    int seguir2 = 0;
    int seguir3 = 0;
    int to;
    int from;

    LinkedList* lista = ll_newLinkedList();
    LinkedList* listaSeguridad;

    do{
        switch(menu())
        {
             case 1:
               if(controller_loadFromText("drugs.csv",lista))
               {
                   printf("Problemas al cargar los datos.\n");
               }
               else
               {
                   printf("Datos cargados correctamente.\n");
               }
                break;
            case 2:
                if(!controller_addDrug(lista))
                {
                    printf("\nDroga agregada con exito.\n\n");
                }
                break;
            case 3:
                if(ll_isEmpty(lista)==0)
                {
                    controller_editDrug(lista);
                }
                else
                {
                    printf("No hay datos cargados.\n");
                }
                break;
            case 4:
                if(ll_isEmpty(lista)==0)
                {
                    controller_removeDrug(lista);
                }
                else
                {
                    printf("No hay datos cargados.\n");
                }
                break;
            case 5:
                if(ll_isEmpty(lista)==0)
                {
                    controller_ListDrug(lista);
                }
                else
                {
                    printf("No hay datos cargados.\n");
                }
                break;
            case 6:
                if(ll_isEmpty(lista)==0)
                {
                    controller_sortDrug(lista);
                }
                else
                {
                    printf("No hay datos cargados.\n");
                }
                break;
            case 7:
                if(ll_isEmpty(lista)==0)
                {
                    if(!controller_saveAsText("drugs.csv", lista))
                    {
                        printf("\nListado en texto realizado con exito.\n\n");
                    }
                    else
                    {
                        printf("Problema para guardar los datos.\n");
                    }
                }
                else
                {
                    printf("Debe cargar los datos primero.\n");
                }
                break;
            case 8:
                if(ll_isEmpty(lista)==0)
                {
                    do
                    {
                        switch(menuCopias())
                        {
                        case 1:
                            listaSeguridad = ll_clone(lista);

                            if(listaSeguridad != NULL  && (ll_containsAll(lista, listaSeguridad)) ==1)
                            {
                                controller_saveAsText("drugsCopiaEntera.csv", listaSeguridad);
                                printf("Copia realiada con exito.\n");
                            }
                            else
                            {
                                printf("Error.\n");
                            }
                            break;
                        case 2:
                            controller_ListDrug(lista);

                            utn_getEntero(&from, 2, "Ingrese desde que id quiere copiar: ", "\nError\n", 1, ll_len(lista));
                            utn_getEntero(&to, 2, "Ingrese hasta que id quiere copiar: ", "\nError\n", 1, ll_len(lista));

                            listaSeguridad = ll_subList(lista, from, to);

                            if(listaSeguridad != NULL)
                            {
                                controller_saveAsText("drugsCopia.csv", listaSeguridad);
                                printf("Copia realizada con exito.\n");
                            }
                            else
                            {
                                printf("Error.\n");
                            }
                            break;
                        case 3:
                            seguir3 = 1;
                            break;
                        }
                        system("pause");
                    }while(seguir3 ==0);
                }
                else
                {
                    printf("No hay datos cargados para copiar.\n");
                }
                break;
            case 9:
                if(ll_isEmpty(lista)==0)
                {
                    do
                    {
                        switch(menuBorrar())
                        {
                        case 1:
                            if(ll_clear(lista)==0)
                            {
                                printf("Datos borrados con exito.\n");
                            }
                            else
                            {
                                printf("Error.\n");
                            }
                            break;
                        case 2:
                            if(ll_deleteLinkedList(lista)==0)
                            {
                                printf("Lista borrada exitosamente.\n");
                                exit(EXIT_FAILURE);
                            }
                            else
                            {
                                printf("Error.\n");
                            }
                            break;
                        case 3:
                            seguir2 =1;
                            break;
                        }
                        system("pause");
                    }while(seguir2 == 0);
                }
                else
                {
                    printf("No hay datos cargados.\n");
                }
                break;
            case 10:
                if(ll_isEmpty(lista)==0)
                {
                    if(!controller_relocate(lista))
                    {
                        printf("Reubicacion exitosa.\n");
                    }
                }
                else
                {
                    printf("No hay datos cargados.\n");
                }
                break;
            case 11:
                seguir = 1;
                break;
        }
        system("pause");
    }while(seguir == 0);
    return 0;
}
