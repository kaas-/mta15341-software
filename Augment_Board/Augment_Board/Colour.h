#pragma once
#ifndef COLOUR_H
#define COLOUR_H

#include <opencv/cv.h>
//#include "Tile.h"

class Colour
{
private:
	Scalar colourType;
	
	
	const Scalar SWAMP;
	const Scalar BADLANDS;
	const Scalar LAKE ;
	const Scalar FOREST ;
	const Scalar DESERT ;
	const Scalar PLAINS ;
	const Scalar MOUNTAIN ;
	const Scalar RIVER ;
	const Scalar DEFAULT;

public:
	Colour();
	Colour(Scalar colourType);
	~Colour();
	
	Scalar getColourType(String);
	void setColourType(Scalar );
	static void filterColour(Scalar);
	


	
}

;
#endif