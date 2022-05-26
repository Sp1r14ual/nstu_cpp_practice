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

typedef struct tab
{
    struct elem * el[N];
    int n;
} table;

bool ordered_insert(table * G, element * x)
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

bool unordered_insert(table * G, element * x)
{
    if (G->n < N)
    {
        G->el[G->n] = x;
        G->n++;
        return true;
    }

    return false;
}

int linear_search_for_id(table * G, int x)
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

int linear_search_for_price(table * G, int x)
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


typedef struct tnode
{
  int field;           
  struct tnode *left;
  struct tnode *right;
} tnode;

void inorder(tnode * tree, table * t_old, table * t_new)
{

  if (tree != NULL) 
  {
    inorder(tree->left, t_old, t_new);
    int index_in_table = linear_search_for_price(t_old, tree->field);
    bool inserted = unordered_insert(t_new, t_old->el[index_in_table]);
    if (!inserted)
    {
        cout << "Error. Table is full." << endl;
        exit(1);
    }
    inorder(tree->right, t_old, t_new);
  }
}

struct tnode * addnode(int x, tnode *tree) {
  if (tree == NULL)
  {
    tree = new tnode;
    tree->field = x;
    tree->left = NULL;
    tree->right = NULL;
  }
  else
    if (x < tree->field)
      tree->left = addnode(x, tree->left);
    else
      tree->right = addnode(x, tree->right);
    return(tree);
}

void freemem(tnode *tree)
{
  if (tree != NULL)
  {
    freemem(tree->left);
    freemem(tree->right);
    delete tree;
  }
}

table * sort(table * t_old)
{
  tnode * root = 0;
  int a;
  for (int i = 0; i < t_old->n; i++) 
    root = addnode(t_old->el[i]->price, root);

  table * t_new = new table;
  t_new->n = 0;
  for (int i = 0; i < N; i++)
    t_new->el[i] = new element;

  inorder(root, t_old, t_new);
  freemem(root);
  return t_new;

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

    while(!prices.eof())
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
    table * t_sorted = sort(t);
    for (int i = 0; i < t->n; i++)
        cout << t_sorted->el[i]->id << " " << t_sorted->el[i]->name << " " << t_sorted->el[i]->amount << " " << t_sorted->el[i]->price << endl;


    return 0;
}