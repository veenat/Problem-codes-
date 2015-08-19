#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Structure for the trie node
struct trieNode{
	int isWord;//Keep track if the current node marks the end of a word
	struct trieNode *children[26];//Holds the diiferent characters of the word
};
typedef struct trieNode newNode;

//Structure to keep track of the root node
struct trie{
	newNode *root;
};
typedef struct trie newTrie;

//Create a new trie node
newNode *createNewNode(){
	newNode *newTrieNode = NULL;
	newTrieNode          = (newNode *)malloc(sizeof(newNode));
	if(newTrieNode){
		newTrieNode->isWord  = 0;
		int i;
		for(i=0; i<26; i++){
			newTrieNode->children[i] = NULL;
		}
	}
	return newTrieNode;
}

//Initialize the trie
void trieInitialization(newTrie *trie){
	trie->root = createNewNode();
}

//Insert strings into the trie data structure
void trieInsert(newTrie *trie,char word[]){
	int j;
	int index;
	int wordLength = strlen(word);
	newNode *nodeLevel;
	nodeLevel = trie->root;
	for(j=0; j<wordLength; j++){
		index = word[j]-'a';
		if(nodeLevel->children[index] == NULL){
			nodeLevel->children[index] = createNewNode();
		}
		
		nodeLevel = nodeLevel->children[index];
	}
	nodeLevel->isWord = 1;
}

//Search for a word in a trie
int searchWord(newTrie *trie, char key[]){
	int j;
	int index;
	int wordLength = strlen(key);
	newNode *nodeLevel;
	nodeLevel = trie->root;
	for(j=0; j<wordLength; j++){
		index = key[j]-'a';
		if(nodeLevel->children[index] != NULL){
			nodeLevel = nodeLevel->children[index];
		}
		else{
			return 0;	
		}
		
	}
	if(nodeLevel->isWord == 1){
		return 1;
	}
	else{
		return 0;	
	}
}

int main(void) {
	char *input[3] = {"as","apple","app"};
	int k;
	newTrie trie;
	trieInitialization(&trie);
	for(k=0; k<3; k++){
		trieInsert(&trie,input[k]);
	}
	int check = searchWord(&trie,"apple");
	if(check == 1){
		printf("The word is present in the trie");
	}
	else if(check == 0){
		printf("The word is not present in the trie");
	}
	return 0;
}
