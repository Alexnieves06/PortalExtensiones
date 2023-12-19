/*----------------------------------------------------------------
|  Autor:          Alexander Nieves           Matricula: 1-19-0554 |
|  Fecha:          15/12/2023                  Versión: 1.0        |
|-----------------------------------------------------------------|
|  Descripción del Programa:                                      |
|  Portal eficiente para gestionar empleados con 
 | funciones clave y autenticación segura.                             |
| ----------------------------------------------------------------*/
#include "funciones.h"
#include <stdio.h>

void mostrarMenu() {
    printf("\n--- Portal de Extensiones ---\n");
    printf("1. Mostrar Empleados\n");
    printf("2. Agregar Empleado\n");
    printf("3. Modificar Empleado\n");
    printf("4. Salir\n");
}

int main() {
    if (login()) {
        Empleado empleados[10][10];
        int numEmpleados = 10;
        int opcion;

        do {
            mostrarMenu();
            printf("Ingrese la opcion: ");
            scanf("%d", &opcion);

            switch (opcion) {
                case 1:
                    mostrarEmpleados(empleados, numEmpleados);
                    break;
                case 2:
                    agregarEmpleado(empleados, &numEmpleados);
                    break;
                case 3:
                    modificarEmpleado(empleados, numEmpleados);
                    break;
                case 4:
                    printf("Saliendo del programa...\n");
                    break;
                default:
                    printf("Opcion no valida. Intente de nuevo.\n");
            }
        } while (opcion != 4);
    } else {
        printf("Login fallido. Saliendo del programa...\n");
    }

    return 0;
}
