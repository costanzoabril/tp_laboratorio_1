/*
 * validaciones.h
 *
 *  Created on: 10 may. 2020
 *      Author: Abril Costanzo
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

int utn_getCadena(char *pAux, int limit, int retry, char* msg, char* msgError);

int getCadena(char* pAux, int limit);

int isChar(char str[]);

int utn_getFlotante(float* pFloat, int retry, char* msg, char*msgError, float min, float max);

int getFloat(float*pAux);

int isFloat(char* pAux);

int utn_getEntero(int* pEntero, int retry, char* msg, char*msgError, int min, int max);

int getInt(int* pAux);

int isInt(char *pAux);

int strLwr(char* str);

int normalizeStr(char* str);

#endif /* VALIDACIONES_H_ */
