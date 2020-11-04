#include <stdlib.h>
#include "Employee.h"
#include <string.h>
#include <stdio.h>

Employee* employee_new()
{
    Employee* pEmployee;

    pEmployee = (Employee*)malloc(sizeof(Employee));

    return pEmployee;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* pEmployee;


    pEmployee = employee_new();

    if(pEmployee != NULL)
    {
        //Usar el retorno
        if(employee_setId(pEmployee, atoi(idStr))                           == 1 &&
           employee_setNombre(pEmployee, nombreStr)                         == 1 &&
           employee_setHorasTrabajadas(pEmployee, atoi(horasTrabajadasStr)) == 1 &&
           employee_setSueldo(pEmployee, atoi(sueldoStr))                   == 1)
        {

        }
        else
        {
            pEmployee = NULL;
            printf("ERROR AL CARGAR LOS DATOS");
        }
    }
    else
    {
        printf("ERROR NO HAY ESPACIO EN MEMORIA");
    }

    return pEmployee;

}

int employee_setId(Employee* this,int id)
{
    int retorno;
    retorno = -1;

    if(this != NULL && id > 0)
    {
        this->id = id;
        retorno = 1;
    }
    return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int retorno;
    retorno = -1;

    if(this != NULL && nombre != NULL)
    {
        strcpy(this->nombre, nombre);
        retorno = 1;
    }

    return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno;
    retorno = -1;

    if(this != NULL && horasTrabajadas >= 0)
    {
        this->horasTrabajadas = horasTrabajadas;
        retorno = 1;
    }

    return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno;
    retorno = -1;

    if(this != NULL && sueldo >= 0)
    {
        this->sueldo = sueldo;
        retorno = 1;
    }

    return retorno;
}


int employee_getId(Employee* this, int* id)
{
    int retorno;

    retorno = -1;
    *id = -1;

    if(this != NULL && id != NULL)
    {
        *id = this->id;
        retorno = 1;
    }

    return retorno;
}

int employee_getNombre(Employee* this, char* nombre)
{
    int retorno;

    retorno = -1;

    if(this != NULL && nombre != NULL)
    {

        strcpy(nombre, this->nombre);
        retorno = 1;
    }

    return retorno;
}

int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas)
{
    int retorno;

    *horasTrabajadas = -1;
    retorno = -1;

    if(this != NULL && horasTrabajadas !=NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno = 1;
    }

    return retorno;
}

int employee_getSueldo(Employee* this, int* sueldo)
{
    int retorno;

    *sueldo = -1;
    retorno = -1;

    if(this != NULL && sueldo !=NULL)
    {
        *sueldo = this->sueldo;
        retorno = 1;
    }

    return retorno;
}

int getIdMaximo(int len, LinkedList* pArrayListEmployee)
{
    Employee* pEmployee;
    int idMaximo;
    int i;
    int id;


    idMaximo = -1;



    if(pArrayListEmployee != NULL)
    {
        for(i = 0; i<len; i++)
        {
            pEmployee = (Employee*)ll_get(pArrayListEmployee, i);
            employee_getId(pEmployee, &id);

            if(idMaximo < id)
            {

                idMaximo = id;

            }
        }
    }

    return idMaximo;
}

int buscarPorNombre(char* nombre, LinkedList* pArrayListEmployee)
{
    Employee* pEmployeeAux;
    int i;
    int len;
    int id;

    char nombreAux[CAPACIDAD_ARRAY];

    strlwr(nombre);
    id = -1;
    len = ll_len(pArrayListEmployee);

    for(i=0; i<len; i++)
    {
        pEmployeeAux = (Employee*)ll_get(pArrayListEmployee, i);
        employee_getNombre(pEmployeeAux, nombreAux);
        strlwr(nombreAux);

        if(strcmp(nombre, nombreAux) == 0)
        {

            employee_getId(pEmployeeAux, &id);
            printf("El empleado enonctrado es: \n");
            MostrarEmpleado(pEmployeeAux);




            break;
        }

    }
    return id;
}

int employee_CompareByName(void* e1, void* e2)
{

    char nombreUno[CAPACIDAD_ARRAY];
    char nombreDos[CAPACIDAD_ARRAY];
    int retorno;

    retorno = 0;

    employee_getNombre(e1, nombreUno);
    employee_getNombre(e2, nombreDos);

    strlwr(nombreUno);
    strlwr(nombreDos);

    if(strcmp(nombreUno, nombreDos )== 1)
    {
        retorno = 1;
    }
    else

    {
        if(strcmp(nombreUno, nombreDos)== -1)
        {
            retorno = -1;
        }
    }

    return retorno;

}


int employee_CompareById(void* e1, void* e2)
{
    Employee* pEmpleadoUno;
    Employee* pEmpleadoDos;
    int idUno;
    int idDos;
    int retorno;


    pEmpleadoUno = (Employee*)e1;
    pEmpleadoDos = (Employee*)e2;

    employee_getId(pEmpleadoUno, &idUno);
    employee_getId(pEmpleadoDos, &idDos);

    if(idUno < idDos)
    {
        retorno = 1;
    }
    else
    {
        retorno = 0;
    }
    return retorno;
}

int MostrarEmpleado(Employee* pEmpleado)
{
    int id;
    int sueldo;
    int horasTrabajadas;
    char nombre[CAPACIDAD_ARRAY];

    employee_getId(pEmpleado, &id);
    employee_getNombre(pEmpleado, nombre);
    employee_getSueldo(pEmpleado, &sueldo);
    employee_getHorasTrabajadas(pEmpleado, &horasTrabajadas);


    printf("%-8d %-15s %-8d %-8d\n", id, nombre, sueldo, horasTrabajadas);
    return 1;
}
