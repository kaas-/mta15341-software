#ifndef HEX_H
#define HEH_H

#include <array>

class Hex 
{
private:
	std::array<int, 2> position;
	int colour;
	void setPosition(std::array<int, 2> p) { position = p; };
	Hex() { }
	
public:
	Hex(std::array<int, 2> p);
	void setColour(int c) { colour = c; };
	int getColour() { return colour; };
	std::array<int, 2> getPosition() { return position; };

};
#endif