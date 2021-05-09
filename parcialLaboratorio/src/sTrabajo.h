#include "sFecha.h"

#ifndef STRABAJO_H_
#define STRABAJO_H_

typedef struct
{
	int id;
	char nombreMascota[50];
	int idServicio;
	sFecha fecha;
	int isEmpty;
} sTrabajo;

#endif /* STRABAJO_H_ */
