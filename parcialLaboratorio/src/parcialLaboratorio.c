/*
 ============================================================================
 Name        : parcialLaboratorio.c
 Author      : Ledesma Matias 1°c
 Version     :
 Description :
 ENTIDADES:
	Servicio:
		• id (comienza en 20000)
		• descripción (máximo 25 caracteres)
		• precio
		Trabajo:
		• id (autoincremental)
		• nombreMascota (cadena)
		• idServicio (debe existir) Validar
		• fecha (Validar día, mes y año)
		DATOS PREVIOS:
		El array de servicios será hardcodeado.
		Servicios (Corte: $250, Desparasitado: $300, Castrado: $400)
		MENU DE OPCIONES:
		A. ALTA TRABAJO
		B. MODIFICAR TRABAJO: Se ingresará el id, permitiendo en un submenú modificar:
		• El nombre de la mascota
		• El servicio
		C. BAJA TRABAJO: Se ingresará el id del trabajo y se realizará una baja lógica.
		D. LISTAR TRABAJOS: Hacer un único listado de todos los trabajos ordenados por año y ante igualdad
		de año por nombre de mascota.
		E. LISTAR SERVICIOS
		F. TOTAL en pesos por los servicios prestados.

		NOTAS:
		I. Se deberá desarrollar bibliotecas por cada entidad, las cuales contendrán las
		funciones Alta, Baja, Modificar y Listar.
		II. Las validaciones (input), deberán estar en una biblioteca aparte.
		III. Tener en cuenta que no se podrá ingresar a los casos Modificar, Baja, y
		listados sin antes haber realizado al menos un Alta (utilizar banderas y/o
		contadores).
		IV. El código deberá tener comentarios con la documentación de cada una de
		las funciones y respetar las reglas de estilo de la cátedra.
============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "Servicios.h"
#include "Trabajo.h"
#include "Inputs.h"

#define S 3
#define X 10
#define FECHA 3
int main(void)
{
	sServicios serviciosArray[S];
	sTrabajo trabajosArray[12];

	HarcodearServicios(serviciosArray, S);
	InicializarProducto(trabajosArray, X);
	char opc;
	do
	{
		printf("A. ALTA TRABAJO\n");
		printf("B. MODIFICAR TRABAJO:\n");
		printf("C. BAJA TRABAJO\n");
		printf("D. LISTAR TRABAJOS\n");
		printf("E. LISTAR SERVICIOS\n");
		printf("F. TOTAL\n");
		printf("G. SALIR\n");
		opc = GetChar("> : ");

		switch(opc)
		{
		case 'A':
			AltaTrabajo(trabajosArray, serviciosArray, S, FECHA, X);
			break;
		case 'B':
			ModificarProducto(trabajosArray, serviciosArray, S, X);
			break;
		case 'C':
			BajaTrabajo(trabajosArray, serviciosArray, S, X);
			break;
		case 'D':
			MostrarProductos(trabajosArray, serviciosArray, X, S);
			break;
		case 'E':
			MostrarServicios(serviciosArray, S);
			break;
		case 'F':

			break;
		case 'G':

			break;
		default:
			printf("Esa no es una opcion\n");
			break;
		}
	} while(opc != 'G');
	return EXIT_SUCCESS;
}
