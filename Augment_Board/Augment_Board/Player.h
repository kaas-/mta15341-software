#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Gesture.h"
#include "Tile.h"


class Player
{
private:

	cv::Scalar faction;
	std::string name;
	Gesture gesture;

public:

	Player(cv::Scalar faction, std::string name);
	Player();
	~Player();
	cv::Scalar getFaction();
	std::string getName();
	void setName(std::string name);
	Gesture getGesture();
	void setGesture(Gesture gesture);
	void setColour(cv::Scalar s) { faction = s; }; //make this a global/static method -- ALREADY USED TWICE JEEZ
};

#endif

