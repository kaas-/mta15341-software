#ifndef STACK_H
#define STACK H
#include "opencv2/opencv.hpp"

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