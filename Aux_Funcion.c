#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "Tablero.h"

int* ArregloAleatorio(){

    int tamaño;
    int numero_aleatorio;
    int min = 1;
    int max = 4;
    srand(time(NULL));
    
    if (Dificultad_Tablero == 1) {
        tamaño = 5;
    } 
    
    else if (Dificultad_Tablero == 2) {
        tamaño = 7;
    } 
    
    else if (Dificultad_Tablero == 3) {
        tamaño = 9;
    }
    
    int* arreglo = (int*)malloc(tamaño * sizeof(int));
    
    for (int i = 0; i < tamaño; i++) {
        numero_aleatorio = min + rand() % (max - min + 1);
        arreglo[i] = numero_aleatorio;
    }

    return arreglo;
}

int Largo_Arreglo(){
   if (Dificultad_Tablero == 1) {
        return 5;
    } 
    
    else if (Dificultad_Tablero == 2) {
        return 7;
    } 
    
    else if (Dificultad_Tablero == 3) {
        return 9;
    }

    return 0;
    
}

int Retorno_Matriz(){
    if (Dificultad_Tablero == 1){
        return 11;
    }
    else if (Dificultad_Tablero == 2){
        return 17;
    }
    else{
        return 21;
    }   
}

int* Rangos_Arreglo(){

     int rango_1 , rango_2 , rango_3 , rango_4;
     int* arreglo = (int*)malloc(4 * sizeof(int));

     if(Dificultad_Tablero == 1){
        rango_1 = 1; rango_2 = 2; rango_3 = 3; rango_4 = 4;
    }
    else if (Dificultad_Tablero == 2){
        rango_1 = 2; rango_2 = 4; rango_3 =5; rango_4=6;
    }
    else{
       rango_1 = 2; rango_2 = 4; rango_3 =6; rango_4=8; 
    }
    
    
    arreglo[0] = rango_1;
    arreglo[1] = rango_2;
    arreglo[2] = rango_3;
    arreglo[3] = rango_4;
  
    return arreglo;
}

int En_Rango(int x, int y){

    if (x < 1 || x > tamano_global || y < 1 || y > tamano_global){
        return 0;
    }
    else{
        return 1;
    }
}

int* Aux_disparoGrande_x() {
    int* arreglo_x = (int*)malloc(9 * sizeof(int));
    arreglo_x[0] = 0;  
    arreglo_x[1] = 1;  
    arreglo_x[2] = -1; 
    arreglo_x[3] = 0;  
    arreglo_x[4] = 0;  
    arreglo_x[5] = 1;  
    arreglo_x[6] = -1; 
    arreglo_x[7] = 1;  
    arreglo_x[8] = -1; 
    return arreglo_x;
}

int* Aux_disparoGrande_y() {
    int* arreglo_y = (int*)malloc(9 * sizeof(int));
    arreglo_y[0] = 0;  
    arreglo_y[1] = 0;  
    arreglo_y[2] = 0;  
    arreglo_y[3] = 1;  
    arreglo_y[4] = -1; 
    arreglo_y[5] = -1; 
    arreglo_y[6] = -1; 
    arreglo_y[7] = 1;  
    arreglo_y[8] = 1;  
    return arreglo_y;
}

int* Aux_disparoLineal_x(int i) {
    int* arreglo_x = (int*)malloc(5 * sizeof(int));
    if (i == 1){
        arreglo_x[0] = -2;  
        arreglo_x[1] = -1;  
        arreglo_x[2] = 0; 
        arreglo_x[3] = 1; 
        arreglo_x[4] = 2;  
        
    }
    else{
        arreglo_x[0] = 0;  
        arreglo_x[1] = 0;  
        arreglo_x[2] = 0; 
        arreglo_x[3] = 0; 
        arreglo_x[4] = 0; 
    }
     
    return arreglo_x;
}

int* Aux_disparoLineal_y(int i) {
    int* arreglo_y = (int*)malloc(5 * sizeof(int));
     if (i == 1){
        arreglo_y[0] = 0;  
        arreglo_y[1] = 0;  
        arreglo_y[2] = 0; 
        arreglo_y[3] = 0; 
        arreglo_y[4] = 0;  
        
    }
    else{
        arreglo_y[0] = -2;  
        arreglo_y[1] = -1;  
        arreglo_y[2] = 0; 
        arreglo_y[3] = 1; 
        arreglo_y[4] = 2;
    }
    return arreglo_y;
}

int* Aux_disparoRadar_x() {

    int* arreglo_x = (int*)malloc(25 * sizeof(int));

    arreglo_x[0] = 0;  
    arreglo_x[1] = 1;  
    arreglo_x[2] = -1; 
    arreglo_x[3] = 0;  
    arreglo_x[4] = 0;  
    arreglo_x[5] = 1;  
    arreglo_x[6] = -1; 
    arreglo_x[7] = 1;  
    arreglo_x[8] = -1;

    arreglo_x[9] = -2;  
    arreglo_x[10] = -1;  
    arreglo_x[11] = 0; 
    arreglo_x[12] = 1;  
    arreglo_x[13] = 2;  
    
    arreglo_x[14] = -2;  
    arreglo_x[15] = 2; 
    
    arreglo_x[16] = -2;  
    arreglo_x[17] = 2;

    arreglo_x[18] = -2;  
    arreglo_x[19] = 2;  
    
    arreglo_x[20] = -2;
    arreglo_x[21] = -1; 
    arreglo_x[22] = 0;  
    arreglo_x[23] = 1; 
    arreglo_x[24] = 2; 




    return arreglo_x;
     
}

int* Aux_disparoRadar_y() {
    int* arreglo_y = (int*)malloc(25 * sizeof(int));

    arreglo_y[0] = 0;  
    arreglo_y[1] = 0;  
    arreglo_y[2] = 0;  
    arreglo_y[3] = 1;  
    arreglo_y[4] = -1; 
    arreglo_y[5] = -1; 
    arreglo_y[6] = -1; 
    arreglo_y[7] = 1;  
    arreglo_y[8] = 1;

    arreglo_y[9] = -2;  
    arreglo_y[10] = -2;  
    arreglo_y[11] = -2; 
    arreglo_y[12] = -2;  
    arreglo_y[13] = -2;  
    
    arreglo_y[14] = -1;  
    arreglo_y[15] = -1; 
    
    arreglo_y[16] = 0;  
    arreglo_y[17] = 0; 

    arreglo_y[18] = 1;  
    arreglo_y[19] = 1;

    arreglo_y[20] = 2;  
    arreglo_y[21] = 2; 
    arreglo_y[22] = 2;  
    arreglo_y[23] = 2; 
    arreglo_y[24] = 2; 

    return arreglo_y;
}

int* Aux_disparo500KG_x() {
    int* arreglo_x = (int*)malloc(121 * sizeof(int)); // 11x11 = 121 desplazamientos
    
    for (int i = 0; i < 121; i++){
        for (int c = -5; c < 5; c++){
            arreglo_x[i] = c;
        }
    }
     
    

    

    return arreglo_x;
}

int* Aux_disparo500KG_y() {
    int* arreglo_y = (int*)malloc(121 * sizeof(int)); // 11x11 = 121 desplazamientos
    int altura = - 5;

    for (int i = 0; i < 121; i++){
        
        arreglo_y[i] = altura;

        if (i % 11 == 0 ){
            altura += 1;
        }      
    }

    return arreglo_y;
}