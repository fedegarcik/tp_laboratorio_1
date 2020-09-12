/*
 * OperacionesAritmeticas.h
 *
 *  Created on: 5 sep. 2020
 *      Author: Federico
 */

#ifndef OPERACIONESARITMETICAS_H_
#define OPERACIONESARITMETICAS_H_



#endif /* OPERACIONESARITMETICAS_H_ */
/**
 * @brief suma dos numeros y devuelve el resultado
 *
 * @param numeroUno primer operando
 * @param numeroDos segundo operando
 * @return resultado de la suma
 */

float Suma(float numeroUno, float numeroDos);

/** \brief resta los dos operando y devuelve el resultado
 *
 * \param numeroUno primer operando
 * \param numeroDos segundo operando
 * \return resultado de la resta
 *
 */

float Resta(float numeroUno, float numeroDos);

/** \brief multiplica los dos operando y devuelve el resultado
 *
 * \param numeroUno: primer operando
 * \param numeroDos: segundo operando
 * \return el resultado de la multiplicacion
 *
 */


float Multiplicacion(float numeroUno, float numeroDos);

/** \brief divide los dos operando y devuelve el resultado
 *
 * \param numeroUno: primer operando
 * \param numeroDos: segundo operando
 * \return el resultado de la division y si divide por cero retorna 0
 *
 */


float Division(float numeroUno, float numeroDos);

/** \brief saca el factorial del numero que recibe como parametro a menos que sea negativo o mayor a 20 o flotante
 *
 * \param numero: numero del cual se va a sacar el factorial
 * \return el factorial del numero o 0 si no se pudo calcular el factorial
 *
 */


unsigned long long int Factorial(float numero);
