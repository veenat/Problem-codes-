//Program to create a linked list
#include <stdio.h>
#include <stdlib.h>

//Structure of the linked list node
struct linkedListNode{
	int value;
	struct linkedListNode *link;
};


typedef struct linkedListNode newNode;

newNode *head = NULL;

//Create a linked list node
newNode *createNewNode(int value){
	newNode *newLinkedListNode = NULL;
	newLinkedListNode = (newNode *)malloc(sizeof(newNode));
	if(newLinkedListNode){
		newLinkedListNode->value = value;
		newLinkedListNode->link = NULL;
	}
	return newLinkedListNode;
}


//Insert nodes into a linked list
void insertLinkedListNode(int value){
	if(head==NULL){
		head = createNewNode(value);
		//head->link = NULL;
	}
	else{
		newNode *llNode= createNewNode(value);
		//llNode= createNewNode(value);
		if(llNode){
			newNode *temp = head;
			while(temp->link != NULL){
				temp = temp->link;
			}
			temp->link = llNode;
		}
	}

}

//Reversing the linked list nodes
void reverseLinkedList(){
	newNode *prev    = NULL;
	newNode *current = head;
	newNode *next;	
	while(current != NULL){
		next          = current->link;
		current->link = prev;
		prev 		  = current;
		current 	  = next;
	}
	head = prev;
}

//Print all the nodes of a linked list
void printLinkedListNodes(){
	newNode *temp = head;
	while(temp != NULL){
		printf("%d\n",temp->value);
		temp = temp->link;
	}
}

int main(){
	insertLinkedListNode(30);
	insertLinkedListNode(40);
	insertLinkedListNode(50);
	printLinkedListNodes();
	reverseLinkedList();
	printLinkedListNodes();
	return 0;
}
