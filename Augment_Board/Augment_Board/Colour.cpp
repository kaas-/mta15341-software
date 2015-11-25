#include "Colour.h"
using namespace cv;

Colour::Colour()
	: colourType()
{
}

Colour::Colour( const Scalar c)
	:  colourType(c)
{
}


Colour::~Colour()
	
{
}


const Scalar SWAMP = Scalar(0, 0, 0);
const Scalar BADLANDS = Scalar(0, 0, 255);
const Scalar LAKE = Scalar(255, 102, 0);
const Scalar FOREST = Scalar(0, 204, 0);
const Scalar DESERT = Scalar(0, 255, 255);
const Scalar PLAINS = Scalar(48, 82, 122);
const Scalar MOUNTAIN = Scalar(179, 179, 179);
const Scalar RIVER = Scalar(166, 166, 76);
const Scalar DEFAULT = Scalar(255, 255, 255);

Scalar Colour::getColourType(String string){
	if (string == "SWAMP"){
		colourType = Colour::SWAMP;
		return colourType;
	}
	if (string == "BADLANDS"){
		colourType = Colour::BADLANDS;
		return colourType;
	}
	if (string == "LAKE"){
		colourType = Colour::LAKE;
		return colourType;
	}
	if (string == "FOREST"){
		colourType = Colour::FOREST;
		return colourType;
	}
	if (string == "DESERT"){
		colourType = Colour::DESERT;
		return colourType;
	}
	if (string == "PLAINS"){
		colourType = Colour::PLAINS;
		return colourType;
	}
	if (string == "MOUNTAIN"){
		colourType = Colour::MOUNTAIN;
		return colourType;
	}
	if (string == "RIVER"){
		colourType = Colour::RIVER;
		return colourType;
	}
	else{
		colourType = Colour::DEFAULT;
		return colourType;
	}
}
void Colour::setColourType(Scalar c ){
	colourType = c;
	
}


/*void Colour::setColourType(Scalar c){
	colourType = c;
}*/










/*void Colour::filterColour(Scalar colourType)
{
	const Scalar SWAMP = Scalar(0, 0, 0);
	const Scalar BADLANDS = Scalar(0, 0, 255);
	const Scalar LAKE = Scalar(255, 102, 0);
	const Scalar FOREST = Scalar(0, 204, 0);
	const Scalar DESERT = Scalar(0, 255, 255);
	const Scalar PLAINS = Scalar(48, 82, 122);
	const Scalar MOUNTAIN = Scalar(179, 179, 179);
	const Scalar RIVER = Scalar(166, 166, 76);
	const Scalar DEFAULT = Scalar(255, 255, 255);


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
		case Tile::Type::FORST:
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

}*/

