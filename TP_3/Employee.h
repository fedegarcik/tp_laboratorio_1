#include "LinkedList.h"
#define CAPACIDAD_ARRAY 200
#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

typedef struct
{
    int id;
    char nombre[CAPACIDAD_ARRAY];
    int horasTrabajadas;
    int sueldo;
}Employee;

#endif // employee_H_INCLUDED

/** \brief Constructor de empleado , reserva espacion en memoria para un empleado
 *
 * \param
 * \param
 * \return pEmpleoyee*: puntero que apunta a la memoria reservada
 *
 */

Employee* employee_new();

/** \brief Contructor de empleado con parametros
 *
 * \param idStr: id cadena de caracteres
 * \param nombreStr: nombre del empleado
 * \param horasTrabajadasStr: horas trabajadas cadena de caracteres
 * \param sueldoStr: sueldo cadena de caracteres
 * \return pEmployee*: puntero a empleado
 *
 */


Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
void employee_delete();

/** \brief setea id en el empleado
 *
 * \param Employee*: puntero a empleado
 * \param id: id a setearse
 * \return 1 en caso de exito -1 en caso de error
 *
 */

int employee_setId(Employee* this,int id);

/** \brief getter de id
 *
 * \param Employee*: puntero a empleado
 * \param id que nos conseguira el getter
 * \return 1 en caso de exito -1 en caso de error
 *
 */


int employee_getId(Employee* this,int* id);


/** \brief setea nombre en el empleado
 *
 * \param Employee*: puntero a empleado
 * \param nombre: nombre a setearse
 * \return 1 en caso de exito -1 en caso de error
 *
 */

int employee_setNombre(Employee* this,char* nombre);

/** \brief getter de nombre
 *
 * \param Employee*: puntero a empleado
 * \param nombre que nos conseguira el getter
 * \return 1 en caso de exito -1 en caso de error
 *
 */


int employee_getNombre(Employee* this,char* nombre);


/** \brief setea horasTrabajadas en el empleado
 *
 * \param Employee*: puntero a empleado
 * \param horasTrabajadas: horas trabajadas a setearse
 * \return 1 en caso de exito -1 en caso de error
 *
 */

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);

/** \brief getter de horas trabajadas
 *
 * \param Employee*: puntero a empleado
 * \param horasTrabajadas que nos conseguira el getter
 * \return 1 en caso de exito -1 en caso de error
 *
 */


int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);


/** \brief setea sueldo en el empleado
 *
 * \param Employee*: puntero a empleado
 * \param sueldo: sueldo a setearse
 * \return 1 en caso de exito -1 en caso de error
 *
 */

int employee_setSueldo(Employee* this,int sueldo);

/** \brief getter de sueldo
 *
 * \param Employee*: puntero a empleado
 * \param sueldo que nos conseguira el getter
 * \return 1 en caso de exito -1 en caso de error
 *
 */


int employee_getSueldo(Employee* this,int* sueldo);


/** \brief compara dos empleados por nombre
 *
 * \param void* e1: puntero al primer empleado
 * \param void* e2: puntero al segundo empleado
 * \return 1 si el nombre del primer empleado es mayor que el segundo caso contrario -1 y si son iguales 0
 *
 */


int employee_CompareByName(void* e1, void* e2);

/** \brief compara dos empleados por id
 *
 * \param void* e1: puntero al primer empleado
 * \param void* e2: puntero al segundo empleado
 * \return devuelve 1 si el id del primer empleado es menor al segundo y si son iguales o caso contrario devuelve 0
 *
 */


int employee_CompareById(void* e1, void* e2);

int getIdMaximo(int len, LinkedList* pArrayListEmployee);

int buscarPorNombre(char* nombre, LinkedList* pArrayListEmployee);

int MostrarEmpleado(Employee* pEmpleado);

