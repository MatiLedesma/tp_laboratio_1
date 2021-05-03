#include "Servicios.h"

void HarcodearServicios(sServicios serviciosArray[], int tam)
{
	int i;
	int id[] = {20000, 20001, 20002};
	char descripcion[][25] = {"Corte", "Desparasitado", "Castrado"};
	float precio[] = {250, 300, 400};

	for (i = 0; i < tam; i++)
	{
		serviciosArray[i].id = id[i];
		strcpy(serviciosArray[i].descripcion, descripcion[i]);
		serviciosArray[i].precio = precio[i];
		serviciosArray[i].isEmpty = OCUPADO;
	}
}

int MostrarServicio(sServicios servicios)
{
	int status;
	status = 0;
	if (servicios.isEmpty != VACIO)
	{
		printf("%20d %25s %20.1f\n", servicios.id, servicios.descripcion, servicios.precio);
		status = 1;
	}

	return status;
}

int MostrarServicios(sServicios serviciosArray[], int tam)
{
	int i;
	int status;

	for (i = 0; i < tam; i++)
	{
		status = MostrarServicio(serviciosArray[i]);
	}

	return status;
}
