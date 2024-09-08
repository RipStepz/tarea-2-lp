#include "Tablero.h"
#include "Cartas.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int Dificultad_Tablero;

int main(){

    printf("Introduzca la dificultad deseada: ");
    scanf("%d", &Dificultad_Tablero); // Lee un entero y lo guarda en la variable 'numero'
    
    inicializarTablero (Retorno_Matriz());
    colocarBarcosAleatoriamente();
    
    // strcpy((char *)tablero[1][2], "X");  // Copiamos "X" en la celda (1,2)
    // char *i = (char *)tablero[1][2];  // Convertimos el puntero a char*
    
    // if (strcmp(i, "X") == 0){
    // printf("En (1,2) esta el caracter : %s \n", (char *)tablero[1][2]);
    // }
    // int x,y;

    // printf("Introduzca dos numeros ");
    // scanf("%d %d", &x , &y);
    // printf("Introduzca dos numeros\n\n ");

    disparo500KG(5,5);

    mostrarTablero();
    liberarTablero(tamano_global);
    return 0;
}