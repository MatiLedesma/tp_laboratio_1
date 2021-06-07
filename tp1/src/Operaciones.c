#include "Operaciones.h"

float AddOperation(float numeroUno , float numeroDos)
{
	float resultado;
	resultado = numeroUno + numeroDos;
	return resultado;
}
float MultiplyOperation(float numeroUno , float numeroDos)
{
	float resultado;
	resultado = numeroUno * numeroDos;
	return resultado;
}

float SubstractOperation(float numeroUno , float numeroDos)
{
	float resultado;
	resultado = numeroUno - numeroDos;
	return resultado;
}

float DivideOperation(float numeroUno , float numeroDos)
{
	float resultado;
	resultado = numeroUno / numeroDos;
	return resultado;
}

float FactorialOperation(float numeroUno)
{
	int i;
	float factorial;
	factorial=1;
	for(i = 1; i <= numeroUno; i++)
	{
	  factorial=factorial*i;
	}
	return factorial;
}
