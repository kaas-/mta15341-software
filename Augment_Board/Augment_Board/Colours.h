#pragma once
#ifndef COLOURS_H
#define COLOURS_H

#include <opencv/cv.h>
#include "Tile.h"

class Colours
{
private:
	cv::Scalar colour;

public:
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

	
	const cv::Scalar black = cv::Scalar(0, 0, 0);
	const cv::Scalar red = cv::Scalar(0, 0, 255);
	const cv::Scalar blue = cv::Scalar(255, 102, 0);
	const cv::Scalar green = cv::Scalar(0, 204, 0);
	const cv::Scalar yellow = cv::Scalar(0, 255, 255);
	const cv::Scalar brown = cv::Scalar(48, 82, 122);
	const cv::Scalar grey = cv::Scalar(179, 179, 179);
	const cv::Scalar teal = cv::Scalar(166, 166, 76);
	const cv::Scalar white = cv::Scalar(255, 255, 255);
	
	void filterColour()
	{
		switch (Tile::Type)
		{
		case Tile::Type::BADLANDS:
			colour = red; //RED
			break;
		case Tile::Type::LAKES:
			colour = Colours::blue; //BLUE
			break;
		case Tile::Type::PLAINS:
			colour = Colours::brown; //BROWN
			break;
		case Tile::Type::DESERT:
			colour = Colours::yellow; //YELLOW
			break;
		case Tile::Type::FOREST:
			colour = Colours::green; //GREEN
			break;
		case Tile::Type::SWAMPS:
			colour = Colours::black; //BLACK LIKE MY SOUL
			break;
		case Tile::Type::MOUNTAINS:
			colour = Colours::grey; //GRAY
			break;
		case Tile::Type::RIVER:
			colour = Colours::teal; //TEAL
			break;
		default:
			colour = Colours::white; //WHITE
			break;
		}
	}
};
#endif