#include <stdio.h>
#include <stdlib.h>

#ifndef INPUTS_H_
#define INPUTS_H_

/**
 * GetInt devuelve el numero entero ingresado por el usuario
 * @param char*, obtiene el mensaje que se desea mostrar al usuario
 * */
int GetInt(char *);
/**
 * GetFloat devuelve el numero flotante ingresado por el usuario
 * @param char*, obtiene el mensaje que se desea mostrar al usuario
 * */
float GetFloat(char *);
/**
 * GetChar devuelve el caracter ingresado por el usuario
 * @param char*, obtiene el mensaje que se desea mostrar al usuario
 * */
char GetChar(char *);
/**
 * GetString guarda la cadena ingresada por el usuario
 * @param char*, obtiene el mensaje que se desea mostrar al usuario
 * @param char*, obtiene el string en el cual se va a guardar el dato ingressado por el usuario
 * */
void GetString(char *, char *);

#endif /* INPUTS_H_ */
