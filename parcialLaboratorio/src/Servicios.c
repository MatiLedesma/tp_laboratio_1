#include "Servicios.h"

void HardcodearServicios(sServicios serviciosArray[], int tam)
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

int DetectarServicios(sServicios serviciosArray[], int tam)
{
	int i;
	int status;
	status = 0;
	for (i = 0; i < tam; i++)
	{
		if (serviciosArray[i].isEmpty != VACIO)
		{
			status = 1;
		}
	}

	return status;
}

void ObtenerServicios(sServicios serviciosArray[], int tam)
{
	int i;
	for (i = 0; i < tam; i++)
	{
		MostrarServicio(serviciosArray[i]);
	}
}

int MostrarServicios(sServicios serviciosArray[], int tam)
{
	int status;
	status = DetectarServicios(serviciosArray, tam);
	if (status != 0)
	{
		ObtenerServicios(serviciosArray, tam);
	}
	else
	{
		printf("No hay servicios cargados...\n");
	}

	return status;
}

/////////// PRECIOS

int CorroborarFkConPk(sTrabajo trabajos, sServicios servicios, int precio)
{
	if (trabajos.idServicio == servicios.id)
	{
		precio += servicios.precio;
	}

	return precio;
}

int ObtenerPrecios(sTrabajo trabajosArray[], sServicios serviciosArray[], int serviciosTam, int trabajosTam)
{
	int precio;
	int i;
	int j;
	precio = 0;
	for (i = 0; i < trabajosTam; i++)
	{
		for (j = 0; j < serviciosTam; j++)
		{
			precio = CorroborarFkConPk(trabajosArray[i], serviciosArray[j], precio);
		}
	}
	return precio;
}

int MostrarPrecioTotal(sTrabajo trabajosArray[], sServicios serviciosArray[], int serviciosTam, int trabajosTam)
{
	int precioTotal;
	precioTotal = ObtenerPrecios(trabajosArray, serviciosArray, serviciosTam, trabajosTam);
	return precioTotal;
}


//////// VALIDAR ID correcta

int IdMinima(int id, int i)
{
	int idMin;

	if (i == 0)
	{
		idMin = id;
	}
	return idMin;
}

int ValidarIdCorrecta(sServicios serviciosArray[], int serviciosTam)
{
	int idServicio;
	int idMax;
	int idMin;
	int i;

	idServicio = GetInt("> : ");
	for (i = 0; i < serviciosTam; i++)
	{
		idMin = IdMinima(serviciosArray[i].id, i);
		idMax = serviciosArray[i].id;
	}
	while(idServicio < idMin || idServicio > idMax)
	{
		idServicio = GetInt("Ingrese una id correcta: ");
	}

	return idServicio;
}
