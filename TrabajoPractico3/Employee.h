#include "LinkedList.h"
#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/** \brief Crea un nuevo empleado
 * \return puntero al nuevo empleado
 */
Employee* employee_new();

/** \brief Crea un nuevo empleado recibiendo informacion como parametros
 * \param char* idStr
 * \param char* nombreStr
 * \param char* horasTrabajadasStr
 * \param char* sueldoStr
 * \return puntero al nuevo empleado
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);

/** \brief Borra un empleado
 * \param Employee* this
 * \return 0 en caso de exito, 1 en caso de error
 */
int employee_delete(Employee* this);

/** \brief Asigna un id validado
 * \param Employee* this
 * \param int id
 * \return 0 en caso de exito, 1 en caso de error
 */
int employee_setId(Employee* this,int id);

/** \brief Accede al campo id
 * \param Employee* this
 * \param int* id
 * \return 0 en caso de exito, 1 en caso de error
 */
int employee_getId(Employee* this,int* id);

/** \brief Asigna un nombre validado
 * \param Employee* this
 * \param char* nombre
 * \return 0 en caso de exito, 1 en caso de error
 */
int employee_setNombre(Employee* this,char* nombre);

/** \brief Accede al campo nombre
 * \param Employee* this
 * \param char* nombre
 * \return 0 en caso de exito, 1 en caso de error
 */
int employee_getNombre(Employee* this,char* nombre);

/** \brief Asigna horas trabajadas validadas
 * \param Employee* this
 * \param int horasTrabajadas
 * \return 0 en caso de exito, 1 en caso de error
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);

/** \brief Accede al campo horas trabajadas
 * \param Employee* this
 * \param int* horasTrabajadas
 * \return 0 en caso de exito, 1 en caso de error
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/** \brief Asigna sueldo validado
 * \param Employee* this
 * \param int sueldo
 * \return 0 en caso de exito, 1 en caso de error
 */
int employee_setSueldo(Employee* this,int sueldo);

/** \brief Accede al campo sueldo
 * \param Employee* this
 * \param int* sueldo
 * \return 0 en caso de exito, 1 en caso de error
 */
int employee_getSueldo(Employee* this,int* sueldo);

/** \brief Muestra un empleado usando su punteor
 * \param Employee* pEmployee
 * \return void
 */
void employee_printEmployee(Employee* pEmployee);

/** \brief Busca el ultimo id de la lista (mayor)
 * \param LinkedList* pArrayListEmployee
 * \return ultimo id
 */
int employee_lastId(LinkedList* pArrayListEmployee);

/** \brief Busca un empleado por id
 * \param LinkedList* pArrayListEmployee
 * \param int id
 * \return indice del empleado
 */
int employee_SearchForId(LinkedList* pArrayListEmployee, int id);

/** \brief Ordena los empleados por sueldo
 * \param void* aux1
 * \param void* aux2
 * \return 0 en caso de ser iguales, 1 si el aux1 es mayor, o -1 si el aux2 es mayor
 */
int sortBySalary(void* aux1, void* aux2);

/** \brief Ordena los empleados por horas trabajadas
 * \param void* aux1
 * \param void* aux2
 * \return 0 en caso de ser iguales, 1 si el aux1 es mayor, o -1 si el aux2 es mayor
 */
int sortByHours(void* aux1, void* aux2);

/** \brief Ordena los empleados por nombre
 * \param void* aux1
 * \param void* aux2
 * \return 0 en caso de ser iguales, 1 si el aux1 es mayor, o -1 si el aux2 es mayor
 */
int sortByName(void* aux1, void* aux2);

/** \brief Ordena los empleados por id
 * \param void* aux1
 * \param void* aux2
 * \return 0 en caso de ser iguales, 1 si el aux1 es mayor, o -1 si el aux2 es mayor
 */
int sortById(void* aux1, void* aux2);




#endif // employee_H_INCLUDED
