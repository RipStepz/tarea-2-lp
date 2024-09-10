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

int generarCarta_Simple() {
    
    int numero_aleatorio;
    srand(time(NULL));
    numero_aleatorio = rand() % 100;
    
    if (numero_aleatorio < 65) {           // 65% para disparoSimple
        return 1;
    } else if (numero_aleatorio < 85) {    // 20% para disparoGrande
        return 2;
    } else if (numero_aleatorio < 90) {    // 5% para disparoLineal
        return 3;
    } else {                               // 10% para disparoRadar
        return 4;
    }
}

int generarCarta_Grande() {
    
    int numero_aleatorio;
    srand(time(NULL));
    numero_aleatorio = rand() % 100;
    
    if (numero_aleatorio < 80) {            // 80% para disparoSimple
        return 1;
    } else if (numero_aleatorio < 83) {     // 3% para disparoGrande
        return 2;
    } else if (numero_aleatorio < 93) {     // 10% para disparoLineal
        return 3;
    } else if (numero_aleatorio < 98) {     // 5% para disparoRadar
        return 4;
    } else {                                // 2% para disparo500KG
        return 5;
    }
}

int generarCarta_Lineal() {
    
    int numero_aleatorio;
    srand(time(NULL));
    numero_aleatorio = rand() % 100;
    
    if (numero_aleatorio < 85) {            // 85% para disparoSimple
        return 1;
    } else if (numero_aleatorio < 90) {     // 5% para disparoGrande
        return 2;
    } else if (numero_aleatorio < 92) {     // 2% para disparoLineal
        return 3;
    } else if (numero_aleatorio < 98) {     // 6% para disparoRadar
        return 4;
    } else {                                // 2% para disparo500KG
        return 5;
    }
}

int generarCarta_Radar() {
    int numero_aleatorio;
    
    // Inicializar generador de números aleatorios
    srand(time(NULL));
    
    // Generar un número entre 0 y 99
    numero_aleatorio = rand() % 100;
    
    // Asignar una carta según los porcentajes
    if (numero_aleatorio < 75) {            // 75% para disparoSimple
        return 1;
    } else if (numero_aleatorio < 90) {     // 15% para disparoGrande
        return 2;
    } else if (numero_aleatorio < 95) {     // 5% para disparoLineal
        return 3;
    } else if (numero_aleatorio < 97) {     // 2% para disparoRadar
        return 4;
    } else {                                // 3% para disparo500KG
        return 5;
    }
}

int En_Rango(int x, int y);



// int * Anti_colision(int x, int y, int direccion, int largo) {
    
//     int* nuevas_coordenadas = (int*)malloc(2 * sizeof(int));  
//     nuevas_coordenadas[0] = x;
//     nuevas_coordenadas[1] = y;
//     srand(time(NULL));

//     int colision = 0;  // Variable para detectar colisiones
//     int limite = largo - 1;

//     // Verificar si hay colisiones según la dirección
//     if (direccion == 1) {  // Izquierda
//         for (int i = 0; i < largo; i++) {
//             if (En_Rango(x - i, y) && *(char *)tablero[x -i -1][y -1] != ' ') {
//                 colision = 1;
//                 break;
//             }
//         }
//     } else if (direccion == 2) {  // Derecha
//         for (int i = 0; i < largo; i++) {
//             if (En_Rango(x + i, y) && *(char *)tablero[x + i -1][y -1] != ' ') {
//                 colision = 1;
//                 break;
//             }
//         }
//     } else if (direccion == 3) {  // Abajo
//         for (int i = 0; i < largo; i++) {
//             if (En_Rango(x, y + i) && *(char *)tablero[x -1][y+  i - 1] != ' ') {
//                 colision = 1;
//                 break;
//             }
//         }
//     } else if (direccion == 4) {  // Arriba
//         for (int i = 0; i < largo; i++) {
//             if (En_Rango(x, y - i) && *(char *)tablero[x-1][y - i - 1] != ' ') {
//                 colision = 1;
//                 break;
//             }
//         }
//     }

//     // Si no hay colisión, retornar las mismas coordenadas
//     if (!colision) {
//         return nuevas_coordenadas;  // No hay colisiones, las coordenadas son válidas
//     }

//     // Si hay colisión, probar con nuevas coordenadas aleatorias hasta que no haya colisiones
//     while (colision) {
//         colision = 0;  // Reiniciar el estado de colisión

//         // Generar nuevas coordenadas aleatorias
//         x = 1 + rand() % tamano_global;
//         y = 1 + rand() % tamano_global;

//         // Verificar la nueva dirección
//         if (direccion == 1) {  // Izquierda
//             for (int i = 0; i < largo; i++) {
//                 if (En_Rango(x - i, y) && *(char *)tablero[x -i -1][y-1] != ' ') {
//                     colision = 1;
//                     break;
//                 }
//             }
//         } else if (direccion == 2) {  // Derecha
//             for (int i = 0; i < largo; i++) {
//                 if (En_Rango(x + i, y) && *(char *)tablero[x +i -1][y-1] != ' ') {
//                     colision = 1;
//                     break;
//                 }
//             }
//         } else if (direccion == 3) {  // Abajo
//             for (int i = 0; i < largo; i++) {
//                 if (En_Rango(x, y + i) && *(char *)tablero[x -i -1][y + i -1] != ' ') {
//                     colision = 1;
//                     break;
//                 }
//             }
//         } else if (direccion == 4) {  // Arriba
//             for (int i = 0; i < largo; i++) {
//                 if (En_Rango(x, y - i) && *(char *)tablero[x -i -1][y - i -1] != ' ') {
//                     colision = 1;
//                     break;
//                 }
//             }
//         }
//     }

//     // Guardar y devolver las nuevas coordenadas sin colisiones
//     nuevas_coordenadas[0] = x;
//     nuevas_coordenadas[1] = y;
//     return nuevas_coordenadas;
// }