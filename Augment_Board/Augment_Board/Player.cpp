#include "Player.h"
#include "Gesture.h"
#include "Colour.h"

//a Player object consists of a tile type (for colour), a string (for name), and a gesture (for starting and ending turns)
Player::Player(Tile::Type t, std::string n, Gesture g)
	: faction(t), name(n), gesture(g)
{
	/*Colours hello; 
	//takes the tile type assigned to the player, and gives it a coresponding colour, just like in hex.cpp
	switch (faction)
	{
	case Tile::Type::BADLANDS:
		colour = Colours::red; //RED
		break;
	case Tile::Type::LAKES:
		colour = Colours::blue; //BLUE
		break;
	case Tile::Type::PLAINS:
		colour = Colours::brown; //BROWN
		break;
	case Tile::Type::DESERT:
		colour = Colours::yellow; //YELLOW
		break;
	case Tile::Type::FOREST:
		colour = Colours::green; //GREEN
		break;
	case Tile::Type::SWAMPS:
		colour = Colours::black; //BLACK LIKE MY SOUL
		break;
	case Tile::Type::MOUNTAINS:
		colour = hello.gray; //GRAY
		break;
	case Tile::Type::RIVER:
		colour = Colours::teal; //TEAL
		break;
	default:
		colour = Colours::white; //WHITE
		break;
	}*/
}

Player::~Player()
{
}

Tile::Type Player::getFaction()
{
	return faction;
}

std::string Player::getName()
{
	return name;
}

void Player::setName(std::string n)
{
	name = n;
}

Gesture Player::getGesture()
{
	return gesture;
}

void Player::setGesture(Gesture g)
{
	gesture = g;
}