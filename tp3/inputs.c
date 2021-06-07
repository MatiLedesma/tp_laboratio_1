#include "inputs.h"

int getString(char *message, char *value)
{
	int status;
	status = 0;
	printf("%s", message);
	scanf("%s", value);

	return status;
}

int getString_number(char *message, char *errorMessage, char *value)
{
	int status;
	int i;
	int length;
	status = 0;
	printf("%s", message);
	scanf("%s", value);

	length = strlen(value);

	for (i = 0; i < length; i++)
	{
		while(!isdigit(value[i]))
		{
			printf("%s", errorMessage);
			scanf("%s", value);
		}
	}

	while(atoi(value) < 0)
	{
		printf("%s", errorMessage);
		scanf("%s", value);
	}

	return status;
}
