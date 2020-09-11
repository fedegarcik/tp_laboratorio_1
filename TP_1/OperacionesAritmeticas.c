/*
 * OperacionesAritmeticas.c
 *
 *  Created on: 5 sep. 2020
 *      Author: Federico
 */

#include <stdio.h>
#include <stdlib.h>
#include "OperacionesAritmeticas.h"
#include "EntradaySalida.h"


float Suma(float numeroUno, float numeroDos, int banderaUno, int banderaDos)
{

	float resultado;

    if(banderaUno && banderaDos)
    {
       resultado = numeroUno + numeroDos;

       return resultado;
    }
    else
    {
        printf("ERROR, ingrese los operando primero por favor, apriete enter para continuar");
        AprieteEnter();
        return 0;
    }



}

float Resta(float numeroUno, float numeroDos, int banderaUno, int banderaDos)
{

	float resultado;

    if(banderaUno && banderaDos)
    {
       resultado = numeroUno - numeroDos;

       return resultado;
    }
    else
    {
        return 0;
    }



}

float Multiplicacion(float numeroUno, float numeroDos, int banderaUno, int banderaDos)
{
    float resultado;

    if(banderaUno && banderaDos)
    {
       resultado = numeroUno * numeroDos;

       return resultado;
    }
    else
    {
        return 0;
    }
}

float Division(float numeroUno, float numeroDos, int banderaUno, int banderaDos)
{
    float resultado;

    if(banderaUno && banderaDos)
    {
        if(numeroDos == 0)
        {
            printf("ERROR, no se puede divir por cero, apriete enter para continuar");
            AprieteEnter();
            return 0;
        }
        resultado = numeroUno / numeroDos;

        return resultado;
    }
    else
    {
        return 0;
    }
}

unsigned long long int Factorial(unsigned long long int numero , int banderaUno, int banderaDos)
{
    unsigned long long int resultado;
    int i;

    resultado = 1;
    if(numero < 0 || numero > 20)
    {
        printf("ERROR, no se puede sacar el factorial de un numero negativo o es un numero que esta aplicacion no soporta, apriete enter para continuar");
        AprieteEnter();
        return 0;
    }
    else
    {
       for(i = 1; i<numero; i++)
        {
            resultado *= (i +1);

        }
    }
    return resultado;






}
