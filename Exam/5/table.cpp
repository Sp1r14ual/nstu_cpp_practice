#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstddef>
#define N 300

using namespace std;

typedef struct elem
{
    char name[53];
    char id[8];
    char date[9];

} element;

typedef struct tab
{
    struct elem *el[N];
    int n;
} table;

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

bool in_table(table *G, int x)
{
    int i = 0;
    while (i < G->n)
    {
        if (atoi(G->el[i]->id) == x)
            return true;
        i++;
    }

    return false;
}

//сортировка слиянием, алгоритмическая сложность O(nlog(n))
void mergeSort(table *G, int n)
{
    int mid = n / 2;
    if (n % 2 == 1)
        mid++;
    int h = 1;
    element *c[n];
    int step;
    while (h < n)
    {
        step = h;
        int i = 0;
        int j = mid;
        int k = 0;
        while (step <= mid)
        {
            while ((i < step) && (j < n) && (j < (mid + step)))
            {
                if (atoi(G->el[i]->id) < atoi(G->el[j]->id))
                {
                    c[k] = G->el[i];
                    i++;
                    k++;
                }
                else
                {
                    c[k] = G->el[j];
                    j++;
                    k++;
                }
            }
            while (i < step)
            {
                c[k] = G->el[i];
                i++;
                k++;
            }
            while ((j < (mid + step)) && (j < n))
            {
                c[k] = G->el[j];
                j++;
                k++;
            }
            step = step + h;
        }
        h = h * 2;

        for (i = 0; i < n; i++)
            G->el[i] = c[i];
    }
}

int main()
{
    ifstream fin;
    fin.open("input.txt");

    if (!fin)
    {
        cout << "File not found" << endl;
        exit(1);
    }

    table *t = new table;
    t->n = 0;

    while (!fin.eof())
    {
        element *worker = new element;
        fin >> worker->name >> worker->id >> worker->date;

        bool inTable = in_table(t, atoi(worker->id));
        if (inTable)
        {
            cout << "Error. Worker is already in table" << endl;
            exit(1);
        }
        else
        {
            bool inserted = unordered_insert(t, worker);
            if (!inserted)
            {
                cout << "Error. The table is full." << endl;
                exit(1);
            }
        }
    }

    mergeSort(t, t->n);
    for (int i = 0; i < t->n; i++)
        cout << t->el[i]->name << " " << t->el[i]->id << " " << t->el[i]->date << endl;

    return 0;
}