#ifndef STACK_ADT2_H
#define STACK_ADT2_H

#include <stdbool.h>

typedef struct stack_type* Stack;
typedef int Item;

Stack create(int size);
void destroy(Stack s);
void make_empty(Stack s);
bool is_empty(Stack s);
bool is_full(Stack s);
void push(Stack s, Item i);
Item pop(Stack s);

#endif