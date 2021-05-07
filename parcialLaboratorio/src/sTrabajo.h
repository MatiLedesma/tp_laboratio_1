#ifndef STRABAJO_H_
#define STRABAJO_H_

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

#endif /* STRABAJO_H_ */
