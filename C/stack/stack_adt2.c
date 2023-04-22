#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "stack_adt2.h"

#define STACK_SIZE 100
#define PRIVATE static

struct stack_type
{
   Item *contents;
   int top;
   int size;
};

PRIVATE void terminate(const char* message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

Stack create(int size)
{
    Stack s = (Stack)calloc(1, sizeof(struct stack_type));

    if(NULL == s)
    {
        terminate("Error in create: stack could not bo created. \n");
    }

    s->contents = (Item*)calloc(size, sizeof(Item));
    if(NULL == s->contents)
    {
        free(s);
        terminate("Error in create: stack.contents could not be created. \n");
    }

    s->top = 0;
    s->size = size;

    return s;
}

void destroy(Stack s)
{
    make_empty(s);
    free(s);
}

void make_empty(Stack s)
{
    free(s->contents);
    s->top = 0;
}

bool is_empty(Stack s)
{
    return s->top == 0;
}

bool is_full(Stack s)
{
    return s->size == s->top;
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
