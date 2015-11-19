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
	//plain tiles
	hexArray[0].setTileType(Tile::Type::PLAINS);
	hexArray[2].setTileType(Tile::Type::PLAINS);
	hexArray[22].setTileType(Tile::Type::PLAINS);
	hexArray[30].setTileType(Tile::Type::PLAINS);
	hexArray[45].setTileType(Tile::Type::PLAINS);
	hexArray[52].setTileType(Tile::Type::PLAINS);
	hexArray[60].setTileType(Tile::Type::PLAINS);
	hexArray[70].setTileType(Tile::Type::PLAINS);
	hexArray[91].setTileType(Tile::Type::PLAINS);
	hexArray[109].setTileType(Tile::Type::PLAINS);
	hexArray[111].setTileType(Tile::Type::PLAINS);
	//River tiles
	hexArray[1].setTileType(Tile::Type::RIVER);
	hexArray[5].setTileType(Tile::Type::RIVER);
	hexArray[14].setTileType(Tile::Type::RIVER);
	hexArray[18].setTileType(Tile::Type::RIVER);
	hexArray[19].setTileType(Tile::Type::RIVER);
	hexArray[20].setTileType(Tile::Type::RIVER);
	hexArray[27].setTileType(Tile::Type::RIVER);
	hexArray[28].setTileType(Tile::Type::RIVER);
	hexArray[29].setTileType(Tile::Type::RIVER);
	hexArray[33].setTileType(Tile::Type::RIVER);
	hexArray[34].setTileType(Tile::Type::RIVER);
	hexArray[35].setTileType(Tile::Type::RIVER);
	hexArray[36].setTileType(Tile::Type::RIVER);
	hexArray[42].setTileType(Tile::Type::RIVER);
	hexArray[46].setTileType(Tile::Type::RIVER);
	hexArray[50].setTileType(Tile::Type::RIVER);
	hexArray[51].setTileType(Tile::Type::RIVER);
	hexArray[53].setTileType(Tile::Type::RIVER);
	hexArray[54].setTileType(Tile::Type::RIVER);
	hexArray[59].setTileType(Tile::Type::RIVER);
	hexArray[64].setTileType(Tile::Type::RIVER);
	hexArray[65].setTileType(Tile::Type::RIVER);
	hexArray[67].setTileType(Tile::Type::RIVER);
	hexArray[68].setTileType(Tile::Type::RIVER);
	hexArray[69].setTileType(Tile::Type::RIVER);
	hexArray[72].setTileType(Tile::Type::RIVER);
	hexArray[76].setTileType(Tile::Type::RIVER);
	hexArray[82].setTileType(Tile::Type::RIVER);
	hexArray[85].setTileType(Tile::Type::RIVER);
	hexArray[89].setTileType(Tile::Type::RIVER);
	hexArray[94].setTileType(Tile::Type::RIVER);
	hexArray[97].setTileType(Tile::Type::RIVER);
	hexArray[102].setTileType(Tile::Type::RIVER);
	hexArray[107].setTileType(Tile::Type::RIVER);
	hexArray[110].setTileType(Tile::Type::RIVER);
	//mountain tiles
	hexArray[6].setTileType(Tile::Type::MOUNTAINS);
	hexArray[16].setTileType(Tile::Type::MOUNTAINS);
	hexArray[24].setTileType(Tile::Type::MOUNTAINS);
	hexArray[38].setTileType(Tile::Type::MOUNTAINS);
	hexArray[58].setTileType(Tile::Type::MOUNTAINS);
	hexArray[73].setTileType(Tile::Type::MOUNTAINS);
	hexArray[75].setTileType(Tile::Type::MOUNTAINS);
	hexArray[78].setTileType(Tile::Type::MOUNTAINS);
	hexArray[84].setTileType(Tile::Type::MOUNTAINS);
	hexArray[92].setTileType(Tile::Type::MOUNTAINS);
	hexArray[100].setTileType(Tile::Type::MOUNTAINS);
	//swamp tiles
	hexArray[3].setTileType(Tile::Type::SWAMPS);
	hexArray[23].setTileType(Tile::Type::SWAMPS);
	hexArray[26].setTileType(Tile::Type::SWAMPS);
	hexArray[41].setTileType(Tile::Type::SWAMPS);
	hexArray[56].setTileType(Tile::Type::SWAMPS);
	hexArray[61].setTileType(Tile::Type::SWAMPS);
	hexArray[86].setTileType(Tile::Type::SWAMPS);
	hexArray[87].setTileType(Tile::Type::SWAMPS);
	hexArray[90].setTileType(Tile::Type::SWAMPS);
	hexArray[96].setTileType(Tile::Type::SWAMPS);
	hexArray[105].setTileType(Tile::Type::SWAMPS);
	//desert tiles
	hexArray[4].setTileType(Tile::Type::DESERT);
	hexArray[10].setTileType(Tile::Type::DESERT);
	hexArray[13].setTileType(Tile::Type::DESERT);
	hexArray[21].setTileType(Tile::Type::DESERT);
	hexArray[32].setTileType(Tile::Type::DESERT);
	hexArray[37].setTileType(Tile::Type::DESERT);
	hexArray[40].setTileType(Tile::Type::DESERT);
	hexArray[77].setTileType(Tile::Type::DESERT);
	hexArray[95].setTileType(Tile::Type::DESERT);
	hexArray[104].setTileType(Tile::Type::DESERT);
	hexArray[106].setTileType(Tile::Type::DESERT);
	//forest tiles
	hexArray[7].setTileType(Tile::Type::FOREST);
	hexArray[25].setTileType(Tile::Type::FOREST);
	hexArray[31].setTileType(Tile::Type::FOREST);
	hexArray[39].setTileType(Tile::Type::FOREST);
	hexArray[47].setTileType(Tile::Type::FOREST);
	hexArray[49].setTileType(Tile::Type::FOREST);
	hexArray[57].setTileType(Tile::Type::FOREST);
	hexArray[62].setTileType(Tile::Type::FOREST);
	hexArray[66].setTileType(Tile::Type::FOREST);
	hexArray[81].setTileType(Tile::Type::FOREST);
	hexArray[101].setTileType(Tile::Type::FOREST);
	//badland tiles
	hexArray[8].setTileType(Tile::Type::BADLANDS);
	hexArray[12].setTileType(Tile::Type::BADLANDS);
	hexArray[17].setTileType(Tile::Type::BADLANDS);
	hexArray[44].setTileType(Tile::Type::BADLANDS);
	hexArray[55].setTileType(Tile::Type::BADLANDS);
	hexArray[63].setTileType(Tile::Type::BADLANDS);
	hexArray[74].setTileType(Tile::Type::BADLANDS);
	hexArray[80].setTileType(Tile::Type::BADLANDS);
	hexArray[83].setTileType(Tile::Type::BADLANDS);
	hexArray[98].setTileType(Tile::Type::BADLANDS);
	hexArray[103].setTileType(Tile::Type::BADLANDS);
	//lake tiles
	hexArray[9].setTileType(Tile::Type::LAKES);
	hexArray[11].setTileType(Tile::Type::LAKES);
	hexArray[15].setTileType(Tile::Type::LAKES);
	hexArray[43].setTileType(Tile::Type::LAKES);
	hexArray[48].setTileType(Tile::Type::LAKES);
	hexArray[71].setTileType(Tile::Type::LAKES);
	hexArray[79].setTileType(Tile::Type::LAKES);
	hexArray[88].setTileType(Tile::Type::LAKES);
	hexArray[93].setTileType(Tile::Type::LAKES);
	hexArray[99].setTileType(Tile::Type::LAKES);
	hexArray[108].setTileType(Tile::Type::LAKES);
	
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
	
	
	
	
	/*Hex tile;
	tile.setTileType(Tile::Type::MOUNTAINS);
	tile = drawHex(x2, y + (15 / 2)*r, h, image, tile.getTileType);*/
	
		
		
		
		
		
		//currently defining ALL hexes as RIVER tiles. not finale.
		//hex[i].setTileType(Tile::Type::RIVER);
	
}
void Board::drawBoard(){
	Mat image;
	image = imread("hvid.jpg", CV_LOAD_IMAGE_COLOR);
	int* anchors = new int[13];
	int x1 = 100;
	int x2 = 87;
	int y = 100;
	int h = 13;
	float r = (2.0 / 3.0) * (sqrt(3.0) * h);
	for (int i = 0; i < 13; i++){
		x1 += 2 * 13;
		anchors[i] = x1;
		drawHex(x1, y, h, image, hexArray[i].getTileType());
	}
	for (int i = 12; i < 25; i++){
		x2 += 2 * 13;
		anchors[i] = x2;
		drawHex(x2, y + (3 / 2)*r, h, image, hexArray[i].getTileType());
	}
	for (int i = 0; i < 13; i++){
		x1 = 100;
		x1 += 2 * 13;
		anchors[i] = x1;
		drawHex(x1, y + 3 * r, h, image, hexArray[i].getTileType());
	}
	for (int i = 12; i < 25; i++){
		x2 = 87;
		x2 += 2 * 13;
		anchors[i] = x2;
		drawHex(x2, y + (9 / 2)*r, h, image, hexArray[i].getTileType());
	}
	for (int i = 0; i < 13; i++){
		x1 = 100;
		x1 += 2 * 13;
		anchors[i] = x1;
		drawHex(x1, y + 6 * r, h, image, hexArray[i].getTileType());
	}
	for (int i = 12; i < 25; i++){
		x2 = 87;
		x2 += 2 * 13;
		anchors[i] = x2;
		drawHex(x2, y + (15 / 2)*r, h, image, hexArray[i].getTileType());
	}
	for (int i = 0; i < 13; i++){
		x1 = 100;
		x1 += 2 * 13;
		anchors[i] = x1;
		drawHex(x1, y + 9 * r, h, image, hexArray[i].getTileType());
	}
	for (int i = 12; i < 25; i++){
		x2 = 87;
		x2 += 2 * 13;
		anchors[i] = x2;
		drawHex(x2, y + (21 / 2)*r, h, image, hexArray[i].getTileType());
	}
	for (int i = 0; i < 13; i++){
		x1 = 100;
		x1 += 2 * 13;
		anchors[i] = x1;
		drawHex(x1, y + 12 * r, h, image, hexArray[i].getTileType());
	}
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