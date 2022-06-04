#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstddef>

using namespace std;
typedef struct tnode
{
  int elem;
  struct tnode *left;
  struct tnode *right;
} tnode;

struct tnode *addnode(int x, tnode *tree)
{
  if (tree == NULL)
  {
    tree = new tnode;
    tree->elem = x;
    tree->left = NULL;
    tree->right = NULL;
  }
  else if (x < tree->elem)
    tree->left = addnode(x, tree->left);
  else
    tree->right = addnode(x, tree->right);
  return (tree);
}

void path_length(tnode *tree, int num, int acc, int &length)
{
  if (tree == nullptr)
    return;

  if (num == tree->elem)
  {
    length = acc;
    return;
  }
  path_length(tree->left, num, acc + 1, length);
  path_length(tree->right, num, acc + 1, length);
}

int main()
{
  ifstream fin;
  fin.open("input.txt");

  int value;

  tnode *root = new tnode;
  fin >> value;
  root->elem = value;
  root->left = NULL;
  root->right = NULL;

  while (!fin.eof())
  {
    fin >> value;
    addnode(value, root);
  }

  int x, length = -1;
  cout << "Введите искомое число: ";
  cin >> x;

  path_length(root, x, 0, length);

  if (length == -1)
    cout << "No such element" << endl;
  else
    cout << length << endl;

  return 0;
}