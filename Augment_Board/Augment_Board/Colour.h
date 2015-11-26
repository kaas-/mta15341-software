#pragma once
#ifndef COLOUR_H
#define COLOUR_H

#include <opencv/cv.h>
//#include "Tile.h"

class Colour
{
private:
	const Scalar colourType;
	
	
	
public:
	Colour();
	Colour(const Scalar colourType);
	~Colour();
	
	Scalar getColourType(String);
	void setColourType(Scalar );
	static void filterColour(Scalar);
	
	static const Scalar SWAMP;
	static const Scalar BADLANDS;
	static const Scalar LAKE;
	static const Scalar FOREST;
	static const Scalar DESERT;
	static const Scalar PLAINS;
	static const Scalar MOUNTAIN;
	static const Scalar RIVER;
	static const Scalar DEFAULT;


	
}

;
#endif