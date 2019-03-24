#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LMAX 2

typedef struct nodo_t nodo;
static int contatore;
// STRUCT

struct nodo_t
{
    int key;
    nodo * left;
    nodo * right;
};

void print_tree(nodo *);
void insert(nodo*, int);

int main ()
{
    nodo * root;
    root = NULL;
    insert(root,15);
    insert(root,6);
    insert(root,18);
    print_tree(root);

    return 0;
}

void print_tree(nodo* root){
    if (root){
        printf("  %d  ",root->key);
        print_tree(root->left);
        print_tree(root->right);
        printf("\n");
    }
}

void insert(nodo * root, int val)
{
    nodo *temp;
    temp = NULL;

    if(root == NULL)
    {
        temp = malloc(sizeof(nodo));
        temp->left = temp->right = NULL;
        temp->key = val;
        root = temp;
        return;
    }

    if(val < root->key)
    {
        insert(root->left, val);
    }
    else if(val > root->key)
    {
        insert(root->right, val);
    }

}
