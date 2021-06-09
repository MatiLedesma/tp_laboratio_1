#include "parser.h"
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
	FILE *pFileId;
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

    pFileId = fopen("../lastId.txt", "w");
    fprintf(pFileId, "%s", id);
    fclose(pFileId);

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
	int status;
	status = 0;
	FILE *pFileId;
	int id;
	int horasTrabajadas;
	int sueldo;
	Employee *employee;

	if (pFile != NULL && pArrayListEmployee != NULL)
	{
		ll_clear(pArrayListEmployee);
		while (!feof(pFile))
		{
			employee = employee_new();
			fread(employee, sizeof(Employee), 1, pFile);

			employee_getId(employee, &id);
			employee_getHorasTrabajadas(employee, &horasTrabajadas);
			employee_getSueldo(employee, &sueldo);

			if (id != 0 && horasTrabajadas != 0 && sueldo != 0)
			{
				if ((pFileId = fopen("../lastId.txt", "w")) != NULL)
				{
					fprintf(pFileId, "%d", id);
					fclose(pFileId);
				}
				ll_add(pArrayListEmployee, employee);
			}
		}
		status = 1;
	}
	else printf("Error...\n");
	return status;
}
