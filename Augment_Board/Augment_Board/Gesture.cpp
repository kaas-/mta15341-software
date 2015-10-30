#include "Gesture.h"

//a gesture object takes a blob as input, and a known blob to compare it to.
Gesture::Gesture(cv::Mat i, cv::Mat k)
	: inputBlob(i), knownBlob(k)
{
}

Gesture::~Gesture()
{
}

//getters and setters for a gesture object
cv::Mat Gesture::getInputBlob()
{
	return inputBlob;
}

void Gesture::setInputBlob(cv::Mat i)
{
	inputBlob = i;
}


bool Gesture::compareBlob(cv::Mat inputBlob, cv::Mat knownBlob)
{
	return true;
	/*
	this is a method, which should compare the input blob from the camera with a known blob, in order to identify gestures.
	this can be done, by comparing the histograms.

	if (inputBlob == knownBlob)
	{
		return true;
	}
	else
	{
		return false;
	}	
	*/
}