CC		:= g++
CFLAGS	:= `sdl2-config --libs --cflags`
LDFLAGS := -lSDL2
LDLIBS  :=

%.x: %.o
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

all: chess.x


chess.x: chess.o initialization.o board.o square.o
chess.o: chess.cpp initialization.hpp constants.hpp
initialization.o: initialization.cpp
board.o: board.cpp constants.hpp square.hpp
square.o: square.cpp constants.hpp 


.PHONY: clean tar

clean:                                                     
	rm -f *.o  *~ *.a *.so *.x core core* a.out;