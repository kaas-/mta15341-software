#ifndef STACK_H
#define STACK_H
#include "opencv2/opencv.hpp"

/*
* Singly Linked List Stack implementation using cv::Point as data
* Can be generalized to any Type with few modifications to the code
* Nodes are pushed to the top and read from the top of the stack.
* Each Node contains a pointer to the next Node.
* Last Node points to NULL.
*/


struct Node{
	cv::Point point;
	Node *next;
};

class Stack {
private:
	Node *top;
	int count;
public:
	void push(cv::Point point);
	cv::Point pop();	
	Node* getTop() { return top; };
	int getCount() { return count; };
	Stack();
	~Stack();
};
#endif