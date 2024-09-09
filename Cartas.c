#include "Cartas.h"
#include "Tablero.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int Arreglo_mano[5];
int Pos_mano;

void * disparoSimple (int x , int y ){ // 1
    
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
   
    Arreglo_mano[Pos_mano] = generarCarta_Simple(); 
}

void *disparoGrande(int x, int y) { // 2
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

    Arreglo_mano[Pos_mano] = generarCarta_Grande(); 
    free(Mov_x);
    free(Mov_y);
}

void * disparoLineal (int x , int y ){ // 3
    
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
    
    Arreglo_mano[Pos_mano] = generarCarta_Lineal(); 
    free(Mov_x);
    free(Mov_y); 
}

void * disparoRadar (int x , int y ){ // 4
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

    Arreglo_mano[Pos_mano] = generarCarta_Radar(); 
    free(Mov_x);
    free(Mov_y);
}

void * disparo500KG (int x , int y ){ // 5
    if (!En_Rango(x, y)) {
        printf("Coordenadas fuera de rango\n");
    }

    int* Mov_x = Aux_disparo500KG_x();
    int* Mov_y = Aux_disparo500KG_y();
    char *c = (char *)tablero[x-1][y-1];

    for (int i = 0; i < 121; i++) {
        
        if (En_Rango(x + Mov_x[i], y + Mov_y[i])) {
            c = (char*)tablero[x + Mov_x[i] -1][y + Mov_y[i] -1];
            if (strcmp(c, "B") == 0) {
                modificarCelda(x + Mov_x[i], y + Mov_y[i], "X");
            } else {
                modificarCelda(x + Mov_x[i], y + Mov_y[i], "O");
            }
        }
    }
    Arreglo_mano[Pos_mano] = -1;
    free(Mov_x);
    free(Mov_y);
}

void inicializarMano (){
    Arreglo_mano[0] = 1;
    Arreglo_mano[1] = 1;
    Arreglo_mano[2] = 1;
    Arreglo_mano[3] = 1;
    Arreglo_mano[4] = 1;
}

void mostrarMano (){
    for (int i = 0; i < 5; i++){
        if ((Arreglo_mano[i] == 1) && (i != 4)){
            printf("Simple  |  ");
        }
        else if ((Arreglo_mano[i] == 1) && (i == 4)){
            printf("Simple\n");
        }

        else if ((Arreglo_mano[i] == 2) && (i == 4)){
            printf("Grande  |  ");
        }
        else if ((Arreglo_mano[i] == 2) && (i == 4)){
            printf("Grande\n");
        }

        else if ((Arreglo_mano[i] == 3) && (i == 4)){
            printf("Lineal  |  ");
        }
        else if ((Arreglo_mano[i] == 3) && (i == 4)){
            printf("Linal\n");
        }

        else if ((Arreglo_mano[i] == 4) && (i == 4)){
            printf("Radar |  ");
        }
        else if ((Arreglo_mano[i] == 4) && (i == 4)){
            printf("Radar\n");
        }

        else if ((Arreglo_mano[i] == 5) && (i == 4)){
            printf("500KG  |  ");
        }
        else if ((Arreglo_mano[i] == 5) && (i == 4)){
            printf("500KG\n");
        }
    }
    
}

void usarCarta () {
    
    int x,y;
    for (int i = 0; i < 5; i++){
        
        if (Arreglo_mano[i] == 1){
            
            printf("Selecciona Coordenadas\n");
            printf("X: ");
            scanf("%d", &x);  
            printf("Y: ");
            scanf("%d", &y);
            
            int Pos_mano = i;
            disparoSimple(x,y);

            break;
        }
        
        else if (Arreglo_mano[i] == 2){
            printf("Selecciona Coordenadas\n");
            printf("X: ");
            scanf("%d", &x);  
            printf("Y: ");
            scanf("%d", &y);
              
            int Pos_mano = i;
            disparoGrande(x,y);
            break;
        }

        else if (Arreglo_mano[i] == 3){
            printf("Selecciona Coordenadas\n");
            printf("X: ");
            scanf("%d", &x);  
            printf("Y: ");
            scanf("%d", &y);
              
            int Pos_mano = i;
            disparoLineal(x,y);
            break;
        }
    
        else if (Arreglo_mano[i] == 4){
            printf("Selecciona Coordenadas\n");
            printf("X: ");
            scanf("%d", &x);  
            printf("Y: ");
            scanf("%d", &y);
              
            int Pos_mano = i;
            disparoRadar(x,y);
            break;
        }
 

        else if (Arreglo_mano[i] == 5){
            printf("Selecciona Coordenadas\n");
            printf("X: ");
            scanf("%d", &x);  
            printf("Y: ");
            scanf("%d", &y);
              
            int Pos_mano = i;
            disparo500KG(x,y);
            break;
        }

    }
}