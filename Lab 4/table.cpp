#define N 10

typedef struct elem
{
    char key[9];
    char name[20];
    int amount;
} element;

typedef struct table
{
    element *el[N];
    int n;
} table;

bool inserttable(table *G, element *x)
{
    int i = G->n - 1;
    if (G->n < N)
    {
        while (i >= 0 && atoi(G->el[i]->key) > atoi(x->key))
        {
            G->el[i + 1] = G->el[i];
            i--;
        }
        G->el[i + 1] = x;
        G->n++;
        return true;
    }
    else
        return false;
}

int linear_search(table *G, element *x)
{
    int i = 0;
    while (i < G->n && atoi(G->el[i]->key) <= atoi(x->key))
    {
        if (atoi(G->el[i]->key) == atoi(x->key))
            return i;
        i++;
    }

    return -1;
}