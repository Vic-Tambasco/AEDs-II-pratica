# Automatizando o makefile

# Nome do projeto
PROJ_NAME=fila

# Arquivos .c
C_SOURCE=$(wildcard *.c)

# Arquivos .h
H_SOURCE=$(wildcard *.h)

# Arquivos objeto
OBJ=$(C_SOURCE:.c=.o)

# Compilador
CC=gcc

# Flags (opções) para o compilador
CC_FLAGS=-c         \
         -Wall      \
         -g         \
         -pedantic

#########################
# Compilação e linkagem #
#########################
all: $(PROJ_NAME)

$(PROJ_NAME): $(OBJ)
	$(CC) -o $@ $^

%.o: %.c %.h
	$(CC) -o $@ $< $(CC_FLAGS)

main.o: fila.c $(H_SOURCE)
	$(CC) -o $@ $< $(CC_FLAGS)

clean:
	rm -rf *.o $(PROJ_NAME) *~

# Regra para rodar o programa após compilar
run: all
	./$(PROJ_NAME)

# Regra para compilar e rodar em sequência
build-and-run: clean all run

# Regra para debug (usando gdb)
debug: all
	gdb ./$(PROJ_NAME)

.PHONY: all clean run build-and-run debug
