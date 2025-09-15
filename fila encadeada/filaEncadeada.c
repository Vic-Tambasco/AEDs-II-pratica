#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include "filaEncadeada.h"

// Definição da estrutura do nó
typedef struct no {
    int valor;
    struct no* proximo;
} No;

// Definição da estrutura da fila
struct fila {
    No* frente;
    No* fundo;
    int tamanho;
};

// Função para criar uma nova fila
Fila* criar_fila() {
    Fila* f = (Fila*)malloc(sizeof(Fila));
    f->frente = NULL;
    f->fundo = NULL;
    f->tamanho = 0;
    return f;
}

// Função para verificar se a fila está vazia
bool ehVazia(Fila* f) {
    return (f->frente == NULL);
}

// Função para adicionar um elemento no fim da fila
void push(Fila* f, int valor) {
    No* novo_no = (No*)malloc(sizeof(No));
    if (novo_no == NULL) {
        printf("\nErro de memória. Impossível inserir elementos");
        return;
    }
    
    novo_no->valor = valor;
    novo_no->proximo = NULL;
    
    if (ehVazia(f)) {
        f->frente = novo_no;
        f->fundo = novo_no;
    } else {
        f->fundo->proximo = novo_no;
        f->fundo = novo_no;
    }
    
    f->tamanho++;
    printf("\nItem %d inserido com sucesso", valor);
}

// Função para remover e retornar o elemento do início da fila
int pop(Fila* f) {
    if (ehVazia(f)) {
        printf("\nFila vazia. Impossível remover elementos");
        return -1;
    }
    
    No* temp = f->frente;
    int valorRemov = temp->valor;
    
    f->frente = f->frente->proximo;
    
    if (f->frente == NULL) {
        f->fundo = NULL;
    }
    
    free(temp);
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
    return f->frente->valor;
}

// Função para mostrar todos os elementos da fila
void mostrar_fila(Fila* f) {
    if (ehVazia(f)) {
        printf("\nFila vazia");
        return;
    }
    
    printf("\nFila (frente -> fundo): ");
    No* atual = f->frente;
    
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
}

// Função para liberar a memória alocada para a fila
void liberar_fila(Fila* f) {
    while (!ehVazia(f)) {
        pop(f);
    }
    free(f);
    printf("\nFila liberada da memória");
}

int main() {
    int val, n;
    bool aux;
    
    Fila* fila = criar_fila();
    
    do {
        printf("\n\n************************* MENU ************************");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Obtém elemento");
        printf("\n4. Fila vazia?");
        printf("\n5. Mostrar fila");
        printf("\n6. Liberar fila");
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
                mostrar_fila(fila);
                break;
                
            case 6:
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
