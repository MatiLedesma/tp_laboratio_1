#include <stdio.h>
#include <stdlib.h>

#ifndef OPERACIONES_H_
#define OPERACIONES_H_
/**
 * AddOperation hace la suma entre el numeroUno y el numeroDos
 *
 * @param float numeroUno
 * @param float numeroDos
 * @return float resultado
 */
float AddOperation(float,float);
/**
 * MultiplyOperation hace la multiplicacion entre el numeroUno y el numeroDos
 *
 * @param float numeroUno
 * @param float numeroDos
 * @return float resultado
 */
float MultiplyOperation(float,float);
/**
 * SubstractOperation hace la resta entre el numeroUno y el numeroDos
 *
 * @param float numeroUno
 * @param float numeroDos
 * @return float resultado
 */
float SubstractOperation(float,float);
/**
 * DivideOperation hace la divicion entre el numeroUno y el numeroDos
 *
 * @param float numeroUno
 * @param float numeroDos
 * @return float resultado
 */
float DivideOperation(float,float);
/**
 * FactorialOperation hace el Factorial del numeroUno
 *
 * @param float numeroUno
 * @return float resultado
 */
float FactorialOperation(float);

#endif /* OPERACIONES_H_ */
