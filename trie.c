#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef enum {false=0, true=1} bool;
//Structure for the trie node
struct trieNode{	
	bool isWord;//Keep track if the current node marks the end of a word
	char * word; //Pointer that points to the location of the actual input word
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
		newTrieNode->word = NULL;
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
	for(j=wordLength-1; j>=0; j--){
		index = word[j]-'a';
		if(nodeLevel->children[index] == NULL){
			nodeLevel->children[index] = createNewNode();
		}
		
		nodeLevel = nodeLevel->children[index];
	}
	nodeLevel->isWord = 1;
	nodeLevel->word = word;
}

//Search for a word in a trie
int searchWord(newTrie *trie, char key[]){
	int j;
	int index;
	int wordLength = strlen(key);
	newNode *nodeLevel;
	nodeLevel = trie->root;
	for(j=wordLength-1; j>=0; j--){
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

//Function used to return the rhymes matching the entered word
/*
	In this implementation I'm just displaying the words that have the 
	last letter (first letter) different from the search word.
	Will print the words in increasing order of rhyminess
*/
void returnRhymes(newTrie *trie, char search[]){
	int j,index,i;
	int wordLength = strlen(search);
	newNode *nodeLevel,*tempNodeLevel,*rhymeNodeLevel;
	nodeLevel = trie->root;
	for(j=wordLength-1; j>0; j--){
		index = search[j]-'a';
		
		if(nodeLevel->children[index] != NULL){
			nodeLevel = nodeLevel->children[index];	
			tempNodeLevel = nodeLevel;	
			//At each level check how many complete words are there at the next level
			for(i=0;i<26;i++){
				if(tempNodeLevel->children[i] != NULL){	
					rhymeNodeLevel = tempNodeLevel->children[i];		
					if(rhymeNodeLevel->isWord == 1){
						printf("%s\n",rhymeNodeLevel->word);			
					}			
				}
			}
		}
		else{
			return 0;
		}
	}
	
}

int main(void) {
	char *input[4] = {"thyme","rhyme","me","dime"};	
	int k;
	char *temp;
	newTrie trie;
	trieInitialization(&trie);
	for(k=0; k<4; k++){							
		trieInsert(&trie,input[k]);
	}
	int check = searchWord(&trie,"hello");
	returnRhymes(&trie,"rhyme");
	if(check == 1){
		printf("The word is present in the trie");
	}
	else if(check == 0){
		printf("The word is not present in the trie");
	}
	return 0;
}
