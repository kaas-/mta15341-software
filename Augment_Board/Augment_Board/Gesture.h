#pragma once
#ifndef GESTURE_H
#define GESTURE_H

#include <string>
#include <opencv/cv.h>

class Gesture
{
private:
	cv::Mat inputBlob;
	cv::Mat knownBlob;
public:
	Gesture(cv::Mat inputBlob, cv::Mat knownBlob);
	~Gesture();
	cv::Mat getInputBlob();
	void setInputBlob(cv::Mat inputBlob);
	bool compareBlob(cv::Mat inputBlob, cv::Mat knownBlob);
};

#endif

