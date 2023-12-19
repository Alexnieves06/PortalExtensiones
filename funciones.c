#include "funciones.h"
#include <stdio.h>
#include <string.h>

void mostrarEmpleados(Empleado empleados[][10], int numEmpleados) {
    FILE *archivoEmpleados = fopen("C:/Users/usuario/Desktop/PortalExtensiones/informacionEmpleados.txt", "r");

    if (archivoEmpleados == NULL) {
        printf("Error al abrir el archivo de empleados.\n");
        return;
    }

    printf("\n--- Lista de Empleados ---\n");

    for (int i = 0; i < numEmpleados; ++i) {
        fscanf(archivoEmpleados, "%s %s %d",
               empleados[i][0].nombre,
               empleados[i][0].posicion,
               &empleados[i][0].extension);

        printf("Empleado %d: Nombre: %s, Posicion: %s, Extension: %d\n",
               i + 1, empleados[i][0].nombre, empleados[i][0].posicion, empleados[i][0].extension);
    } fflush(archivoEmpleados);

    fclose(archivoEmpleados);
}

void agregarEmpleado(Empleado empleados[][10], int *numEmpleados) {
    FILE *archivoEmpleados = fopen("C:/Users/usuario/Desktop/PortalExtensiones/informacionEmpleados.txt", "a");

    if (archivoEmpleados == NULL) {
        printf("Error al abrir el archivo de empleados.\n");
        return;
    }

    printf("\n--- Agregar Empleado ---\n");
    printf("Nombre: ");
    scanf("%s", empleados[*numEmpleados][0].nombre);
    printf("Posicion: ");
    scanf("%s", empleados[*numEmpleados][0].posicion);
    printf("Correo: ");
    scanf("%s", empleados[*numEmpleados][0].correo);
    printf("Extension: ");
    scanf("%d", &empleados[*numEmpleados][0].extension);

    fprintf(archivoEmpleados, "%s %s %s %d\n",
            empleados[*numEmpleados][0].nombre,
            empleados[*numEmpleados][0].posicion,
            empleados[*numEmpleados][0].correo,
            empleados[*numEmpleados][0].extension);

    (*numEmpleados)++;
    printf("Empleado agregado exitosamente.\n");

    fclose(archivoEmpleados);
}

void modificarEmpleado(Empleado empleados[][10], int numEmpleados) {
    int fila;

    printf("Ingrese el número de empleado a modificar (fila): ");
    scanf("%d", &fila);

    fila--;

    if (fila < 0 || fila >= numEmpleados) {
        printf("Número de empleado no válido.\n");
        return;
    }

    printf("Empleado %d: Nombre: %s, Posicion: %s, Correo: %s, Extension: %d\n",
           fila + 1, empleados[fila][0].nombre, empleados[fila][0].posicion,
           empleados[fila][0].correo, empleados[fila][0].extension);

    printf("\nIngrese los nuevos datos del empleado:\n");
    printf("Nuevo nombre: ");
    scanf("%s", empleados[fila][0].nombre);
    printf("Nueva posicion: ");
    scanf("%s", empleados[fila][0].posicion);
    printf("Nuevo correo: ");
    scanf("%s", empleados[fila][0].correo);
    printf("Nueva extension: ");
    scanf("%d", &empleados[fila][0].extension);

    FILE *archivoEmpleados = fopen("C:/Users/usuario/Desktop/PortalExtensiones/informacionEmpleados.txt", "w");

    if (archivoEmpleados == NULL) {
        printf("Error al abrir el archivo de empleados.\n");
        return;
    }

    for (int i = 0; i < numEmpleados; ++i) {
        fprintf(archivoEmpleados, "%s %s %s %d\n",
                empleados[i][0].nombre,
                empleados[i][0].posicion,
                empleados[i][0].correo,
                empleados[i][0].extension);
    }

    fclose(archivoEmpleados);

    printf("Empleado modificado exitosamente.\n");
}

int login() {
    FILE *archivoUsuarios = fopen("C:/Users/usuario/Desktop/PortalExtensiones/usuarios.txt", "r");

    if (archivoUsuarios == NULL) {
        printf("Error al abrir el archivo de usuarios.\n");
        return 0;
    }

    char usuario[20];
    char contrasena[20];

    printf("Ingrese su usuario: ");
    fflush(stdout);
    if (scanf("%19s", usuario) != 1) {
        printf("Error al leer el usuario.\n");
        fclose(archivoUsuarios);
        return 0;
    }

    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    printf("Ingrese su contrasena: ");
    fflush(stdout);
    if (scanf("%19s", contrasena) != 1) {
        printf("Error al leer la contraseña.\n");
        fclose(archivoUsuarios);
        return 0;
    }

    while (1) {
        char usuarioArchivo[20];
        char contrasenaArchivo[20];

        if (fscanf(archivoUsuarios, "%19s %19s", usuarioArchivo, contrasenaArchivo) != 2) {
            break;
        }

        if (strcmp(usuario, usuarioArchivo) == 0 && strcmp(contrasena, contrasenaArchivo) == 0) {
            printf("Login exitoso.\n");
            fclose(archivoUsuarios);
            return 1;
        }
    }

    printf("Usuario o contraseña incorrectos.\n");
    fclose(archivoUsuarios);
    return 0;
}
