CC		:= g++
CFLAGS	:= `sdl2-config --libs --cflags`
LDFLAGS := -lSDL2
LDLIBS  :=

%.x: %.o
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

all: chess.x

#Zadanie 1 obsluga
chess.x: chess.o initialization.o
chess.o: chess.cpp initialization.hpp
initialization.o: initialization.cpp


.PHONY: clean tar

clean:                                                     
	rm -f *.o  *~ *.a *.so *.x core core* a.out;