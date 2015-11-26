#pragma once
#ifndef COLOUR_H
#define COLOUR_H

#include <opencv/cv.h>
//#include "Tile.h"

class Colour
{
private:
	const cv::Scalar colourType;
	
	
	
public:
	Colour();
	Colour(const cv::Scalar colourType);
	~Colour();
	
	/*Scalar getColourType(String);
	void setColourType(Scalar );*/
//	static void filterColour(Scalar);
	
	static const cv::Scalar SWAMP;
	static const cv::Scalar BADLANDS;
	static const cv::Scalar LAKE;
	static const cv::Scalar FOREST;
	static const cv::Scalar DESERT;
	static const cv::Scalar PLAINS;
	static const cv::Scalar MOUNTAIN;
	static const cv::Scalar RIVER;
	static const cv::Scalar DEFAULT;


	
}

;
#endif