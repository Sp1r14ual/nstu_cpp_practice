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
        delete tree;
    }
}