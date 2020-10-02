#define CANTIDAD_EMPLEADOS 1000
#define TAMANIO_ARRAYS 30

typedef struct
{
    int id;
    char name[TAMANIO_ARRAYS];
    char lastName[TAMANIO_ARRAYS];
    float salary;
    int sector;
    int isEmpty;
}eEmployee;

/** \brief Muestra un menu interactivo
 *
 * \param eEmployee[]: array de empleados con el que el menu trabajara para relaizar distintas operaciones
 * \return
 *
 */

void Menu(eEmployee[]);

/** \brief inicializa la varaibla is empty en 0 de todo el array
* \param Array de empleados
* \param capacidad del array
* \return int devuelve (-1) si hay error [longitud invalida] - (0) si ok
*
*/

int initEmployees(eEmployee[], int);

/** \brief Busca un espacio libre en el array de empleados si lo encuentra devuelve el indice sino devuelve -1
 *
 * \param eEmpleado el array de empleados donde se buscara el espacio li
 * \param int el indice donde hay un espacio libre
 * \return
 *
 */


int ObtenerEspacioLibre(eEmployee[], int);

/** \brief Carga un empleado en el array de empleados
 *
 * \param eEmployee[]: array de empleados donde se cargara el empleado
 * \param int: capacidad del array de empleados
 * \param int: el indice del array donde se cargara el empleado
 * \return
 *
 */


void CargarEmpleado(eEmployee[], int, int);

/** \brief Muestra los empleados cargados en el array
 *
 * \param eEmployee[]: el array de empleados;
 * \param int : capacidad del array;
 * \return
 *
 */


void MostrarEmpleados(eEmployee[], int );

/** \brief inicializa el campo id de todo el array en 0
 *
 * \param eEmployee[]: el array de empleados cullos id seran inicializados
 * \param int: capacidad de elementos del array
 * \return
 *
 */


void InicializarId(eEmployee[], int);

/** \brief Se busca un empleado segun su id, en caso de coincidencia devuelve el id correspondiente, en caso contrario devuelve 0
 *
 * \param eEmployee[]: el array de empleados en el cual se buscara la coincidencia de id
 * \param int: la cantidad de elementos del array de empleados
 * \return el id en caso de coincidencia, 0 en caso de error
 *
 */


int BuscarPorId(eEmployee[], int);

/** \brief Hardcodea los datos dentro del array de empleados
 *
 * \param eEmployee[]: el array de empleados donde se van a hardcodear los datos
 * \param int: la cantidad de elementos del array de empleados
 * \return retorna 1 si logro hardcodear los datos y 0 si no
 *
 */


int HardcodearDatos(eEmployee[], int);

/** \brief Da de baja logicamente a un empleado dentro del array de empleados a tra vez de una busqueda por id
 *
 * \param eEmployee[]: array de empleados en el cual se buscara el empleado a dar de baja
 * \param int capacidad del array
 * \param int id del empleado a ser dado de baja
 * \return devuelve 1 si logro dar de baja al empleado o 0 si no lo logro
 *
 */


int RemoverEmpleado(eEmployee[], int, int);


/** \brief Ordena los empleados por nombre y sector de manera descendente o ascendente dependiendo del parametro que se le pase
 *
 * \param eEmployee[]: array de empleados a ser ordenado
 * \param int: cantidad de elementos del array
 * \param int: numero que indica el orden en ser ordenados los elementos
 * \return devuelve 1 en caso de haber hecho ordenamientos y 0 si no fue capaz de ordenar nada
 *
 */


int ordenarEmpleados(eEmployee empleados[], int capacidad, int orden);


/** \brief Saca el salario total y promedio de los empleados del array los muestras y tambien a aquellos empleados que superen el salario promedio
 *
 * \param eEmployee[]: el array de empleados a calcular el salario total
 * \param int: la cantidad de elementos del array
 * \return Devuelve 0 si no encontro ningun empleado que supere el salario promedio y 1 si encontro almenos uno
 *
 */


int SacarSalarios(eEmployee empleados[], int capacidad);

/** \brief Modifica el empleado correspondiente al id ingresado
 *
 * \param eEmplyee[]: el array de empleados donde se buscara el empleado a modificar
 * \param int: cantidad de elementos del array de empleados
 * \param int: el id del empleado a modificar
 * \return
 *
 */


void ModificarEmpleado(eEmployee[], int, int);
