#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "Tablero.h"

void *** tablero = NULL;
int tamano_global = 0;

void inicializarTablero(int tamano) {
    tamano_global = tamano;

    tablero = (void ***)malloc(tamano * sizeof(void **));

    for (int i = 0; i < tamano; i++) {
        tablero[i] = (void **)malloc(tamano * sizeof(void *));
        for (int j = 0; j < tamano; j++) {
            tablero[i][j] = malloc(sizeof(char));
            *(char *)tablero[i][j] = ' ';  // Inicializamos con espacios vacíos
        }
    }
}

void mostrarTablero() {
    for (int i = 0; i < tamano_global; i++) {
        for (int j = 0; j < tamano_global; j++) {
            printf("|%s", (char *)tablero[i][j]);
        }
        printf("|\n");
    }
}

void modificarCelda(int x, int y, char nuevoContenido) {
    int fila = x - 1;
    int columna = y - 1;

    if (fila >= 0 && fila < tamano_global && columna >= 0 && columna < tamano_global) {
        *(char *)tablero[fila][columna] = nuevoContenido;
    } else {
        printf("Índices fuera de los límites del tablero: (%d, %d)\n", x, y);
    }
}

// Función auxiliar para verificar si el espacio está disponible para colocar el barco
int verificarEspacioDisponible(int x, int y, int largo, int orientacion) {
    for (int i = 0; i < largo; i++) {
        int fila = x - 1, columna = y - 1;
        if (orientacion == 1) fila -= i;          // Izquierda
        else if (orientacion == 2) fila += i;     // Derecha
        else if (orientacion == 3) columna += i;  // Abajo
        else if (orientacion == 4) columna -= i;  // Arriba

        // Verifica si está dentro de los límites
        if (fila < 0 || fila >= tamano_global || columna < 0 || columna >= tamano_global) {
            return 0;  // Espacio fuera de los límites
        }

        // Verifica si la celda está ocupada
        if (*(char *)tablero[fila][columna] != ' ') {
            return 0;  // La celda está ocupada
        }
    }
    return 1;  // Espacio disponible
}

void colocarBarco(int x, int y, int largo, int orientacion, char simbolo) {
    // Sigue intentando hasta encontrar un espacio disponible
    while (!verificarEspacioDisponible(x, y, largo, orientacion)) {
        // Si el espacio no está disponible, generamos nuevas coordenadas y orientación
        x = 1 + rand() % tamano_global;
        y = 1 + rand() % tamano_global;
        orientacion = 1 + rand() % 4;  // Nueva orientación aleatoria
    }

    // Una vez verificado el espacio, colocamos el barco
    for (int i = 0; i < largo; i++) {
        if (orientacion == 1) modificarCelda(x - i, y, simbolo);       // Izquierda
        else if (orientacion == 2) modificarCelda(x + i, y, simbolo);  // Derecha
        else if (orientacion == 3) modificarCelda(x, y + i, simbolo);  // Abajo
        else if (orientacion == 4) modificarCelda(x, y - i, simbolo);  // Arriba
    }
}

void colocarBarcosAleatoriamente() {
    int* barcos = ArregloAleatorio(1);
    int * Rangos = Rangos_Arreglo();
    int Tamaño_Array = Largo_Arreglo();
    srand(time(NULL));

    for (int i = 0; i < Tamaño_Array; i++) {
        int x = 1 + rand() % tamano_global;  // Coordenadas aleatorias
        int y = 1 + rand() % tamano_global;
        int orientacion = 1 + rand() % 4;  // Orientación aleatoria

        if (i <= Rangos[0]) {
            colocarBarco(x, y, 2, orientacion, 'B');
        } else if (Rangos[0] < i && i <= Rangos[1]) {
            colocarBarco(x, y, 3, orientacion, 'B');
        } else if (Rangos[1] < i && i <= Rangos[2]) {
            colocarBarco(x, y, 4, orientacion, 'B');
        } else if (Rangos[2] < i && i <= Rangos[3]) {
            colocarBarco(x, y, 5, orientacion, 'B');
        }
    }

    free(barcos);
    free(Rangos);
}

void liberarTablero() {
    for (int i = 0; i < tamano_global; i++) {
        for (int j = 0; j < tamano_global; j++) {
            free(tablero[i][j]);
        }
        free(tablero[i]);
    }
    free(tablero);
}
