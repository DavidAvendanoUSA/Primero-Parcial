#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *nombre;
    char *apellido;
    unsigned int edad : 7;   
    unsigned int id   : 24;  
    float *calificaciones;
    int numMaterias;
} Estudiante;


Estudiante* crearEstudiante(const char *nombre, const char *apellido, unsigned int edad, unsigned int id, float *notas, int numMaterias) {
    Estudiante *e = (Estudiante*) malloc(sizeof(Estudiante));
    if (!e) return NULL;


    e->nombre = (char*) malloc(strlen(nombre) + 1);
    strcpy(e->nombre, nombre);


    e->apellido = (char*) malloc(strlen(apellido) + 1);
    strcpy(e->apellido, apellido);

    // Guardar edad e id
    e->edad = edad;
    e->id = id;


    e->calificaciones = (float*) malloc(numMaterias * sizeof(float));
    for (int i = 0; i < numMaterias; i++) {
        e->calificaciones[i] = notas[i];
    }
    e->numMaterias = numMaterias;

    return e;
}


void liberarEstudiante(Estudiante *e) {
    if (!e) return;
    free(e->nombre);
    free(e->apellido);
    free(e->calificaciones);
    free(e);
}

void mostrarEstudiante(Estudiante *e) {
    printf("Nombre: %s %s\n", e->nombre, e->apellido);
    printf("Edad: %u | ID: %u\n", e->edad, e->id);
    printf("Notas: ");
    for (int i = 0; i < e->numMaterias; i++) {
        printf("%.2f ", e->calificaciones[i]);
    }
    printf("\n");
}

int main() {
    float notas1[] = {4.5, 3.8, 4.0};
    float notas2[] = {3.2, 2.9};

    Estudiante *e1 = crearEstudiante("Camilo", "Perez", 20, 123456, notas1, 3);
    Estudiante *e2 = crearEstudiante("Sara", "Gomez", 22, 654321, notas2, 2);

    mostrarEstudiante(e1);
    mostrarEstudiante(e2);

    liberarEstudiante(e1);
    liberarEstudiante(e2);

    return 0;
}