#include <iostream>
#include <cstdlib>
#include "main.cpp"
using namespace std;

typedef struct tnode
{
  int field;           
  struct tnode *left;
  struct tnode *right;
} tnode;

void inorder(tnode * tree)
{
  if (tree != NULL) 
  {
    inorder(tree->left); 
    cout << tree->field << " ";
    inorder(tree->right);
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

table * sort(table * t)
{
  tnode * root = 0;
  int a;
  for (int i = 0; i < t->n; i++) 
    root = addnode(t->el[i]->price, root);
  inorder(root);

  table * t_new = new table;

}


//draft