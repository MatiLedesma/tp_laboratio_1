#include "Trabajo.h"

void InicializarProducto(sTrabajo trabajosArray[], int tam)
{
	int i;
	for (i = 0; i < tam; i++)
	{
		trabajosArray[i].isEmpty = VACIO;
	}
}

int BuscarLibre(sTrabajo trabajosArray[], int tam)
{
	int i;
	int index;
	index = -1;
	for (i = 0; i < tam; i++)
	{
		if (trabajosArray[i].isEmpty == VACIO)
		{
			index = i;
			break;
		}
	}
	return index;
}

int AsignarId(sTrabajo trabajoArray[], int trabajoTam)
{
	int i;
	int id;
	id = 0;
	for (i = 0; i < trabajoTam; i++)
	{
		if (trabajoArray[i].isEmpty == VACIO)
		{
			id = i;
			break;
		}
	}
	printf("id: %d\n", i);
	return id;
}

sTrabajo CargarTrabajo(sServicios serviciosArray[], sTrabajo trabajoArray[], int serviciosTam, int trabajoTam)
{
	sTrabajo trabajo;

	trabajo.id = AsignarId(trabajoArray, trabajoTam);
	GetString("Ingrese el nombre de la mascota: ", trabajo.nombreMascota);
	printf("Ingrese el servicio para la mascota: \n");
	MostrarServicios(serviciosArray, serviciosTam);
	trabajo.idServicio = GetInt("> : ");
	trabajo.fecha.dia = GetInt("Ingrese el dia: ");
	trabajo.fecha.mes = GetInt("Ingrese el mes: ");
	trabajo.fecha.anio = GetInt("Ingrese el año: ");

	return trabajo;
}

int AltaTrabajo(sTrabajo trabajosArray[], sServicios serviciosArray[], int serviciosTam, int trabajoTam)
{
	int index;

	index = BuscarLibre(trabajosArray, trabajoTam);

	if (index == -1)
	{
		printf("No hay espacio disponible para insertar un producto...\n");
	}
	else
	{
		trabajosArray[index] = CargarTrabajo(serviciosArray, trabajosArray, serviciosTam, trabajoTam);
	}

	return 0;
}

/////////////// BAJA

void ImprimirMensaje(sTrabajo trabajos, sServicios servicios)
{
	printf("%5d %15s %d/%d/%d %20s %10.2f\n", trabajos.id, trabajos.nombreMascota,
			trabajos.fecha.dia, trabajos.fecha.mes, trabajos.fecha.anio,
			servicios.descripcion, servicios.precio);
}

int ObtenerDescripcionDeServicio(sTrabajo trabajosArray[], sServicios serviciosArray[], int index, int serviciosTam)
{
	int i;
	int id;
	for (i = 0; i < serviciosTam; i++)
	{
		if (trabajosArray[index].idServicio == serviciosArray[i].id)
		{
			id = i;
		}
	}

	return id;
}

void MostrarUnProducto(sTrabajo trabajosArray[], sServicios serviciosArray[], int index, int trabajosTam, int serviciosTam)
{
	int id;

	id = ObtenerDescripcionDeServicio(trabajosArray, serviciosArray, index, serviciosTam);
	ImprimirMensaje(trabajosArray[index], serviciosArray[id]);
}

int MostrarProductos(sTrabajo trabajosArray[],sServicios serviciosArray[], int trabajoTam, int servicioTam)
{
	int i;
	int status;
	status = 0;
	for (i = 0; i < trabajoTam; i++)
	{
		if (trabajosArray[i].isEmpty != VACIO)
		{
			MostrarUnProducto(trabajosArray, serviciosArray, i, trabajoTam, servicioTam);
			status = 1;
		}
	}

	return status;
}


int BuscarProducto(sTrabajo trabajosArray[], int tam)
{
	int i;
	int id;
	int find;
	find = -1;

	id = GetInt("Ingrese la id del producto: ");

	for (i = 0; i < tam; i++)
	{
		if (id == trabajosArray[i].id && trabajosArray[i].isEmpty != VACIO)
		{
			find = i;
			break;
		}
	}

	return find;
}

int BajaTrabajo(sTrabajo trabajosArray[], sServicios serviciosArray[], int serviciosTam, int trabajosTam)
{
	int id;
	char opc;
	MostrarProductos(trabajosArray, serviciosArray, trabajosTam, serviciosTam);
	id = BuscarProducto(trabajosArray, trabajosTam);

	if (id != -1)
	{
		opc = GetChar("Desea eliminar este producto? s/n: ");
		if (opc == 's')
		{
			trabajosArray[id].isEmpty = VACIO;
		}
		else
		{
			printf("Cancelado\n");
		}
	}
	else
	{
		printf("No se encontro la id\n");
	}

	return id;

}

int ModificarProducto(sTrabajo trabajosArray[], sServicios serviciosArray[], int serviciosTam, int trabajosTam)
{
	int id;
	int opc;
	MostrarProductos(trabajosArray, serviciosArray, trabajosTam, serviciosTam);
	id = BuscarProducto(trabajosArray, trabajosTam);

	if (id != -1)
	{
		opc = GetInt("Que desea modificar del producto? 1 (Nombre de la mascota) 2 (Servicio): ");
		if (opc == 1)
		{
			GetString("Ingrese el nuevo nombre: ", trabajosArray[id].nombreMascota);
		}
		else
		{
			printf("Ingrese el nuevo servicio para la mascota: \n");
			MostrarServicios(serviciosArray, serviciosTam);
		}
	}
	else
	{
		printf("No se encontro la id\n");
	}

	return id;
}

