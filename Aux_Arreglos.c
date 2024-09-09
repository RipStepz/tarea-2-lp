#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "Cartas.h"

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

    int* arreglo_x = (int*)malloc(121 * sizeof(int)); 
    int index = 0;

    for (int i = 0; i < 11; i++) {
        for (int j = -5; j <= 5; j++) {
            arreglo_x[index++] = j;
        }
    }


    return arreglo_x;
}

int* Aux_disparo500KG_y() {
    int* arreglo_y = (int*)malloc(121 * sizeof(int));
    int altura = - 6;

    for (int i = 0; i < 121; i++){
        
        
        if (i % 11 == 0 ){
            altura += 1;
        }   

        arreglo_y[i] = altura;   
    }

    return arreglo_y;
}