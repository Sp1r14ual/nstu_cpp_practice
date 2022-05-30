#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstddef>
#include "tree.cpp"

using namespace std;

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