#include "Stack.h"
#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

Stack::Stack() : top(NULL), count(0) {}

Stack::~Stack()
{
	Node* current = top;

	while (current != NULL)
	{
		Node* next = current->next;
		delete current;
		current = next;
	}

	top = NULL;
}

void Stack::push(Point point)
{
	Node* newTop = new Node;
	newTop->point = point;
	newTop->next = top;
	top = newTop;
	count++;
}

Point Stack::pop() {
	if (top == NULL)
	{
		cout << "Stack empty" << endl;
		return NULL;
	}
	else
	{
		Node* oldTop = top;
		top = top->next;
		Point oldTopPoint = oldTop->point;
		delete(oldTop);
		count--;
		return oldTopPoint;
	}
}