#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h> 
#include <stdbool.h>
#include "fila circular.h"

#define TAM 5

struct fila{ 
	int frente;
    int fundo; 
	int tamanho; 
	int items[TAM]; 
}; 

struct fila criar_fila() { 
    struct fila f;
    f.frente = -1;
    f.fundo = -1;
    f.tamanho = 0; 
	return f; 
} 

bool ehCheia(struct fila* f) { 
    return (f ->tamanho == TAM);
} 

bool ehVazia(struct fila* f) { 
    return (f->tamanho == 0);
} 

void push(struct fila* f, int item) { 
    if (ehCheia(f)) {
		printf("\nFila cheia. Impossível inserir elementos");
        return; 
    }
    if(ehVazia(f)){
        f->frente = 0;
        f->fundo = 0;
    }else{
        f-> fundo = (f-> fundo + 1)%TAM;
    }
    f->items [f->fundo] = item;
    f->tamanho++;
    printf("\nElemento %d inserido no fim da fila com sucesso", item);
}


int pop(struct fila* f) { 
    if (ehVazia(f)) {
		printf("\nFila  vazia. Impossível remover elementos");
        return -1; 
    }
	int item = f-> items[f->fundo];
    if(f-> frente == f->fundo){
        f->frente = -1;
        f->fundo = -1;

    }else{
        f->frente = (f->frente + 1)%TAM;
    }
    f->tamanho--;
    return item;
} 

int obtem_elemento(struct fila* f) { 
	// Se a pilha estiver vazia, não tem como obter nenhum elemento
    if (ehVazia(f)) {
		printf("\nFila vazia. Impossível obter elementos");
        return INT_MIN; 
    }
	return f->items[f->frente]; 
} 


int main() { 
    int val, n;
    bool aux;
    // Cria pilha com 5 posições
    struct fila f = criar_fila(); 
    do {
        printf("\n************************* MENU ************************");
	    printf("\n1. Push");
	    printf("\n2. Pop");
	    printf("\n3. Obtém elemento");
	    printf("\n4. Fila vazia?");
      printf("\n5. Fila cheia?");
	    printf("\n6. Sair");
	    printf("\n Digite sua escolha : ");
	    scanf("%d",&n);
	    switch(n) {
            case 1: 
		        printf("\nDigite o valor ");
                scanf("%d",&val);
                push(&f , val);
                break;
            case 2: 
                val = pop(&f);
                if(val != -1){
                    printf("\nElemento removido no início: %d", val);
                }
                break;
            case 3: 
                val = obtem_elemento(&f);
                if(val != INT_MIN){
                    printf("\nPrimeiro elemento: %d", val);
                }
                break;
            case 4: 
                aux = ehVazia(&f);
                if (aux) {
                    printf("\nFila vazia");
                } else {
                    printf("\nFila não está vazia");
                }
                break;
            case 5: 
                aux = ehCheia(&f);
                if (aux) {
                    printf("\nFila cheia");
                } else {
                    printf("\nFila não está cheia");
                }
                break;         
            case 6:
                return (1);
                break;
            default: printf("\nOpção errada!");
                break;
        }
	} while(1);
    
    return (0);
 }




