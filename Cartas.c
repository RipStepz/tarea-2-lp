#include "Cartas.h"
#include "Tablero.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void * disparoSimple (int x , int y ){
    
    if (x < 1 || x > tamano_global || y < 1 || y > tamano_global ){
        printf("Coordenadas fuera de rango");
    }
    
    char *i = (char *)tablero[x-1][y-1];
    if (strcmp(i, "B") == 0){
        modificarCelda(x, y, "X");
    }
    else{
        modificarCelda(x, y, "O");
    }
    
}

void *disparoGrande(int x, int y) {
    if (!En_Rango(x, y)) {
        printf("Coordenadas fuera de rango\n");
    }

    int* Mov_x = Aux_disparoGrande_x();
    int* Mov_y = Aux_disparoGrande_y();
    char *c = (char *)tablero[x-1][y-1];

    for (int i = 0; i < 9; i++) {
        
        if (En_Rango(x + Mov_x[i], y + Mov_y[i])) {
            c = (char*)tablero[x + Mov_x[i] -1][y + Mov_y[i] -1];
            if (strcmp(c, "B") == 0) {
                modificarCelda(x + Mov_x[i], y + Mov_y[i], "X");
            } else {
                modificarCelda(x + Mov_x[i], y + Mov_y[i], "O");
            }
        }
    }

    free(Mov_x);
    free(Mov_y);
}

void * disparoLineal (int x , int y ){
    
    int Direccion; // 1 horizontal , 2 vertical

    printf("Introduzca 1 para lanzar el disparo Lineal en dirreccion horizontal o 2 para direccion vertical: ");
    scanf("%d", &Direccion); 
    printf("\n");

    if (!En_Rango(x,y)){
        printf("Coordenadas fuera de rango\n");
    }
    
    int * Mov_x = Aux_disparoLineal_x(Direccion);         
    int * Mov_y = Aux_disparoLineal_y(Direccion);  
    char *c = (char *)tablero[x-1][y-1];
    
    for (int i = 0; i < 9; i++) {
        
        if (En_Rango(x + Mov_x[i], y + Mov_y[i])) {
            c = (char*)tablero[x + Mov_x[i] -1][y + Mov_y[i] -1];
            if (strcmp(c, "B") == 0) {
                modificarCelda(x + Mov_x[i], y + Mov_y[i], "X");
            } else {
                modificarCelda(x + Mov_x[i], y + Mov_y[i], "O");
            }
        }
    }
    free(Mov_x);
    free(Mov_y); 
}

void * disparoRadar (int x , int y ){
    if (!En_Rango(x, y)) {
        printf("Coordenadas fuera de rango\n");
    }

    int* Mov_x = Aux_disparoRadar_x();
    int* Mov_y = Aux_disparoRadar_y();
    char *c = (char *)tablero[x-1][y-1];

    for (int i = 0; i < 25; i++) {
        
        if (En_Rango(x + Mov_x[i], y + Mov_y[i])) {
            c = (char*)tablero[x + Mov_x[i] -1][y + Mov_y[i] -1];
            if (strcmp(c, "B") == 0) {
                modificarCelda(x + Mov_x[i], y + Mov_y[i], "E");
            } else {
                modificarCelda(x + Mov_x[i], y + Mov_y[i], "O");
            }
        }
    }

    free(Mov_x);
    free(Mov_y);
}

void * disparo500KG (int x , int y ){
    if (!En_Rango(x, y)) {
        printf("Coordenadas fuera de rango\n");
    }

    int* Mov_x = Aux_disparo500KG_x();
    int* Mov_y = Aux_disparoRadar_y();
    char *c = (char *)tablero[x-1][y-1];

    for (int i = 0; i < 121; i++) {
        
        if (En_Rango(x + Mov_x[i], y + Mov_y[i])) {
            c = (char*)tablero[x + Mov_x[i] -1][y + Mov_y[i] -1];
            if (strcmp(c, "B") == 0) {
                modificarCelda(x + Mov_x[i], y + Mov_y[i], "E");
            } else {
                modificarCelda(x + Mov_x[i], y + Mov_y[i], "O");
            }
        }
    }

    free(Mov_x);
    free(Mov_y);
}