#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LMAX 2

typedef struct nodo_t nodo;
struct nodo_t
{
    int key;
    nodo * left;
    nodo * right;
};

void print_tree(nodo *);
void insert(nodo**, int);
nodo* mirror(nodo*);

int main ()
{
    nodo * root;
    root = NULL;
    insert(&root,15);
    insert(&root,6);
    insert(&root,18);
    insert(&root,3);
    insert(&root,7);
    insert(&root,2);
    insert(&root,4);
    insert(&root,20);
    insert(&root,17);

    print_tree(root);

    nodo * alfa;
    alfa = NULL;
    alfa = mirror(root);
    printf("-------\n");
    print_tree(alfa);

    return 0;
}

void print_tree(nodo* root){
    if (root){
        printf("  %d  ",root->key);
        print_tree(root->left);
        printf("\n");
        print_tree(root->right);
        printf("\n");
    }
}

nodo* mirror(nodo* x){
    if(x->left == NULL && x->right == NULL)
        return x;

    nodo * temp = NULL;
    x->left = mirror(x->left);
    x->right = mirror(x->right);
    temp = x->left;
    x->left = x->right;
    x->right = temp;

    return x;
}

void insert(nodo ** root, int val)
{
    nodo *temp;
    temp = NULL;

    if((*root) == NULL)
    {
        temp = malloc(sizeof(nodo));
        temp->left = temp->right = NULL;
        temp->key = val;
        (*root)= temp;
        return;
    }

    if(val <(*root)->key)
    {
        insert(&(*root)->left, val);
    }
    else if(val >(*root)->key)
    {
        insert(&(*root)->right, val);
    }

}
