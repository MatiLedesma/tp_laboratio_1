#include <stdio.h>
#include <string.h>
#include "sServicios.h"
#include "sTrabajo.h"
#include "Inputs.h"

#define VACIO 0
#define OCUPADO 1

#ifndef SERVICIOS_H_
#define SERVICIOS_H_

/**
 * HardcodearServicios permite guardar datos hardcodeados en la estructura de servicios
 * @param sServicios permite guardar datos en la estructura de servicios
 * @param int es el tamaño del array
 * */
void HardcodearServicios(sServicios[], int);
int DetectarServicios(sServicios[], int);
void ObtenerServicios(sServicios[], int);
/**
 * MostrarServicio permite mostrar un dato de la estructura servicios
 * @param sServicio obtiene los datos de la estructura
 * @param int es el tamaño del array
 * */
int MostrarServicio(sServicios);
/**
 * MostrarServicios permite mostrar los datos de la estructura servicios
 * @param sServicios obtiene los datos de la estructura
 * @param int es el tamaño del array
 * */
int MostrarServicios(sServicios [], int);

int CorroborarFkConPk(sTrabajo, sServicios, int);
int ObtenerPrecios(sTrabajo[], sServicios[], int, int);
int MostrarPrecioTotal(sTrabajo[], sServicios[], int, int);

int IdMinima(int, int);
int ValidarIdCorrecta(sServicios[], int);

#endif /* SERVICIOS_H_ */
