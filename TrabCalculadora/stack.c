#include "stack.h"
#include <stdio.h>

void initStack(Stack *s) {
    s->top = -1; // Inicializa o topo da pilha
}

int isEmpty(Stack *s) {
    return s->top == -1; // Verifica se a pilha está vazia
}

int isFull(Stack *s) {
    return s->top == MAX - 1; // Verifica se a pilha está cheia
}

void push(Stack *s, double value) {
    if (!isFull(s)) {
        s->items[++(s->top)] = value; // Empilha o valor
    } else {
        printf("Pilha está cheia\n"); // Mensagem de erro se a pilha estiver cheia
    }
}

double pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->items[(s->top)--]; // Desempilha e retorna o valor
    } else {
        printf("Pilha está vazia\n"); // Mensagem de erro se a pilha estiver vazia
        return -1; // Valor de erro
    }
}
