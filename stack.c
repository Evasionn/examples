// STACK IMPLEMENTATION
#include <stdlib.h>
#include <stdio.h>
#define size 10
typedef int elemType;
typedef struct {
	elemType data[size];
	int last;
}Stack;

void intStack(Stack * s) {
	s->last = -1;
}
int isFull(Stack * s) {
	return s->last = size - 1 ? 1 : 0;
}
int isEmpty(Stack *s) {
	return s->last = -1 ? 1 : 0;
}
elemType pop(Stack *s) {
	if (isEmpty(s)) { puts("There is no item in stack"); exit(0); }
	s->last--;
	return s->data[s->last + 1];
}
void push(Stack *s, elemType data) {
	if (isFull(s)) { puts("The stack is full"); exit(0); }
	s->last++;
	s->data[s->last] = data;
}
void main() {
	Stack myStack;
	intStack(&myStack);
	/*push(&myStack, 1);
	push(&myStack, 2);
	push(&myStack, 3);*/
}