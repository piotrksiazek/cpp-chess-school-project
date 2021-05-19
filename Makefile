CC		:= g++
CFLAGS	:= `sdl2-config --libs --cflags`
LDFLAGS := -lSDL2 -lSDL2_image
LDLIBS  :=

%.x: %.o
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

all: chess.x


chess.x: chess.o initialization.o board.o square.o utils.o piece.o king.o controller.o
controller.o: controller.cpp board.hpp
chess.o: chess.cpp initialization.hpp constants.hpp utils.hpp square.hpp board.hpp
utils.o: utils.cpp constants.hpp square.hpp board.hpp
initialization.o: initialization.cpp
board.o: board.cpp constants.hpp square.hpp king.hpp piece.hpp
square.o: square.cpp constants.hpp piece.hpp
piece.o: piece.cpp constants.hpp
king.o: king.cpp piece.hpp

.PHONY: clean tar

clean:                                                     
	rm -f *.o  *~ *.a *.so *.x core core* a.out;