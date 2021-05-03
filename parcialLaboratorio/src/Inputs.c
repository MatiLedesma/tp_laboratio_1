#include "Inputs.h"

int GetInt(char *mensaje)
{
	int valor;

	printf(mensaje);
	scanf("%d", &valor);
	return valor;
}

float GetFloat(char *mensaje)
{
	float valor;

	printf(mensaje);
	scanf("%f", &valor);
	return valor;
}

char GetChar(char *mensaje)
{
	char valor;

	printf(mensaje);
	fflush(stdin);
	scanf("%c", &valor);
	return valor;
}

void GetString(char *mensaje, char *valor)
{
	printf(mensaje);
	fflush(stdin);
	scanf("%[^\n]", valor);
}
