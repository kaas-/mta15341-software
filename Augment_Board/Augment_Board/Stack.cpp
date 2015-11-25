#include "Stack.h"
#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;


Stack::Stack() : top(NULL), count(0) {} 

void Stack::push(Point point) //Insert new Node to the beginning of the list.
{
	Node* newTop = new Node; //Prepare the Node
	newTop->point = point; //Set data
	newTop->next = top; //Point to the next data point
	top = newTop; //Put the new node on top
	count++;
}

Point Stack::pop() { //Deletes the topmost Node and returns its data.
	if (top == NULL)
	{
		cout << "Stack empty" << endl; //If pop() is called with no data in the list.
		return NULL;
	}
	else
	{
		Node* oldTop = top; 
		top = top->next; //Next Node in the list is the new top
		Point oldTopPoint = oldTop->point; //Put data in a variable before deletion - this is needed if we want to return the data and stil delete it
		delete(oldTop); 
		count--;
		return oldTopPoint;
	}
}

//Destructor goes through each Node and deletes the data from memory. The nature of the implemeted grassfire algortithm means that this is not strictly necessary
//since that function calls pop() until it reaches the end of the list, thus deleting all of it from memory anyway.
//Still, good coding practice.
Stack::~Stack()
{
	Node* current = top; //Conductor used to go through the list.

	while (current != NULL) //Go through the list until next points to NULL
	{
		Node* next = current->next; //Prepare to go the next Node in the list
		delete(current);
 		current = next; //Go to the next Node.
	}

	top = NULL;
}