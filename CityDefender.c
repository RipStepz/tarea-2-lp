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
    printf("Ingrese un numero: \n");
    scanf("%d", &Dificultad_Tablero); // Lee un entero y lo guarda en la variable 'numero'
    while (Dificultad_Tablero < 1 || Dificultad_Tablero > 3){
        printf("Dificultad invalida, favor ingresar nueva");
        printf("Ingrese un numero: ");
        scanf("%d", &Dificultad_Tablero);
        printf("\n");
    }
    
    
    inicializarTablero (Retorno_Matriz());
    inicializarMano();
    colocarBarcosAleatoriamente();

    for (int i = 1; i <= Turnos; i++){
        printf("Turno %d\n", i);
        mostrarTablero();
        mostrarTableroOculto();
        //mostrarMano();
        usarCarta();
        printf("Quedan %d barcos \n", Total_Barcos);
        if (Total_Barcos == 0){
            printf("Ganaste, has hundido todos los barcos\n");
            mostrarTablero();
            break;
        } 
    }

    if (Total_Barcos !=0){
        printf("Perdiste\n");
        mostrarTablero();
    }
    liberarTablero(tamano_global);
    return 0;
}