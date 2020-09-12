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


float Suma(float numeroUno, float numeroDos)
{

	float resultado;


    resultado = numeroUno + numeroDos;

    return resultado;

}

float Resta(float numeroUno, float numeroDos)
{

	float resultado;


    resultado = numeroUno - numeroDos;

    return resultado;

}

float Multiplicacion(float numeroUno, float numeroDos)
{
    float resultado;


    resultado = numeroUno * numeroDos;

    return resultado;

}

float Division(float numeroUno, float numeroDos)
{
    float resultado;


    if(numeroDos == 0)
    {
        printf("ERROR, no se puede divir por cero, apriete enter para continuar");
        AprieteEnter();
        return 0;
    }
    resultado = numeroUno / numeroDos;

    return resultado;

}

unsigned long long int Factorial(float numero)
{
    unsigned long long int resultado;
    int i;
    int numAux;

    resultado = 1;
    numAux = numero;

    if(numAux - numero)
    {
        printf("ERROR, no se puede calcular el factorial de un numero flotante");
        AprieteEnter();
        return 0;
    }


    if(numero < 0 || numero > 20)
    {
        printf("ERROR, no se puede sacar el factorial de un numero negativo, flotante o es un numero que esta aplicacion no soporta, apriete enter para continuar");
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
