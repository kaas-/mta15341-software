#pragma once
#ifndef HEX_H
#define HEX_H


#include "Colour.h"
#include "opencv2/opencv.hpp"
#include "opencv2/imgproc/imgproc.hpp" 


using namespace std;
using namespace cv;

class Hex
{
private:
	//Tile::Type TileType;
	Scalar colourType;
	vector<Point> points;

public:
	Hex();
	Hex(Scalar colourType, vector<Point> points);
	~Hex();

	const char* getTileName();
	Scalar getColour() { return colourType; };
	void setColour(Scalar s) { colourType = s; };
	vector<Point> getPoints() { return points; };
	bool Pointpoly(Point p);

	void drawHex(Mat image);
};

#endif