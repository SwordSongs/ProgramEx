#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack_adt.h"

#define STACK_SIZE 100
#define PRIVATE static

struct stack_type
{
   Item contents[STACK_SIZE];
   int top;
};

PRIVATE void terminate(const char* message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

Stack create(void)
{
    Stack s = (Stack)malloc(sizeof(struct stack_type));

    if(NULL == s)
    {
        terminate("Error in create: stack could not bo created. \n");
    }
    
    memset(s->contents, 0, STACK_SIZE);
    s->top = 0;

    return s;
}

void destroy(Stack s)
{
    free(s);
}

void make_empty(Stack s)
{
    memset(s->contents, 0, STACK_SIZE);
    s->top = 0;
}

bool is_empty(Stack s)
{
    return s->top == 0;
}

bool is_full(Stack s)
{
    return s->top == STACK_SIZE;
}

void push(Stack s, Item i)
{
    if(is_full(s))
        terminate("Error in push: stack is full. \n");
    s->contents[s->top++] = i;    
}

Item pop(Stack s)
{
      if(is_empty(s))
        terminate("Error in pop: stack is empty. \n");
    
    return s->contents[--(s->top)];   
}
