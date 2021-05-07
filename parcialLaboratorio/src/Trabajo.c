#include "Trabajo.h"

void InicializarTrabajo(sTrabajo trabajosArray[], int tam)
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

int ValidarDia(int mes, int dia)
{
	int status;
	status = 0;
	switch(mes)
	{
	case 1:case 3:case 5:case 7:case 8:case 10:case 12:
		if (dia >= 1 && dia <= 31)
		{
			status = 1;
		}
		break;
	case 4:case 6:case 9:case 11:
		if (dia >= 1 && dia <= 30)
		{
			status = 1;
		}
		break;
	}
	return status;
}

sFecha VerificarValidez(int status, sFecha fecha)
{
	while(status != 1)
	{
		fecha.dia = GetInt("Ingrese un dia valido: ");
		status = ValidarDia(fecha.mes, fecha.dia);
	}
	if (status == 1)
	{
		printf("Fecha agendada!\n");
	}

	return fecha;
}

sFecha ValidarFecha(sFecha fecha)
{
	int status;
	fecha.dia = GetInt("Dia: ");
	fecha.mes = GetInt("Mes: ");
	fecha.anio = GetInt("A�o: ");
	status = ValidarDia(fecha.mes, fecha.dia);
	fecha = VerificarValidez(status, fecha);

	return fecha;
}

sTrabajo CargarTrabajo(sServicios serviciosArray[], sTrabajo trabajoArray[], int serviciosTam, int trabajoTam)
{
	sTrabajo trabajo;

	trabajo.id = AsignarId(trabajoArray, trabajoTam);
	GetString("Ingrese el nombre de la mascota: ", trabajo.nombreMascota);
	printf("Ingrese el servicio para la mascota: \n");
	MostrarServicios(serviciosArray, serviciosTam);
	trabajo.idServicio = GetInt("> : ");
	trabajo.fecha = ValidarFecha(trabajo.fecha);

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

void MostrarUnTrabajo(sTrabajo trabajosArray[], sServicios serviciosArray[], int index, int trabajosTam, int serviciosTam)
{
	int id;

	id = ObtenerDescripcionDeServicio(trabajosArray, serviciosArray, index, serviciosTam);
	ImprimirMensaje(trabajosArray[index], serviciosArray[id]);
}

int DetectarTrabajo(sTrabajo trabajosArray[], int trabajoTam)
{
	int i;
	int status;

	status = 0;
	for (i = 0; i < trabajoTam; i++)
	{
		if (trabajosArray[i].isEmpty != VACIO)
		{
			status = 1;
		}
	}

	return status;
}

void ObtenerTrabajos(sTrabajo trabajosArray[],sServicios serviciosArray[], int trabajoTam, int servicioTam)
{
	int i;
	for (i = 0; i < trabajoTam; i++)
	{
		if (trabajosArray[i].isEmpty != VACIO)
		{
			MostrarUnTrabajo(trabajosArray, serviciosArray, i, trabajoTam, servicioTam);
		}
	}
}

int MostrarTrabajos(sTrabajo trabajosArray[],sServicios serviciosArray[], int trabajoTam, int servicioTam)
{
	int status;
	status = DetectarTrabajo(trabajosArray, trabajoTam);

	if (status != 0)
	{
		ObtenerTrabajos(trabajosArray, serviciosArray, trabajoTam, servicioTam);
	}
	else
	{
		printf("No se cargaron datos aun...\n");
	}

	return status;
}


int BuscarTrabajo(sTrabajo trabajosArray[], int tam)
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

sTrabajo OpcionBajaTrabajo(sTrabajo trabajo)
{
	char opc;
	opc = GetChar("Desea eliminar este producto? s/n: ");
	if (opc == 's')
	{
		trabajo.isEmpty = VACIO;
	}
	else
	{
		printf("Cancelado\n");
	}

	return trabajo;
}

int BajaTrabajo(sTrabajo trabajosArray[], sServicios serviciosArray[], int serviciosTam, int trabajosTam)
{
	int id;
	MostrarTrabajos(trabajosArray, serviciosArray, trabajosTam, serviciosTam);
	id = BuscarTrabajo(trabajosArray, trabajosTam);

	if (id != -1)
	{
		trabajosArray[id] = OpcionBajaTrabajo(trabajosArray[id]);
	}
	else
	{
		printf("No se encontro la id\n");
	}

	return id;

}

sTrabajo OpcionModificarTrabajo(sTrabajo trabajo, sServicios serviciosArray[], int serviciosTam)
{
	int opc;
	opc = GetInt("Que desea modificar del producto? 1 (Nombre de la mascota) 2 (Servicio): ");
	if (opc == 1)
	{
		GetString("Ingrese el nuevo nombre: ", trabajo.nombreMascota);
	}
	else
	{
		printf("Ingrese el nuevo servicio para la mascota: \n");
		MostrarServicios(serviciosArray, serviciosTam);
		trabajo.idServicio = GetInt("> : ");
	}

	return trabajo;
}

int ModificarTrabajo(sTrabajo trabajosArray[], sServicios serviciosArray[], int serviciosTam, int trabajosTam)
{
	int id;
	MostrarTrabajos(trabajosArray, serviciosArray, trabajosTam, serviciosTam);
	id = BuscarTrabajo(trabajosArray, trabajosTam);

	if (id != -1)
	{
		trabajosArray[id] = OpcionModificarTrabajo(trabajosArray[id], serviciosArray, serviciosTam);
	}
	else
	{
		printf("No se encontro la id\n");
	}

	return id;
}

