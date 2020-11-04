
/** \brief Parsea un archivo de texto a una lista de empleados
 *
 * \param FILE*: puntero al archivo
 * \param LinkedList* puntero a la lista enlazada
 * \return 1 en caso de exito -1 en caso de error
 *
 */


int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);

/** \brief parsea un archivo binario a una lista de empleados
 *
 * \param FILE*: puntero al archivo
 * \param LinkedList* Puntero a la lista enlazada
 * \return -1 en caso de error 1 en caso de exito
 *
 */


int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);


