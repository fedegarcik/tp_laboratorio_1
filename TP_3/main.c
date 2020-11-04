#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include <string.h>
#include "EntradaySalida.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main()
{
    int opcion;
    int banderaLoad;
    LinkedList* pEmployeeList;
    pEmployeeList = ll_newLinkedList();

    banderaLoad = 0;
    do
    {
        system("cls");
        printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
        printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
        printf("3. Alta de empleado\n");
        printf("4. Modificar datos de empleado\n");
        printf("5. Baja de empleado\n");
        printf("6. Listar empleados\n");
        printf("7. Ordenar empleados\n");
        printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
        printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
        printf("10. Salir\n");
        printf("Ingrese una opcion: \n");
        scanf("%d", &opcion);
        switch(opcion)
        {
            case 1:
                if(banderaLoad == 1)
                {
                    printf("Ya esta cargados los archivos");
                }
                else
                {
                    if(banderaLoad == 0)
                    {
                        banderaLoad = controller_loadFromText("data.csv", pEmployeeList);
                    }
                    else
                    {
                        printf("ERROR NO SE ENCUENTRA EL ARCHIVO\n");
                    }
                }
                AprieteEnter();

                break;
            case 2:
                if(banderaLoad == 1)
                {
                    printf("Ya estan cargados los datos");
                }
                else
                {
                    if(banderaLoad == 0)
                    {
                        banderaLoad = controller_loadFromBinary("data.bin", pEmployeeList);
                    }
                    else
                    {
                        printf("ERROR NO SE ENCUENTRA EL ARCHIVO\n");
                    }
                }

                AprieteEnter();
                break;
            case 3:
                if(banderaLoad == 1)
                {
                    controller_addEmployee(pEmployeeList);
                }
                else
                {
                    printf("ERROR NO SE ENCONTRARON LOS DATOS");
                }
                AprieteEnter();
                break;
            case 4:
                if(banderaLoad == 1)
                {
                    controller_editEmployee(pEmployeeList);
                }
                else
                {
                    printf("ERROR NO SE ENCONTRARON LOS DATOS");
                }
                AprieteEnter();
                break;
            case 5:
                if(banderaLoad == 1)
                {
                    controller_removeEmployee(pEmployeeList);
                }
                else
                {
                    printf("ERROR NO SE ENCONTRARON LOS DATOS");
                }
                AprieteEnter();
                break;
            case 6:
                if(banderaLoad == 1)
                {
                    controller_ListEmployee(pEmployeeList);
                }
                else
                {
                    printf("ERROR NO SE PUDIERON ENCONTRAR LOS DATOS\n");
                }
                AprieteEnter();
                break;
            case 7:
                if(banderaLoad == 1)
                {
                    controller_sortEmployee(pEmployeeList);
                }
                else
                {
                    printf("ERROR NO SE ENCONTRARON LOS DATOS");
                }
                AprieteEnter();
                break;
            case 8:
                if(banderaLoad == 1)
                {
                    controller_saveAsText("data.csv", pEmployeeList);
                }
                else
                {
                    printf("ERROR NO SE ENCONTRARON LOS DATOS");
                }
                AprieteEnter();
                break;
            case 9:
                if(banderaLoad == 1)
                {
                    controller_saveAsBinary("data.bin", pEmployeeList);
                }
                else
                {
                    printf("ERROR NO SE ENCONTRARON LOS DATOS");
                }
                AprieteEnter();
                break;
            case 10:
                printf("Gracias por usar el programa\n");
                break;
            default:
                printf("Opcion invalida\n");
                AprieteEnter();
                break;
        }
    }while(opcion!=10);



    return 0;
}
