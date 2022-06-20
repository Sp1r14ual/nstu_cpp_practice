#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstddef>
#define N 10

using namespace std;

typedef struct elem
{
    int number;
    double start_time;
    double finish_time;

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
        while (i >= 0 && G->el[i]->finish_time > x->finish_time)
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

bool in_table(table *G, int x)
{
    int i = 0;
    while (i < G->n && G->el[i]->number <= x)
    {
        if (G->el[i]->number == x)
            return true;
        i++;
    }

    return false;
}

int main()
{
    ifstream fin;
    fin.open("input.txt");

    table *t = new table;
    t->n = 0;

    while (!fin.eof())
    {
        element *athlete = new element;
        fin >> athlete->number >> athlete->start_time >> athlete->finish_time;

        bool inTable = in_table(t, athlete->number);
        if (inTable)
        {
            cout << "Error. An athlete is already in the table" << endl;
            exit(1);
        }
        else
        {
            bool inserted = ordered_insert(t, athlete);
            if (!inserted)
            {
                cout << "Error. The table is full." << endl;
                exit(1);
            }
        }
    }

    cout << t->el[0]->number << " " << t->el[0]->start_time << " " << t->el[0]->finish_time << endl;
    cout << t->el[1]->number << " " << t->el[1]->start_time << " " << t->el[1]->finish_time << endl;
    cout << t->el[2]->number << " " << t->el[2]->start_time << " " << t->el[2]->finish_time << endl;

    return 0;
}