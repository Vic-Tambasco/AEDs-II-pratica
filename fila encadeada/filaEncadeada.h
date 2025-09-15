#ifndef FILA_H
#define FILA_H

#include <stdbool.h>

typedef struct fila Fila;

Fila* criar_fila();
bool ehVazia(Fila* f);
void push(Fila* f, int valor);
int pop(Fila* f);
int obtem_elemento(Fila* f);
void mostrar_fila(Fila* f);
void liberar_fila(Fila* f);

#endif
