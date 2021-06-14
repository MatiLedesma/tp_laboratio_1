#include "parser.h"
#include "Controller.h"
/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE *pFile, LinkedList *pArrayListEmployee)
{
	int status;
	status = 0;
    //id,nombre,horasTrabajadas,sueldo
    char id[50];
    char nombre[50];
    char horasTrabajadas[50];
    char sueldo[50];
    Employee *employee;

    if (pFile != NULL && pArrayListEmployee != NULL)
    {
    	ll_clear(pArrayListEmployee);
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo);
        while (!feof(pFile))
        {
            fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo);
            employee = employee_newParametros(id, nombre, horasTrabajadas, sueldo);
            ll_add(pArrayListEmployee, employee);
        }
        status = 1;
    }
    else printf("Error...\n");

    controller_loadLastId("../lastId.txt", id);

    return status;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE *pFile, LinkedList *pArrayListEmployee)
{
	int fReadStatus;
	int status;
	status = 0;
	int id;
	char idStr[50];
	Employee *employee;

	if (pFile != NULL && pArrayListEmployee != NULL)
	{
		ll_clear(pArrayListEmployee);
		while (!feof(pFile))
		{
			employee = employee_new();
			fReadStatus = fread(employee, sizeof(Employee), 1, pFile);

			if (fReadStatus == 1)
			{
				employee_getId(employee, &id);
				sprintf(idStr, "%d", id);
				controller_loadLastId("../lastId.txt", idStr);
				ll_add(pArrayListEmployee, employee);
			}
		}
		status = 1;
	}
	else printf("Error...\n");
	return status;
}
