#ifndef FUNCIONES_H
#define FUNCIONES_H

typedef struct {
    char nombre[50];
    char posicion[30];
    char correo[50];
    int extension;
} Empleado;

void mostrarMenu();
void mostrarEmpleados(Empleado empleados[][10], int numEmpleados);
void agregarEmpleado(Empleado empleados[][10], int *numEmpleados);
void modificarEmpleado(Empleado empleados[][10], int numEmpleados);
int login();

#endif
