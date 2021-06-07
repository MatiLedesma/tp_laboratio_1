#include "Controller.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char *path, LinkedList *pArrayListEmployee)
{
	int status;
    FILE *archivo;

	status = 0;
    if ((archivo = fopen(path, "r")) != NULL)
    {
        parser_EmployeeFromText(archivo, pArrayListEmployee);
		fclose(archivo);
		status = 1;
    } else printf("Archivo vacio...\n");

    return status;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char *path, LinkedList *pArrayListEmployee)
{
	int status;
	FILE *archivo;

	status = 0;
	if ((archivo = fopen(path, "r")) != NULL)
	{
		parser_EmployeeFromBinary(archivo, pArrayListEmployee);
		fclose(archivo);
		status = 1;
	} else printf("Archivo vacio...\n");

    return status;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList *pArrayListEmployee)
{
	FILE *fileId;
	Employee *employee;
	char id[50];
	char nombre[50];
	char horasTrabajadas[50];
	char salario[50];

	if ((fileId = fopen("../lastId.txt", "r")) != NULL)
	{
		fscanf(fileId, "%s", id);
		fclose(fileId);
	}

	getString("Ingrese su nombre: ", nombre);
	getString_number("Ingrese sus horas trabajadas: ", "Error, reingrese: ", horasTrabajadas);
	getString_numer("Ingrese su salario: ", "Error, reingrese: ", salario);

	employee = employee_newParametros(id, nombre, horasTrabajadas, salario);

	ll_add(pArrayListEmployee, employee);

	sprintf(id, "%d", atoi(id)+1);

	if ((fileId = fopen("../lastId.txt", "w")) != NULL)
	{
		fprintf(fileId, "%s", id);
		fclose(fileId);
	}
	printf("id: %s\n", id);

    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList *pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList *pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList *pArrayListEmployee)
{
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList *pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char *path, LinkedList *pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char *path, LinkedList *pArrayListEmployee)
{
    return 1;
}
