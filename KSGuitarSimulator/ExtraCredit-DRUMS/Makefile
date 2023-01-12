CC = g++
CFLAGS = -g -w -Wall -Werror -pedantic
OBJ = CircularBuffer.o
GUITAR = StringSound.o KSGuitarSim.o
DRUM = DrumSound.o KSDrumSim.o
SFML = -lsfml-audio -lsfml-window -lsfml-graphics -lsfml-system
KSDrumSim: $(OBJ) $(DRUM)
	$(CC) $(CFLAGS) -o KSDrumSim $(OBJ) $(DRUM) $(SFML)
KSGuitarSim: $(OBJ) $(GUITAR)
	$(CC) $(CFLAGS) -o KSGuitarSim $(OBJ) $(GUITAR) $(SFML)
all: KSGuitarSim KSGuitarSim
CircularBuffer.o: CircularBuffer.cpp CircularBuffer.h
	$(CC) $(CFLAGS) -c CircularBuffer.cpp
StringSound.o: StringSound.cpp StringSound.h
	$(CC) $(CFLAGS) -c StringSound.cpp
KSGuitarSim.o: KSGuitarSim.cpp
	$(CC) $(CFLAGS) -c KSGuitarSim.cpp $(SFML)
KSDrumSim.o: KSDrumSim.cpp
	$(CC) $(CFLAGS) -c KSDrumSim.cpp $(SFML)
DrumSound.o: DrumSound.cpp DrumSound.h
	$(CC) $(CFLAGS) -c DrumSound.cpp
clean:
	rm KSGuitarSim KSDrumSim *.o
