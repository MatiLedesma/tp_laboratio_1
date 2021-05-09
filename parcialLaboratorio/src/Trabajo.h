#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Servicios.h"
#include "Inputs.h"
#include "sTrabajo.h"

#define VACIO 0
#define OCUPADO 1

#ifndef TRABAJO_H_
#define TRABAJO_H_

/**
 * InicializarTrabajo, inicializa el isEmpty en 0 para saber si estan o no estan ocupados
 * @param sTrabajo obtiene los datos de la estructura sTrabajo
 * @param int el tamaño del array
 * */
void InicializarTrabajo(sTrabajo[], int);
/**
 * BuscarLibre, busca un espacio libre para poder ingresar datos o no dependiendo si existe el espacio o no
 * @param sTrabajo obtiene los datos de la estructura sTrabajo
 * @param int el tamaño del array
 * */
int BuscarLibre(sTrabajo[], int);
/**
 * ValidarFecha, valida que la fecha ingresada exista
 * @param sFecha obtiene los datos de la estructura fecha
 * */
sFecha ValidarFecha(sFecha);
/**
 * ValidarDiaMes, verifica que el dia y/o el mes esten bien ingresados
 * @param int mes ingresado
 * @param int dia ingresado
 * */
int ValidarDiaMes(int, int);
/**
 * ValidarAnio, valida que el año ingresado sea correcto
 * @param int, toma el año ingresado
 * */
int ValidarAnio(int);
/**
 * VerificarValidez, se encarga de pedirle al usuario que ingrese el mes y/o la fecha correcta
 * @param int el status de la validez, -1 y 0 son error 1 para valido
 * @param sFecha obtiene la estructura de fecha y la devuelve
 * */
sFecha VerificarValidez(int, sFecha);
/**
 * CargarTrabajo, retorna un trabajo
 * @param sServicios[] obtiene la estructura de servicios
 * @param sTrabajo[] obtiene la estructura de trabajo
 * @param int es el tamaño de la estructura de servicios
 * @param int es el tamaño de la estructura de trabajos
 * */
sTrabajo CargarTrabajo(sServicios [], sTrabajo [], int, int);
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
 * BuscarTrabajo, busca un producto por la id del mismo y devuelve el index, en caso de no encontrarlo devuelve -1
 * @param sTrabajo[], array de la estructura trabajos
 * @param int, el tamaño de la estructura trabajos
 * */
int BuscarTrabajo(sTrabajo[], int);
/**
 * OrdenarTrabajos ordena los trabajos por el bubble sort
 * @param sTrabajo[] obtiene el array de los trabajos
 * @param int, obtiene el tamaño del array
 * */
int OrdenarTrabajos(sTrabajo[], int);
/**
 * OrdenPorAnio, ordena el array filtrando por año
 * @param sTrabajo[] obtiene el array de los trabajos
 * @param int, obtiene el contador i del for
 * @param int, obtiene el contador j del for
 * */
int OrdenPorAnio(sTrabajo[], int, int);
/**
 * CasoIgualdad, contempla si existe una igualdad y ordena por el nombre de la mascota
 * @param sTrabajo[] obtiene el array de los trabajos
 * @param int, obtiene el contador i del for
 * @param int, obtiene el contador j del for
 * */
int CasoIgualdad(sTrabajo[], int, int);
/**
 * MostrarUnTrabajo, muestra un trabajo cargado
 * @param sTrabajo[], obtiene los datos del array de la estructura trabajo
 * @param sServicios[], obtiene los datos del array de la estructura servicios
 * @param int posicion en el array de la estructura de trabajos para comparar fk con pk
 * @param int tamaño del array de trabajos
 * @param int tamaño del array de servicios
 * */
void MostrarUnTrabajo(sTrabajo[], sServicios[], int, int, int);
/**
 * DetectarTrabajo, detecta si existen trabajos cargados o no, retorna un status en 1 o 0 dependiendo el caso
 * @param sTrabajo[] array de la estructura de trabajo
 * @param int tamaño del array
 * */
int DetectarTrabajo(sTrabajo [], int);
/**
 * ObtenerTrabajos, obtiene los trabajos y contempla que no esten vacios
 * @param sTrabajo[], obtiene el array de los trabajos
 * @param sServicios[], obtiene el array de los servicios
 * @param int, el tamaño del array de los trabajos
 * @param int, el tamaño del array de los servicios
 * */
void ObtenerTrabajos(sTrabajo [],sServicios [], int, int);
/**
 * MostrarTrabajos, muestra todos los trabajos ingresados en el array
 * @param sTrabajo[], obtiene el array de los trabajos
 * @param sServicios[], obtiene el array de los servicios
 * @param int, el tamaño del array de los trabajos
 * @param int, el tamaño del array de los servicios
 * */
int MostrarTrabajos(sTrabajo [],sServicios [], int , int );
/**
 * OpcionBajaTrabajo, controla la eliminacion del trabajo
 * @sTrabajo, obtiene la estructura de trabajo
 * */
sTrabajo OpcionBajaTrabajo(sTrabajo);
/**
 * DarDeBaja, busca el producto para ser eliminado
 * @param sTrabajo[], obtiene la estructura de trabajo
 * @param int, el tamaño del array
 * */
int DarDeBaja(sTrabajo[], int);
/**
 * BajaTrabajo, inicia la baja del trabajo si existe algun dato ingresado, de lo contrario da error
 * @param sTrabajos[] array de los trabajos
 * @param sServicios[] array de los servicios
 * @param int, el tamaño del array de los servicios
 * @param int, el tamaño del array de los trabajos
 * */
int BajaTrabajo(sTrabajo [], sServicios [], int , int );
/**
 * OpcionModificarTrabajo, hace la modificacion del trabajo
 * @param sTrabajo obtiene la estructura de trabajo
 * @param sServicios[] array de los servicios
 * @param int tamaño de los servicios
 * */
sTrabajo OpcionModificarTrabajo(sTrabajo, sServicios[], int);
/**
 * HacerModificacion, inicia la modificacion del trabajo
 * @param sTrabajo[] array de los trabajos
 * @param int tamaño del array de los trabajos
 * @param sServicios[] array de los servicios
 * @param int tamaño del array de los servicios
 * */
int HacerModificacion(sTrabajo[], int, sServicios[], int);
/**
 * ModificarTrabajo, verifica si existen datos ingresados
 * @param sTrabajo[] array de los trabajos
 * @param sServicios[] array de los servicios
 * @param int tamaño de los servicios
 * @param int tamaño de los trabajos
 * */
int ModificarTrabajo(sTrabajo[], sServicios[], int, int);

#endif /* TRABAJO_H_ */
