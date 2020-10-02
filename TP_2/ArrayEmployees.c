#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "EntradaySalida.h"
#include "ArrayEmployees.h"



void Menu()
{
    char subOpcion;
    char opcionAux[TAMANIO_ARRAYS];
    int opcion;

    do
    {
        //Limpio la pantalla
        system("cls");

        //Muestro primeras opciones
        printf("1_Cargar empleado\n");
        printf("2_Modificar empleado\n");
        printf("3_Dar de baja empleado\n");
        printf("4_Informar\n");

        //Ingreso la opcion y valido que sea un numero
        IngresarDatoCadenaCaracteres(opcionAux, "Ingrese una opcion por favor: \n");
        opcion = ValidarNumeroEntero(opcionAux);

        switch(opcion)
        {
            case 1:
                AprieteEnter();
                break;
            case 2:
                AprieteEnter();
                break;
            case 3:
                AprieteEnter();
                break;
            case 4:
                //Sub menu para elegir de que manera listar los empleados
                printf("A_listar por nombre y salario\n");
                printf("B_listar por promedio salarial\n");

                printf("Ingrese una opcion por favor: \n");
                fflush(stdin);
                scanf("%c", &subOpcion);

                subOpcion = toupper(subOpcion);

                switch(subOpcion)
                {
                    case 'A':
                        printf("a");
                        AprieteEnter();
                        break;
                    case 'B':
                        printf("b");
                        AprieteEnter();
                        break;
                    //Caso en el que no se ingresa opcion valida
                    default:
                        printf("ERROR eso no es una opcion valida\n");
                        AprieteEnter();
                        break;
                }
                break;
            //Caso en el que no se ingresa una opcion valida
            default:
                printf("ERROR esa no es una opcion valida:");
                AprieteEnter();
                break;
        }


    }while(opcion != 5);
}

int initEmployees(eEmployee empleados[], int capacidad)
{
    //eEmployee empleadosAux[CANTIDAD];
    int i;
    int retorno;
    //int peso;



    //peso = (sizeof(empleadosAux) / sizeof(struct eEmployee));


    //printf("%d\n", peso);


    retorno = -1;

    if(capacidad == CANTIDAD_EMPLEADOS || capacidad < CANTIDAD_EMPLEADOS)
    {
        //Inicializo los id en 0 para poder buscar un maximo
        InicializarId(empleados, capacidad);

        //Inicializo la variable de estado para no tener valores basures y que comienzen  todos dados de baja
        for(i = 0; i < capacidad ; i++)
        {
            empleados[i].isEmpty = 0;
        }
        retorno = 0;
    }
    return retorno;
}

int ObtenerEspacioLibre(eEmployee empleados[], int capacidad)
{
    int i;
    int banderaEspacioLibre;

    banderaEspacioLibre = 0;

    //Busco en el array cual es el espacio libre
    for(i = 0; i<capacidad; i++)
    {
        if(empleados[i].isEmpty == 0)
        {
            banderaEspacioLibre  = 1;
            //empleados[i].estado = 1;

            break;
        }
    }

    //En caso de no encontrar espacio se devuelve -1 como error
    if(banderaEspacioLibre == 0)
    {
        i = -1;
    }
    return i;
}

void CargarEmpleado(eEmployee empleados[], int indice, int capacidad)
{
    int idMaximo;
    int i;

    idMaximo = 0;
    //Se cargan todos los datos
    printf("Ingrese nombre\n");
    fflush(stdin);
    gets(empleados[indice].name);

    printf("Ingrese apellido por favor\n");
    fflush(stdin);
    gets(empleados[indice].lastName);

    printf("Ingrese el salario por favor\n");
    scanf("%f", &empleados[indice].salary);

    printf("Ingrese el sector por favor\n");
    scanf("%d", &empleados[indice].sector);


    //Se busca cual es el id maximo ya que estan inicializados en 0 si es la primera vez devolvera 0 sino devolvera el ultimo id asignado
    for(i = 0; i<capacidad; i++)
    {
        if(empleados[i].id > idMaximo)
        {
            idMaximo = empleados[i].id;
        }
    }
    //Al id maximo se le suma uno de esta forma se vuelve al campo id en auto incremental
    empleados[indice].id = idMaximo + 1;

    //Se hace la alta logica del empleado
    empleados[indice].isEmpty = 1;
}

void InicializarId(eEmployee empleados[], int capacidad)
{
    int i;
    //Recorro el array comletamente mientras incializo el campo id en 0
    for(i=0; i<capacidad; i++)
    {
        empleados[i].id = 0;
    }
}

void MostrarEmpleados(eEmployee empleados[], int capacidad)
{
    int i;
    //Recorro el array de empleados mostrando los datos de cada empleado con formato
    for(i = 0; i< capacidad; i++)
    {
        if(empleados[i].isEmpty == 1)
        {
            /*
            Es de observar que la juistificacion esta en negativo ya que en positivo no da el formato deseado, no se sabe el motivo sin embargo funciona
            se supone que justifica en vez de a la derecha hacia la izquierda asi que se toma como solucion
            */
            printf("%-10s", empleados[i].name);
            printf("%-10s", empleados[i].lastName);
            printf("%-5d", empleados[i].id);
            printf("%-10.2f", empleados[i].salary);
            printf("%-5d\n", empleados[i].sector);
        }
    }
}



int BuscarPorId(eEmployee empleados[], int capacidad)
{
    int i;
    int idBusqueda;
    int flagId;
    int retorno;

    retorno = 0;
    flagId = 0;
    //Se pide ingresar el id del empleado a buscar
    printf("ingrese el id del empleado a buscar: \n");
    scanf("%d", &idBusqueda);

    //Bucle for que reccore todo el array de empleados en busca de una coincidencia del id ingresado
    for(i = 0; i<capacidad; i++)
    {
        //En caso de coincidencia se muestra el empleado y se almacena en la variable de retorno el id del empleado
        if(idBusqueda == empleados[i].id)
        {
            flagId = 1;
            retorno = empleados[i].id;
             /*
            Es de observar que la juistificacion esta en negativo ya que en positivo no da el formato deseado, no se sabe el motivo sin embargo funciona
            se supone que justifica en vez de a la derecha hacia la izquierda asi que se toma como solucion
            */
            printf("El empleado encontrado es: \n");
            printf("%-10s", empleados[i].name);
            printf("%-10s", empleados[i].lastName);
            printf("%-5d", empleados[i].id);
            printf("%-10.2f", empleados[i].salary);
            printf("%-5d\n", empleados[i].sector);
            break;
       }
    }


    //En caso de no encontrar coincidencia muestra mensaje de error y se retorna 0
    if(flagId == 0)
    {
        printf("Error, no existe el id");
    }



    return retorno;
}

void HardcodearDatos(eEmployee empleados[], int capacidad)
{
    //Se hardcodean los datos
    int i;
    int id[3] = {1,2,3};
    char nombre [3][30] = {"fede","german","octavio"};
    char apellido [3][30] = {"garcik","scarafilo","villegas"};
    int salario[3] = {3000,4000,5000};
    int sector[3] = {01,02,03};
    int isEmpty[3] = {1,1,1};

    //Bucle for donde los datos hardcodeados son introducidos al array de empleados
    for(i=0; i < capacidad; i++)
    {
        empleados[i].id      = id[i];
        empleados[i].salary     = salario[i];
        empleados[i].sector  = sector[i];
        empleados[i].isEmpty = isEmpty[i];
        strcpy(empleados[i].name, nombre[i]);
        strcpy(empleados[i].lastName,apellido[i]);

    }
}
