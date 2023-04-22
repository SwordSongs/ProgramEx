#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(void)
{
    push(100);
    push(200);
    push(300);

    int result = pop();
    printf("%d ", result);
    result = pop();
    printf("%d ", result);
    result = pop();
    printf("%d ", result);

    return EXIT_SUCCESS;
}