#include <stdio.h>
#include <stdlib.h>
#include "EntradaySalida.h"
#include "ArrayEmployees.h"


int main()
{

    eEmployee empleados[3];//CANTIDAD_EMPLEADOS];
    //Menu();
    int indice;
    int i;
    int id;
    initEmployees(empleados, 3);
    /*

    for(i = 0; i<3; i++)
    {
        indice = ObtenerEspacioLibre(empleados, 3);
        CargarEmpleado(empleados, indice, 3);

    }
    */
    HardcodearDatos(empleados, 3);

    MostrarEmpleados(empleados, 3);

    id = BuscarPorId(empleados, 3);
    printf("%d", id);

    return 0;
}
