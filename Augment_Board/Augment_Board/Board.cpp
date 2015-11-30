#include "Board.h"
#include "Gesture.h"
#include "Colour.h"
#include "opencv2/opencv.hpp" 
#include "opencv2/imgproc/imgproc.hpp" 
#include "opencv2/highgui/highgui.hpp" 

using namespace std;
using namespace cv;

//makes an array of hexes, capable of containing 112 of them

Scalar hexArray[112];
Board::Board(Gesture g, Scalar hexArray)
	: terraform(g), hex(hexArray)
{
}


Board::~Board()
{
}

//method for going through the hex array
//this method probably shouldn't return "void". This should be looked at
void Board::buildBoard()
{




	//plain tiles
	hexArray[0] = Colour::PLAINS;
	hexArray[2] = Colour::PLAINS;
	hexArray[22] = Colour::PLAINS;
	hexArray[30] = Colour::PLAINS;
	hexArray[45] = Colour::PLAINS;
	hexArray[52] = Colour::PLAINS;
	hexArray[60] = Colour::PLAINS;
	hexArray[70] = Colour::PLAINS;
	hexArray[91] = Colour::PLAINS;
	hexArray[109] = Colour::PLAINS;
	hexArray[111] = Colour::PLAINS;
	//River tiles
	hexArray[1] = Colour::RIVER;
	hexArray[5] = Colour::RIVER;
	hexArray[14] = Colour::RIVER;
	hexArray[18] = Colour::RIVER;
	hexArray[19] = Colour::RIVER;
	hexArray[20] = Colour::RIVER;
	hexArray[27] = Colour::RIVER;
	hexArray[28] = Colour::RIVER;
	hexArray[29] = Colour::RIVER;
	hexArray[33] = Colour::RIVER;
	hexArray[34] = Colour::RIVER;
	hexArray[35] = Colour::RIVER;
	hexArray[36] = Colour::RIVER;
	hexArray[42] = Colour::RIVER;
	hexArray[46] = Colour::RIVER;
	hexArray[50] = Colour::RIVER;
	hexArray[51] = Colour::RIVER;
	hexArray[53] = Colour::RIVER;
	hexArray[54] = Colour::RIVER;
	hexArray[59] = Colour::RIVER;
	hexArray[64] = Colour::RIVER;
	hexArray[65] = Colour::RIVER;
	hexArray[67] = Colour::RIVER;
	hexArray[68] = Colour::RIVER;
	hexArray[69] = Colour::RIVER;
	hexArray[72] = Colour::RIVER;
	hexArray[76] = Colour::RIVER;
	hexArray[82] = Colour::RIVER;
	hexArray[85] = Colour::RIVER;
	hexArray[89] = Colour::RIVER;
	hexArray[94] = Colour::RIVER;
	hexArray[97] = Colour::RIVER;
	hexArray[102] = Colour::RIVER;
	hexArray[107] = Colour::RIVER;
	hexArray[110] = Colour::RIVER;
	//mountain tiles
	hexArray[6] = Colour::MOUNTAIN;
	hexArray[16] = Colour::MOUNTAIN;
	hexArray[24] = Colour::MOUNTAIN;
	hexArray[38] = Colour::MOUNTAIN;
	hexArray[58] = Colour::MOUNTAIN;
	hexArray[73] = Colour::MOUNTAIN;
	hexArray[75] = Colour::MOUNTAIN;
	hexArray[78] = Colour::MOUNTAIN;
	hexArray[84] = Colour::MOUNTAIN;
	hexArray[92] = Colour::MOUNTAIN;
	hexArray[100] = Colour::MOUNTAIN;
	//swamp tiles
	hexArray[3] = Colour::SWAMP;
	hexArray[23] = Colour::SWAMP;
	hexArray[26] = Colour::SWAMP;
	hexArray[41] = Colour::SWAMP;
	hexArray[56] = Colour::SWAMP;
	hexArray[61] = Colour::SWAMP;
	hexArray[86] = Colour::SWAMP;
	hexArray[87] = Colour::SWAMP;
	hexArray[90] = Colour::SWAMP;
	hexArray[96] = Colour::SWAMP;
	hexArray[105] = Colour::SWAMP;
	//desert tiles
	hexArray[4] = Colour::DESERT;
	hexArray[10] = Colour::DESERT;
	hexArray[13] = Colour::DESERT;
	hexArray[21] = Colour::DESERT;
	hexArray[32] = Colour::DESERT;
	hexArray[37] = Colour::DESERT;
	hexArray[40] = Colour::DESERT;
	hexArray[77] = Colour::DESERT;
	hexArray[95] = Colour::DESERT;
	hexArray[104] = Colour::DESERT;
	hexArray[106] = Colour::DESERT;
	//forest tiles
	hexArray[7] = Colour::FOREST;
	hexArray[25] = Colour::FOREST;
	hexArray[31] = Colour::FOREST;
	hexArray[39] = Colour::FOREST;
	hexArray[47] = Colour::FOREST;
	hexArray[49] = Colour::FOREST;
	hexArray[57] = Colour::FOREST;
	hexArray[62] = Colour::FOREST;
	hexArray[66] = Colour::FOREST;
	hexArray[81] = Colour::FOREST;
	hexArray[101] = Colour::FOREST;
	//badland tiles
	hexArray[8] = Colour::BADLANDS;
	hexArray[12] = Colour::BADLANDS;
	hexArray[17] = Colour::BADLANDS;
	hexArray[44] = Colour::BADLANDS;
	hexArray[55] = Colour::BADLANDS;
	hexArray[63] = Colour::BADLANDS;
	hexArray[74] = Colour::BADLANDS;
	hexArray[80] = Colour::BADLANDS;
	hexArray[83] = Colour::BADLANDS;
	hexArray[98] = Colour::BADLANDS;
	hexArray[103] = Colour::BADLANDS;
	//lake tiles
	hexArray[9] = Colour::LAKE;
	hexArray[11] = Colour::LAKE;
	hexArray[15] = Colour::LAKE;
	hexArray[43] = Colour::LAKE;
	hexArray[48] = Colour::LAKE;
	hexArray[71] = Colour::LAKE;
	hexArray[79] = Colour::LAKE;
	hexArray[88] = Colour::LAKE;
	hexArray[93] = Colour::LAKE;
	hexArray[99] = Colour::LAKE;
	hexArray[108] = Colour::LAKE;

}
//Tile::Type row1[13] = { Tile::Type::PLAINS, Tile::Type::RIVER , Tile::Type::PLAINS, Tile::Type::SWAMPS, DESERT, Tile::Type::RIVER  , Tile::Type::MOUNTAINS , FOREST  , BADLANDS  , LAKES  , DESERT , LAKES  };
/*Tile::Type colours[112] = { Tile::Type::PLAINS, Tile::Type::RIVER, Tile::Type::PLAINS, Tile::Type::SWAMPS, DESERT, Tile::Type::RIVER, Tile::Type::MOUNTAINS, FOREST, BADLANDS, LAKES, DESERT, LAKES,
BADLANDS, DESERT, Tile::Type::RIVER , LAKES, Tile::Type::MOUNTAINS, BADLANDS, Tile::Type::RIVER , Tile::Type::RIVER , Tile::Type::RIVER , DESERT, Tile::Type::PLAINS, Tile::Type::SWAMPS, Tile::Type::MOUNTAINS,
FOREST, Tile::Type::SWAMPS, Tile::Type::RIVER , Tile::Type::RIVER , Tile::Type::RIVER , Tile::Type::PLAINS, FOREST, DESERT, Tile::Type::RIVER , Tile::Type::RIVER , Tile::Type::RIVER , Tile::Type::RIVER ,
DESERT, Tile::Type::MOUNTAINS, FOREST, DESERT, Tile::Type::SWAMPS, Tile::Type::RIVER , LAKES, BADLANDS, Tile::Type::PLAINS, Tile::Type::RIVER , FOREST, LAKES, FOREST,
Tile::Type::RIVER , Tile::Type::RIVER , Tile::Type::PLAINS, Tile::Type::RIVER , Tile::Type::RIVER , BADLANDS, Tile::Type::SWAMPS, FOREST, Tile::Type::MOUNTAINS, Tile::Type::RIVER , Tile::Type::PLAINS, Tile::Type::SWAMPS,
FOREST, BADLANDS, Tile::Type::RIVER , Tile::Type::RIVER , FOREST, Tile::Type::RIVER , Tile::Type::RIVER , Tile::Type::RIVER , Tile::Type::PLAINS, LAKES, Tile::Type::RIVER , Tile::Type::MOUNTAINS, BADLANDS,
Tile::Type::MOUNTAINS, Tile::Type::RIVER , DESERT, Tile::Type::MOUNTAINS, LAKES, BADLANDS, FOREST, Tile::Type::RIVER , BADLANDS, Tile::Type::MOUNTAINS, Tile::Type::RIVER , Tile::Type::SWAMPS,
Tile::Type::SWAMPS, LAKES, Tile::Type::RIVER , Tile::Type::SWAMPS, Tile::Type::PLAINS, Tile::Type::MOUNTAINS, LAKES, Tile::Type::RIVER , DESERT, Tile::Type::SWAMPS, Tile::Type::RIVER , BADLANDS, LAKES,
Tile::Type::MOUNTAINS, FOREST, Tile::Type::RIVER , BADLANDS, DESERT, Tile::Type::SWAMPS, DESERT, Tile::Type::RIVER , LAKES, Tile::Type::PLAINS, Tile::Type::RIVER , Tile::Type::PLAINS };*/

/*	Scalar colours[112] = { Scalar(0, 75, 150), Scalar(255, 255, 0), Scalar(0, 75, 150), Scalar(0, 0, 0), Scalar(0, 255, 255), Scalar(255, 255, 0), Scalar(179, 179, 179), Scalar(0, 189, 0), Scalar(0, 0, 255), Scalar(255, 0, 0), Scalar(0, 255, 255), Scalar(255, 0, 0),
Scalar(0, 0, 255), Scalar(0, 255, 255), Scalar(255, 255, 0), Scalar(255, 0, 0), Scalar(179, 179, 179), Scalar(0, 0, 255), Scalar(255, 255, 0), Scalar(255, 255, 0), Scalar(255, 255, 0), Scalar(0, 255, 255), Scalar(0, 75, 150), Scalar(0, 0, 0), Scalar(179, 179, 179),
Scalar(0, 189, 0), Scalar(0, 0, 0), Scalar(255, 255, 0), Scalar(255, 255, 0), Scalar(255, 255, 0), Scalar(0, 75, 150), Scalar(0, 189, 0), Scalar(0, 255, 255), Scalar(255, 255, 0), Scalar(255, 255, 0), Scalar(255, 255, 0), Scalar(255, 255, 0),
Scalar(0, 255, 255), Scalar(179, 179, 179), Scalar(0, 189, 0), Scalar(0, 255, 255), Scalar(0, 0, 0), Scalar(255, 255, 0), Scalar(255, 0, 0), Scalar(0, 0, 255), Scalar(0, 75, 150), Scalar(255, 255, 0), Scalar(0, 189, 0), Scalar(255, 0, 0), Scalar(0, 189, 0),
Scalar(255, 255, 0), Scalar(255, 255, 0), Scalar(0, 75, 150), Scalar(255, 255, 0), Scalar(255, 255, 0), Scalar(0, 0, 255), Scalar(0, 0, 0), Scalar(0, 189, 0), Scalar(179, 179, 179), Scalar(255, 255, 0), Scalar(0, 75, 150), Scalar(0, 0, 0),
Scalar(0, 189, 0), Scalar(0, 0, 255), Scalar(255, 255, 0), Scalar(255, 255, 0), Scalar(0, 189, 0), Scalar(255, 255, 0), Scalar(255, 255, 0), Scalar(255, 255, 0), Scalar(0, 75, 150), Scalar(255, 0, 0), Scalar(255, 255, 0), Scalar(179, 179, 179), Scalar(0, 0, 255),
Scalar(179, 179, 179), Scalar(255, 255, 0), Scalar(0, 255, 255), Scalar(179, 179, 179), Scalar(255, 0, 0), Scalar(0, 0, 255), Scalar(0, 189, 0), Scalar(255, 255, 0), Scalar(0, 0, 255), Scalar(179, 179, 179), Scalar(255, 255, 0), Scalar(0, 0, 0),
Scalar(0, 0, 0), Scalar(255, 0, 0), Scalar(255, 255, 0), Scalar(0, 0, 0), Scalar(0, 75, 150), Scalar(179, 179, 179), Scalar(255, 0, 0), Scalar(255, 255, 0), Scalar(0, 255, 255), Scalar(0, 0, 0), Scalar(255, 255, 0), Scalar(0, 0, 255), Scalar(255, 0, 0),
Scalar(179, 179, 179), Scalar(0, 189, 0), Scalar(255, 255, 0), Scalar(0, 0, 255), Scalar(0, 255, 255), Scalar(0, 0, 0), Scalar(0, 255, 255), Scalar(255, 255, 0), Scalar(255, 0, 0), Scalar(0, 75, 150), Scalar(255, 255, 0), Scalar(0, 75, 150) };*/



/*Hex tile;
tile.setColourType(Tile::Type::MOUNTAINS);
tile = drawHex(x2, y + (15 / 2)*r, h, image, tile.getTileType);*/






//currently defining ALL hexes as RIVER tiles. not finale.
//hex[i].setColourType(Tile::Type::RIVER);
//The function that actually draws the board. This needs an´image to print on, some x,y coordinates for the top of the hexes 
//and then it needs an h input which is the distance from the center of the hex to a flat side.
//This function draws nine lines of hexes via for loops that changes the x coodinate every time it runs.
void Board::drawBoard(){
	Mat image;
	Hex hello;
	image = imread("Test1.jpg", CV_LOAD_IMAGE_COLOR);
	int* anchors = new int[112];
	int x1 = 978;
	int x2 = 900;
	int x3 = 978;
	int x4 = 900;
	int x5 = 978;
	int x6 = 900;
	int x7 = 978;
	int x8 = 900;
	int x9 = 978;
	//En optimal løsning ville være at have ét x-koordinat som den så ville kunne tegne hele boardet ud fra. 
	int y = 870;
	int h = 78;
	float r = (2.0 / 3.0) * (sqrt(3.0) * h);
	for (int i = 0; i < 12; i++){
		x1 += 2 * h;
		anchors[i] = x1;
		hello.drawHex(x1, y, h, image, hexArray[i]);
	}
	for (int i = 12; i < 25; i++){
		x2 += 2 * h;
		anchors[i] = x2;
		hello.drawHex(x2, y + ((3 * r) / 2), h, image, hexArray[i]);
	}
	for (int i = 25; i < 37; i++){

		x3 += 2 * h;
		anchors[i] = x3;
		hello.drawHex(x3, y + (3 * r), h, image, hexArray[i]);
	}
	for (int i = 37; i < 50; i++){

		x4 += 2 * h;
		anchors[i] = x4;
		hello.drawHex(x4, y + ((9 * r) / 2), h, image, hexArray[i]);
	}
	for (int i = 50; i < 62; i++){

		x5 += 2 * h;
		anchors[i] = x5;
		hello.drawHex(x5, y + (6 * r), h, image, hexArray[i]);
	}
	for (int i = 62; i < 75; i++){

		x6 += 2 * h;
		anchors[i] = x6;
		hello.drawHex(x6, y + ((15 * r) / 2), h, image, hexArray[i]);
	}
	for (int i = 75; i < 87; i++){

		x7 += 2 * h;
		anchors[i] = x7;
		hello.drawHex(x7, y + (9 * r), h, image, hexArray[i]);
	}
	for (int i = 87; i < 100; i++){

		x8 += 2 * h;
		anchors[i] = x8;
		hello.drawHex(x8, y + ((21 * r) / 2), h, image, hexArray[i]);
	}
	for (int i = 100; i < 112; i++){

		x9 += 2 * h;
		anchors[i] = x9;
		hello.drawHex(x9, y + (12 * r), h, image, hexArray[i]);
	}
	namedWindow("Terra Mystica Board", WINDOW_NORMAL);
	imshow("Terra Mystica Board", image);

	waitKey(0);
}
/*//getters and setters for hex
Hex Board::getHex(int position)
{
return hex[position];
}

void Board::setHex(Hex hexNew, int position)
{
hex[position] = hexNew;
}*/