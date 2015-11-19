#pragma once
#ifndef HEX_H
#define HEX_H

#include "Tile.h"
#include "opencv2/opencv.hpp"
#include "opencv2/imgproc/imgproc.hpp" 
#include "opencv2/highgui/highgui.hpp"


using namespace std;
using namespace cv;

class Hex
{
private:
	Tile::Type TileType;
	cv::Scalar colour;

public:
	Hex(/*Tile::Type TileType*/);
	~Hex();

	cv::Scalar getColour();
	void setColour(cv::Scalar colour);
	Tile::Type getTileType();
	void setTileType(Tile::Type);
	const char* getTileName();
	void filterColour();
	void drawHex(int x, int y, float h, Mat image, Tile::Type tiletype);
};

#endif