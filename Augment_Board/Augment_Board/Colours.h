#pragma once
#ifndef COLOURS_H
#define COLOURS_H

class Colours
{
public:
	//makes a list of colours, and defines the hex codes for each colour
	static const unsigned long int white = 0xFFFFFF;
	static const unsigned long int black = 0x000000;
	static const unsigned long int red = 0xff0000;
	static const unsigned long int blue = 0x0066FF;
	static const unsigned long int green = 0x00CC00;
	static const unsigned long int yellow = 0xFFFF00;
	const cv::Scalar gray = cv::Scalar(179, 179, 179);
	
	static const unsigned long int brown = 0x7A5230;
	static const unsigned long int teal = 0x4CA6A6;
};
#endif