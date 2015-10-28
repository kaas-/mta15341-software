#pragma once
#ifndef HEX_H
#define HEX_H

#include "Tile.h"

class Hex
{
private:
	Tile::Type TileType;
	unsigned long int colour;

public:
	Hex(Tile::Type TileType, unsigned long int colour);
	~Hex();

	unsigned long int getColour();
	void setColour(unsigned long int colour);
};

#endif