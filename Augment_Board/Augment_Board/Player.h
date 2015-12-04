#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Gesture.h"
#include "Tile.h"
#include "Colour.h"


class Player
{
private:
	Colour faction;
	cv::Scalar colour;
	std::string name;
	Gesture gesture;

public:
	Player(Colour faction, std::string name);
	~Player();
	Colour getFaction();
	std::string getName();
	void setName(std::string name);
	Gesture getGesture();
	void setGesture(Gesture gesture);
	void setColourByType(Tile::Type); //make this a global/static method -- ALREADY USED TWICE JEEZ
};

#endif

