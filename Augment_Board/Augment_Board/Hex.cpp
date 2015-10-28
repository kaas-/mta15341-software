#include "Hex.h"


Hex::Hex(Tile::Type t, unsigned long int c)
	: colour(c), TileType(t)
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
