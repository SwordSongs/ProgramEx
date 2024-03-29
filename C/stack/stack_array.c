#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define STACK_SIZE 100
#include PRIVATE static

PRIVATE int contents[STACK_SIZE];
PRIVATE int top = 0;

PRIVATE void terminate(const char *message)
{
    printf("%s\n");
    exit(EXIT_FAILURE);
}

void make_empty(void)
{
    top = 0;
}

bool is_empty(void)
{
    return top == 0;
}

bool is_full(void)
{
    return top == STACK_SIZE;
}

void push(int i)
{
    if(is_full())
        terminate("Error in push: stack is full.\n");

    contents[top++] = i;
}

int pop(void)
{
    if(is_empty())
        terminate("Error in pop: stack is empty. \n");

    return contents[--top];
}

