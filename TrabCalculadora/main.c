#include <stdio.h>
#include <stdlib.h>
#include "postfix_evaluator.h"

#define BUFFER_SIZE 256

int main() {
    char expression[BUFFER_SIZE];
    printf("Digite uma expressão pós-fixada: ");
    if (fgets(expression, BUFFER_SIZE, stdin) != NULL) {
        // Remove nova linha se presente
        size_t len = strlen(expression);
        if (len > 0 && expression[len-1] == '\n') {
            expression[len-1] = '\0';
        }

        double result = evaluatePostfix(expression); // Avalia a expressão pós-fixada
        printf("Resultado: %lf\n", result); // Exibe o resultado
    } else {
        printf("Erro ao ler a expressão\n"); // Mensagem de erro se não conseguir ler a expressão
    }
    return 0;
}
