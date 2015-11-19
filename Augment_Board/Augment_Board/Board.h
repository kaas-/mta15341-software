#pragma once
#ifndef BOARD_H
#define BOARD_H

#include "Gesture.h"
#include "Hex.h"

using namespace std;
using namespace cv;

class Board
{
private:
	Hex* hex;
	Gesture terraform;

public:
	Board(Gesture terraform);
	~Board();

	void buildBoard();
	Hex getHex(int);
	void setHex(Hex, int);
	Hex drawHex(int x, int y, float h, Mat image, Tile::Type tiletype);

};

#endif