/*============================================================================
 Name        : parcialLaboratorio.c
 Author      : Ledesma Matias 1�c
 Version     :
 Description :
 ENTIDADES:
	Servicio:
		� id (comienza en 20000)
		� descripci�n (m�ximo 25 caracteres)
		� precio
		Trabajo:
		� id (autoincremental)
		� nombreMascota (cadena)
		� idServicio (debe existir) Validar
		� fecha (Validar d�a, mes y a�o)
		DATOS PREVIOS:
		El array de servicios ser� hardcodeado.
		Servicios (Corte: $250, Desparasitado: $300, Castrado: $400)
		MENU DE OPCIONES:
		A. ALTA TRABAJO
		B. MODIFICAR TRABAJO: Se ingresar� el id, permitiendo en un submen� modificar:
		� El nombre de la mascota
		� El servicio
		C. BAJA TRABAJO: Se ingresar� el id del trabajo y se realizar� una baja l�gica.
		D. LISTAR TRABAJOS: Hacer un �nico listado de todos los trabajos ordenados por a�o y ante igualdad
		de a�o por nombre de mascota.
		E. LISTAR SERVICIOS
		F. TOTAL en pesos por los servicios prestados.

		NOTAS:
		I. Se deber� desarrollar bibliotecas por cada entidad, las cuales contendr�n las
		funciones Alta, Baja, Modificar y Listar.
		II. Las validaciones (input), deber�n estar en una biblioteca aparte.
		III. Tener en cuenta que no se podr� ingresar a los casos Modificar, Baja, y
		listados sin antes haber realizado al menos un Alta (utilizar banderas y/o
		contadores).
		IV. El c�digo deber� tener comentarios con la documentaci�n de cada una de
		las funciones y respetar las reglas de estilo de la c�tedra.
============================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "Servicios.h"
#include "Trabajo.h"
#include "Inputs.h"

#define S 3
#define X 10

int main(void)
{
	sServicios serviciosArray[S];
	sTrabajo trabajosArray[12];

	HardcodearServicios(serviciosArray, S);
	InicializarTrabajo(trabajosArray, X);
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
		opc = toupper(opc);
		switch (opc)
		{
		case 'A':
			AltaTrabajo(trabajosArray, serviciosArray, S, X);
			break;
		case 'B':
			ModificarTrabajo(trabajosArray, serviciosArray, S, X);
			break;
		case 'C':
			BajaTrabajo(trabajosArray, serviciosArray, S, X);
			break;
		case 'D':
			MostrarTrabajos(trabajosArray, serviciosArray, X, S);
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
	} while (opc != 'G');
	return EXIT_SUCCESS;
}
