# Automatizando o makefile

# Nome do projeto
PROJ_NAME=filaEncadeada

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

%.o: %.c
	$(CC) $(CC_FLAGS) -o $@ $<

main.o: main.c $(H_SOURCE)
	$(CC) $(CC_FLAGS) -o $@ $<

clean:
	rm -rf *.o $(PROJ_NAME) *~
