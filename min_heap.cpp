#include<iostream>

using namespace std;

class MinHeap
{
	int heapArray[10];
	int counter=0;
	
	public:
		//Function to insert the elements into the min heap
		void insert(int element){
			heapArray[counter] = element;
			heapify();
			counter++;
		}
		
		
		//Function to retain the min heap property for the heap
		/*
		To maintain the property of min heap I check if the current inserted element is less than its parent element
		The parent element for the ith element is at the location i-1/2. Keep checking until you reach the root 
		element.
		*/
		void heapify(){
			int tempCounter = counter;
			int tempSwap;
			while(tempCounter != 0){
				if(heapArray[tempCounter] < heapArray[(tempCounter-1)/2])
				{
					tempSwap = heapArray[(tempCounter-1)/2];
					heapArray[(tempCounter-1)/2] = heapArray[tempCounter];
					heapArray[tempCounter] = tempSwap;
				}
				tempCounter = (tempCounter-1)/2;
			}
		}
		
		//Function to display the elements of the min heap
		void displayHeapElements(){
			int i;
			for(i=0; i<counter;i++){
				cout<<heapArray[i]<<"\n";
			}
		}
		
		//Re heapify the min heap after deleting the root
		/*
			Check if the swapped last element is greater than either one of its children, if it is then you 
			swap it with its smaller child 			
		*/
		void reHeapify(){
			int tempCounter = 0;
			int tempSwap;			
			while((heapArray[tempCounter] > heapArray[tempCounter*2+1]) || (heapArray[tempCounter] > heapArray[tempCounter*2+2])){
				if(heapArray[tempCounter] > heapArray[tempCounter*2+1]){
					tempSwap                   = heapArray[tempCounter];
					heapArray[tempCounter]     = heapArray[tempCounter*2+1];
					heapArray[tempCounter*2+1] = tempSwap;
					tempCounter                = tempCounter*2+1;
				}
				else if(heapArray[tempCounter] > heapArray[tempCounter*2+2]){
					tempSwap                   = heapArray[tempCounter];
					heapArray[tempCounter]     = heapArray[tempCounter*2+2];
					heapArray[tempCounter*2+2] = tempSwap;
					tempCounter                = tempCounter*2+2;
				}
			}
		}
		
		//Function to delete the root and reheapify the heap elements
		/*
			Root is replaced by the last element in the heap
		*/
		void deleteElement(){
			int tempCounter;
			tempCounter = counter-1;
			heapArray[0] = heapArray[tempCounter];
			counter--;
			reHeapify();			
		}
};

int main(){
	int n,i,ele;
	MinHeap min;
	cout<<"How many elements do you want to insert?\n";
	cin>>n;
	for(i=0;i<n;i++){
		cout<<"Enter the element\n";
		cin>>ele;
		min.insert(ele);
	}
	cout<<"Entered all the eleemnts\n";
	min.displayHeapElements();	
	min.deleteElement();
	cout<<"After Deletion\n";
	min.displayHeapElements();
	return 0;
}
