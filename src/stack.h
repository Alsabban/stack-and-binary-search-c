#ifndef __STACK_H_
#define __STACK_H_

/*
    initStack: initializes the stack with a capacity of 10 elements.
*/
void initStack();

/*
    push: pushes the argument onto the stack
*/
void push(void *object);

/*
    pop: pops the top element of the stack from the stack.
    assumes: stack not empty.
*/
void *pop();

/*
    stackSize: gets the number of elements of the stack.
*/
int stackSize();

/*
    isEmpty(): returns 1 if stack is empty otherwise 0.
*/
int isEmpty();

/*
    top: returns the top element from the stack without removing it.
*/
void *top();

#endif
