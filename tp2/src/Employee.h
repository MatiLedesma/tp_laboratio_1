#include <ctype.h>
#include <string.h>
#include "sEmployee.h"
#include "Inputs.h"

#define EMPTY 0
#define OCUPED 1

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

/**
 * initEmployee, inicializa el array de los empleados poniendo el isEmpty en VACIO (0) para validar los ingresos
 * @param sEmployee, obtiene el array de la estructura de empleados
 * @param int el tamaño del array
 * */
int initEmployee(sEmployee*, int);
/**
 * searchFree, busca si existe espacio disponible en el vector para poder ingresar empleados
 * @param sEmployee, obtiene el array de la estructura de empleados
 * @param int el tamaño del array
 * */
int searchFree(sEmployee*, int);
/**
 * limitSector, limita al usuario a ingresar sectores entre 0 y 10
 * @int el sector ingresado por el usuario
 * */
int limitSector(int*, char*);
/**
 * createEmployee, crea el alta del empleado
 * @param sEmployee, obtiene el array de la estructura de empleados
 * @param int el tamaño del array
 * @param char el mensaje que se le muestra al usuario
 * */
sEmployee createEmployee(sEmployee*, int);
/**
 * addEmployee, añade 1 empleado al array de empleados
 * @param sEmployee, obtiene el array de la estructura de empleados
 * @param int el tamaño del array
 * */
int addEmployee(sEmployee*, int);
/**
 * existProduct, verifica si hay empleados cargados
 * */
int existEmployee();
/**
 * findEmployeeById, busca a un empleado por el id
 * @param sEmployee obtiene el array de la estructura de empleados
 * @param int el tamaño del array
 * */
int findEmployeeById(sEmployee*, int);
/**
 * optionModify, verifica la opcion escogida por el usuario y modifica al empleado
 * @sEmployee obtiene al empleado seleccionado por el usuario
 * */
int optionModify(sEmployee*);
/**
 * modifyEmployee, permite modificar al empleado seleccionado
 * @param sEmployee obtiene el array de la estructura de empleados
 * @param int el tamaño del array
 * */
int modifyEmployee(sEmployee*, int);
/**
 * removeEmployee, elimina a un empleado del array de empleados
 * @param sEmployee obtiene el array de la estructura de empleados
 * @param int el tamaño del array
 * */
int removeEmployee(sEmployee*, int);
/**
 * optionRemove, verifica la opcion escogida por el usuario y elimina o no el empleado
 * @sEmployee obtiene al empleado seleccionado por el usuario
 * */
int optionRemove(sEmployee*);
/**
 * sortLastName, ordena los empleados por el apellido
 * @param sEmployee obtiene el array de los empleados
 * @param int obtiene el valor i de la iteracion
 * @param int obtiene el valor j de la iteracion
 * */
int sortLastName(sEmployee*, int, int);
/**
 * sortLastName, ordena los empleados por el sector
 * @param sEmployee obtiene el array de los empleados
 * @param int obtiene el valor i de la iteracion
 * @param int obtiene el valor j de la iteracion
 * */
int sortSector(sEmployee*, int, int);
/**
 * calculateTotalSalary, calcula el salario total
 * @param sEmployee obtiene el array de lo empleados
 * @param int obtiene el tramaño del array
 * */
int calculateTotalSalary(sEmployee*, int);
/**
 * calculateAverage, calcula el promedio de los precios
 * @param sEmployee obtiene el array de lo empleados
 * @param int obtiene el tramaño del array
 * */
float calculateAverage(sEmployee*, int);
/**
 * averageSalary, muestra el salario total, el promedio y cuantos empleados estan sobre el promedio
 * @param sEmployee obtiene el array de lo empleados
 * @param int obtiene el tramaño del array
 * */
int averageSalary(sEmployee*, int);
/**
 * sortEmployee, ordena a los empleados del array
 * @param sEmployee obtiene el array de los empleados
 * @param int obtiene el tamaño del array
 * */
int sortEmployee(sEmployee*, int);
/**
 * showSingleEmployee, muestra a un unico empleado guardado en el array
 * @param sEmployee, obtiene el empleado del array de empleados
 * */
int showSingleEmployee(sEmployee);
/**
 * showEmployee, muestra los empleados guardados en el array
 * @param sEmployee, obtiene el array de la estructura de empleados
 * @param int el tamaño del array
 * */
int showEmployee(sEmployee*, int);
/**
 * printMessage, imprime el mensaje con los datos del empleado
 * @sEmployee obtiene los datos del empleado
 * */
void printMessage(sEmployee);

#endif /* EMPLOYEE_H_ */
