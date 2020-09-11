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


int main() {

	char primerOperandoAux[CANTIDAD];
	char segundoOperandoAux[CANTIDAD];
	float primerOperando;
	float segundoOperando;
	float resultadoResta;
	float resultadoSuma;
	float resultadoMultiplicacion;
    float resultadoDivision;
    unsigned long long int factorial;
	int banderaPrimerOperando;
	int banderaSegundoOperando;
	int banderaCalculos;
    int opcion;

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
		printf("0_Salir\n");

		printf("Ingrese opcion: \n");
		fflush(stdin);
		scanf("%d", &opcion);

		switch(opcion)

		{   case 1:
			    IngresarDatoCadenaCaracteres(primerOperandoAux, "Ingrese el primer operando y luego apriete enter para continuar:  ", CANTIDAD);
			    primerOperando = ValidarNumeroFlotante(primerOperandoAux, CANTIDAD);
			    banderaPrimerOperando = 1;
				break;
			case 2:
				IngresarDatoCadenaCaracteres(segundoOperandoAux, "Ingrese el segundo operando luego apriete enter para continuar:  ", CANTIDAD);
				segundoOperando = ValidarNumeroFlotante(segundoOperandoAux, CANTIDAD);
				banderaSegundoOperando = 1;
				break;
			case 3:
				resultadoSuma = Suma(primerOperando, segundoOperando, banderaPrimerOperando, banderaSegundoOperando);
				resultadoResta = Resta(primerOperando, segundoOperando, banderaPrimerOperando, banderaSegundoOperando);
				resultadoMultiplicacion = Multiplicacion(primerOperando, segundoOperando, banderaPrimerOperando, banderaSegundoOperando);
				resultadoDivision = Division(primerOperando, segundoOperando, banderaPrimerOperando, banderaSegundoOperando);
				factorial = Factorial(primerOperando, banderaPrimerOperando, banderaSegundoOperando);
				banderaCalculos = ActivarBandera(banderaPrimerOperando, banderaSegundoOperando);
				break;
			case 4:
			    MostrarResultados(resultadoSuma, resultadoResta, resultadoMultiplicacion, resultadoDivision, factorial, banderaCalculos, segundoOperando);
				break;
			case 0:
				printf("Gracias por usar el programa, Apriete enter para continuar");
				AprieteEnter();
				break;
			default:
				printf("ERROR, esa no es una opcion valida, apriete enter para continuar");
				AprieteEnter();






	}

    system("cls");

    }while(opcion != 0);


	return 0;
}
