#include "Hex.h"


Hex::Hex(Tile::Type t, unsigned long int c)
	: colour(c), TileType(t)
{
	switch (TileType)
	{
	case Tile::Type::BADLANDS:
		colour = 0xff0000; //RED
		break;
	case Tile::Type::LAKES: 
		colour = 0x0066FF;
		break;
	default:
		colour = 0xFFFFFF;
		break;
	}
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



