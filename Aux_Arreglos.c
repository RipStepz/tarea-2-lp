#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "Cartas.h"
/*Para entender estas funciones, hay que mirarlos de a pares Aux_TipoDisparo_X y Aux_TipoDisparo_y
estas funciones retornan las coordenadas (x,y) que deberias marcar para la logica del disparo en un array
en este caso retorna las coordenadas (x) que formen un 3x3 al rededor de la coordenada (x,y)
no recibe parametros ni retorna nada 
*/
int* Aux_disparoGrande_x() {
    int* arreglo_x = (int*)malloc(9 * sizeof(int)); // 9 porque 3x3 es 9 coordenadas
    int index = 0;
    int rango = 1; // El rango de x va de -1 a 1

    for (int y = -rango; y <= rango; y++) {
        for (int x = -rango; x <= rango; x++) {
            arreglo_x[index++] = x;
        }
    }

    return arreglo_x;
}
/*Para entender estas funciones, hay que mirarlos de a pares Aux_TipoDisparo_X y Aux_TipoDisparo_y
estas funciones retornan las coordenadas (x,y) que deberias marcar para la logica del disparo en un array
en este caso retorna las coordenadas (y) que formen un 3x3 al rededor de la coordenada (x,y)
no recibe parametros ni retorna nada 
*/
int* Aux_disparoGrande_y() {
   int* arreglo_y = (int*)malloc(9 * sizeof(int)); // 9 porque 3x3 es 9 coordenadas
    int index = 0;
    int rango = 1; // El rango de y va de -1 a 1

    for (int y = -rango; y <= rango; y++) {
        for (int x = -rango; x <= rango; x++) {
            arreglo_y[index++] = y;
        }
    }

    return arreglo_y;
}
/*Para entender estas funciones, hay que mirarlos de a pares Aux_TipoDisparo_X y Aux_TipoDisparo_y
estas funciones retornan las coordenadas (x,y) que deberias marcar para la logica del disparo en un array
en este caso retorna las coordenadas (x) que formen una linea de largo 5 centrada en (x,y)
no recibe parametros ni retorna nada 
*/
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
/*Para entender estas funciones, hay que mirarlos de a pares Aux_TipoDisparo_X y Aux_TipoDisparo_y
estas funciones retornan las coordenadas (x,y) que deberias marcar para la logica del disparo en un array
en este caso retorna las coordenadas (y) que formen una linea de largo 5 centrada en (x,y)
no recibe parametros ni retorna nada 
*/
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
/*Para entender estas funciones, hay que mirarlos de a pares Aux_TipoDisparo_X y Aux_TipoDisparo_y
estas funciones retornan las coordenadas (x,y) que deberias marcar para la logica del disparo en un array
en este caso retorna las coordenadas (x) que formen un 5x5 al rededor de (x,y)
no recibe parametros ni retorna nada 
*/
int* Aux_disparoRadar_x() {

    int* arreglo_x = (int*)malloc(25 * sizeof(int)); // 25 porque 5x5 es 25 coordenadas
    int index = 0;
    int rango = 2; // El rango de x va de -2 a 2

    for (int y = -rango; y <= rango; y++) {
        for (int x = -rango; x <= rango; x++) {
            arreglo_x[index++] = x;
        }
    }

    return arreglo_x;
     
}
/*Para entender estas funciones, hay que mirarlos de a pares Aux_TipoDisparo_X y Aux_TipoDisparo_y
estas funciones retornan las coordenadas (x,y) que deberias marcar para la logica del disparo en un array
en este caso retorna las coordenadas (y) que formen un 5x5 al rededor de (x,y)
no recibe parametros ni retorna nada 
*/
int* Aux_disparoRadar_y() {
    int* arreglo_y = (int*)malloc(25 * sizeof(int)); // 25 porque 5x5 es 25 coordenadas
    int index = 0;
    int rango = 2; // El rango de y va de -2 a 2

    for (int y = -rango; y <= rango; y++) {
        for (int x = -rango; x <= rango; x++) {
            arreglo_y[index++] = y;
        }
    }

    return arreglo_y;
}
/*Para entender estas funciones, hay que mirarlos de a pares Aux_TipoDisparo_X y Aux_TipoDisparo_y
estas funciones retornan las coordenadas (x,y) que deberias marcar para la logica del disparo en un array
en este caso retorna las coordenadas (x) que formen un 11x11 al rededor de (x,y)
no recibe parametros ni retorna nada 
*/
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
/*Para entender estas funciones, hay que mirarlos de a pares Aux_TipoDisparo_X y Aux_TipoDisparo_y
estas funciones retornan las coordenadas (x,y) que deberias marcar para la logica del disparo en un array
en este caso retorna las coordenadas (y) que formen un 11x11 al rededor de (x,y)
no recibe parametros ni retorna nada 
*/
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