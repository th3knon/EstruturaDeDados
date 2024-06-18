#include "postfix_evaluator.h"
#include "stack.h"
#include "operations.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

double evaluatePostfix(char* expression) {
    Stack stack;
    initStack(&stack); // Inicializa a pilha
    char* token = strtok(expression, " "); // Divide a expressão em tokens
    while (token != NULL) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            push(&stack, atof(token)); // Converte o token em número e empilha
        } else {
            double val2 = pop(&stack); // Desempilha o segundo operando
            double val1 = pop(&stack); // Desempilha o primeiro operando
            switch (token[0]) {
                case '+': push(&stack, add(val1, val2)); break;
                case '-': push(&stack, subtract(val1, val2)); break;
                case '*': push(&stack, multiply(val1, val2)); break;
                case '/': push(&stack, divide(val1, val2)); break;
                case '^': push(&stack, power(val1, val2)); break;
                case 'r': push(&stack, root(val2)); break; // Usa val2 para funções de um operando
                case 's': push(&stack, sine(val2)); break;
                case 'c': push(&stack, cosine(val2)); break;
                case 't': push(&stack, tangent(val2)); break;
                case 'l': push(&stack, logarithm(val2)); break;
                default: printf("Operador inválido: %s\n", token); exit(1); // Mensagem de erro para operador inválido
            }
        }
        token = strtok(NULL, " "); // Pega o próximo token
    }
    return pop(&stack); // Retorna o resultado final
}
