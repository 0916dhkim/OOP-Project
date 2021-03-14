CC=g++
CFLAGS=-I. -Wall -Werror -std=c++0x -ggdb
OBJ=Time.o ms1Tester.o utils.o

%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

ws.out: $(OBJ)
	$(CC) $(OBJ) -o ws.out

.PHONY: clean

clean:
	rm *.o ws.out

