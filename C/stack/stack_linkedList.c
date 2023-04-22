#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define PRIVATE static

typedef struct _tag_Node
{
    int data;
    struct _tag_Node *next;
} Node;

PRIVATE Node *top = NULL;

PRIVATE void terminate(const char *message)
{
    printf("%s \n", message);
    exit(EXIT_FAILURE);
}

void make_empty(void)
{
    while(!is_empty())
        pop();
}

bool is_empty(void)
{
    return top == NULL;
}

bool is_full(void)
{
    return false;
}

void push(int i)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    
    if(NULL == new_node)
        terminate("Error in push: stack is full. \n");
    
    new_node->data = i;
    new_node->next = top;
    top = new_node;
}

int pop(void)
{
    int ret_val;

    if(is_empty())
        terminate("Error in pop: stack is empty. \n");
    
    Node *old_top = top;
    ret_val = top->data;
    top = top->next;
    free(old_top);

    return ret_val;
}
