#pragma once
#ifndef COLOUR_H
#define COLOUR_H

#include <opencv/cv.h>
#include "Tile.h"

class Colour
{
private:
	cv::Scalar colour;
	Tile::Type colourType;
	
	const cv::Scalar black ;
	const cv::Scalar red;
	const cv::Scalar blue ;
	const cv::Scalar green ;
	const cv::Scalar yellow ;
	const cv::Scalar brown ;
	const cv::Scalar gray ;
	const cv::Scalar teal ;
	const cv::Scalar white;

public:
	Colour(Tile::Type colourType, cv::Scalar colour);
	~Colour();

	static void filterColour(Tile::Type);


	
}

;
#endif