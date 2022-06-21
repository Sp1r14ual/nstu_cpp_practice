#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstddef>

using namespace std;

typedef struct tnode
{
    int field;
    struct tnode *left;
    struct tnode *right;
} tnode;

struct tnode *addnode(int x, tnode *tree)
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

    int num;
    fin >> num;

    if (num == 0)
        return 0;

    tnode *root;
    root = addnode(num, root);

    while (!fin.eof())
    {
        int num;
        fin >> num;

        if (num == 0)
            break;

        addnode(num, root);
    }

    treeprint(root);
    cout << endl;

    return 0;
}