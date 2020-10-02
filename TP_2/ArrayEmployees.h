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
 * \return
 *
 */

void Menu();

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

void HardcodearDatos(eEmployee[], int);

