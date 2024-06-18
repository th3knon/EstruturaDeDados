#ifndef STACK_H
#define STACK_H

#define MAX 100

typedef struct {
    double items[MAX];
    int top;
} Stack;

void initStack(Stack *s);
int isEmpty(Stack *s);
int isFull(Stack *s);
void push(Stack *s, double value);
double pop(Stack *s);

#endif
