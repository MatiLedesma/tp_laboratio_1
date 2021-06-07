#include "Inputs.h"

int GetInt(int* numero, char* mensaje)
{
	int status;
	status = 0;
	if (numero != NULL)
	{
		printf(mensaje);
		scanf("%d", numero);
		status = 1;
	}
	return status;
}

int GetFloat(float* numero, char* mensaje)
{
	int status;
	status = 0;
	if (numero != NULL)
	{
		printf(mensaje);
		scanf("%f", numero);
		status = 1;
	}
	return status;
}

int GetChar(char* caracter, char* mensaje)
{
	int status;
	status = 0;
	if (caracter != NULL)
	{
		printf(mensaje);
		fflush(stdin);
		scanf("%c", caracter);
		status = 1;
	}
	return status;
}

void GetString(char* caracter, char* mensaje)
{
	printf(mensaje);
	fflush(stdin);
	scanf("%[^\n]", caracter);
}
