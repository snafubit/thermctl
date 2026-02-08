CC = gcc
CFLAGS = -Wall -Wextra -std=c11

SRC = src/main.c src/thermal.c
OUT = tempguard

all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

run: all
	./$(OUT)

clean:
	rm -f $(OUT)
