#include <stdio.h>
#include <stdlib.h>
#include "stack_Array.h"

int main(void)
{
    push(10);
    push(20);
    push(30);

    int result = pop();
    printf("%d ", result);
    result = pop();
    printf("%d ", result);
    result = pop();
    printf("%d ", result);

    return EXIT_SUCCESS;
}