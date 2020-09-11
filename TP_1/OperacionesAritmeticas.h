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
 * @param banderaUno bandera del primer operando
 * @param banderaDos bandera del segundo operando
 * @return resultado de la suma o mensaje de error en caso de no poder sumar
 */

float Suma(float numeroUno, float numeroDos, int banderaUno, int BanderaDos);

/** \brief se fija que se hallan ingresado los operando y si es asi los resta y devuelve el resultado
 *
 * \param numeroUno primer operando
 * \param numeroDos segundo operando
 * \param banderaUno primer bandera a verificar
 * \param banderaDos segunda bandera a verificar
 * \return resultado de la resta o 0 si no puede restar
 *
 */

float Resta(float numeroUno, float numeroDos, int banderaUno, int BanderaDos);

/** \brief verifica que se hallan ingresado los operando de ser asi los multiplica y devuelve el resultado
 *
 * \param numeroUno: primer operando
 * \param numeroDos: segundo operando
 * \param banderaUno: bandera que verifica que se halla ingresado el primer operando
 * \param banderaDos: bandera que verifica que se halla ingresado el segundo operando
 * \return el resultado de la multiplicacion
 *
 */


float Multiplicacion(float numeroUno, float numeroDos, int banderaUno, int banderaDos);

/** \brief verifica que se hallan ingresado los operando de ser asi los multiplica y devuelve el resultado
 *
 * \param numeroUno: primer operando
 * \param numeroDos: segundo operando
 * \param banderaUno: bandera que verifica que se halla ingresado el primer operando
 * \param banderaDos: bandera que verifica que se halla ingresado el segundo operando
 * \return el resultado de la division y si divide por cero retorna 0
 *
 */


float Division(float numeroUno, float numeroDos, int banderaUno, int banderaDos);

unsigned long long int Factorial(unsigned long long int numero , int banderaUno, int banderaDos);
