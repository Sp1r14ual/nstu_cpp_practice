#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#define N 10

using namespace std;


typedef struct elem
{
    char key[9];
    char name[20];
    int amount;
    int price;
} element;

typedef struct table
{
    element * el[N];
    int n;
} table;

bool inserttable (table * G, element * x)
{
    int i = G->n - 1;
    if (G->n < N)
    {
        while (i >= 0 && atoi(G->el[i]->key) > atoi(x->key))
        {
            G->el[i+1] = G->el[i];
            i--;
        }
        G->el[i+1] = x;
        G->n++;
        return true;
    }
    else
        return false;
}

int linear_search(table * G, element * x)
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

int main()
{
    ifstream items;
    items.open("work.txt");

    ifstream prices;
    prices.open("price.txt");



    table * t = new table;
    t->n = 0;
    while(!fin.eof())
    {
        element * x = new element;
        fin >> x->key >> x->name >> x->amount;
        int index_in_table = linear_search(t, x);
        if (index_in_table != -1)
            t->el[index_in_table]->amount += x->amount;
        else
        {
            bool inserted = inserttable(t, x);
            if (inserted)
                continue;
            else
            {
                printf("Error. Table is full.");
                exit(1);
            }
        }
    }

    for (int i = 0; i < t->n; i++)
        cout << t->el[i]->key << " " << t->el[i]->name << " " << t->el[i]->amount << endl;


    return 0;
}