#ifndef CALCULADORA_H_INCLUDED
#define CALCULADORA_H_INCLUDED

int utn_getNumero(int* pResultado, char* mensaje,char* mensajeError, int minimo,int maximo,int reintentos);
int sumar(int a, int b);
int restar(int a, int b);
int multiplicar(int a, int b);
float dividir(float a, float b);

#endif // CALCULADORA_H_INCLUDED
