#include "LinkedList.h"
#ifndef DRUG_H_INCLUDED
#define DRUG_H_INCLUDED

typedef struct
{
    int id;
    char nombre[20];
    char laboratorio[20];
    float precio;
}eDrug;

/** \brief Crea una nueva droga
 * \return puntero a la nueva droga
 */
eDrug* drug_new();

/** \brief Crea una nueva droga recibiendo informacion como parametros
 * \param char* idStr
 * \param char* nombreStr
 * \param char* laboratorioStr
 * \param char* precioStr
 * \return puntero a la nueva droga
 */
eDrug* drug_newParametros(char* idStr,char* nombreStr,char* laboratorioStr, char* precioStr);

/** \brief Borra una droga de la lista
 * \param eDrug* this
 * \return 0 en caso de exito, 1 en caso de error
 */
int drug_delete(eDrug* this);

/** \brief Busca una droga por id
 * \param LinkedList* list
 * \param int id
 * \return indice de la droga
 */
int drug_SearchForId(LinkedList* list, int id);

/** \brief Asigna un id validado
 * \param eDrug* this
 * \param int id
 * \return 0 en caso de exito, 1 en caso de error
 */
int drug_setId(eDrug* this,int id);

/** \brief Accede al campo id
 * \param eDrug* this
 * \param int* id
 * \return 0 en caso de exito, 1 en caso de error
 */
int drug_getId(eDrug* this,int* id);

/** \brief Asigna un nombre validado
 * \param eDrug* this
 * \param char* nombre
 * \return 0 en caso de exito, 1 en caso de error
 */
int drug_setNombre(eDrug* this,char* nombre);

/** \brief Accede al campo nombre
 * \param eDrug* this
 * \param char* nombre
 * \return 0 en caso de exito, 1 en caso de error
 */
int drug_getNombre(eDrug* this,char* nombre);

/** \brief Asigna un laboratorio validado
 * \param eDrug* this
 * \param char* laboratorio
 * \return 0 en caso de exito, 1 en caso de error
 */
int drug_setLab(eDrug* this,char* laboratorio);

/** \brief Accede al campo laboratorio
 * \param eDrug* this
 * \param char* laboratorio
 * \return 0 en caso de exito, 1 en caso de error
 */
int drug_getLab(eDrug* this,char* laboratorio);

/** \brief Asigna un precio validado
 * \param eDrug* this
 * \param float* precio
 * \return 0 en caso de exito, 1 en caso de error
 */
int drug_setPrecio(eDrug* this,float precio);

/** \brief Accede al campo precio
 * \param eDrug* this
 * \param float* precio
 * \return 0 en caso de exito, 1 en caso de error
 */
int drug_getPrecio(eDrug* this,float* precio);

/** \brief Muestra una droga
 * \param eDrug* pDrug
 * \return void
 */
void drug_printDrug(eDrug* pDrug);

/** \brief Busca el ultimo id de la lista (mayor)
 * \param LinkedList* list
 * \return ultimo id
 */
int drug_lastId(LinkedList* list);

/** \brief Busca una droga por id
 * \param LinkedList* list
 * \param int id
 * \return indice de la droga
 */
int drug_SearchForId(LinkedList* list, int id);

/** \brief Modifica el nombre
 * \param LinkedList* list
 * \param int index
 * \return 0 en caso de exito, 1 en caso de error
 */
int editNombre(LinkedList* list, int index);

/** \brief Modifica el laboratorio
 * \param LinkedList* list
 * \param int index
 * \return 0 en caso de exito, 1 en caso de error
 */
int editLab(LinkedList* list, int index);

/** \brief Modifica el precio
 * \param LinkedList* list
 * \param int index
 * \return 0 en caso de exito, 1 en caso de error
 */
int editPrecio(LinkedList* list, int index);

/** \brief Ordena por id
 * \param void* aux1
 * \param void* aux2
 * \return 0 en caso de ser iguales, 1 si el aux1 es mayor, o -1 si el aux2 es mayor
 */
int sortById(void* aux1, void* aux2);

/** \brief Ordena por nombre
 * \param void* aux1
 * \param void* aux2
 * \return 0 en caso de ser iguales, 1 si el aux1 es mayor, o -1 si el aux2 es mayor
 */
int sortByName(void* aux1, void* aux2);

/** \brief Ordena por laboratorio
 * \param void* aux1
 * \param void* aux2
 * \return 0 en caso de ser iguales, 1 si el aux1 es mayor, o -1 si el aux2 es mayor
 */
int sortByLab(void* aux1, void* aux2);

/** \brief Ordena por precio
 * \param void* aux1
 * \param void* aux2
 * \return 0 en caso de ser iguales, 1 si el aux1 es mayor, o -1 si el aux2 es mayor
 */
int sortByPrecio(void* aux1, void* aux2);
#endif // DRUG_H_INCLUDED
