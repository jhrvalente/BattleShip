CFLAGS = $(shell pkg-config --cflags gtk+-3.0)
LDFLAGS = $(shell pkg-config --libs gtk+-3.0)

all: battleShip

battleShip: window.o board.o events.o termInit.o main.o
	gcc -o $@ $^ ${LDFLAGS}

clean: window.o board.o events.o termInit.o main.o
	rm -rf $^