CC=g++
CFLAGS=-I. -Wall -Werror -std=c++0x -ggdb
OBJ=Menu.o ms2Tester.o utils.o Time.o IOAble.o

%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

ws.out: $(OBJ)
	$(CC) $(OBJ) -o ws.out

.PHONY: clean

clean:
	rm *.o ws.out

