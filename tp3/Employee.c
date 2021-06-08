#include "Employee.h"

Employee* employee_new()
{
	Employee* empleado;
	empleado = (Employee*)malloc(sizeof(Employee));
	return empleado;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* empleado;

	empleado = employee_new();

	employee_setId(empleado, atoi(idStr));
	employee_setNombre(empleado, nombreStr);
	employee_setHorasTrabajadas(empleado, atoi(horasTrabajadasStr));
	employee_setSueldo(empleado, atoi(idStr));

	return empleado;
}


int employee_setId(Employee* this,int id)
{
	int status;
	status= 0;
	if (this != NULL)
	{
		this->id = id;
		status = 1;
	}
	return status;
}
int employee_getId(Employee* this,int* id)
{
	int status;
	status = 0;
	if (this != NULL && id != NULL)
	{
		*id = this->id;
		status = 1;
	}
	return status;
}

int employee_setNombre(Employee* this,char* nombre)
{
	int status;
	status= 0;
	if (this != NULL)
	{
		strcpy(this->nombre, nombre);
		status = 1;
	}
	return status;
}
int employee_getNombre(Employee* this,char* nombre)
{
	int status;
	status = 0;
	if (this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
		status = 1;
	}
	return status;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int status;
	status= 0;
	if (this != NULL)
	{
		this->horasTrabajadas = horasTrabajadas;
		status = 1;
	}
	return status;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int status;
	status = 0;
	if (this != NULL && horasTrabajadas != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		status = 1;
	}
	return status;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int status;
	status= 0;
	if (this != NULL)
	{
		this->sueldo = sueldo;
		status = 1;
	}
	return status;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
	int status;
	status = 0;
	if (this != NULL && sueldo != NULL)
	{
		*sueldo = this->sueldo;
		status = 1;
	}
	return status;
}
