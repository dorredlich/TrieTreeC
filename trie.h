#ifndef TRIENODE_H
#define TRIENODE_H
#define CHAR_TO_INDEX(c) ((int)c - (int)'a') 
#define NUM_LETTERS ((int)26)
#include <stdbool.h>


typedef struct TrieNode{
    struct TrieNode *children[NUM_LETTERS];
    char letter;
    long unsigned int count;
    bool isEndOfWord;
    
} TrieNode;

TrieNode *createTrieNode();
void insert(TrieNode*,char*);
void Print(TrieNode*,char[],int);
void PrintR(TrieNode*,char[],int);
void TrieDestroy(TrieNode**);

#endif
