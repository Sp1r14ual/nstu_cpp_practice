#include <stdio.h>
#include <stdlib.h>


typedef struct tnode 
{
  char field;
  struct tnode * left;
  struct tnode * right;
} tnode;

void treeprint_preorder(tnode * tree) 
{
  if (tree != NULL)
  { 
    printf("%c ", tree->field);
    treeprint_preorder(tree->left);
    treeprint_preorder(tree->right);
  }
}

void treeprint_inorder(tnode * tree) 
{
  if (tree!=NULL)
  { 
    treeprint_inorder(tree->left);
    printf("%c ", tree->field);
    treeprint_inorder(tree->right);
  }
}

void treeprint_postorder(tnode * tree) 
{
  if (tree != NULL)
  {
    treeprint_postorder(tree->left);
    treeprint_postorder(tree->right);
    printf("%c ", tree->field);
  }
}

tnode * addnode(int x, tnode * tree) 
{
  if (tree == NULL)
  { 
    tree = (tnode *)malloc(sizeof(tnode));
    tree->field = x;
    tree->left = NULL;
    tree->right = NULL;
  }
  else if (x < tree->field)
    tree->left = addnode(x, tree->left);
  else
    tree->right = addnode(x, tree->right);
  return(tree);
}

void freemem(tnode * tree) 
{
  if (tree != NULL) 
  {
    freemem(tree->left);
    freemem(tree->right);
    free(tree);
  }
}

int path_length(tnode * tree, int value) 
{
    if (!tree)
        return NULL;
    else if (tree->field == value)
        return 0;
    else
      return 1 + path_length( ( (tree->field > value ) ? tree->left : tree->right), value);
}

tnode * build_tree()
{
  char value;
  tnode * d;
  scanf("%c", &value);
  if (value == "(")
  {
    d = (tnode *)malloc(sizeof(tnode));
    scanf("%c", &value);
    d->field = value;
    d->left = build_tree();
    d->right = build_tree();
    scanf("%c", &value);
    return d;
  }
  else if (value == "0")
    return NULL;
  else if (value == ",")
    d = build_tree();
}



int main()
{
    //FILE * f = fopen("input.txt", "r");
    tnode * root = build_tree();
    treeprint_preorder(root);


    return 0;
}