#ifndef TABLERO_H
#define TABLERO_H

extern void *** tablero ;
extern int tamano_global;
extern int Dificultad_Tablero;
extern int Arreglo_mano[];
extern int Pos_mano;
extern int Turnos;
extern int Total_Barcos;
extern int Romper_Probabilidad_500kg;

void inicializarTablero (int tamano ) ;
void mostrarTablero () ;
void liberarTablero();
void modificarCelda(int x, int y, char nuevoContenido);

void colocarBarco(int x, int y, int largo, int orientacion, char simbolo);
void colocarBarcosAleatoriamente();

int * ArregloAleatorio();
int Largo_Arreglo();
int Retorno_Matriz();
int* Rangos_Arreglo();
int En_Rango(int x, int y);
void mostrarTableroOculto();

#endif