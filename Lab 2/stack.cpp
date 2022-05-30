typedef struct node
{
    int field;
    struct node *next;
} node;

typedef struct
{
    node *elem;
    int top;
} stack;

stack *init()
{
    stack *stk = new stack;
    stk->elem = NULL;
    stk->top = 0;
    return stk;
}

void delete_element(node *elem)
{
    if (elem->next)
        delete_element(elem->next);
    delete elem;
}

void delete_stack(stack *stk)
{
    if (!stk)
        return;
    if (stk->elem)
        delete_element(stk->elem);
    delete stk;
}

void push(stack *stk, int value)
{
    if (!stk)
        return;
    node *temp = new node;
    temp->field = value;
    if (!stk->elem)
    {
        temp->next = NULL;
        stk->elem = temp;
    }
    else
    {
        temp->next = stk->elem;
        stk->elem = temp;
    }
    stk->top++;
}

int pop(stack *stkk)
{
    if (!stkk || !stkk->elem)
        return 0;
    int field = stkk->elem->field;
    node *del = stkk->elem;
    stkk->elem = stkk->elem->next;
    delete del;
    stkk->top--;
    return field;
}

int stack_size(stack *stkk)
{
    return stkk->top;
}

int is_empty(stack *stkk)
{
    return !stkk->elem;
}