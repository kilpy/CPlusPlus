CC = g++
CFLAGS = -g -w -Wall -Werror -pedantic
OBJ = main.o
REGEX = -lboost_date_time
ps6: $(OBJ)
	$(CC) $(CFLAGS) -o ps6 $(OBJ) $(REGEX)
all: ps3a
main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp $(REGEX)
clean:
	rm ps6 *.o
