#include <stdio.h>
#include <stdlib.h>
#include "BST.h"
#include "file.h"
#define WORDS 3000
#define WORD_LENGTH 20

/// Global Variables
extern char dictionary[WORDS][WORD_LENGTH];

void filesCheck()
{
    FILE *f1;
    f1 = fopen("English.txt", "r");
    if(!f1)
    {
        printf("Missing Files!\n");
        fclose(f1);
        exit(1);
    }
    fclose(f1);
}
void loadData()
{
    FILE *f1;
    f1 = fopen("English.txt", "r");
    int i;
    while(!feof(f1))
    {
        for(i = 0; i < WORDS; i++)
        {
            fscanf(f1, "%[^\n]\n ", &dictionary[i]);
        }
    }
    fclose(f1);
}
void printData()
{
    int i;
    for(i = 0; i < WORDS; i++)
        printf("%s\n", dictionary[i]);
}
/*
int wordsInFile(char *filePath)
{
    int ch=0;
    int lines=0;
    FILE *processesFile;
    processesFile = fopen(filePath, "r");
    lines++;
    while ((ch = fgetc(processesFile)) != EOF)
    {
      if (ch == '\n')
            lines++;
    }
    fclose(processesFile);
    return lines;
}
//*/
