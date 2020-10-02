#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "EntradaySalida.h"
#include "ArrayEmployees.h"



void Menu(eEmployee empleados[])
{
    char subOpcion;
    char opcionAux[TAMANIO_ARRAYS];
    int opcion;
    int banderaInicializacion;
    int indice;
    int id;

    banderaInicializacion = 0;

    do
    {


        //Limpio la pantalla
        system("cls");

        //Muestro primeras opciones
        printf("1_Cargar empleado\n");
        printf("2_Modificar empleado\n");
        printf("3_Dar de baja empleado\n");
        printf("4_Informar\n");
        printf("5_Salir\n");

        //Ingreso la opcion y valido que sea un numero
        IngresarDatoCadenaCaracteres(opcionAux, "Ingrese una opcion por favor: \n");
        opcion = ValidarNumeroEntero(opcionAux);

        switch(opcion)
        {
            case 1:
                if(banderaInicializacion == 0)
                {
                    InicializarId(empleados, CANTIDAD_EMPLEADOS);
                    initEmployees(empleados, CANTIDAD_EMPLEADOS);
                    banderaInicializacion = 1;
                }
                indice = ObtenerEspacioLibre(empleados, CANTIDAD_EMPLEADOS);
                CargarEmpleado(empleados, indice, CANTIDAD_EMPLEADOS);
                AprieteEnter();
                break;
            case 2:
                if(banderaInicializacion == 0)
                {
                    printf("ERROR NECESITA CARGAR EMPLEADOS\n");
                    AprieteEnter();
                }
                else
                {
                    id = BuscarPorId(empleados, CANTIDAD_EMPLEADOS);
                    ModificarEmpleado(empleados, CANTIDAD_EMPLEADOS, id);
                }
                break;
            case 3:
                if(banderaInicializacion == 0)
                {
                    printf("ERROR NECESITA CARGAR EMPLEADOS\n");
                    AprieteEnter();
                }
                else
                {
                    id = BuscarPorId(empleados, CANTIDAD_EMPLEADOS);
                    RemoverEmpleado(empleados, CANTIDAD_EMPLEADOS, id);
                    AprieteEnter();
                }
                break;
            case 4:
                if(banderaInicializacion == 0)
                {
                    printf("ERROR NECESITA CARGAR EMPLEADOS\n");
                    AprieteEnter();
                }
                else
                {
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
                            ordenarEmpleados(empleados, CANTIDAD_EMPLEADOS, 1);
                            MostrarEmpleados(empleados, CANTIDAD_EMPLEADOS);
                            AprieteEnter();
                            break;
                        case 'B':
                            SacarSalarios(empleados, CANTIDAD_EMPLEADOS);
                            AprieteEnter();
                            break;
                        //Caso en el que no se ingresa opcion valida
                        default:
                            printf("ERROR eso no es una opcion valida\n");
                            AprieteEnter();
                            break;
                    }
                }
                break;
            //Caso en el que no se ingresa una opcion valida
            case 5:
                printf("Gracias por usar el programa!\n");
                AprieteEnter();
                break;
            default:
            printf("error");
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

    printf("Nombre   ");
    printf("Apellido  ");
    printf("id   ");
    printf("Salario  ");
    printf("Sector  \n");

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
            printf("Nombre   ");
            printf("Apellido  ");
            printf("id   ");
            printf("Salario  ");
            printf("Sector  \n");
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

int HardcodearDatos(eEmployee empleados[], int capacidad)
{
    int retorno;

    retorno = 0;

    //Se hardcodean los datos
    int i;
    int id[3] = {1,2,3};
    char nombre [3][30] = {"eduardo","fede","alejandro"};
    char apellido [3][30] = {"garcik","kluivoort","gomez"};
    int salario[3] = {3000,4000,5000};
    int sector[3] = {01,02,03};
    int isEmpty[3] = {1,1,1};

    //Bucle for donde los datos hardcodeados son introducidos al array de empleados
    for(i=0; i < capacidad; i++)
    {
        empleados[i].id      = id[i];
        empleados[i].salary  = salario[i];
        empleados[i].sector  = sector[i];
        empleados[i].isEmpty = isEmpty[i];
        strcpy(empleados[i].name, nombre[i]);
        strcpy(empleados[i].lastName,apellido[i]);

        //Condicion que evalua si se pudo hardcodear  los datos
        if(empleados[i].id                            == id[i]      &&
           strcmp(empleados[i].name,nombre[i])        == 0          &&
           strcmp(empleados[i].lastName, apellido[i]) == 0          &&
           empleados[i].salary                        == salario[i] &&
           empleados[i].sector                        == sector[i]  &&
           empleados[i].isEmpty                       == isEmpty[i])

        {
            retorno = 1;
        }

    }

    return retorno;
}


int RemoverEmpleado(eEmployee empleados[], int capacidad, int id)
{
    int i;
    int confirmacion;
    int retorno;

    retorno = 0;

    for(i=0; i< capacidad; i++)
    {
        if(id == empleados[i].id)
        {
            confirmacion = IngresarNumeroEntero("Esta seguro que desea borrar al empleado? 1 para si 0 para no");
            while(confirmacion != 0 &&
                  confirmacion != 1)
            {
                confirmacion = IngresarNumeroEntero("ERROR NUMERO NO VALIDO 1 para si 0 para no");
            }
            empleados[i].isEmpty = 0;
            retorno = 1;
        }
    }

    return retorno;
}

int ordenarEmpleados(eEmployee empleados[], int capacidad, int orden)
{
    eEmployee empleadoAux;
    int i;
    int j;
    int retorno;

    retorno = 0;

    for(i=0; i<capacidad; i++)
    {

        for(j = i+1; j<capacidad; j++)
        {

            if(orden == 0)
            {
                if(strcmp(empleados[i].name, empleados[j].name) > 0)
                empleadoAux  = empleados[i];
                empleados[i] = empleados[j];
                empleados[j] = empleadoAux;
                retorno = 1;
            }
            else
            {
                if(orden == 1)
                {
                    if(strcmp(empleados[i].name, empleados[j].name) < 0)
                    {
                        empleadoAux  = empleados[i];
                        empleados[i] = empleados[j];
                        empleados[j] = empleadoAux;
                        retorno = 1;
                    }
                }
            }
        }
    }


    return retorno;
}

int SacarSalarios(eEmployee empleados[], int capacidad)
{
    int i;
    int salarioTotal;
    int contadorSalarios;
    float salarioPromedio;
    int banderaPromedio;

    banderaPromedio = 0;
    contadorSalarios =0;
    salarioTotal = 0;

    for(i=0; i < capacidad; i++)
    {
        if(empleados[i].isEmpty == 1)
        {
            salarioTotal += empleados[i].salary;
            contadorSalarios++;
        }
    }

    salarioPromedio = (float)salarioTotal/contadorSalarios;

    printf("El salario total de los empleados es de %d\n", salarioTotal);
    printf("El salario promedio de los empleados es de %.2f\n", salarioPromedio);
    printf("Los empleados que superan el salario minimo son:\n");


    printf("Nombre   ");
    printf("Apellido  ");
    printf("id   ");
    printf("Salario  ");
    printf("Sector  \n");
    for(i = 0; i< capacidad; i++)
    {
        if(empleados[i].isEmpty == 1)
        {
            if(empleados[i].salary > salarioPromedio)
            {
                printf("%-10s", empleados[i].name);
                printf("%-10s", empleados[i].lastName);
                printf("%-5d", empleados[i].id);
                printf("%-10.2f", empleados[i].salary);
                printf("%-5d\n", empleados[i].sector);
                banderaPromedio = 1;
            }

        }
    }

    if(banderaPromedio == 0)
    {
        printf("No se encontro ningun empleado que superara el salario promedio\n");
    }
    return banderaPromedio;
}

void ModificarEmpleado(eEmployee empleados[], int capacidad, int id)
{
    int i;
    int opcion;
    char opcionAux[TAMANIO_ARRAYS];
    for(i=0; i<capacidad; i++)
    {
        if(empleados[i].id == id)
        {
            printf("Empleado a modificar:  \n");
            printf("Nombre   ");
            printf("Apellido  ");
            printf("id   ");
            printf("Salario  ");
            printf("Sector  \n");
            printf("%-10s", empleados[i].name);
            printf("%-10s", empleados[i].lastName);
            printf("%-5d", empleados[i].id);
            printf("%-10.2f", empleados[i].salary);
            printf("%-5d\n", empleados[i].sector);
            printf("*****************************************************");
            printf("1_Modificar nombre\n");
            printf("2_Modificar apellido\n");
            printf("3_Modificar sueldo\n");
            printf("4_modificar sector\n");

            //Ingreso la opcion y valido que sea un numero
            IngresarDatoCadenaCaracteres(opcionAux, "Ingrese una opcion por favor: \n");
            opcion = ValidarNumeroEntero(opcionAux);

            switch(opcion)
            {
                case 1:
                    printf("Ingrese nombre\n");
                    fflush(stdin);
                    gets(empleados[i].name);
                    break;
                case 2:
                    printf("Ingrese apellido por favor\n");
                    fflush(stdin);
                    gets(empleados[i].lastName);
                    break;
                case 3:
                    printf("Ingrese el salario por favor\n");
                    scanf("%f", &empleados[i].salary);
                    break;
                case 4:
                    printf("Ingrese el sector por favor\n");
                    scanf("%d", &empleados[i].sector);
                    break;
            }
        }
    }
    printf("Modifcaciones realizadas correctamente\n");
    AprieteEnter();



}
