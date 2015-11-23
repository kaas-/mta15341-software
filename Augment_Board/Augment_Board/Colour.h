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

	void filterColour();
	/*
	//makes a list of colours, and defines the hex codes for each colour
	static const unsigned long int white = 0xFFFFFF;
	static const unsigned long int black = 0x000000;
	static const unsigned long int red = 0xff0000;
	static const unsigned long int blue = 0x0066FF;
	static const unsigned long int green = 0x00CC00;
	static const unsigned long int yellow = 0xFFFF00;
	static const unsigned long int brown = 0x7A5230;
	static const unsigned long int grey = 0xB3B3B3;
	static const unsigned long int teal = 0x4CA6A6;
	*/


	

	
}

;
#endif