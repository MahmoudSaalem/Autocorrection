#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "BST.h"
#include "file.h"
#define WORDS 3000
#define WORD_LENGTH 20

/// Global Variables
char dictionary[WORDS][WORD_LENGTH];
node *root;
int flag = 1;

int main()
{
    filesCheck();
    loadData();
    start();
    return 0;
}
