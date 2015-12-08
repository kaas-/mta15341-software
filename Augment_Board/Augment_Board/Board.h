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
	Scalar hexArray[112];
	vector<Hex> HexPoints;

public:


	Board();
	~Board();

	void buildHex(int x, int y, float h, Scalar colour);
	void buildBoard();
	void drawBoard(Mat image);
	void changeHex(int i, Scalar s) { HexPoints[i].setColour(s); };
	Hex getHex(int i) { return HexPoints[i]; };
	
};

#endif