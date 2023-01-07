CC = g++
CFLAGS = -Wall -Werror -pedantic
SFML = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
OBJ = CelestialBody.o NBody.o Universe.o

ps2a: $(OBJ)
	$(CC) $(CFLAGS) -o ps2a $(OBJ) $(SFML)
	$(CC) $(CFLAGS) -o NBody NBody.o  $(SFML)
all: NBody
CelestialBody.o: CelestialBody.cpp
	$(CC) $(CFLAGS) CelestialBody.cpp -c $(SFML)
NBody.o: NBody.cpp
	$(CC) $(CFLAGS) NBody.cpp -c $(SFML)
Universe.o: Universe.cpp
	$(CC) $(CFLAGS) Universe.cpp -c $(SFML)
clean:
	rm NBody *.o
