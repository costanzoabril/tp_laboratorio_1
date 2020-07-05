#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Drug.h"

/** \brief Parsea los datos desde el archivo data.csv (modo texto).
 * \param path char*
 * \param list LinkedList*
 * \return int 1 en caso de error, 0 en caso de exito
 */
int parser_DrugFromText(FILE* pFile , LinkedList* list)
{
    int retorno = 1;
    char buffer[4][128];
    eDrug* nuevo = NULL;

    if(pFile != NULL && list != NULL)
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n",buffer[0], buffer[1], buffer[2], buffer[3]);
        while(!feof(pFile))
        {
            if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]",buffer[0], buffer[1], buffer[2], buffer[3])==4)
            {
                nuevo = drug_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);

                 if (nuevo != NULL)
                {
                    ll_add(list, nuevo);
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


/** \brief Parsea los datos desde el archivo data.csv (modo binario).
 * \param path char*
 * \param list LinkedList*
 * \return int 1 en caso de error, 0 en caso de exito
 */
int parser_DrugFromBinary(FILE* pFile , LinkedList* list)
{
    int retorno = -1;
	eDrug* pDrug;

	if(pFile != NULL)
	{
		do
		{
			pDrug = drug_new();
			if(fread(pDrug, sizeof(eDrug), 1, pFile) == 1)
			{
				ll_add(list, pDrug);
				retorno = 0;
			}
		}while(!feof(pFile));
	}
    return retorno;
}
