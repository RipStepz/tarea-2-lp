#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "Tablero.h"

void *** tablero = NULL;
int tamano_global = 0;

// Esta funcion recibe de parametro tamano, que es el tamaño del tablero, no retorna nada y inicia el tablero, con espacios en blanco
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
/*
Muestra el tablero como una matriz y mostrando los barcos.
no recibe parametros, ni retorna nada
*/
void mostrarTablero() {
    for (int i = 0; i < tamano_global; i++) {
        for (int j = 0; j < tamano_global; j++) {
            printf("|%s", (char *)tablero[i][j]);
        }
        printf("|\n");
    }
}

/*
Muestra el tablero como una matriz ocultando los barcos.
no recibe parametros, ni retorna nada
*/
void mostrarTableroOculto() {
    for (int i = 0; i < tamano_global; i++) {
        for (int j = 0; j < tamano_global; j++) {
            char celda = *(char *)tablero[i][j];
            if (celda == 'B') {
                // Oculta los barcos mostrando un espacio en blanco
                printf("| ");
            } else {
                // Muestra el contenido de la celda
                printf("|%c", celda);
            }
        }
        printf("|\n");  // Barra final para la última columna y nueva línea después de cada fila
    }
}
/*
Recibe como parametro una coordenada en x otra en y el caracter a insertar en el tablero
Ya que el tablero es un arreglo, se le resta uno a la fila y columna, para que las coordenadas
(1,1) sean las primeras
*/
void modificarCelda(int x, int y, char nuevoContenido) {
    int fila = x - 1;
    int columna = y - 1;

    if (fila >= 0 && fila < tamano_global && columna >= 0 && columna < tamano_global) {
        *(char *)tablero[fila][columna] = nuevoContenido;
    } else {
        printf("Índices fuera de los límites del tablero: (%d, %d)\n", x, y);
    }
}

    /*Función auxiliar para verificar si el espacio está disponible para colocar el barco y no haya colicion
    Recibe como parametro la coordenada de donde nace el barco osea (x,y), el largo del barco a insertar y su orientacion
    no retorna nada
    */ 
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

/* Coloca los barcos en una de las cuatro orientaciones
    Recibe como parametro la coordenada de donde nace el barco osea (x,y), el largo del barco a insertar y su orientacion
    no retorna nada
*/ 
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

        Total_Barcos ++;
        if (orientacion == 1) modificarCelda(x - i, y, simbolo);       // Izquierda
        else if (orientacion == 2) modificarCelda(x + i, y, simbolo);  // Derecha
        else if (orientacion == 3) modificarCelda(x, y + i, simbolo);  // Abajo
        else if (orientacion == 4) modificarCelda(x, y - i, simbolo);  // Arriba
    }
}
/* Dependiendo de los rangos que signficia de que tipo de barco es, el puntero a int barcos, son las dirrecciones
el tamaño aray es para saber cuantos barcos hay que poner
    no recibe parametros ni retorna nada
*/ 
void colocarBarcosAleatoriamente() {
    int* barcos = ArregloAleatorio();
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
/* Libera la memoria del tablero
    no recibe parametros ni retorna nada
*/ 
void liberarTablero() {
    for (int i = 0; i < tamano_global; i++) {
        for (int j = 0; j < tamano_global; j++) {
            free(tablero[i][j]);
        }
        free(tablero[i]);
    }
    free(tablero);
}
