#include <iostream>
#include <cstdlib>
#include <cstddef>
#include "stack.cpp"

int main()
{
    stack *s = init();
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