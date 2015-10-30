#include "Board.h"
#include "Gesture.h"

//makes an array of hexes, capable of containing 112 of them
Hex hexArray[112];

Board::Board(Gesture g)
	: hex(hexArray), terraform(g)
{
}


Board::~Board()
{
}

//method for going through the hex array
//this method probably shouldn't return "void". This should be looked at
void Board::buildBoard(Gesture terraform)
{
	for (int i = 0; i < 112; i++)
	{
		//currently defining ALL hexes as RIVER tiles. not finale.
		hex[i].setTileType(Tile::Type::RIVER);
	}
}

//getters and setters for hex
Hex Board::getHex(int position)
{
	return hex[position];
}

void Board::setHex(Hex hexNew, int position)
{
	hex[position] = hexNew;
}