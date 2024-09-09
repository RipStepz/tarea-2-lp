#include "Tablero.h"
#include "Cartas.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int Dificultad_Tablero;

int main(){

    printf("Selecciona la Dificultad:\n");
    printf("1. Facil  -> 11 X 11 , 5 Barcos\n");
    printf("2. Medio  -> 17 X 17 , 7 Barcos\n");
    printf("3. Dificil -> 21 X 21 , 9 Barcos\n");
    printf("Ingrese numero: ");
    scanf("%d", &Dificultad_Tablero); // Lee un entero y lo guarda en la variable 'numero'
    
    inicializarTablero (Retorno_Matriz());
    inicializarMano();
    colocarBarcosAleatoriamente();
    mostrarTablero();
    mostrarMano();
    liberarTablero(tamano_global);
    
    // strcpy((char *)tablero[1][2], "X");  // Copiamos "X" en la celda (1,2)
    // char *i = (char *)tablero[1][2];  // Convertimos el puntero a char*
    
    // if (strcmp(i, "X") == 0){
    // printf("En (1,2) esta el caracter : %s \n", (char *)tablero[1][2]);
    // }
    // int x,y;

    // printf("Introduzca dos numeros ");
    // scanf("%d %d", &x , &y);
    // printf("Introduzca dos numeros\n\n ");


    
    return 0;
}