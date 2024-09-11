# Variables
CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJ = CityDefender.o Tablero.o Aux_Funcion.o Cartas.o Aux_Arreglos.o
TARGET = CityDefender

# Regla principal
all: $(TARGET)

# Regla para enlazar el ejecutable final
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

# Reglas para compilar cada archivo .c en un archivo .o
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

# Regla para limpiar archivos generados
clean:
	rm -f $(OBJ) $(TARGET)

# Regla para forzar recompilación de todo
.PHONY: all clean