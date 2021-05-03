#include <stdio.h>
#include <stdlib.h>
#include "Servicios.h"
#include "Inputs.h"

#define VACIO 0
#define OCUPADO 1

#ifndef TRABAJO_H_
#define TRABAJO_H_

typedef struct
{
	int dia;
	int mes;
	int anio;
} sFecha;

typedef struct
{
	int id;
	char nombreMascota[50];
	int idServicio;
	sFecha fecha;
	int isEmpty;
} sTrabajo;


/**
 * InicializarProducto, inicializa el isEmpty en 0 para saber si estan o no estan ocupados
 * @param sTrabajo obtiene los datos de la estructura sTrabajo
 * @param int el tamaño del array
 * */
void InicializarProducto(sTrabajo[], int);
/**
 * BuscarLibre, busca un espacio libre para poder ingresar datos o no dependiendo si existe el espacio o no
 * @param sTrabajo obtiene los datos de la estructura sTrabajo
 * @param int el tamaño del array
 * */
int BuscarLibre(sTrabajo[], int);
/**
 *
 * */
sTrabajo CargarTrabajo(sServicios [], sTrabajo [], int, int);
/**
 * AsignarId, recorre el array hasta encontrar un EMPTY, cuando lo encuentra devuelve el index
 * @param sTrabajo, obtiene los datos de la estructura trabajos
 * @param int el tamaño del array
 * */
int AsignarId(sTrabajo [], int);
/**
 * AltaTrabajo, da el alta a un trabajo
 * @param sTrabajo[], un array de la estructura de trabajo
 * @param sServicios[], un array de la estructura de servicios
 * @param int tamaño de la estructura servicios
 * @param int tamaño de la estructura trabajos
 * */
int AltaTrabajo(sTrabajo [], sServicios [], int , int );
/**
 * ImprimirMensaje, permite imprimir el mensaje con los datos ingresados en la tabla
 * @param sTrabajo, obtiene los datos de la estructura trabajos
 * @param sServicios, obtiene los datos de la estructura servicios
 * */
void ImprimirMensaje(sTrabajo, sServicios);
/**
 * ObtenerDescripcionDeServicio, obtiene la descripcion comparando la fk de trabajos con la pk de servicios
 * @param sTrabajo[], obtiene los datos del array de la estructura trabajo
 * @param sServicios[], obtiene los datos del array de la estructura servicios
 * @param int, es el index con los datos de la estructura de trabajo
 * @param int, es el tamaño de la estructura de servicios
 * */
int ObtenerDescripcionDeServicio(sTrabajo[], sServicios[], int, int);
/**
 * BuscarProducto, busca un producto por la id del mismo y devuelve el index, en caso de no encontrarlo devuelve -1
 * @param sTrabajo[], array de la estructura trabajos
 * @param int, el tamaño de la estructura trabajos
 * */
int BuscarProducto(sTrabajo[], int);
void MostrarUnProducto(sTrabajo[], sServicios[], int, int, int);
int MostrarProductos(sTrabajo [],sServicios [], int , int );
int BajaTrabajo(sTrabajo [], sServicios [], int , int );

#endif /* TRABAJO_H_ */
