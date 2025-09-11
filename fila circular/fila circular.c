#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h> 
#include <stdbool.h>
#include "fila.h"

// Definição da estrutura
typedef struct fila {
    int frente;
    int fundo; 
    int tamanho; 
    int items[TAM]; 
} Fila;

// Função para criar uma nova fila
Fila* criar_fila() {
    Fila* f = (Fila*)malloc(sizeof(Fila));
    f->frente = -1;
    f->fundo = -1;
    f->tamanho = 0;
    return f;
}

// Função para verificar se a fila está cheia
bool ehCheia(Fila* f) { 
    return (f->tamanho == TAM);
} 

// Função para verificar se a fila está vazia
bool ehVazia(Fila* f) { 
    return (f->tamanho == 0);
} 

// Função para adicionar um elemento no fim da fila
void push(Fila* f, int valor) { 
    if (ehCheia(f)) {
        printf("\nFila cheia. Impossível inserir elementos");
        return; 
    }
    
    if (ehVazia(f)) {
        f->frente = 0;
        f->fundo = 0;
    } else {
        f->fundo = (f->fundo + 1) % TAM;
    }
    
    f->items[f->fundo] = valor;
    f->tamanho++;
    printf("\nItem %d inserido com sucesso", valor);
}

// Função para remover e retornar o elemento do início da fila
int pop(Fila* f) { 
    if (ehVazia(f)) {
        printf("\nFila vazia. Impossível remover elementos");
        return -1; 
    }
    
    int valorRemov = f->items[f->frente];
    
    if (f->frente == f->fundo) {
        f->frente = -1;
        f->fundo = -1;
    } else {
        f->frente = (f->frente + 1) % TAM;
    }
    
    f->tamanho--;
    printf("\nValor %d removido com sucesso", valorRemov);
    return valorRemov;
} 

// Função para obter o elemento do início da fila sem removê-lo
int obtem_elemento(Fila* f) { 
    if (ehVazia(f)) {
        printf("\nFila vazia. Impossível obter elementos");
        return INT_MIN; 
    }
    return f->items[f->frente]; 
} 

// Função para mostrar todos os elementos da fila
void mostrar_fila(Fila* f) {
    if (ehVazia(f)) {
        printf("\nFila vazia");
        return;
    }
    
    printf("\nFila (frente -> fundo): ");
    int i = f->frente;
    int count = 0;
    
    while (count < f->tamanho) {
        printf("%d ", f->items[i]);
        i = (i + 1) % TAM;
        count++;
    }
}

// Função para liberar a memória alocada para a fila
void liberar_fila(Fila* f) {
    free(f);
    printf("\nFila liberada da memória");
}

int main() { 
    int val, n;
    bool aux;
    
    // Cria fila
    Fila* fila = criar_fila();
    
    do {
        printf("\n\n************************* MENU ************************");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Obtém elemento");
        printf("\n4. Fila vazia?");
        printf("\n5. Fila cheia?");
        printf("\n6. Mostrar fila");
        printf("\n7. Liberar fila");
        printf("\n0. Sair");
        printf("\nDigite sua escolha: ");
        scanf("%d",&n);
        
        switch(n) {
            case 1: 
                printf("\nDigite o valor: ");
                scanf("%d",&val);
                push(fila, val);
                break;
                
            case 2: 
                val = pop(fila);
                if (val != -1) {
                    printf("\nElemento retirado: %d", val);
                }
                break;
                
            case 3: 
               val = obtem_elemento(fila);
                if (val != INT_MIN) {
                    printf("\nPrimeiro elemento: %d", val);
                }
                break;
                
            case 4: 
                aux = ehVazia(fila);
                if (aux) {
                    printf("\nFila vazia");
                } else {
                    printf("\nFila não está vazia");
                }
                break;
                
            case 5: 
                aux = ehCheia(fila);
                if (aux) {
                    printf("\nFila cheia");
                } else {
                    printf("\nFila não está cheia");
                }
                break;
                
            case 6:
                mostrar_fila(fila);
                break;
                
            case 7:
                liberar_fila(fila);
                fila = criar_fila();
                break;
                
            case 0:
                liberar_fila(fila);
                printf("\nSaindo...");
                return 0;
                
            default: 
                printf("\nOpção inválida!");
                break;
        }
    } while(1);
    
    return 0;
}
