#include "Colour.h"


Colour::Colour(Tile::Type t, const cv::Scalar c)
	: colourType(t), colour(c)
{
}


Colour::~Colour()
	
{
}

void Colour::filterColour(Tile::Type colourType)
{
	const cv::Scalar black = cv::Scalar(0, 0, 0);
	const cv::Scalar red = cv::Scalar(0, 0, 255);
	const cv::Scalar blue = cv::Scalar(255, 102, 0);
	const cv::Scalar green = cv::Scalar(0, 204, 0);
	const cv::Scalar yellow = cv::Scalar(0, 255, 255);
	const cv::Scalar brown = cv::Scalar(48, 82, 122);
	const cv::Scalar gray = cv::Scalar(179, 179, 179);
	const cv::Scalar teal = cv::Scalar(166, 166, 76);
	const cv::Scalar white = cv::Scalar(255, 255, 255);

	cv::Scalar colour;
	//Tile::Type colourType;


	switch (colourType)
		{
		case Tile::Type::BADLANDS:
			colour = red; //RED
			break;
		case Tile::Type::LAKES:
			colour = blue; //BLUE
			break;
		case Tile::Type::PLAINS:
			colour = brown; //BROWN
			break;
		case Tile::Type::DESERT:
			colour = yellow; //YELLOW
			break;
		case Tile::Type::FOREST:
			colour = green; //GREEN
			break;
		case Tile::Type::SWAMPS:
			colour = black; //BLACK LIKE MY SOUL
			break;
		case Tile::Type::MOUNTAINS:
			colour = gray; //GRAY
			break;
		case Tile::Type::RIVER:
			colour = teal; //TEAL
			break;
		default:
			colour = white; //WHITE
			break;
		
	}

}

