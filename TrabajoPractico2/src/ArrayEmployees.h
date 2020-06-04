/*
 * ArrayEmployees.h
 *
 *  Created on: 7 may. 2020
 *      Author: Abril Costanzo
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
}eEmployee;


/** \brief Indica que todas las posiciones en el array estan vacias,
* pone la bandera (isEmpty) en TRUE en todas las posiciones del array.
* \param eEmployee lista[]: puntero del array de empleados
* \param len: tamaño del array
* \return -1 si hay error, 0 si salio bien
*/
int initEmployees(eEmployee list[], int len);




/** \brief Agrega en un array de empleados existente los valores recibidos como parámetro en la primer posición libre.
* \param eEmployee list[]: puntero del array de empleados
* \param len: tamaño del array
* \param id: id del empleado
* \param name[]: nombre del empleado
* \param lastName[]: apellido del empleado
* \param salary: salario del empleado
* \param sector: sector del empleado
* \return -1 si hay un error, 0 si salio bien
*/
int addEmployee(eEmployee list[], int len, int id, char name[],char lastName[],float salary,int sector);



/** \brief Busca un empleado recibiendo como parámetro de búsqueda su Id.
* \param eEmployee list[]: puntero del array de empleados
* \param len: tamaño del array
* \param id: id del empleado
* \return devuelve el indice del empleado o -1 si hay error
*/
int findEmployeeById(eEmployee list[], int len,int id);



/** \brief Elimina de manera lógica (isEmpty Flag en 1) un empleado recibiendo como parámetro su Id.
* \param eEmployee list[]: puntero del array de empleados
* \param len: tamaño del array
* \param id: id del empleado
* \return -1 si hay error, 0 si salio bien
*/
int removeEmployee(eEmployee list[], int len, int id);



/** \brief Ordena el array de empleados por apellido y sector de manera ascendente o descendente.
* \param eEmployee list[]: puntero del array de empleados
* \param len: tamaño del array
* \param order: 1 indica ascendente, 0 descendente
* \return -1 si hay error, 0 si salio bien
*/
int sortEmployees(eEmployee list[], int len, int order);



/** \brief Imprime el array de empleados de forma encolumnada.
* \param eEmployee list[]: puntero del array de empleados
* \param length:tamaño del array
* \return 0
*/
int printEmployees(eEmployee list[], int lenght);


#endif /* ARRAYEMPLOYEES.H*/

