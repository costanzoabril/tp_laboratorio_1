#include <stdio.h>
#include <stdlib.h>
#include "tpUno.h"

int main(void)
{
int a=0;
int b=0;
int flag=0;
char respuesta = 'a';

do{
	switch(menu(a,b))
	{
	case 1:
		printf("Ingrese el primer operando: ");
		scanf("%d", &a);
		flag=1;
		system("cls");
		break;
	case 2:
	    if(flag==1)
        {
            printf("Ingrese el segundo operando: ");
		    scanf("%d", &b);
		    system("cls");
        }
        else
        {
            printf("Debe ingresar el primer operando.\n");
            system("pause");
            system("cls");
        }

		break;
	case 3:
		sumar(a,b);
		restar(a,b);
		multiplicar(a,b);
		dividir(a,b);
		system("cls");
		break;
	case 4:
		printf("La suma es: %d\n", sumar(a,b));
		printf("La resta es: %d\n", restar(a,b));
		printf("La multiplicacion es: %d\n", multiplicar(a,b));
		if(b == 0)
        {
            printf("No es posible dividir por 0.\n");
        }
        else
        {
            printf("La division es : %.2f\n", dividir(a,b));
        }
		system("pause");
		system("cls");
		break;
	case 5:
		respuesta = 'b';
		break;
	default:
		printf("No es una opcion valida. ");
		system("pause");
		system("cls");
	}
  }while(respuesta == 'a');

return 0;
}
