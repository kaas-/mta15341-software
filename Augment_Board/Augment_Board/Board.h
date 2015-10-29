#pragma once
#ifndef BOARD_H
#define BOARD_H

#include "Gesture.h"
#include "Hex.h"

class Board
{
private:
	Hex* hex;
	Gesture terraform;

public:
	Board(Gesture terraform);
	~Board();

	void buildBoard(Gesture);
	Hex getHex(int);
	void setHex(Hex, int);

};

#endif