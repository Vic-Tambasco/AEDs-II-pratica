#ifndef _H_FILA
#define _H_FILA

#include <stdbool.h>

#define TAM 5

typedef struct fila Fila;

Fila* criar_fila();
bool ehCheia(Fila* f);
bool ehVazia(Fila* f);
void push(Fila* f, int valor);
int pop(Fila* f);
int obtem_elemento(Fila* f);
void mostrar_fila(Fila* f);
void liberar_fila(Fila* f);

#endif // _H_FILA
