/*
 ============================================================================
 Name        : tp1.c
 Author      : Ledesma Matias

Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:

1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular todas las operaciones
a) Calcular la suma (A+B)
b) Calcular la resta (A-B)
c) Calcular la division (A/B)
d) Calcular la multiplicacion (A*B)
e) Calcular el factorial (A!)
4. Informar resultados
a) “El resultado de A+B es: r”
b) “El resultado de A-B es: r”
c) “El resultado de A/B es: r” o “No es posible dividir por cero”
d) “El resultado de A*B es: r”
e) “El factorial de A es: r1 y El factorial de B es: r2”
5. Salir

• Todas las funciones matemáticas del menú se deberán realizar en una biblioteca aparte,
que contenga las funciones para realizar las cinco operaciones.

• En el menú deberán aparecer los valores actuales cargados en los operandos A y B
(donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)

• Deberán contemplarse los casos de error (división por cero, etc)

• Documentar todas las funciones
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "Operaciones.h"

int main(void)
{
	int opcion;
	float firstNumber;
	float secondNumber;
	float sumResult;
	float substractResult;
	float multiplyResult;
	float divisionResult;
	float factorialOneResult;
	float factorialTwoResult;
	int firstNumberFlag;
	int secondNumberFlag;
	int controller;

	firstNumberFlag=1;
	secondNumberFlag=1;
	controller=0;

	setbuf(stdout, NULL);
	do
	{
		if(firstNumberFlag==1)
		{
		  printf("\n1. Ingresar primer operando (A=x)\n");
		}else
		{
			printf("\n1. Ingresar primer operando (A=%.2f)\n", firstNumber);
		}

		if(secondNumberFlag==1)
		{
			printf("2. Ingresar segundo operando (B=y)\n");
		}else
		{
			printf("2. Ingresar segundo operando (B=%.2f)\n", secondNumber);
		}
		printf("3. Calcular todas las operaciones \n");
		printf("4. Informar resultados\n");
		printf("5. Salir\n");
		printf("> : ");
		scanf("%d", &opcion);
		switch(opcion)
		{
			case 1:
				printf("Ingrese el primer operando: ");
				scanf("%f",&firstNumber);
				firstNumberFlag=0;
				break;
			case 2:
				if(firstNumberFlag==1)
				{
					printf("Debe ingresar el primer operando para continuar...\n");
				}else
				{
					printf("Ingrese el segundo operando: ");
					scanf("%f",&secondNumber);
					secondNumberFlag=0;
				}
				break;
			case 3:

				if(firstNumberFlag==1 || secondNumberFlag==1)
				{
					printf("No hay operandos ingresados...\n");
				}else
				{
					sumResult = AddOperation(firstNumber, secondNumber);
					substractResult = SubstractOperation(firstNumber, secondNumber);
					multiplyResult = SubstractOperation(firstNumber, secondNumber);
					if(secondNumber != 0)
					{
						divisionResult = DivideOperation(firstNumber, secondNumber);
					}
					factorialOneResult = FactorialOperation(firstNumber);
					factorialTwoResult = FactorialOperation(secondNumber);
					controller++;
				}
				break;
			case 4:
				if(controller==0)
				{
					printf("Primero debe calcular las operaciones...\n");
				}else
				{
					printf("El resultado de A+B es: %.2f\n",sumResult);
					printf("El resultado de A-B es: %.2f\n",substractResult);
					printf("El resultado de A*B es: %.2f\n",multiplyResult);
					if(secondNumber!=0)
					{
						printf("El resultado de A/B es: %.2f\n",divisionResult);
					}else
					{
						printf("No es posible dividir por cero\n");
					}

					printf("El factorial de A es: %.0f y El factorial de B es: %.0f\n", factorialOneResult, factorialTwoResult);

					firstNumberFlag=1;
					secondNumberFlag=1;
				}
				break;
			case 5:
				break;
			default:
				printf("Esa no es una opcion...");
				break;
		}

	}while(opcion!=5);

	return EXIT_SUCCESS;
}
