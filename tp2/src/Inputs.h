#include <stdio.h>
#include <stdlib.h>

#ifndef INPUTS_H_
#define INPUTS_H_

/**
 * GetInt, le pide al usuario ingresar un entero y retorna el mismo
 * @param int el numero que ingresa el usuario
 * @param char* el mensaje que se le mostrará al usuario
 * */
int GetInt(int*, char*);
/**
 * GetFloat, le pide al usuario ingresar un entero y retorna el mismo
 * @param float el numero que ingresa el usuario
 * @param char* el mensaje que se le mostrará al usuario
 * */
int GetFloat(float*, char*);
/**
 * GetChar, le pide al usuario ingresar un entero y retorna el mismo
 * @param char el caracter que ingresa el usuario
 * @param char* el mensaje que se le mostrará al usuario
 * */
int GetChar(char*, char*);
/**
 * GetString, le pide al usuario ingresar un entero y retorna el mismo
 * @param char* la cadena que ingresa el usuario
 * @param char* el mensaje que se le mostrará al usuario
 * */
void GetString(char*, char*);


#endif /* INPUTS_H_ */
