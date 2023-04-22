#include <stdio.h>
#include <stdlib.h>
//#include "stack.h"
//#include "stack_adt.h"
#include "stack_adt2.h"


int main(void)
{
 /* push(100);
    push(200);
    push(300);

    int result = pop();
    printf("%d ", result);
    result = pop();
    printf("%d ", result);
    result = pop();
    printf("%d ", result);*/

    Stack s1, s2;
    int n;

    s1 = create(10);
    s2 = create(10);

    push(s1, 1);
    push(s1, 2);

    n = pop(s1);
    printf("Popped %d from s1. \n", n);
    n = pop(s1);
    printf("Popped %d from s1. \n", n);

    push(s2, n);
    destroy(s1);

    while(!is_empty(s2))
        printf("Popped %d from s2. \n", pop(s2));

    push(s2, 3);
    make_empty(s2);

    if(is_empty(s2))
        printf("s2 is empty. \n");
    else 
        printf("s2 is not empty. \n");

    destroy(s2);

    return EXIT_SUCCESS;
}