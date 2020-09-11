/*
 * EntradaySalida.h
 *
 *  Created on: 5 sep. 2020
 *      Author: Federico
 */

#ifndef ENTRADAYSALIDA_H_
#define ENTRADAYSALIDA_H_



#endif /* ENTRADAYSALIDA_H_ */

/**brief: ingresa una cadena de caracteres por teclado
 *
 * @param input: array de caracteres donde se ingresara la cadena
 * @param mensaje: array de caracteres que contiene mensaje a mostrar
 * @param cantidad: cantidad de elementos que puede almacenar el array
 */

void IngresarDatoCadenaCaracteres(char input[], char mensaje[], int cantidad);

/**brief valida que una cadena sea un numero y  la devuelve cuando sea un numero
 *
 * @param numero: cadena de caracteres con el numero a validar
 * @return numero: validado
 */

float ValidarNumeroFlotante(char numero[], int cantidad);

/**
 * @fn int ValidarFlotante(float)
 * @brief Valida que el numero sea flotante
 * @param cantidad: cantidad de elementos que puede almacenar el array
 * @param numero: numero a validar
 * @return El numero como flotante
 */
int ValidarFlotante(char numero[]);


/**brief muestra un numero entero por pantalla
 *
 * @param numero numero a mostrase por pantalla
 * @param mensaje mensaje a mostrarse por pantalla
 */
void MostrarNumeroEntero(int numero, char mensaje[]);

/** \brief Pide apretar enter para continuar despues de un mensaje
 *
 * \param
 * \param
 * \return void
 *
 */

 /** \brief muestra un numero de tipo long long int junto a un mensaje personalizado
  *
  * \param numero: numero de tipo long long int
  * \param mensaje: mensaje a mostrar
  * \return
  *
  */


void MostrarNumeroLongLong(unsigned long long int numero, char mensaje[]);

void AprieteEnter();

/** \brief Muestra un numero flotante
 *
 * \param numero: numero a mostrar
 * \param mensaje: mensaje a mostrar junto al numero
 * \return void
 *
 */

void MostrarNumeroFlotante(float numero, char mensaje[]);

/** \brief
 *
 * \param suma: resultado de la suma
 * \param resta: resultado de la resta a mostrarse
 * \param multiplicacion: resultado de la multiplicacion a mostrarse
 * \param division: resultado de la division a mostrarse
 * \param factorial: resultado del factorial a mostrarse
 * \param banderaCalculos: bandera que verifica que se hallan realizado los calculos
 * \param denominador: el denominador de la division
 * \return void
 *
 */

void MostrarResultados(float suma, float resta, float multiplicacion, float division, unsigned long long int factorial, int banderaCalculos, int denominador);

/** \brief si las primeras dos banderas estan activadas devuelve uno sino 0
 *
 * \param banderaUno: primera bandera a verificar
 * \param banderaDos: segunda bandera a verificar
 * \return 1 si las banderas estan activadas 0 sino
 *
 */


int ActivarBandera(int banderaUno, int banderaDos);
