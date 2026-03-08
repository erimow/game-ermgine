CC = gcc
CFLAGS = -Wall -Wextra -std=c11
#LIBS = -lSDL3 -lSDL3_image -lm

SRC = main.c $(shell find Engine Scripts -name "*.c")

game:
	$(CC) $(SRC) $(CFLAGS) -IEngine -IArt -IScripts -IFonts -o game $(LIBS)

clean:
	rm -f game