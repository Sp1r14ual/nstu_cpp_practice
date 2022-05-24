#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#define N 10

using namespace std;


typedef struct elem
{
    char id[9];
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
        while (i >= 0 && atoi(G->el[i]->id) > atoi(x->id))
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

int linear_search(table * G, int x)
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

int main()
{
    ifstream items;
    items.open("work.txt");

    ifstream prices;
    prices.open("price.txt");



    table * t = new table;
    t->n = 0;
    while(!items.eof())
    {
        element * x = new element;
        items >> x->id >> x->name >> x->amount;
        int index_in_table = linear_search(t, atoi(x->id));
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

    while(!prices.eof())
    {
        char key[9];
        int price;
        prices >> key >> price;
        int index_in_table = linear_search(t, atoi(key));
        t->el[index_in_table]->price = price;
    }

    for (int i = 0; i < t->n; i++)
        cout << t->el[i]->id << " " << t->el[i]->name << " " << t->el[i]->amount << " " << t->el[i]->price << endl;


    return 0;
}