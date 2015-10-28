#include "Board.h"
#include "Gesture.h"

Board::Board(Hex h, Gesture g)
	: hex(h), terraform(g)
{
}


Board::~Board()
{
}

//this method probably shouldn't return "void". This should be looked at
void Board::buildBoard(Hex hex[], Gesture terraform)
{

}