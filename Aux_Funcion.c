#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "Tablero.h"

int Turnos;
/* Esta funcion retorna un arreglo que su largo depende de la dificultad
Este arreglo se llena de numeros del 1 al 4 aleatoreamente que represetan las 4 dirrecciones
en las que se puede poner un barco
no recibe parametros ni retorna nada
*/
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
/* Esta funcion se usa para primero Guardar en una varieble global la
cantidad de turnos que tendra el juego dependiendo de la dificultad elegida

no recibe parametros y retorna el tamaño del tablero dependiendo de la dificultar
(usado para inicializar el tablero)
*/
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
/* Esta funcion se usa para primero Guardar en una varieble global la
cantidad de turnos que tendra el juego dependiendo de la dificultad elegida

no recibe parametros y retorna el tamaño del tablero dependiendo de la dificultar
(usado para inicializar el tablero)
*/
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
/*Simplente retorna true si las coordenadas estan dentro del tablero o no
usado para control de errores
recibe como parametro las coordenadas (x,y) y retorna 1 (true) en caso de estar en rango
0 (false) en caso de no estarlo
*/
int En_Rango(int x, int y){

    if (x < 1 || x > tamano_global || y < 1 || y > tamano_global){
        return 0;
    }
    else{
        return 1;
    }
}
/* Genera de manera semialeatoria la nueva carta dependiendo de
las condiciones de DisparoSimple
no recibe parametros ni retorna nada
*/
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
/* Genera de manera semialeatoria la nueva carta dependiendo de
las condiciones de DisparoGrande
no recibe parametros ni retorna nada
*/
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
/* Genera de manera semialeatoria la nueva carta dependiendo de
las condiciones de DisparoLineal
no recibe parametros ni retorna nada
*/
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
/* Genera de manera semialeatoria la nueva carta dependiendo de
las condiciones de DisparoRadar
no recibe parametros ni retorna nada
*/
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