#include "Hex.h"
#include "opencv2/opencv.hpp"
#include "opencv2/imgproc/imgproc.hpp" 
#include "opencv2/highgui/highgui.hpp"
using namespace std;
using namespace cv;

Hex::Hex()
	:colourType()
{

}



Hex::Hex(Scalar t)
	:colourType(t)
{
	
}


Hex::~Hex()
{
}
/*
cv::Scalar Hex::getColour()
{
	return colourType;
}

void Hex::setColour(cv::Scalar c)
{
	colourType = c;
}

Scalar Hex::getTileType()
{
	return colourType;
}*/

//here we get a tile type from the tile.h and return a string with its name
/*const char* Hex::getTileName()
{
	switch (TileType)
	{
	case Tile::Type::BADLANDS:
		return "Badlands";
		break;
	case Tile::Type::LAKES:
		return "Lakes";
		break;
	case Tile::Type::PLAINS:
		return "Plains";
		break;
	case Tile::Type::DESERT:
		return "Desert";
		break;
	case Tile::Type::FOREST:
		return "Forest";
		break;
	case Tile::Type::SWAMPS:
		return "Swamps";
		break;
	case Tile::Type::MOUNTAINS:
		return "Mountains";
		break;
	case Tile::Type::RIVER:
		return "River";
		break;
	default:
		return "Doesn't have a type";
		break;
	}
}*/

//the tile type we just got is then assigned to a hex object
/*void Hex::setTileType(Scalar t)
{
	colourType = t;
	Colour::filterColour(colourType);
}*/


//This draws the actual hex
vector<Point> Hex::drawHex(int x, int y, float h, Mat image, Scalar colour ){
	float r = (2.0 / 3.0) * (sqrt(3.0) * h);
	
		Point a(x, y);
		Point b(x + h, y + (0.5*r));
		Point c(x + h, y + (1.5*r));
		Point d(x, y + (2 * r));
		Point e(x - h, y + (1.5*r));
		Point f(x- h, y + (0.5*r));
		Point points[6] = { a, b, c, d, e, f };
		vector<Point> pointsVec = { a, b, c, d, e, f };
		
		fillConvexPoly(image, points, 6, colour, LINE_8,0);

		//cout << "\n" << pointPolygonTest(pointsVec, Point(x+1, y+1), false);
		return pointsVec;

	}
void Hex::changeHex(int x, int y, float h, Mat image, Scalar colour, bool gesture){

}
	





