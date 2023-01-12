CC = g++
CFLAGS = -g -w -Wall -Werror -pedantic
OBJ = CircularBuffer.o StringSound.o KSGuitarSim.o
SFML = -lsfml-audio -lsfml-window -lsfml-graphics -lsfml-system
KSGuitarSim: $(OBJ)
	$(CC) $(CFLAGS) -o KSGuitarSim $(OBJ) $(SFML)
all: KSGuitarSim
CircularBuffer.o: CircularBuffer.cpp CircularBuffer.h
	$(CC) $(CFLAGS) -c CircularBuffer.cpp
StringSound.o: StringSound.cpp StringSound.h
	$(CC) $(CFLAGS) -c StringSound.cpp
KSGuitarSim.o: KSGuitarSim.cpp
	$(CC) $(CFLAGS) -c KSGuitarSim.cpp $(SFML)
clean:
	rm KSGuitarSim *.o
