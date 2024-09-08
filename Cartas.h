#ifndef CARTAS_H
#define CARTAS_H

typedef struct Mano {
    void ** carta ;
    int disponibles ;
 } Mano ;

extern Mano Cartas ;
void inicializarMano () ;
void mostrarMano () ;
void usarCarta () ;

void * disparoSimple (int x , int y );
void * disparoGrande (int x , int y );
void * disparoLineal (int x , int y );
void * disparoRadar (int x , int y ) ;
void * disparo500KG (int x , int y ) ;

int* Aux_disparoGrande_x();
int* Aux_disparoGrande_y ();

int* Aux_disparoLineal_x(int i);
int* Aux_disparoLineal_y(int i);

int* Aux_disparoRadar_x();
int* Aux_disparoRadar_y();

int* Aux_disparo500KG_x();
int* Aux_disparo500KG_y();

#endif