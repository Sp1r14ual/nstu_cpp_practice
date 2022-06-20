#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstddef>

using namespace std;

typedef struct tnode
{
    string field;
    struct tnode *left;
    struct tnode *right;
} tnode;

struct tnode *addnode(string x, tnode *tree)
{
    if (tree == nullptr)
    {
        tree = new tnode;
        tree->field = x;
        tree->left = nullptr;
        tree->right = nullptr;
    }
    else if (x < tree->field)
        tree->left = addnode(x, tree->left);
    else
        tree->right = addnode(x, tree->right);
    return tree;
}

void treeprint(tnode *tree)
{
    if (tree != nullptr)
    {
        treeprint(tree->left);
        cout << tree->field << " ";
        treeprint(tree->right);
    }
}

int main()
{
    ifstream fin;
    fin.open("input.txt");

    string word;
    fin >> word;

    tnode *root;
    root = addnode(word, root);

    while (!fin.eof())
    {
        string word;
        fin >> word;
        addnode(word, root);
    }

    treeprint(root);
    cout << endl;

    return 0;
}