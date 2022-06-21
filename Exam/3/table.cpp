#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstddef>
#define N 50

using namespace std;

typedef struct elem
{
    int number;
    double time;
    int rating;

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
        while (i >= 0 && G->el[i]->rating > x->rating)
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
        element *cooker = new element;
        fin >> cooker->number >> cooker->time >> cooker->rating;

        bool inTable = in_table(t, cooker->number);
        if (inTable)
        {
            cout << "Error. Cooker is already in table" << endl;
            exit(1);
        }
        else
        {
            bool inserted = ordered_insert(t, cooker);
            if (!inserted)
            {
                cout << "Error. The table is full." << endl;
                exit(1);
            }
        }
    }

    if (t->n < 3)
    {
        cout << "Error. There are less than 3 cookers in the table." << endl;
        exit(1);
    }

    element *x1 = t->el[t->n - 1];
    element *x2 = t->el[t->n - 2];
    element *x3 = t->el[t->n - 3];

    if (x1->time < x2->time && x1->time < x3->time)
    {
        cout << x1->number << " " << x1->time << endl;
        if (x2->time < x3->time)
        {
            cout << x2->number << " " << x2->time << endl;
            cout << x3->number << " " << x3->time << endl;
        }
        else
        {
            cout << x3->number << " " << x3->time << endl;
            cout << x2->number << " " << x2->time << endl;
        }
    }
    else if (x2->time < x1->time && x2->time < x3->time)
    {
        cout << x2->number << " " << x2->time << endl;
        if (x1->time < x3->time)
        {
            cout << x1->number << " " << x1->time << endl;
            cout << x3->number << " " << x3->time << endl;
        }
        else
        {
            cout << x3->number << " " << x3->time << endl;
            cout << x1->number << " " << x1->time << endl;
        }
    }
    else
    {
        cout << x3->number << " " << x3->time << endl;
        if (x1->time < x2->time)
        {
            cout << x1->number << " " << x1->time << endl;
            cout << x2->number << " " << x2->time << endl;
        }
        else
        {
            cout << x2->number << " " << x2->time << endl;
            cout << x1->number << " " << x1->time << endl;
        }
    }

    return 0;
}
