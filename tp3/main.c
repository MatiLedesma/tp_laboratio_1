/****************************************************
 * Ledesma Matias 1°C
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
    char id[20];

    LinkedList *listaEmpleados = ll_newLinkedList();
    controller_loadLastId("../lastId.txt", "1000");
    controller_readLastId("../lastId.txt", id);

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
            break;
        case 2:
        	controller_loadFromBinary("../data.bin", listaEmpleados);
        	break;
        case 3:
        	controller_addEmployee(listaEmpleados, id);
        	break;
        case 4:
        	controller_editEmployee(listaEmpleados);
        	break;
        case 5:
        	controller_removeEmployee(listaEmpleados);
        	break;
        case 6:
        	controller_ListEmployee(listaEmpleados);
        	break;
        case 7:
        	controller_sortEmployee(listaEmpleados);
        	break;
        case 8:
        	controller_saveAsText("../data.csv", listaEmpleados);
        	break;
        case 9:
        	controller_saveAsBinary("../data.bin", listaEmpleados);
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
