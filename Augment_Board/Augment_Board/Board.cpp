#include "Board.h"
#include "Gesture.h"

Hex hexArray[112];

Board::Board(Gesture g)
	: hex(hexArray), terraform(g)
{
}


Board::~Board()
{
}

//this method probably shouldn't return "void". This should be looked at
void Board::buildBoard(Gesture terraform)
{
	for (int i = 0; i < 112; i++)
	{
		hex[i].setTileType(Tile::Type::RIVER);
	}
}

Hex Board::getHex(int position)
{
	return hex[position];
}

void Board::setHex(Hex hexNew, int position)
{
	hex[position] = hexNew;
}