CC = gcc
CFLAGS = -Wall -Wextra -g3
SRC = src/main.c src/inventory.c
OBJ = obj/main.o obj/inventory.o
BIN = bin/main.exe

# A regra padrão que será executada com 'mingw32-make'
all: $(BIN)

# Como criar o binário (main.exe) a partir dos arquivos objetos (.o)
$(BIN): $(OBJ)
	$(CC) $(OBJ) -o $(BIN)

# Como compilar os arquivos .c em arquivos .o
obj/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpeza dos arquivos gerados
clean:
	rm -rf obj/* bin/*
