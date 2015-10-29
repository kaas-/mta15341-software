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
	Board(Hex* hex, Gesture terraform);
	~Board();

	void buildBoard(Hex* hex, Gesture gesture);
};

#endif