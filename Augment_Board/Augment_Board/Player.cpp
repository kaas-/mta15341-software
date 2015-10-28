#include "Player.h"
#include "Gesture.h"

Player::Player(unsigned long int c, std::string n, Gesture g)
	: colour(c), name(n), gesture(g)
{
}

Player::~Player()
{
}

unsigned long int Player::getColour()
{
	return colour;
}

void Player::setColour(unsigned long int c)
{
	colour = c;
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