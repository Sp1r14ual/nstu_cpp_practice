#include <stdio.h>
#include <stdlib.h>
#include "stack.c"

int main()
{
    stack * s = init();
    int i;
    for (i = 5; i < 10; ++i)
        push(s, i);
    while (!is_empty(s))
    {
        printf("%d\n", pop(s));
    }
    delete_stack(s);
    return 0;
}