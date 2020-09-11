/*
 * EntradaySalida.c
 *
 *  Created on: 5 sep. 2020
 *      Author: Federico
 */

#include <stdio.h>
#include <stdlib.h>
#include "EntradaySalida.h"
#include <string.h>
#include <ctype.h>

void IngresarDatoCadenaCaracteres(char input[], char mensaje[], int cantidad)
{
	printf("%s\n", mensaje);
    fflush(stdin);
    gets(input);
}

float ValidarNumeroFlotante(char numero[], int cantidad)
{
    float numAux;
    int flagNum = 1;
    int i;
    int longitudNumero;

    longitudNumero = strlen(numero);
        for(i = 0; i < longitudNumero ; i++)
        {

            if(!isdigit(numero[i]) && numero[i] != '0')
               {
                  flagNum = 0;
                  break;

               }
        }
    numAux = atof(numero);
    while(flagNum == 0)
    {
        if(numAux == 0)
        {
            printf("ERROR: ese no es un numero reingrese: \n");
            IngresarDatoCadenaCaracteres(numero, "", cantidad);

            numAux = atof(numero);
        }
        else
        {
            flagNum = 1;
        }
    }

    return numAux;
}

/*int ValidarFlotante(char numero[])
{

	int flag;
	int i;


	i = 0;
	flag = 0;

	while(numero[i++] != '\0')
	{
		if(numero[i] == '.')
	    {
	        flag = 1;
	        break;
	    }
	}

	if(flag)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}*/


void MostrarNumeroEntero(int numero, char mensaje[])
{
	printf("%s %d ,Apriete enter para continuar\n", mensaje, numero);

}

void AprieteEnter()
{
    char enter;
    fflush(stdin);
    scanf("%c", &enter);
}


void MostrarNumeroFlotante(float numero, char mensaje[])
{
    printf("%s %.2f \n", mensaje, numero);
}

void MostrarResultados(float suma, float resta, float multiplicacion, float division,unsigned long long int factorial, int banderaCalculos, int denominador)
{
    if(banderaCalculos)
    {
        MostrarNumeroFlotante(suma, "El resultado de la suma es :");
        MostrarNumeroFlotante(resta, "El resultado de la resta es :");
        MostrarNumeroFlotante(multiplicacion, "El resultado de la multiplicacion es :");


        if(denominador == 0)
        {
            printf("No se pudo dividir\n");
        }
        else
        {
            MostrarNumeroFlotante(division, "El resultado de la division es :");
        }


        if(factorial == 0)
        {
            printf("No se pudo sacar el factorial porque es un numero negativo o es mayor a 20 y este programa no soporta factoriales mayores a 20\n");
        }
        else
        {
             MostrarNumeroLongLong(factorial, "El factorial de A es :");
        }
        printf("Apriete enter para continuar: ");
        AprieteEnter();

    }
    else
    {
         printf("ERROR, realize primero los calculos, apriete enter para continuar\n");
         AprieteEnter();
    }

}

int ActivarBandera(int banderaUno, int banderaDos)
{
    if(banderaUno && banderaDos)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void MostrarNumeroLongLong(unsigned long long int numero, char mensaje[])
{
    printf("%s %I64u ,\n", mensaje, numero);
}
