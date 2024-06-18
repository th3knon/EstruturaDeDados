all: postfix_evaluator

postfix_evaluator: stack.o operations.o postfix_evaluator.o main.o
	gcc -o postfix_evaluator stack.o operations.o postfix_evaluator.o main.o -lm

stack.o: stack.c stack.h
	gcc -c stack.c

operations.o: operations.c operations.h
	gcc -c operations.c

postfix_evaluator.o: postfix_evaluator.c postfix_evaluator.h stack.h operations.h
	gcc -c postfix_evaluator.c

main.o: main.c postfix_evaluator.h
	gcc -c main.c

clean:
	rm -f *.o postfix_evaluator