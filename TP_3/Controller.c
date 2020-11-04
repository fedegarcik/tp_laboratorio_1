#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "EntradaySalida.h"
#include "Controller.h"
#include "limits.h"
#include "ctype.h"


int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno;
    FILE* pFile;

    retorno = -1;


    pFile = fopen(path, "r");
    if(pFile != NULL)
    {
        retorno = parser_EmployeeFromText(pFile, pArrayListEmployee);
    }

    fclose(pFile);


    return retorno;
}


int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    int retorno;

    retorno = -1;


    pFile = fopen(path, "rb");

    if(pFile != NULL)
    {
        retorno = parser_EmployeeFromBinary(pFile, pArrayListEmployee);

    }
    fclose(pFile);
    return retorno;
}


int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pEmployeeAux;
    char nombre[CAPACIDAD_ARRAY];
    char horasTrabajadasStr[CAPACIDAD_ARRAY];
    char sueldoStr[CAPACIDAD_ARRAY];
    char idMaximoStr[CAPACIDAD_ARRAY];
    int idMaximo;
    int horasTrabajadas;
    int sueldo;
    int retorno;

    retorno = -1;

    if(pArrayListEmployee !=NULL)
    {

        pEmployeeAux = employee_new();
        int len = ll_len(pArrayListEmployee);
        idMaximo = getIdMaximo(len, pArrayListEmployee);
        itoa(idMaximo+1,idMaximoStr, 10);

        IngresarDatoCadenaCaracteres(nombre, "Ingrese el nombre del empleado: ");

        IngresarDatoCadenaCaracteres(horasTrabajadasStr, "Ingrese la cantidad de horas trabajadas: ");
        horasTrabajadas = ValidarNumeroEntero(horasTrabajadasStr);

        IngresarDatoCadenaCaracteres(sueldoStr, "Ingrese el sueldo del empleado: ");
        sueldo = ValidarNumeroEntero(sueldoStr);


        if(sueldo          < INT_MAX &&
           horasTrabajadas < INT_MAX &&
           sueldo          > 0       &&
           horasTrabajadas > 0)
        {
            //Usar empleado new  parametros ?
            pEmployeeAux = employee_newParametros(idMaximoStr, nombre, horasTrabajadasStr, sueldoStr);
            ll_add(pArrayListEmployee, pEmployeeAux);
            printf("Empleado agregado exitosamente\n");
            retorno = 1;
        }
        else
        {
            printf("Valores invalidos o no soportados por la aplicacion.\n");
        }



    }
    return retorno;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pEmployeeAux;
    int index;
    int retorno;
    int sueldo;
    int horasTrabajadas;
    char indexStr[CAPACIDAD_ARRAY];
    char nombre[CAPACIDAD_ARRAY];
    char horasTrabajadasStr[CAPACIDAD_ARRAY];
    char sueldoStr[CAPACIDAD_ARRAY];


    retorno = -1;

    if(pArrayListEmployee != NULL)
    {
        controller_ListEmployee(pArrayListEmployee);


        IngresarDatoCadenaCaracteres(indexStr, "Ingrese el nombre del empleado que quiere modificar");
        index = buscarPorNombre(indexStr, pArrayListEmployee);






        IngresarDatoCadenaCaracteres(nombre, "Ingrese el nombre del empleado: ");

        IngresarDatoCadenaCaracteres(horasTrabajadasStr, "Ingrese la cantidad de horas trabajadas: ");
        horasTrabajadas = ValidarNumeroEntero(horasTrabajadasStr);

        IngresarDatoCadenaCaracteres(sueldoStr, "Ingrese el sueldo del empleado: ");
        sueldo = ValidarNumeroEntero(sueldoStr);



        if(sueldo          < INT_MAX &&
           horasTrabajadas < INT_MAX &&
           sueldo          > 0       &&
           horasTrabajadas > 0)
        {

            pEmployeeAux = employee_newParametros(itoa(index, indexStr, 10), nombre, horasTrabajadasStr, sueldoStr);
            ll_set(pArrayListEmployee, index-1, pEmployeeAux);
            retorno = 1;
            printf("Empleado modificado correctamente\n");
        }
        else
        {
            printf("Valores invalidos o no soportados por la aplicacion.\n");
        }



    }
    return retorno;
}

//Buquedas por rasgo no por id
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{

    int index;
    int retorno;
    char indexStr[CAPACIDAD_ARRAY];
    char confirmacion;

    retorno = -1;


    if(pArrayListEmployee != NULL)
    {
        controller_ListEmployee(pArrayListEmployee);

        IngresarDatoCadenaCaracteres(indexStr, "Ingrese el nombre del empleado que quiere modificar");
        index = buscarPorNombre(indexStr, pArrayListEmployee);








        printf("Esta seguro que desea eleminarlo s para si n para no");
        scanf("%c", &confirmacion);
        confirmacion = tolower(confirmacion);
        if(confirmacion != 's' &&
           confirmacion != 'n')
        {
            printf("ERROR NO ES UNA OPCION VALIDA REINGRESE s para si n para no");
            scanf("%c", &confirmacion);
            confirmacion = tolower(confirmacion);
        }

        if(confirmacion == 's')
        {
            index = ll_remove(pArrayListEmployee, index -4);

            printf("Se borro exitosamente el empleado");
            retorno = 1;
        }
        else
        {
            printf("Se cancelo la operacion");
            retorno = 2;
        }

    }

    return retorno;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pEmployeeAux;
    int len;
    int i;
    int retorno;


    len =  ll_len(pArrayListEmployee);
    retorno = -1;

    if(pArrayListEmployee != NULL)
    {
        for(i=0;i<len;i++)
        {
            pEmployeeAux = ll_get(pArrayListEmployee, i);
            MostrarEmpleado(pEmployeeAux);
            /*
            employee_getId(pEmployeeAux, &id);
            employee_getNombre(pEmployeeAux, nombre);
            employee_getSueldo(pEmployeeAux, &sueldo);
            employee_getHorasTrabajadas(pEmployeeAux, &horasTrabajadas);


            printf("%-8d %-15s %-8d %-8d\n", id, nombre, sueldo, horasTrabajadas);
            */

            retorno = 1;
        }

    }

    return retorno;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int opcion;
    char opcionAux[CAPACIDAD_ARRAY];
    int retorno;

    IngresarDatoCadenaCaracteres(opcionAux, "Ingrese 1 para ordenar por nombre o 2 para ordenar por id");
    opcion = ValidarNumeroEntero(opcionAux);
    retorno = -1;

    if(opcion == 1)
    {
        printf("Aguarde puede tomar varios segundos...\n");
        ll_sort(pArrayListEmployee, employee_CompareByName, 1);
        retorno = 1;
    }
    else
    {
        if(opcion == 2)
        {
            printf("Aguarde puede tomar varios segundos...\n");
            ll_sort(pArrayListEmployee, employee_CompareById, 1);
            retorno = 1;
        }
        else
        {
            printf("Opcion invalida");
        }
    }
    return retorno;
}


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    Employee* pEmployeeAux;
    FILE* pFile;
    int i;
    int len;
    int id;
    char nombre[CAPACIDAD_ARRAY];
    int sueldo;
    int horasTrabajadas;
    int retorno;

    retorno = -1;

    len = ll_len(pArrayListEmployee);

    pFile = fopen(path, "w");

    if(pFile != NULL)
    {

        for(i=0;i<len;i++)
        {
            pEmployeeAux = (Employee*)ll_get(pArrayListEmployee, i);
            employee_getId(pEmployeeAux, &id);
            employee_getNombre(pEmployeeAux, nombre);
            employee_getSueldo(pEmployeeAux, &sueldo);
            employee_getHorasTrabajadas(pEmployeeAux, &horasTrabajadas);

            fprintf(pFile, "%d,%s,%d,%d,\n", id, nombre, horasTrabajadas, sueldo);
            retorno = 1;
        }
    }

    fclose(pFile);



    return retorno;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    Employee* pEmployeeAux;
    FILE* pFile;
    int len;
    int i;
    int retorno;

    retorno = -1;


    len = ll_len(pArrayListEmployee);
    pFile = fopen(path, "wb");

    if(pFile != NULL)
    {
        for(i=0;i<len;i++)
        {
            pEmployeeAux = (Employee*)ll_get(pArrayListEmployee, i);
            fwrite(pEmployeeAux, sizeof(Employee), 1, pFile);
            retorno = 1;

        }
    }
    fclose(pFile);


    return retorno;;
}

