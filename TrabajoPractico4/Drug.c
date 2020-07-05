#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Drug.h"

#define NOMBRE_TAM 20
eDrug* drug_new()
{
    return (eDrug*) malloc(sizeof(eDrug));
}

eDrug* drug_newParametros(char* idStr,char* nombreStr,char* laboratorioStr, char* precioStr)
{
    eDrug* nuevo = drug_new();

	if(nuevo != NULL)
	{
		if(    drug_setId(nuevo, atoi(idStr))
            || drug_setNombre(nuevo, nombreStr)
            || drug_setLab(nuevo, laboratorioStr)
            ||drug_setPrecio(nuevo, atoi(precioStr)))
		{
			drug_delete(nuevo);
			nuevo = NULL;
		}
	}
	return nuevo;
}

int drug_delete(eDrug* this)
{
    int retorno = 1;
	if(this != NULL)
	{
		free(this);
		retorno = 0;
	}
	return retorno;
}

int drug_setId(eDrug* this,int id)
{
    int retorno = 1;

	if(this != NULL && id >=0)
	{
		this->id = id;
		retorno = 0;
	}
	return retorno;
}

int drug_getId(eDrug* this,int* id)
{
   int retorno = 1;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}

int drug_setNombre(eDrug* this,char* nombre)
{
    int retorno = 1;

	if(this != NULL && nombre != NULL && strlen(nombre) >= 3 && strlen(nombre) <20)
	{
		strcpy(this->nombre, nombre);
		retorno = 0;
		}
	return retorno;
}

int drug_getNombre(eDrug* this,char* nombre)
{
    int retorno = 1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
		retorno = 0;
	}
	return retorno;
}

int drug_setLab(eDrug* this,char* laboratorio)
{
    int retorno = 1;

	if(this != NULL && laboratorio != NULL && strlen(laboratorio) >= 3 && strlen(laboratorio) <20)
	{
		strcpy(this->laboratorio, laboratorio);
		retorno = 0;
		}
	return retorno;
}

int drug_getLab(eDrug* this,char* laboratorio)
{
    int retorno = 1;

	if(this != NULL && laboratorio != NULL)
	{
		strcpy(laboratorio, this->laboratorio);
		retorno = 0;
	}
	return retorno;
}

int drug_setPrecio(eDrug* this,float precio)
{
    int retorno = 1;

	if(this != NULL && precio >0)
	{
		this->precio = precio;
		retorno = 0;
	}
	return retorno;
}

int drug_getPrecio(eDrug* this,float* precio)
{
    int retorno = 1;

	if(this != NULL && precio != NULL)
	{
		*precio = this->precio;
		retorno = 0;
	}
	return retorno;
}


void drug_printDrug(eDrug* pDrug)
{
	if(pDrug != NULL)
	{
		printf("%5d    %18s    %18s    %.2f\n", pDrug->id, pDrug->nombre, pDrug->laboratorio, pDrug->precio);
	}
}

int drug_lastId(LinkedList* list)
{
	eDrug* pDrug;
	int len = ll_len(list);
	int auxId;
	int lastId = -1;

	if(list != NULL)
	{
		for(int i = 0; i < len; i++)
		{
			pDrug = (eDrug*) ll_get(list,i);
			drug_getId(pDrug, &auxId);

			if(auxId > lastId)
			{
				lastId = auxId;
			}
		}
	}
	return lastId;
}

int drug_SearchForId(LinkedList* list, int id)
{
	int retorno = 1;
	int idAux;
	eDrug* pDrug;

	for(int index = 0; index < ll_len(list); index++)
	{
		pDrug = ll_get(list, index);

		if(drug_getId(pDrug, &idAux) == 0 &&
		   idAux == id)
		{
			retorno = index;
		}
	}
	return retorno;
}

int editNombre(LinkedList* list, int index)
{
	int retorno = 1;
	char nuevoNombre[NOMBRE_TAM];
	eDrug* pDrug;

	pDrug = ll_get(list, index);

	if(utn_getCadena(nuevoNombre, NOMBRE_TAM, 2, "\nIngrese nuevo nombre: ","\nError\n") == 0)
	{
		drug_setNombre(pDrug, nuevoNombre);
		retorno = 0;
	}
	return retorno;
}

int editLab(LinkedList* list, int index)
{
	int retorno = 1;
	char nuevoLab[NOMBRE_TAM];
	eDrug* pDrug;

	pDrug = ll_get(list, index);

	if(utn_getCadena(nuevoLab, NOMBRE_TAM, 2, "\nIngrese nuevo laboratorio: ","\nError\n") == 0)
	{
		drug_setLab(pDrug, nuevoLab);
		retorno = 0;
	}
	return retorno;
}

int editPrecio(LinkedList* list, int index)
{
	int retorno = 1;
	int precio;
	eDrug* pDrug;

	pDrug = ll_get(list, index);

	if(utn_getEntero(&precio, 2, "Ingrese nuevo precio (20-3000):  ", "\nError\n", 20, 3000) == 0)
	{
		drug_setPrecio(pDrug, precio);
		retorno = 0;
	}
	return retorno;
}

int sortById(void* aux1, void* aux2)
{
    int retorno = 0;
	int id1;
	int id2;

	drug_getId(aux1, &id1);
	drug_getId(aux2, &id2);

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

	drug_getNombre(aux1, name1);
	drug_getNombre(aux2, name2);

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

int sortByLab(void* aux1, void* aux2)
{
	int retorno = 0;
	char lab1[NOMBRE_TAM];
	char lab2[NOMBRE_TAM];

	drug_getLab(aux1, lab1);
	drug_getLab(aux2, lab2);

	if(strcmp(lab1, lab2) > 0)
	{
		retorno = 1;
	}
	else if(strcmp(lab1, lab2) < 0)
	{
		retorno = -1;
	}
	return retorno;
}

int sortByPrecio(void* aux1, void* aux2)
{
	int retorno = 0;
	float precio1;
	float precio2;

	drug_getPrecio(aux1, &precio1);
	drug_getPrecio(aux2, &precio2);

	if(precio1 > precio2)
	{
		retorno = 1;
	}
	else if(precio1 < precio2)
	{
		retorno = -1;
	}
	return retorno;
}
