#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstddef>
#include "table.cpp"
#define N 10

using namespace std;

int main()
{
  ifstream items;
  items.open("work.txt");

  ifstream prices;
  prices.open("price.txt");

  table *t = new table;
  t->n = 0;

  while (!items.eof())
  {
    element *x = new element;
    items >> x->id >> x->name >> x->amount;
    int index_in_table = linear_search_for_id(t, atoi(x->id));
    if (index_in_table != -1)
      t->el[index_in_table]->amount += x->amount;
    else
    {
      bool inserted = ordered_insert(t, x);
      if (inserted)
        continue;
      else
      {
        printf("Error. Table is full.");
        exit(1);
      }
    }
  }

  while (!prices.eof())
  {
    char key[9];
    int price;
    prices >> key >> price;
    int index_in_table = linear_search_for_id(t, atoi(key));
    if (index_in_table == -1)
      cout << "No such an element in the table" << endl;
    else
      t->el[index_in_table]->price = price;
  }

  table *t_sorted = sort_table(t);

  for (int i = 0; i < t->n; i++)
    cout << t_sorted->el[i]->id << " " << t_sorted->el[i]->name << " " << t_sorted->el[i]->amount << " " << t_sorted->el[i]->price << endl;

  return 0;
}