#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

typedef struct tnode
{
  int field;
  struct tnode *left;
  struct tnode *right;
} tnode;

void treeprint_preorder(tnode *tree)
{
  if (tree != NULL)
  {
    cout << tree->field << " ";
    treeprint_preorder(tree->left);
    treeprint_preorder(tree->right);
  }
}

void treeprint_inorder(tnode *tree)
{
  if (tree != NULL)
  {
    treeprint_inorder(tree->left);
    cout << tree->field << " ";
    treeprint_inorder(tree->right);
  }
}

void treeprint_postorder(tnode *tree)
{
  if (tree != NULL)
  {
    treeprint_postorder(tree->left);
    treeprint_postorder(tree->right);
    cout << tree->field << " ";
  }
}

tnode *addnode(int x, tnode *tree)
{
  if (tree == NULL)
  {
    tree = new tnode;
    tree->field = x;
    tree->left = NULL;
    tree->right = NULL;
  }
  else if (x < tree->field)
    tree->left = addnode(x, tree->left);
  else
    tree->right = addnode(x, tree->right);
  return tree;
}

void freemem(tnode *tree)
{
  if (tree != NULL)
  {
    freemem(tree->left);
    freemem(tree->right);
    free(tree);
  }
}

int path_length(tnode *tree, int value)
{
  if (!tree || tree->field == value)
    return 0;
  else
    return 1 + path_length(((tree->field > value) ? tree->left : tree->right), value);
}

int main()
{
  ifstream fin;
  fin.open("input.txt");

  tnode *root = NULL;
  int value;
  int search_value;

  fin >> value;
  root = addnode(value, root);

  while (!fin.eof())
  {
    fin >> value;
    addnode(value, root);
  }

  treeprint_inorder(root);
  cout << endl;

  cout << "Введите значение" << endl;
  cin >> search_value;
  cout << path_length(root, search_value) << endl;

  return 0;
}