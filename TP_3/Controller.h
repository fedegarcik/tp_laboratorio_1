
/** \brief Carga desde un archivo de texto datos
 *
 * \param char*: path al archivo
 * \param LinkedList*: puntero a la lista enlazada donde se almacenara la informacion
 * \return 1 en caso de exito -1 en caso de error
 *
 */


int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);

/** \brief Carga desde un archivo binario datos
 *
 * \param char*: path al archivo
 * \param LinkedList*: puntero a la lista enlazada donde se almacenara la informacion
 * \return 1 en caso de exito -1 en caso de error
 *
 */


int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);

/** \brief Agrega un empleado a la lista
 *
 * \param LinkedList*: puntero a la lista enlazada donde se agregara el empleado
 * \return devuelve 1 en caso de exito -1 en caso de error
 *
 */


int controller_addEmployee(LinkedList* pArrayListEmployee);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);


