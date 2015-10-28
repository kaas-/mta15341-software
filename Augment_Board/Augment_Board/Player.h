#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Gesture.h"

class Player
{
private:
	unsigned long int colour;
	std::string name;
	Gesture gesture;

public:
	Player(unsigned long int colour, std::string name, Gesture gesture);
	~Player();
	unsigned long int getColour();
	void setColour(unsigned long int colour);
	std::string getName();
	void setName(std::string name);
	Gesture getGesture();
	void setGesture(Gesture gesture);
};

#endif

