#include "Board.h"
#include "Gesture.h"
#include "opencv2/opencv.hpp" 
#include "opencv2/imgproc/imgproc.hpp" 
#include "opencv2/highgui/highgui.hpp" 

using namespace std;
using namespace cv;

//makes an array of hexes, capable of containing 112 of them
Hex hexArray[112];

Board::Board(Gesture g)
	: hex(hexArray), terraform(g)
{
}


Board::~Board()
{
}

//method for going through the hex array
//this method probably shouldn't return "void". This should be looked at
void Board::buildBoard()
{
	Mat image;
	image = imread("hvid.jpg", CV_LOAD_IMAGE_COLOR);
	int* anchors = new int[13];
	int x1 = 100;
	int x2 = 87;
	int y = 100;
	int h = 13; 
	float r = (2.0 / 3.0) * (sqrt(3.0) * h);

	//hexArray[7, 17, 25, 39, 59, 73, 75, 78, 84, 91, 99].setTileType(Tile::Type::MOUNTAINS); 
	hexArray[7].setTileType(Tile::Type::MOUNTAINS);
	hexArray[17].setTileType(Tile::Type::MOUNTAINS);
	hexArray[25].setTileType(Tile::Type::MOUNTAINS);
	hexArray[39].setTileType(Tile::Type::MOUNTAINS);
	hexArray[59].setTileType(Tile::Type::MOUNTAINS);
	hexArray[73].setTileType(Tile::Type::MOUNTAINS);
	hexArray[75].setTileType(Tile::Type::MOUNTAINS);
	hexArray[78].setTileType(Tile::Type::MOUNTAINS);
	hexArray[84].setTileType(Tile::Type::MOUNTAINS);
	hexArray[91].setTileType(Tile::Type::MOUNTAINS);
	hexArray[99].setTileType(Tile::Type::MOUNTAINS);



	cout << hexArray[7].getTileType();
	cout << hexArray[17].getTileType();
	cout << hexArray[25].getTileType();
	cout << hexArray[39].getTileType();
	cout << hexArray[59].getTileType();
	cout << hexArray[73].getTileType();
	cout << hexArray[75].getTileType();
	cout << hexArray[78].getTileType();
	cout << hexArray[84].getTileType();
	cout << hexArray[91].getTileType();
	cout << hexArray[99].getTileType();
	

	//Tile::Type row1[13] = { Tile::Type::PLAINS, Tile::Type::RIVER , Tile::Type::PLAINS, Tile::Type::SWAMPS, Tile::Type::DESERT, Tile::Type::RIVER  , Tile::Type::MOUNTAINS , Tile::Type::FOREST  , Tile::Type::BADLANDS  , Tile::Type::LAKES  , Tile::Type::DESERT , Tile::Type::LAKES  };
	/*Tile::Type colours[112] = { Tile::Type::PLAINS, Tile::Type::RIVER, Tile::Type::PLAINS, Tile::Type::SWAMPS, Tile::Type::DESERT, Tile::Type::RIVER, Tile::Type::MOUNTAINS, Tile::Type::FOREST, Tile::Type::BADLANDS, Tile::Type::LAKES, Tile::Type::DESERT, Tile::Type::LAKES,
		Tile::Type::BADLANDS, Tile::Type::DESERT, Tile::Type::RIVER , Tile::Type::LAKES, Tile::Type::MOUNTAINS, Tile::Type::BADLANDS, Tile::Type::RIVER , Tile::Type::RIVER , Tile::Type::RIVER , Tile::Type::DESERT, Tile::Type::PLAINS, Tile::Type::SWAMPS, Tile::Type::MOUNTAINS,
		Tile::Type::FOREST, Tile::Type::SWAMPS, Tile::Type::RIVER , Tile::Type::RIVER , Tile::Type::RIVER , Tile::Type::PLAINS, Tile::Type::FOREST, Tile::Type::DESERT, Tile::Type::RIVER , Tile::Type::RIVER , Tile::Type::RIVER , Tile::Type::RIVER ,
		Tile::Type::DESERT, Tile::Type::MOUNTAINS, Tile::Type::FOREST, Tile::Type::DESERT, Tile::Type::SWAMPS, Tile::Type::RIVER , Tile::Type::LAKES, Tile::Type::BADLANDS, Tile::Type::PLAINS, Tile::Type::RIVER , Tile::Type::FOREST, Tile::Type::LAKES, Tile::Type::FOREST,
		Tile::Type::RIVER , Tile::Type::RIVER , Tile::Type::PLAINS, Tile::Type::RIVER , Tile::Type::RIVER , Tile::Type::BADLANDS, Tile::Type::SWAMPS, Tile::Type::FOREST, Tile::Type::MOUNTAINS, Tile::Type::RIVER , Tile::Type::PLAINS, Tile::Type::SWAMPS,
		Tile::Type::FOREST, Tile::Type::BADLANDS, Tile::Type::RIVER , Tile::Type::RIVER , Tile::Type::FOREST, Tile::Type::RIVER , Tile::Type::RIVER , Tile::Type::RIVER , Tile::Type::PLAINS, Tile::Type::LAKES, Tile::Type::RIVER , Tile::Type::MOUNTAINS, Tile::Type::BADLANDS,
		Tile::Type::MOUNTAINS, Tile::Type::RIVER , Tile::Type::DESERT, Tile::Type::MOUNTAINS, Tile::Type::LAKES, Tile::Type::BADLANDS, Tile::Type::FOREST, Tile::Type::RIVER , Tile::Type::BADLANDS, Tile::Type::MOUNTAINS, Tile::Type::RIVER , Tile::Type::SWAMPS,
		Tile::Type::SWAMPS, Tile::Type::LAKES, Tile::Type::RIVER , Tile::Type::SWAMPS, Tile::Type::PLAINS, Tile::Type::MOUNTAINS, Tile::Type::LAKES, Tile::Type::RIVER , Tile::Type::DESERT, Tile::Type::SWAMPS, Tile::Type::RIVER , Tile::Type::BADLANDS, Tile::Type::LAKES,
		Tile::Type::MOUNTAINS, Tile::Type::FOREST, Tile::Type::RIVER , Tile::Type::BADLANDS, Tile::Type::DESERT, Tile::Type::SWAMPS, Tile::Type::DESERT, Tile::Type::RIVER , Tile::Type::LAKES, Tile::Type::PLAINS, Tile::Type::RIVER , Tile::Type::PLAINS };*/
	
	
	
	/*for (int i = 0; i < 13; i++){
		x1 += 2 * 13;
		anchors[i] = x1;
		drawHex(x1, y, h, image, colours[i]);
	}
	for (int i = 12; i < 25; i++){
		x2 += 2 * 13;
		anchors[i] = x2; 
		drawHex(x2, y + (3 / 2)*r, h, image, colours[i]);
	}
	for (int i = 0; i < 13; i++){
		x1 = 100;
		x1 += 2 * 13;
		anchors[i] = x1;
		drawHex(x1, y+3*r, h, image, colours[i]);
	}
	for (int i = 12; i < 25; i++){
		x2 = 87;
		x2 += 2 * 13;
		anchors[i] = x2;
		drawHex(x2, y + (9 / 2)*r, h, image, colours[i]);
	}
	for (int i = 0; i < 13; i++){
		x1 = 100;
		x1 += 2 * 13;
		anchors[i] = x1;
		drawHex(x1, y + 6 * r, h, image, colours[i]);
	}
	for (int i = 12; i < 25; i++){
		x2 = 87;
		x2 += 2 * 13;
		anchors[i] = x2;
		drawHex(x2, y + (15 / 2)*r, h, image, colours[i]);
	}
	for (int i = 0; i < 13; i++){
		x1 = 100;
		x1 += 2 * 13;
		anchors[i] = x1;
		drawHex(x1, y + 9 * r, h, image, colours[i]);
	}
	for (int i = 12; i < 25; i++){
		x2 = 87;
		x2 += 2 * 13;
		anchors[i] = x2;
		drawHex(x2, y + (21 / 2)*r, h, image, colours[i]);
	}
	for (int i = 0; i < 13; i++){
		x1 = 100;
		x1 += 2 * 13;
		anchors[i] = x1;
		drawHex(x1, y + 12 * r, h, image, colours[i]);
	}*/
	/*Hex tile;
	tile.setTileType(Tile::Type::MOUNTAINS);
	tile = drawHex(x2, y + (15 / 2)*r, h, image, tile.getTileType);*/
	
		
		
		
		
		
		//currently defining ALL hexes as RIVER tiles. not finale.
		//hex[i].setTileType(Tile::Type::RIVER);
	
}

//getters and setters for hex
Hex Board::getHex(int position)
{
	return hex[position];
}

void Board::setHex(Hex hexNew, int position)
{
	hex[position] = hexNew;
}