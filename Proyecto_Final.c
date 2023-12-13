#include <stdio.h>
#define MAX_CHAR 50

struct Usuario {
    char nombre[MAX_CHAR];
    char clave[MAX_CHAR];
};

int comprobarDatos(char nombre[], char clave[]) {
    FILE *archivo = fopen("C:/Users/usuario/Desktop/Proyecto final Programacion/usuarios.txt", "r");

    if (archivo == NULL) {
        perror("Error al abrir el archivo de usuarios");
        return 0;
    }

    struct Usuario usuarioActual;

    while (fscanf(archivo, "%s %s", usuarioActual.nombre, usuarioActual.clave) != EOF) {
        if (strcmp(usuarioActual.nombre, nombre) == 0 && strcmp(usuarioActual.clave, clave) == 0) {
            fclose(archivo);
            return 1; // Datos correctos
        }
    }

    fclose(archivo);
    return 0; // Datos incorrectos
}

int main() {
    char nombre[MAX_CHAR];
    char clave[MAX_CHAR];

    printf("Ingrese nombre de usuario: ");
    scanf("%s", nombre);

    printf("Ingrese clave: ");
    scanf("%s", clave);

    if (comprobarDatos(nombre, clave)) {
        printf("Acceso concedido. ¡Bienvenido, %s!\n", nombre);
        // continuar aqui
    } else {
        printf("Datos incorrectos. Acceso denegado.\n");
    }

    return 0;
}