#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "Tablero.h"

void *** tablero = NULL;
int tamano_global = 0;

void inicializarTablero(int tamano) {
    tamano_global = tamano;  // Asignamos el tamaño del tablero

    // Reservar memoria para las filas, casteando a void***
    tablero = (void ***)malloc(tamano * sizeof(void **));

    for (int i = 0; i < tamano; i++) {
        // Para cada fila, reservamos memoria para las columnas y casteamos a void**
        tablero[i] = (void **)malloc(tamano * sizeof(void *));
        for (int j = 0; j < tamano; j++) {
            // Para cada celda, reservamos memoria para un char
            tablero[i][j] = malloc(sizeof(char));
            *(char *)tablero[i][j] = ' ';  // Guardamos un espacio en blanco
        }
    }
}

// Función para imprimir el tablero con separadores visuales "|"
void mostrarTablero() {
    for (int i = 0; i < tamano_global; i++) {
        for (int j = 0; j < tamano_global; j++) {
            printf("|%s", (char *)tablero[i][j]);  // Imprimimos "|" seguido del espacio en blanco
        }
        printf("|\n");  // Barra final para la última columna y nueva línea después de cada fila
    }
}

void modificarCelda(int x, int y, char nuevoContenido) {
    // Convertir coordenadas 1-basadas a 0-basadas
    int fila = x - 1;
    int columna = y - 1;

    // Verifica que los índices estén dentro de los límites del tablero
    if (fila >= 0 && fila < tamano_global && columna >= 0 && columna < tamano_global) {
        // Cambia el contenido de la celda en (fila, columna)
        *(char *)tablero[fila][columna] = nuevoContenido;
    } else {
        printf("Índices fuera de los límites del tablero, letra en conflicto : %c, Coordenadas (%d , %d) \n", nuevoContenido , x , y);
    }
}

void colocarBarco(int x, int y, int largo, int orientacion, char simbolo) {
    // Orientación 1: izquierda, 2: derecha, 3: abajo, 4: arriba
    
    int limite;
    limite = largo - 1;
    int * Nueva_Seed; 
    
    for (int i = 0; i < largo; i++) {
        
        if (orientacion == 1) { // Movimiento izquierda, si no se puede derecha
            
            if (x - limite  < 1){
                for (int b = 0; b < largo; b++){
                    modificarCelda(x + b, y, simbolo);
                }     
            }
            else{
                for (int c = 0; c < largo; c++){
                modificarCelda(x - c, y, simbolo);
            }
        }
        }

        else if (orientacion == 2) { // Movimiento derecha, si no se puede izquierda
            
            if (x + limite > tamano_global){
                for (int b = 0; b < largo; b++){
                    modificarCelda(x - b, y, simbolo);
                }     
            }
            
            else{
                for (int c = 0; c < largo; c++){
                modificarCelda(x + c, y, simbolo);
            }
        }
        }  
        if (orientacion == 3) { // Movimiento abajo, si no se puede arriba
            
            if (y - limite < 1){
                for (int b = 0; b < largo; b++){
                    modificarCelda(x, y + b, simbolo);
                }     
            }
            
            else{
                for (int c = 0; c < largo; c++){
                modificarCelda(x , y - c, simbolo);
            }
        } 
        }

         else if (orientacion == 4) { // Movimiento arriba, si no se puede abajo
            
            if (y + limite > tamano_global){
                for (int b = 0; b < largo; b++){
                    modificarCelda(x, y -b, simbolo);
                }     
            }
            
            else{
                for (int c = 0; c < largo; c++){
                modificarCelda(x, y + c, simbolo);
            }
        } 
        }
    }
}

void colocarBarcosAleatoriamente() {
    
    int* barcos = ArregloAleatorio(1);
    int * Rangos = Rangos_Arreglo();
    int Tamaño_Array = Largo_Arreglo();
    srand(time(NULL));

    // La posicion en el arreglo "barcos", equivale al barco, en orden de mas chico a grande
    // Con un numero de del 1 al 4 que representa su orientacion siendo
    // 1 izquierda, 2 aderech , 3 abajo , 4 arriba
    
    for (int i = 0; i < Tamaño_Array; i++){
        
        
        if (i<= Rangos[0]){
            int x = 1 + rand() % tamano_global;     // Fila aleatoria entre 1 y n
            int y = 1 + rand() % tamano_global;  // Columna aleatoria entre 1 y n
            colocarBarco(x, y , 2 , barcos[i] , 'B');
        }
        else if (Rangos[0] < i && i <= Rangos[1]){
            int x = 1 + rand() % tamano_global;     // Fila aleatoria entre 1 y n
            int y = 1 + rand() % tamano_global;  // Columna aleatoria entre 1 y n
            
            colocarBarco(x, y , 3 , barcos[i] , 'B');
            
        }
        else if (Rangos[1]<i && i<= Rangos[2]){
            int x = 1 + rand() % tamano_global;     // Fila aleatoria entre 1 y n
            int y = 1 + rand() % tamano_global;  // Columna aleatoria entre 1 y n
            
            colocarBarco(x, y , 4 , barcos[i] , 'B');
        }
        else if (Rangos[2] < i && i<= Rangos[3]){

            int x = 1 + rand() % tamano_global;     // Fila aleatoria entre 1 y n
            int y = 1 + rand() % tamano_global;  // Columna aleatoria entre 1 y n
            colocarBarco(x, y , 5 , barcos[i] , 'B');
        }          
    }  
    free(barcos);
    free(Rangos);  
}

void liberarTablero() {
    for (int i = 0; i < tamano_global; i++) {
        for (int j = 0; j < tamano_global; j++) {
            free(tablero[i][j]);  // Liberamos cada celda
        }
        free(tablero[i]);  // Liberamos cada fila
    }
    free(tablero);  // Finalmente, liberamos el puntero principal
}