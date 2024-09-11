#include "Cartas.h"
#include "Tablero.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int Arreglo_mano[5];
int Pos_mano;
int Total_Barcos;

void * disparoSimple (int x , int y ){ // 1
    
    if (x < 1 || x > tamano_global || y < 1 || y > tamano_global ){
        printf("Coordenadas fuera de rango");
    }
    
    printf("Letra encontrada_ %c\n", *(char *)tablero[x-1][y-1]);

    if (*(char *)tablero[x-1][y-1] == ' ' || *(char *)tablero[x-1][y-1] == 'O' ){
        modificarCelda(x, y, 'O');
    }
    else{
        modificarCelda(x, y, 'X');
    }
   
    
    Arreglo_mano[Pos_mano] = generarCarta_Simple(); 
}

void *disparoGrande(int x, int y) { // 2
    if (!En_Rango(x, y)) {
        printf("Coordenadas fuera de rango\n");
    }

    int* Mov_x = Aux_disparoGrande_x();
    int* Mov_y = Aux_disparoGrande_y();

    for (int i = 0; i < 9; i++) {
        
        //printf("%d\n", En_Rango(x,y));
        if (En_Rango(x + Mov_y[i], y + Mov_x[i])) {

            if (*(char *)tablero[x + Mov_y[i]-1][y+ Mov_x[i]-1] == ' ' || *(char *)tablero[x + Mov_y[i]-1][y+ Mov_x[i]-1] == 'O' ){
                modificarCelda(x + Mov_y[i], y + Mov_x[i], 'O');
             }
            else{
                printf("Entro Else\n");
                modificarCelda(x + Mov_y[i], y + Mov_x[i], 'X');
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
    
    for (int i = 0; i < 9; i++) {
        
        if (En_Rango(x + Mov_y[i], y + Mov_x[i])) {

            if (*(char *)tablero[x + Mov_y[i]-1][y+ Mov_x[i]-1] == ' ' || *(char *)tablero[x + Mov_y[i]-1][y+ Mov_x[i]-1] == 'O' ){
                modificarCelda(x + Mov_y[i], y + Mov_x[i], 'O');
             }
            else{
                printf("Entro Else\n");
                modificarCelda(x + Mov_y[i], y + Mov_x[i], 'X');
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

    for (int i = 0; i < 25; i++) {
        
        if (En_Rango(x + Mov_y[i], y + Mov_x[i])) {

            if (*(char *)tablero[x + Mov_y[i]-1][y+ Mov_x[i]-1] == ' ' || *(char *)tablero[x + Mov_y[i]-1][y+ Mov_x[i]-1] == 'O' ){
                modificarCelda(x + Mov_y[i], y + Mov_x[i], 'O');
             }
            else{
                printf("Entro Else\n");
                modificarCelda(x + Mov_y[i], y + Mov_x[i], 'E');
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
        
        if (En_Rango(x + Mov_y[i], y + Mov_x[i])) {

            if (*(char *)tablero[x + Mov_y[i]-1][y+ Mov_x[i]-1] == ' ' || *(char *)tablero[x + Mov_y[i]-1][y+ Mov_x[i]-1] == 'O' ){
                modificarCelda(x + Mov_y[i], y + Mov_x[i], 'O');
             }
            else{
                printf("Entro Else\n");
                modificarCelda(x + Mov_y[i], y + Mov_x[i], 'X');
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
    
    printf("Cartas:\n");
    for (int i = 0; i < 5; i++){
        if ((Arreglo_mano[i] == 1) && (i != 4)){
            printf("Simple  |  ");
        }
        else if ((Arreglo_mano[i] == 1) && (i == 4)){
            printf("Simple\n");
        }

        else if ((Arreglo_mano[i] == 2) && (i != 4)){
            printf("Grande  |  ");
        }
        else if ((Arreglo_mano[i] == 2) && (i == 4)){
            printf("Grande\n");
        }

        else if ((Arreglo_mano[i] == 3) && (i != 4)){
            printf("Lineal  |  ");
        }
        else if ((Arreglo_mano[i] == 3) && (i == 4)){
            printf("Linal\n");
        }

        else if ((Arreglo_mano[i] == 4) && (i !=4)){
            printf("Radar |  ");
        }
        else if ((Arreglo_mano[i] == 4) && (i == 4)){
            printf("Radar\n");
        }

        else if ((Arreglo_mano[i] == 5) && (i != 4)){
            printf("500KG  |  ");
        }
        else if ((Arreglo_mano[i] == 5) && (i == 4)){
            printf("500KG\n");
        }
        else if ((Arreglo_mano[i] == -1) && (i != 4)){
            printf("X  |  ");
        }
        else if ((Arreglo_mano[i] == -1) && (i == 4)){
            printf("X\n");
        }
    }
}

void usarCarta () {
    
    int indice, x,y;

    printf("Seleciona una Carta: ");
    scanf("%d", &indice);
    printf("\n");

    
    while (indice < 1 || indice >5){
        printf("Carta invalida, seleccione otra: ");
        scanf("%d", &indice);
        printf("\n");
    }
        
    
    
    indice = indice - 1;
            
        while (1==1){
            
        if (Arreglo_mano[indice] == 1){
            
            printf("Selecciona Coordenadas\n");
            printf("X: ");
            scanf("%d", &x);  
            printf("Y: ");
            scanf("%d", &y);

            while (!En_Rango(y,x)){
                printf("Coordenadas fuera de rango, favor ingresar otras\n");
                printf("X: ");
                scanf("%d", &x);  
                printf("Y: ");
                scanf("%d", &y);
            }
            Pos_mano = indice;
            
            disparoSimple(y,x);
            break;    
        }
        
        else if (Arreglo_mano[indice] == 2){
            printf("Selecciona Coordenadas\n");
            printf("X: ");
            scanf("%d", &x);  
            printf("Y: ");
            scanf("%d", &y);

            while (!En_Rango(y,x)){
                printf("Coordenadas fuera de rango, favor ingresar otras\n");
                printf("X: ");
                scanf("%d", &x);  
                printf("Y: ");
                scanf("%d", &y);
            }
              
            Pos_mano = indice;
            disparoGrande(y,x);
            break;
            
        }

        else if (Arreglo_mano[indice] == 3){
            printf("Selecciona Coordenadas\n");
            printf("X: ");
            scanf("%d", &x);  
            printf("Y: ");
            scanf("%d", &y);

            while (!En_Rango(y,x)){
                printf("Coordenadas fuera de rango, favor ingresar otras\n");
                printf("X: ");
                scanf("%d", &x);  
                printf("Y: ");
                scanf("%d", &y);
            }
              
            Pos_mano = indice;
            disparoLineal(y,x);
            break;
            
        }
    
        else if (Arreglo_mano[indice] == 4){
            printf("Selecciona Coordenadas\n");
            printf("X: ");
            scanf("%d", &x);  
            printf("Y: ");
            scanf("%d", &y);

            while (!En_Rango(y,x)){
                printf("Coordenadas fuera de rango, favor ingresar otras\n");
                printf("X: ");
                scanf("%d", &x);  
                printf("Y: ");
                scanf("%d", &y);
            }
              
            Pos_mano = indice;
            disparoRadar(y,x);
            break;
            
        }
 

        else if (Arreglo_mano[indice] == 5){
            printf("Selecciona Coordenadas\n");
            printf("X: ");
            scanf("%d", &x);  
            printf("Y: ");
            scanf("%d", &y);

            while (!En_Rango(y,x)){
                printf("Coordenadas fuera de rango, favor ingresar otras\n");
                printf("X: ");
                scanf("%d", &x);  
                printf("Y: ");
                scanf("%d", &y);
            }
              
            int Pos_mano = indice;
            disparo500KG(y,x);
            break;
            
        }
        else if (Arreglo_mano[indice] == -1){
            printf("Cañon desabilitado, favor elegir otro\n");
    }
}
}