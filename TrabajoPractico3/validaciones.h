#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

/** \brief para capturar una cadena del usuario que no supere el limite ingresado
* \param el puntero donde se guardara la cadena
* \param el limite que la cadena no puede superar
*  \param la cantidad de veces que el usuario puede intentar ingresar datos
*  \param el mensaje que se le mostrara al usuario
*  \param el mensaje que se le mostrara al usuario en caso de error
*  \return retorna 1 en caso de error(cadena demasiado grande, caracteres no numericos en la cadena) o 0 en caso de exito
*/
int utn_getCadena(char *pAux, int limit, int retry, char* msg, char* msgError);

/** \brief para capturar una cadena del usuario que no supere el limite ingresado
* \param el puntero donde se guardara la cadena
* \param el limite que la cadena no puede superar
* \return retorna 1 en caso de error(punteros vacios o cadena mas larga que el limite) retorna 0 en caso de exito
*/
int getCadena(char* pAux, int limit);

int isChar(char str[]);

/**  \brief para validar que lo ingresado por el usuario sea un numero entero o flotante
*  \param la cantidad de veces que el usuario puede intentar ingresar datos
*  \param el mensaje que se le mostrara al usuario
*  \param el mensaje que se le mostrara al usuario en caso de error (punteros vacios,supero la cantidad de intentos, o caracteres no numericos)
*  \param el limite inferior del numero a ingresar
*  \param el limite superior del numero a ingresar
*  \return retorna 1 en caso de error(puntero vacio,intentos agotados, caracter no numerico) retorna 0 en caso de exito
*/
int utn_getFlotante(float* pFloat, int retry, char* msg, char*msgError, float min, float max);

/**
*  \brief para transformar una cadena de caracteres a numero flotante
*  \param el puntero a la cadena donde se va a guardar el numero flotante
*  \return retorna 1 en caso de error(cadena demasiado grande, caracteres no numericos en la cadena) o 0 en caso de exito
*/
int getFloat(float*pAux);

/**   \brief para validar que una cadena ingresada sea un numero entero o flotante
*   \param puntero de la cadena a validar
*   \return retorna 1 en caso de ser una cadena con caracteres no numericos o con mas de un punto ('.'), retorna 0 en caso de exito
*/

int isFloat(char* pAux);

/** \brief para validar que lo ingresado por el usuario sea un numero entero
* \param el puntero donde se guardara el numero en caso de exito
* \param la cantidad de veces que el usuario puede intentar ingresar el dato
* \param el mensaje que se le mostrara al usuario
* \param el mensaje que se le mostrara al usuario en caso de error
* \param el limite inferior del numero a ingresar
* \param el limite superior del numero a ingresar
* \return retorna 1 en caso de error(puntero vacio,intentos agotados, caracter no numerico) retorna 0 en caso de exito
*/

int utn_getEntero(int* pEntero, int retry, char* msg, char*msgError, int min, int max);

/**
*  \brief para capturar un numero ingresado por el usuario
*  \param el puntero donde se  guardara el numero
*  \return retorna 1 en caso de error (lo ingresado no es un numero) o en caso de exito, retorna 0
*/
int getInt(int* pAux);

/**
* \brief para validar que la cadema que recibe la funcion no contenga caracteres no numericos dentro
* \param la cadena a validar
* \return retorna 1 en caso de error (caracteres no numericos dentro de la cadena)
*/
int isInt(char *pAux);

#endif /* VALIDACIONES_H_ */
