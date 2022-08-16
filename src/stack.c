

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"

/*
   actual stack data structure
   This pointer will pointing at the actual field (of void * pointers)
   that represents the stack.
 */
void **array;

/* the current capacity of the stack */
int max = 10;

/* counter variable for counting the elements of the stack. */
int size = 0;

/*
    offset address
    points at the top element of the stack.
*/
int offset = -1;

void initStack()
{
    array = malloc(sizeof(void *) * max);
    assert(array); /* tests whether pointer is assigned to memory. */
}

/*
    grow: increases the stack by 10 elements.
          This utility function isn't part of the public interface
*/
void grow()
{
    max += 10; /* increases the capacity */

    int i;  // for the loop
    void **tmp = malloc(sizeof(void *) * max);

    /* copies the elements from the origin array in the new one. */
    for (i = 0; i < max - 10; i++)
    {
        *(tmp + i) = *(array + i);
    }
    /*free the memory */
    free(array);
    array = tmp;
}

/* push: pushes the argument onto the stack */
void push(void *object)
{
    assert(object); /* tests whether pointer isn't null */

    if (size < max)
    {
        offset++; /* increases the element-pointer */

        /*
            moves pointer by the offset address
            pushes the object onto stack
         */
        *(array + offset) = object;

        /* increases the inner size */
        size++;
    }
    else /* stack is full */
    {
        grow();       /* lets grow stack */
        push(object); /* recursive call */
    }
}

/*
    pop: pops the top element of the stack from the stack.
*/
void *pop()
{
    void *top = *(array + offset);

    /* check pointers */
    assert(top);

    /* if use the pop-function, stack must not empty. */
    assert(!isEmpty());

    /* decreases the offset address for pointing of
        the new top element */
    offset--;

    /* decreases the inner size */
    size--;

    return top;
}

/*
    Returns the number of elements of the stack
*/
int stackSize() { return size; }

/*
    returns 1 if stack is empty
*/
int isEmpty() { return size == 0; }

/*
    top: returns the top element from the stack without removing it
*/
void *top()
{
    /* offset address points to the top element */
    return array[offset];
}

