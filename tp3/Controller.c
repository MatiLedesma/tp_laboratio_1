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
	status = 0;

	FILE* pFile;
	if(path != NULL && pArrayListEmployee != NULL)
	{
		if((pFile = fopen(path,"rb")) != NULL)
		{
			parser_EmployeeFromBinary(pFile, pArrayListEmployee);
			status = 1;
			fclose(pFile);
		} else printf("Archivo vacio...\n");
	}
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
	getString_number("Ingrese su salario: ", "Error, reingrese: ", salario);

	sprintf(id, "%d", atoi(id)+1);
	employee = employee_newParametros(id, nombre, horasTrabajadas, salario);

	ll_add(pArrayListEmployee, employee);

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
	int status;
	status = 0;
	char id[50];
	int idEncontrado;
	int length = ll_len(pArrayListEmployee);
	int i;
	Employee *employee;

	char nombre[50];
	char horasTrabajadas[50];
	char salario[50];
	int option;


	getString_number("Ingrese la id que desea buscar: ", "Error, reingrese: ", id);

	if (pArrayListEmployee != NULL)
	{
		for (i = 0; i < length; i++)
		{
			employee = (Employee*)ll_get(pArrayListEmployee, i);
			employee_getId(employee, &idEncontrado);
			if (idEncontrado == atoi(id))
			{
				printf("Que desea modificar? \n1. Nombre\n2. Horas trabajadas\n3. Salario\n > : ");
				scanf("%d", &option);
				switch(option)
				{
				case 1:
					getString("Ingrese el nuevo nombre: ", nombre);
					employee_setNombre(employee, nombre);
					break;
				case 2:
					getString_number("Ingrese las nuevas horas trabajadas: ", "Error, reingrese", horasTrabajadas);
					employee_setHorasTrabajadas(employee, atoi(horasTrabajadas));
					break;
				case 3:
					getString_number("Ingrese su nuevo salario: ", "Error, reingrese: ", salario);
					employee_setSueldo(employee, atoi(salario));
					break;
				}
				status = 1;
				printf("Empleado modificado!\n");
				break;
			}
		}
	}


    return status;
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
	int status;
	status = 0;
	char id[50];
	int idEncontrado;
	int length = ll_len(pArrayListEmployee);
	int i;
	Employee *employee;

	char option[50];


	getString_number("Ingrese la id que desea eliminar: ", "Error, reingrese: ", id);

	if (pArrayListEmployee != NULL)
	{
		for (i = 0; i < length; i++)
		{
			employee = (Employee*)ll_get(pArrayListEmployee, i);
			employee_getId(employee, &idEncontrado);
			if (idEncontrado == atoi(id))
			{
				getString("Ingrese 'si' si desea eliminar al empleado: ", option);
				if (strcmp(option, "si") == 0 || strcmp(option, "Si") == 0 || strcmp(option, "SI") == 0)
				{
					ll_remove(pArrayListEmployee, i);
					printf("Empleado eliminado...\n");
					break;
				}
			}
		}
	}
	return status;
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
	int status;
	status = 0;
	int i;
	Employee *employee;
	int length = ll_len(pArrayListEmployee);

	if (pArrayListEmployee != NULL)
	{
		for (i = 0; i < length; i++)
		{
			employee = (Employee*)ll_get(pArrayListEmployee, i);
			printf("%20d %30s %20d %20d\n", employee->id, employee->nombre,
					employee->horasTrabajadas, employee->sueldo);
			status = 1;
		}
	}
    return status;
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
	ll_sort(pArrayListEmployee, swap_alpha, 1);
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
	int i;
	FILE *pFile;
	Employee *employee;
	if (pArrayListEmployee != NULL)
	{
		int length = ll_len(pArrayListEmployee);

		if ((pFile = fopen(path, "w")) != NULL)
		{
			fprintf(pFile, "id,nombre,horasTrabajadas,sueldo\n");
			for (i = 0; i < length; i++)
			{
				employee = (Employee*)ll_get(pArrayListEmployee, i);
				fprintf(pFile, "%d,%s,%d,%d\n", employee->id, employee->nombre
						, employee->horasTrabajadas, employee->sueldo);
			}
			fclose(pFile);
		}
	}
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
	int i;
	FILE *pFile;
	Employee *employee;
	if (pArrayListEmployee != NULL)
	{
		int length = ll_len(pArrayListEmployee);

		if ((pFile = fopen(path, "wb")) != NULL)
		{
			for (i = 0; i < length; i++)
			{
				employee = (Employee*)ll_get(pArrayListEmployee, i);
				fwrite(employee, sizeof(Employee), 1, pFile);
			}
			fclose(pFile);
		}
	}
    return 1;
}
