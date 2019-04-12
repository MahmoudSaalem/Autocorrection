#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BST.h"
#include "file.h"
#define WORDS 3000
#define WORD_LENGTH 20
#define max(a, b) (((a) > (b)) ? (a) : (b))

/// Global Variables
extern char dictionary[WORDS][WORD_LENGTH];
extern node *root;
extern int flag;

node* newNode(type item)
{
    node *temp =  (node*)malloc(sizeof(node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

node* search(node *node, char val[])
{
    int res;
    struct node *temp;
    temp = NULL;
    while(node!=NULL)
    {
        res=strcasecmp(val,node->key);
        if(res==0){
            printf("%s: This word is correct\n",node->key);
            return node;}
        else if(res==1)
        {
            temp = node;
            node=node->right;
        }
        else
        {
            temp = node;
            node=node->left;
        }
    }
    printf("%s: ", val);
    struct node *pre = NULL, *suc = NULL;
    findPreSuc(root, pre, suc,temp->key);
    return temp;
}

node* insertRecursion(char arr[][20], int start, int end){
    if (start >end)
        return NULL;
    int mid= (start + end)/2;
    node* newn=newNode(arr[mid]);
    newn->left=insertRecursion(arr,start,mid -1);
    newn->right=insertRecursion(arr, mid+1,end);
        return newn;
}

void findPreSuc(node* root, node* pre, node* suc, type key)
{
    if (root == NULL)
        return;
    if (strcasecmp(root->key, key) == 0)
    {
        if (root->left != NULL)
        {
            node* tmp = root->left;
            while (tmp->right)
                tmp = tmp->right;
            pre = tmp ;
        }

        if (root->right != NULL)
        {
            node* tmp = root->right ;
            while (tmp->left)
                tmp = tmp->left ;
            suc = tmp ;
        }
        if(flag)
        {
            if(pre != NULL)
                printf("%s", pre->key);
            printf(", %s", key);
            if(suc != NULL)
                printf(", %s", suc->key);
            puts("");
            flag = 0;
        }
        return ;
    }
    if (strcasecmp(root->key, key) == 1)
    {
        suc = root ;
        findPreSuc(root->left, pre, suc, key) ;
    }
    else
    {
        pre = root;
        findPreSuc(root->right, pre, suc, key) ;
    }
}

int height(node *root)
{
    if(root==NULL)
        return 0;
    else
        return 1+max(height(root->left),height(root->right));

}

void start()
{
    root = insertRecursion(dictionary,0,2999);
    printf("The height of the tree equals %d\n",height(root));
    puts("");
    printf("Enter your sentence: ");
    char array[WORDS][WORD_LENGTH];
    char string[200];
    gets(string);
    const char s[2] = " ";
    char *token;
    token = strtok(string, s);

    int i = 0;
    while( token != NULL ) {
        strcpy(array[i++], token);
        token = strtok(NULL, s);
    }
    puts("\nSuggestions:");
    int counter = i;
    for(i = 0; i < counter; i++)
    {
        search(root, array[i]);
        flag = 1;
    }
}
