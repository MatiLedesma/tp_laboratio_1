/****************************************************
 * Ledesma Matias 1�C
****************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"
#include "inputs.h"
/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
     10. Salir
*****************************************************/

int main()
{
	setbuf(stdout, NULL);
    int option = 0;

    LinkedList *listaEmpleados = ll_newLinkedList();
    do
    {
        printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
        printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
        printf("3. Alta de empleado\n");
        printf("4. Modificar datos de empleado\n");
        printf("5. Baja de empleado\n");
        printf("6. Listar empleados\n");
        printf("7. Ordenar empleados\n");
        printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
        printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
        printf("10. Salir\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            controller_loadFromText("../data.csv", listaEmpleados);
            printf("Length %d\n", ll_len(listaEmpleados));
            break;
        case 2:
        	controller_loadFromBinary("../data.csv", listaEmpleados);
        	printf("Length %d\n", ll_len(listaEmpleados));
        	break;
        case 3:
        	controller_addEmployee(listaEmpleados);
        	printf("Length: %d\n", ll_len(listaEmpleados));
        	break;
        case 10:
        	break;
        default:
            printf("No es una opcion...");
            break;
        }
    } while (option != 10);
    return 0;
}