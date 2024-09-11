Arturo ALmonacid 
202373515-9
Para compilar se debe usar la siguiente secuencia de comandos:
gcc -c CityDefender.c -o CityDefender.o
gcc -c Tablero.c -o Tablero.o
gcc -c Aux_Funcion.c -o Aux_Funcion.o
gcc -c Cartas.c -o Cartas.o
gcc -c Aux_Arreglos.c -o Aux_Arreglos.o
gcc CityDefender.o Tablero.o Aux_Funcion.o Cartas.o Aux_Arreglos.o -o CityDefender

Otra opcion es make ya que el Makefile esta implementado

y para correrlo se debe usar ./CityDefender