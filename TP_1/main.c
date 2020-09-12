/*
 ============================================================================
 Name        : TP1_CALCULADORA.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "EntradaySalida.h"
#include "OperacionesAritmeticas.h"
#define CANTIDAD 30
#define INICIALIZADOR 0
#define BANDERA_ARRIBA 1


int main() {

	char primerOperandoAux[CANTIDAD];
	char segundoOperandoAux[CANTIDAD];
	char opcion;
	float primerOperando;
	float segundoOperando;
	float resultadoResta;
	float resultadoSuma;
	float resultadoMultiplicacion;
    float resultadoDivision;
    unsigned long long int factorialPrimerOperando;
    unsigned long long int factorialSegundoOperando;
	int banderaPrimerOperando;
	int banderaSegundoOperando;
	int banderaCalculos;


	banderaCalculos = INICIALIZADOR;
	banderaPrimerOperando = INICIALIZADOR;
	banderaSegundoOperando = INICIALIZADOR;


	primerOperando = INICIALIZADOR;
	segundoOperando = INICIALIZADOR;


	primerOperando = INICIALIZADOR;
	do{
		printf("****Menu****\n");
		printf("1_Ingrese primer operando A = %.2f\n", primerOperando);
		printf("2_Ingrese segundo operando B = %.2f\n", segundoOperando);
		printf("3_Calcular todas las operaciones\n");
		printf("4_Informar resultados\n");
		printf("5_Salir\n");

		printf("Ingrese opcion: \n");
		fflush(stdin);
		scanf("%c", &opcion);

		switch(opcion)

		{
		    case '1':
			    IngresarDatoCadenaCaracteres(primerOperandoAux, "Ingrese el primer operando y luego apriete enter para continuar:  ");
			    primerOperando = ValidarNumeroFlotante(primerOperandoAux);
			    banderaPrimerOperando = BANDERA_ARRIBA;
				break;
			case '2':
				IngresarDatoCadenaCaracteres(segundoOperandoAux, "Ingrese el segundo operando luego apriete enter para continuar:  ");
				segundoOperando = ValidarNumeroFlotante(segundoOperandoAux);
				banderaSegundoOperando = BANDERA_ARRIBA;
				break;
			case '3':
			    if(banderaPrimerOperando == BANDERA_ARRIBA && banderaSegundoOperando == BANDERA_ARRIBA)
                {
                    resultadoSuma = Suma(primerOperando, segundoOperando);
                    resultadoResta = Resta(primerOperando, segundoOperando);
                    resultadoMultiplicacion = Multiplicacion(primerOperando, segundoOperando);
                    resultadoDivision = Division(primerOperando, segundoOperando);
                    factorialPrimerOperando = Factorial(primerOperando);
                    factorialSegundoOperando = Factorial(segundoOperando);
                    banderaCalculos = BANDERA_ARRIBA;
                    printf("Calculos realizados, apriete enter para continuar");
                    AprieteEnter();
                }
                else
                {
                    printf("ERROR, ingrese los operando primero por favor, apriete enter para continuar");
                    AprieteEnter();
                }
                printf("enrtro");

				break;
			case '4':
			    if(banderaCalculos == BANDERA_ARRIBA)
                {
                     MostrarResultados(resultadoSuma, resultadoResta, resultadoMultiplicacion, resultadoDivision, factorialPrimerOperando, factorialSegundoOperando, segundoOperando);
                }
                else
                {
                    printf("ERROR, realize primero los calculos, apriete enter para continuar\n");
                    AprieteEnter();
                }

				break;
			case '5':
				printf("Gracias por usar el programa, Apriete enter para continuar");
				AprieteEnter();
				break;
			default:
				printf("ERROR, esa no es una opcion valida, apriete enter para continuar");
				AprieteEnter();







	}

    system("cls");

    }while(opcion != '5');


	return 0;
}
