#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED

typedef char* type;

typedef struct node
{
    type key;
    struct node *left, *right;
} node;

node* newNode(type item);
node* search(node *node, char val[]);
void findPreSuc(node* root, node* pre, node* suc, type key);
node* insertRecursion(char arr[3000][20], int start, int end);
void start();

#endif // BST_H_INCLUDED
