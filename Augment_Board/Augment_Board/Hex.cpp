#include "Hex.h"
#include "Colours.h"

Hex::Hex(/*Tile::Type t*/)
	:TileType()
{
	
}


Hex::~Hex()
{
}

unsigned long int Hex::getColour()
{
	return colour;
}

void Hex::setColour(unsigned long int c)
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
		colour = Colours::gray; //GRAY
		break;
	case Tile::Type::RIVER:
		colour = Colours::teal; //TEAL
		break;
	default:
		colour = Colours::white; //WHITE
		break;
	}
}



