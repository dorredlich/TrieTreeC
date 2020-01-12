#include "trie.h"
#include <stdio.h>
#include <string.h>
#define LINE 1024
#define WORD 256



int main(int argc, char const *argv[]){
	char word[WORD];
	char line[LINE];
	TrieNode *node = createTrieNode();
	int index = 0;
	while(fgets(line,sizeof(line), stdin)){
		for(int i = 0; i < LINE && line[i] != '\0' ; i++){
    		if(line[i] >= 97 && line[i] <= 122 && line[i] != '\n' && line[i] != ' ' && line[i] != '\t'){//for only the character between 'a' to 'z'
				word[index++] = line[i];	
			}
     		else if(line[i] == '\n' || line[i] == ' ' || line[i] == '\t' || line[i] == '\0') {
		 		word[index] = '\0';
				insert(node, word);
				index = 0;
	 		}	         
 		}
	}

char temp[LINE];

if(argc > 1 && *(argv[1]) == 'r') PrintR(node, temp, 0);
else{Print(node, temp, 0);}
TrieDestroy(&node);
}

	






