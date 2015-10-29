#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Gesture.h"
#include "Tile.h"

class Player
{
private:
	Tile::Type faction;
	unsigned long int colour;
	std::string name;
	Gesture gesture;

public:
	Player(Tile::Type faction, std::string name, Gesture gesture);
	~Player();
	Tile::Type getFaction();
	std::string getName();
	void setName(std::string name);
	Gesture getGesture();
	void setGesture(Gesture gesture);
	void setColourByType(Tile::Type); //make this a global/static method -- ALREADY USED TWICE JEEZ
};

#endif

