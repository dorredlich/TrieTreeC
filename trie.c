#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"

TrieNode *createTrieNode() {	
	TrieNode *node;
    node = (TrieNode*)malloc(sizeof(TrieNode));
	node->isEndOfWord = false;
    int i = 0;
	node->count = 0;
    while(i < NUM_LETTERS){
        node->children[i] = NULL;
        i++;
    }
    return node; 
}

void insert(TrieNode *root,char *word){
	int index = 0;
    for (int i = 0; i < strlen(word); i++) {
        index = CHAR_TO_INDEX(word[i]);
        if(!root->children[index]){
            root->children[index] = createTrieNode();
            root->children[index]->letter = word[i];
        }
        root = root->children[index];
    }
    root->isEndOfWord = true;
    root->count++;
		
}

void Print(TrieNode *root, char word[], int index){
	if(root == NULL) return;
	if(root->isEndOfWord){//if i get to the end of any word
		word[index] = '\0';
		printf("%s\t %ld \n", word, root->count);
	}
	for(int i = 0; i < NUM_LETTERS;i++){
		if(root->children[i]){
                word[index] = (char)(97+i);
                Print(root->children[i],word,index+1);//recurstion by print all node
		}
	}
}

void PrintR(TrieNode *root, char word[], int index){
	if(root == NULL) return;
	if(root->isEndOfWord){
		word[index] = '\0';
		printf("%s\t %ld \n", word, root->count);
	}
	for(int i = NUM_LETTERS-1; i >= 0; i--){
		if(root->children[i]){
                word[index] = (char)(97+i);
                PrintR(root->children[i],word,index+1);//recurstion by print all node
		}
	}
}

void TrieDestroy(TrieNode** root){
	TrieNode *node = *root;
	for(int i = 0; i < NUM_LETTERS;i++){
		if(node->children[i] != NULL)
			TrieDestroy(&(node->children[i]));//recurstion for free all the nodes.
	}
	free(node);
}


