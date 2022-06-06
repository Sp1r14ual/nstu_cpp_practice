#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstddef>

using namespace std;

ifstream fin;
typedef struct tnode
{
  char elem;
  struct tnode *left;
  struct tnode *right;
} tnode;

tnode *build_tree()
{
  char sym;
  tnode *d;
  fin >> sym;
  switch (sym)
  {
  case '(':
  {
    d = new tnode;
    fin >> sym;
    d->elem = sym;
    d->left = build_tree();
    d->right = build_tree();
    fin >> sym;
    return d;
  }
  case '0':
    return NULL;
  case ',':
    d = build_tree();
    return d;
  }
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
  fin.open("input.txt");

  int value;

  tnode *root = build_tree();

  int length = -1;
  char x;
  cout << "Введите искомое число: ";
  cin >> x;

  path_length(root, x, 0, length);

  if (length == -1)
    cout << "No such element" << endl;
  else
    cout << length << endl;

  return 0;
}