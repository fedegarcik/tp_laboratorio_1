#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    //Inicializo variables
    int retorno;
    int banderaCarga;
    Employee* pEmployeeAux;
    char id[CAPACIDAD_ARRAY];
    char nombre[CAPACIDAD_ARRAY];
    char horasTrabajadas[CAPACIDAD_ARRAY];
    char sueldo[CAPACIDAD_ARRAY];

    //Pongo la bandera de carga en 0
    banderaCarga = 0;

    //Pongo el retorno en -1 en caso de error
    retorno = 1;

    //Leo un empleado en este caso la cabecera para evitar cargarlas en el array
    fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo);

    //Recorro el archivo hasta el final de este
    if(pArrayListEmployee != NULL && pFile !=NULL)
    {
        while(!feof(pFile))
        {

            //Leo un empleado
            if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo) == 4)
            {
                //Reservo espacio en memoria para el empleado y cargo los datos
                pEmployeeAux = employee_newParametros(id, nombre, horasTrabajadas, sueldo);

                //Agrego mi empleado a mi lista enlazada
                ll_add(pArrayListEmployee, pEmployeeAux);
                banderaCarga = 1;
            }
            else
            {
                banderaCarga = 0;
            }

            //Compruebo que se hallan cargado correctamente los datos
            if(banderaCarga == 0)
            {
                //Pongo el retorno en -1 en caso de error y salgo del bucle
                retorno = -1;
                break;
            }
        }
    }


    return retorno;

}

int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* pEmployeeAux;
    int retorno;

    retorno = -1;



    if(pArrayListEmployee != NULL && pFile != NULL)
    {
        while(!feof(pFile))
        {


                pEmployeeAux = employee_new();
                fread(pEmployeeAux ,sizeof(Employee), 1, pFile);
                //printf("%s", pEmployeeAux->nombre);
                if(!feof(pFile))
                {
                    ll_add(pArrayListEmployee, pEmployeeAux);

                }

                retorno = 1;

        }
    }

    return retorno;
}

