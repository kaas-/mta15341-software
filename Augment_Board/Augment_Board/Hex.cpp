#include "Hex.h"
#include "Colour.h"
#include "opencv2/opencv.hpp"
#include "opencv2/imgproc/imgproc.hpp" 
#include "opencv2/highgui/highgui.hpp"
using namespace std;
using namespace cv;

Hex::Hex(/*Tile::Type t*/)
	:TileType()
{
	
}


Hex::~Hex()
{
}

cv::Scalar Hex::getColour()
{
	return colour;
}

void Hex::setColour(cv::Scalar c)
{
	colour = c;
}

Tile::Type Hex::getTileType()
{
	return TileType;
}

//here we get a tile type from the tile.h and return a string with its name
const char* Hex::getTileName()
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
}

//the tile type we just got is then assigned to a hex object
void Hex::setTileType(Tile::Type t)
{
	TileType = t;
	filterColour();
}

//this takes the type of the hex, and assigns it a corresponding colour, just like in player.cpp
void Hex::filterColour()
{
	/*Colours hello;
	switch (TileType)
	{
	case Tile::Type::BADLANDS:
		setColour(Colours::red);
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
		colour = hello.gray; //GRAY
		break;
	case Tile::Type::RIVER:
		colour = Colours::teal; //TEAL
		break;
	default:
		colour = Colours::white; //WHITE
		break;
	}*/
}

//This draws the actual hex
void Hex::drawHex(int x, int y, float h, Mat image, Tile::Type tiletype){
	float r = (2.0 / 3.0) * (sqrt(3.0) * h);
	
		Point a(x, y);
		Point b(x + h, y + (0.5*r));
		Point c(x + h, y + (1.5*r));
		Point d(x, y + (2 * r));
		Point e(x - h, y + (1.5*r));
		Point f(x- h, y + (0.5*r));
		Point points[6] = { a, b, c, d, e, f };

		fillConvexPoly(image, points, 6, colour, LINE_8,0);
	}





