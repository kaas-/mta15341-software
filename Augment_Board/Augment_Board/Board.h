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
	Hex hex;
	Gesture terraform;
	Scalar hexArray[];

public:
	Board(Gesture terraform, Scalar hexArray);
	~Board();

	void buildBoard();
	void drawBoard();
	Scalar getHex(int i) { return hexArray[i]; };
	void setHex(Scalar h, int i) { hexArray[i] = h; };

};

#endif