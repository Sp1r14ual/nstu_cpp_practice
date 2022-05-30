#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstddef>
#include "table.cpp"

using namespace std;

int main()
{
    ifstream fin;
    fin.open("work.txt");

    table *t = new table;
    t->n = 0;
    while (!fin.eof())
    {
        element *x = new element;
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