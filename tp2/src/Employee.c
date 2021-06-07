#include "Employee.h"

static int id;
static int datosCargados = 0;

int initEmployee(sEmployee* employeeArray, int tam)
{
	int i;

	for (i = 0; i < tam; i++)
	{
		(employeeArray+i)->isEmpty = EMPTY;
	}

	return 0;
}

int searchFree(sEmployee* employeeArray, int tam)
{
	int i;
	int index;
	index = -1;

	for (i = 0; i < tam; i++)
	{
		if ((employeeArray+i)->isEmpty == EMPTY)
		{
			index = i;
			break;
		}
	}

	return index;
}
///////// ALTA EMPLOYEES
int limitSector(int* sector, char* msj)
{
	GetInt(sector, msj);
	while(*sector < 0 || *sector > 10)
	{
		GetInt(sector, msj);
	}
	return 0;
}
sEmployee createEmployee(sEmployee* employeeArray, int tam)
{
	sEmployee employee;
	id = searchFree(employeeArray, tam);
	employee.id = id;
	GetString(employee.name, "Ingrese su nombre: ");
	GetString(employee.lastName, "Ingrese su apellido: ");
	GetFloat(&employee.salary, "Ingrese su salario: ");
	limitSector(&employee.sector, "Ingrese el sector (0, 10): ");
	employee.isEmpty = OCUPED;
	return employee;
}

int addEmployee(sEmployee* employeeArray, int tam)
{
	int index;

	index = searchFree(employeeArray, tam);
	if (index != -1)
	{
		employeeArray[index] = createEmployee(employeeArray, tam);
		datosCargados++;
	}
	else
	{
		printf("No hay espacio para ingresar mas empleados...\n");
	}

	return index;
}
////////// SEARCH, MODIFY AND DELETE EMPLOYEES
int findEmployeeById(sEmployee* employeeArray, int tam)
{
	int i;
	int id;
	int index;
	index = -1;
	GetInt(&id, "Ingrese la id del producto: ");

	for (i = 0; i < tam; i++)
	{
		if ((employeeArray+i)->id == id)
		{
			index = i;
			break;
		}
	}

	return index;
}

int optionModify(sEmployee* employeeData)
{
	int opc;
	GetInt(&opc, "> : ");

	switch(opc)
	{
	case 1:
		GetString(employeeData->name, "Ingrese el nuevo nombre: ");
		break;
	case 2:
		GetString(employeeData->lastName, "Ingrese el nuevo apellido: ");
		break;
	case 3:
		GetFloat(&employeeData->salary, "Ingrese el nuevo salario: ");
		break;
	case 4:
		limitSector(&employeeData->sector, "Ingrese el nuevo sector (0, 10): ");;
		break;
	}

	return 0;
}

int modifyEmployee(sEmployee* employeeArray, int tam)
{
	int index;
	if(existEmployee() != 0)
	{
		showEmployee(employeeArray, tam);
		index = findEmployeeById(employeeArray, tam);
		if(index != -1)
		{
			if(employeeArray[index].isEmpty != EMPTY)
			{
				showSingleEmployee(employeeArray[index]);
				printf("Que desea modificar? \n 1(nombre)\n 2(apellido)\n 3(salario)\n 4(sector)\n");
				optionModify(&employeeArray[index]);
			}
		}
		else
		{
			printf("No se encontro la id...\n");
		}
	}
	return 0;
}

int optionRemove(sEmployee* employeeData)
{
	char opc;
	GetChar(&opc, "> : ");
	opc = toupper(opc);
	if (opc == 'S')
	{
		employeeData->isEmpty = EMPTY;
	}
	else
	{
		printf("Cancelado\n");
	}

	return 0;
}

int removeEmployee(sEmployee* employeeArray, int tam)
{
	int index;
	if(existEmployee() != 0)
	{
		showEmployee(employeeArray, tam);
		index = findEmployeeById(employeeArray, tam);
		if(index != -1)
		{
			if(employeeArray[index].isEmpty != EMPTY)
			{
				showSingleEmployee(employeeArray[index]);
				printf("Seguro desea eliminar este empleado? s/n");
				optionRemove(&employeeArray[index]);
				datosCargados--;
			}
		}
		else
		{
			printf("No se encontro la id...\n");
		}
	}
	return 0;
}
///////// SORT EMPLOYEES

int sortLastName(sEmployee* employeeData, int i, int j)
{
	sEmployee auxiliar;
	if (strcmp((employeeData+i)->lastName, (employeeData+j)->lastName) > 0)
	{
		auxiliar = employeeData[i];
		employeeData[i] = employeeData[j];
		employeeData[j] = auxiliar;
	}

	return 0;
}
int sortSector(sEmployee* employeeData, int i, int j)
{
	sEmployee auxiliar;
	if ((employeeData+i)->sector > (employeeData+j)->sector)
	{
		auxiliar = employeeData[i];
		employeeData[i] = employeeData[j];
		employeeData[j] = auxiliar;
	}

	return 0;
}

int sortEmployee(sEmployee* employeeData, int tam)
{
	int i;
	int j;

	for (i = 0; i < tam - 1; i++)
	{
		for (j = i+1; j < tam; j++)
		{
			sortLastName(employeeData, i, j);
			sortSector(employeeData, i, j);
		}
	}

	return 0;
}

////////// AVERAGES

int calculateTotalSalary(sEmployee* employeeArray, int tam)
{
	int price;
	int i;
	price = 0;
	for(i = 0; i < tam; i++)
	{
		if((employeeArray+i)->isEmpty != EMPTY)
		{
			price += employeeArray[i].salary;
		}
	}
	return price;
}

float calculateAverage(sEmployee* employeeArray, int tam)
{
	int salaryTotal;
	int average;
	salaryTotal = calculateTotalSalary(employeeArray, tam);
	average = 0;
	average = salaryTotal / tam;
	return average;
}

int averageSalary(sEmployee* employeeArray, int tam)
{
	int i;
	int counter;
	float average;
	int salaryTotal;
	salaryTotal = calculateTotalSalary(employeeArray, tam);
	counter = 0;
	average = calculateAverage(employeeArray, tam);
	for (i = 0; i < tam; i++)
	{
		if ((employeeArray+i)->salary > average)
		{
			counter++;
		}
	}

	printf("El salario total es: %d\n", salaryTotal);
	printf("El promedio es: %.2f\n", average);
	printf("%d empleado/s superan el salario promedio. \n", counter);
	return 0;
}

///////// SHOW EMPLOYEES
int existEmployee()
{
	int status;
	status = 1;
	if (datosCargados == 0)
	{
		printf("No hay datos cargados...\n");
		status = 0;
	}
	return status;
}

void printMessage(sEmployee employeeData)
{
	printf("%20d %20s %20s %10.1f %10d\n",
		employeeData.id,employeeData.name, employeeData.lastName,
		employeeData.salary, employeeData.sector);
}

int showSingleEmployee(sEmployee employeeData)
{
	if(employeeData.isEmpty != EMPTY)
	{
		printMessage(employeeData);
	}

	return 0;
}

int showEmployee(sEmployee* employeeArray, int tam)
{
	int i;

	if (existEmployee() != 0)
	{
		for (i = 0; i < tam; i++)
		{
			sortEmployee(employeeArray, tam);
			showSingleEmployee(employeeArray[i]);
		}
	}
	return 0;
}
