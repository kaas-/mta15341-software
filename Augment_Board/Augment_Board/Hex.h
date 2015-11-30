#pragma once
#ifndef HEX_H
#define HEX_H


#include "Colour.h"
#include "opencv2/opencv.hpp"
#include "opencv2/imgproc/imgproc.hpp" 
#include "opencv2/highgui/highgui.hpp"


using namespace std;
using namespace cv;

class Hex
{
private:
	//Tile::Type TileType;
	Scalar colourType;

public:
	Hex();
	Hex(Scalar colourType);
	~Hex();

	/*Scalar getColour();
	void setColour(Scalar colour);
	Scalar getTileType();
	void setTileType(Scalar);*/
	const char* getTileName();
	void drawHex(int x, int y, float h, Mat image, Scalar colour);
};

#endif