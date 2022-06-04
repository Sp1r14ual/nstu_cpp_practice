#define N 10

using namespace std;

typedef struct elem
{
    char id[9];
    char name[20];
    int amount;
    int price;
} element;

typedef struct tab
{
    struct elem *el[N];
    int n;
} table;

bool ordered_insert(table *G, element *x)
{
    int i = G->n - 1;
    if (G->n < N)
    {
        while (i >= 0 && atoi(G->el[i]->id) > atoi(x->id))
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

bool unordered_insert(table *G, element *x)
{
    if (G->n < N)
    {
        G->el[G->n] = x;
        G->n++;
        return true;
    }

    return false;
}

int linear_search_for_id(table *G, int x)
{
    int i = 0;
    while (i < G->n && atoi(G->el[i]->id) <= x)
    {
        if (atoi(G->el[i]->id) == x)
            return i;
        i++;
    }

    return -1;
}

int linear_search_for_price(table *G, int x)
{
    int i = 0;
    while (i < G->n)
    {
        if (G->el[i]->price == x)
            return i;
        i++;
    }

    return -1;
}

void siftDown(table *t, int root, int bottom)
{
    int maxChild;
    bool done = false;

    while ((root * 2 <= bottom) && (!done))
    {
        if (root * 2 == bottom)
            maxChild = root * 2;
        else if (t->el[root * 2]->price > t->el[root * 2 + 1]->price)
            maxChild = root * 2;
        else
            maxChild = root * 2 + 1;

        if (t->el[root]->price < t->el[maxChild]->price)
        {
            element *temp = t->el[root];
            t->el[root] = t->el[maxChild];
            t->el[maxChild] = temp;
            root = maxChild;
        }
        else
            done = true;
    }
}

void heapSort(table *t, int array_size)
{

    for (int i = (array_size / 2); i >= 0; i--)
        siftDown(t, i, array_size - 1);

    for (int i = array_size - 1; i >= 1; i--)
    {
        element *temp = t->el[0];
        t->el[0] = t->el[i];
        t->el[i] = temp;
        siftDown(t, 0, i - 1);
    }
}