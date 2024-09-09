#ifndef TABLERO_H
#define TABLERO_H

extern void *** tablero ;
extern int tamano_global;
extern int Dificultad_Tablero;
extern int Arreglo_mano[];
extern int Pos_mano;
extern int Turnos;

void inicializarTablero (int tamano ) ;
void mostrarTablero () ;
void liberarTablero();
void modificarCelda(int fila, int columna, const char *nuevoContenido);

void colocarBarco(int x, int y, int largo, int orientacion, const char *simbolo);
void colocarBarcosAleatoriamente();

int * ArregloAleatorio();
int Largo_Arreglo();
int Retorno_Matriz();
int* Rangos_Arreglo();
int En_Rango(int x, int y);

#endif