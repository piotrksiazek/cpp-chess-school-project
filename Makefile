CC		:= g++
CFLAGS	:= `sdl2-config --libs --cflags`
LDFLAGS := -lSDL2
LDLIBS  :=

%.x: %.o
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

all: chess

#Zadanie 1 obsluga
chess: initialization.o
initialization.o: initialization.cpp


.PHONY: clean tar

clean:                                                     
	rm -f *.o  *~ *.a *.so *.x core core* a.out;