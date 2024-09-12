CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJ = CityDefender.o Tablero.o Aux_Funcion.o Cartas.o Aux_Arreglos.o
TARGET = CityDefender

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

CityDefender.o: CityDefender.c
	$(CC) $(CFLAGS) -c CityDefender.c -o CityDefender.o

Tablero.o: Tablero.c
	$(CC) $(CFLAGS) -c Tablero.c -o Tablero.o

Aux_Funcion.o: Aux_Funcion.c
	$(CC) $(CFLAGS) -c Aux_Funcion.c -o Aux_Funcion.o

Cartas.o: Cartas.c
	$(CC) $(CFLAGS) -c Cartas.c -o Cartas.o

Aux_Arreglos.o: Aux_Arreglos.c
	$(CC) $(CFLAGS) -c Aux_Arreglos.c -o Aux_Arreglos.o

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean