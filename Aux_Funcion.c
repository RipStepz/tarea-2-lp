#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "Tablero.h"

int Turnos;

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
        Turnos = 30;
        return 11;
    }
    else if (Dificultad_Tablero == 2){
        Turnos = 25;
        
        return 17;
    }
    else{
        Turnos = 15;
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

int *generarCarta_Simple() {
    
    int numero_aleatorio;
    int *retorno = malloc(sizeof(int));
    srand(time(NULL));
    numero_aleatorio = rand() % 100;
    
    if (numero_aleatorio < 65) {           // 65% para disparoSimple
        *retorno = 1;
        return retorno;
    } else if (numero_aleatorio < 85) {    // 20% para disparoGrande
        *retorno = 2;
        return retorno;
    } else if (numero_aleatorio < 90) {    // 5% para disparoLineal
        *retorno = 3;
        return retorno;
    } else {                               // 10% para disparoRadar
        *retorno = 4;
        return retorno;
    }
}

int *generarCarta_Grande() {
    
    int numero_aleatorio;
    int *retorno = malloc(sizeof(int));
    srand(time(NULL));
    numero_aleatorio = rand() % 100;
    
    if (numero_aleatorio < 80) {            // 80% para disparoSimple
        *retorno = 1;
        return retorno;
    } else if (numero_aleatorio < 83) {     // 3% para disparoGrande
        *retorno = 2;
        return retorno;;
    } else if (numero_aleatorio < 93) {     // 10% para disparoLineal
        *retorno = 3;
        return retorno;
    } else if (numero_aleatorio < 98) {     // 5% para disparoRadar
        *retorno = 4;
        return retorno;
    } else {                                // 2% para disparo500KG
        *retorno = 5;
        return retorno;
    }
}

int *generarCarta_Lineal() {
    
    int numero_aleatorio;
    int *retorno = malloc(sizeof(int));
    srand(time(NULL));
    numero_aleatorio = rand() % 100;
    
    if (numero_aleatorio < 85) {            // 85% para disparoSimple
        *retorno = 1;
        return retorno;
    } else if (numero_aleatorio < 90) {     // 5% para disparoGrande
        *retorno = 2;
        return retorno;
    } else if (numero_aleatorio < 92) {     // 2% para disparoLineal
        *retorno = 3;
        return retorno;
    } else if (numero_aleatorio < 98) {     // 6% para disparoRadar
        *retorno = 4;
        return retorno;
    } else {                                // 2% para disparo500KG
        *retorno = 5;
        return retorno;
    }
}

int *generarCarta_Radar() {
    int numero_aleatorio;
    int *retorno = malloc(sizeof(int));
    
    // Inicializar generador de números aleatorios
    srand(time(NULL));
    
    // Generar un número entre 0 y 99
    numero_aleatorio = rand() % 100;
    
    // Asignar una carta según los porcentajes
    if (numero_aleatorio < 75) {            // 75% para disparoSimple
        *retorno = 1;
        return retorno;
    } else if (numero_aleatorio < 90) {     // 15% para disparoGrande
        *retorno = 2;
        return retorno;
    } else if (numero_aleatorio < 95) {     // 5% para disparoLineal
        *retorno = 3;
        return retorno;
    } else if (numero_aleatorio < 97) {     // 2% para disparoRadar
        *retorno = 4;
        return retorno;
    } else {                                // 3% para disparo500KG
        *retorno = 5;
        return retorno;
    }
}