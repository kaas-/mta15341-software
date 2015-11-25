#include "Board.h"
#include "Gesture.h"
#include "Colour.h"
#include "opencv2/opencv.hpp" 
#include "opencv2/imgproc/imgproc.hpp" 
#include "opencv2/highgui/highgui.hpp" 

using namespace std;
using namespace cv;

//makes an array of hexes, capable of containing 112 of them


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
	Colour hexArray[112];
	Colour p;
	p.getColourType("PLAINS"); 
	p.setColourType(); 


	//plain tiles
	hexArray[0].setColourType(Colour::PLAINS);
	hexArray[2].setColourType(PLAINS);
	hexArray[22].setColourType(PLAINS);
	hexArray[30].setColourType(PLAINS);
	hexArray[45].setColourType(PLAINS);
	hexArray[52].setColourType(PLAINS);
	hexArray[60].setColourType(PLAINS);
	hexArray[70].setColourType(PLAINS);
	hexArray[91].setColourType(PLAINS);
	hexArray[109].setColourType(PLAINS);
	hexArray[111].setColourType(PLAINS);
	//River tiles
	hexArray[1].setColourType(RIVER);
	hexArray[5].setColourType(RIVER);
	hexArray[14].setColourType(RIVER);
	hexArray[18].setColourType(RIVER);
	hexArray[19].setColourType(RIVER);
	hexArray[20].setColourType(RIVER);
	hexArray[27].setColourType(RIVER);
	hexArray[28].setColourType(RIVER);
	hexArray[29].setColourType(RIVER);
	hexArray[33].setColourType(RIVER);
	hexArray[34].setColourType(RIVER);
	hexArray[35].setColourType(RIVER);
	hexArray[36].setColourType(RIVER);
	hexArray[42].setColourType(RIVER);
	hexArray[46].setColourType(RIVER);
	hexArray[50].setColourType(RIVER);
	hexArray[51].setColourType(RIVER);
	hexArray[53].setColourType(RIVER);
	hexArray[54].setColourType(RIVER);
	hexArray[59].setColourType(RIVER);
	hexArray[64].setColourType(RIVER);
	hexArray[65].setColourType(RIVER);
	hexArray[67].setColourType(RIVER);
	hexArray[68].setColourType(RIVER);
	hexArray[69].setColourType(RIVER);
	hexArray[72].setColourType(RIVER);
	hexArray[76].setColourType(RIVER);
	hexArray[82].setColourType(RIVER);
	hexArray[85].setColourType(RIVER);
	hexArray[89].setColourType(RIVER);
	hexArray[94].setColourType(RIVER);
	hexArray[97].setColourType(RIVER);
	hexArray[102].setColourType(RIVER);
	hexArray[107].setColourType(RIVER);
	hexArray[110].setColourType(RIVER);
	//mountain tiles
	hexArray[6].setColourType(MOUNTAINS);
	hexArray[16].setColourType(MOUNTAINS);
	hexArray[24].setColourType(MOUNTAINS);
	hexArray[38].setColourType(MOUNTAINS);
	hexArray[58].setColourType(MOUNTAINS);
	hexArray[73].setColourType(MOUNTAINS);
	hexArray[75].setColourType(MOUNTAINS);
	hexArray[78].setColourType(MOUNTAINS);
	hexArray[84].setColourType(MOUNTAINS);
	hexArray[92].setColourType(MOUNTAINS);
	hexArray[100].setColourType(MOUNTAINS);
	//swamp tiles
	hexArray[3].setColourType(SWAMPS);
	hexArray[23].setColourType(SWAMPS);
	hexArray[26].setColourType(SWAMPS);
	hexArray[41].setColourType(SWAMPS);
	hexArray[56].setColourType(SWAMPS);
	hexArray[61].setColourType(SWAMPS);
	hexArray[86].setColourType(SWAMPS);
	hexArray[87].setColourType(SWAMPS);
	hexArray[90].setColourType(SWAMPS);
	hexArray[96].setColourType(SWAMPS);
	hexArray[105].setColourType(SWAMPS);
	//desert tiles
	hexArray[4].setColourType(DESERT);
	hexArray[10].setColourType(DESERT);
	hexArray[13].setColourType(DESERT);
	hexArray[21].setColourType(DESERT);
	hexArray[32].setColourType(DESERT);
	hexArray[37].setColourType(DESERT);
	hexArray[40].setColourType(DESERT);
	hexArray[77].setColourType(DESERT);
	hexArray[95].setColourType(DESERT);
	hexArray[104].setColourType(DESERT);
	hexArray[106].setColourType(DESERT);
	//forest tiles
	hexArray[7].setColourType(FOREST);
	hexArray[25].setColourType(FOREST);
	hexArray[31].setColourType(FOREST);
	hexArray[39].setColourType(FOREST);
	hexArray[47].setColourType(FOREST);
	hexArray[49].setColourType(FOREST);
	hexArray[57].setColourType(FOREST);
	hexArray[62].setColourType(FOREST);
	hexArray[66].setColourType(FOREST);
	hexArray[81].setColourType(FOREST);
	hexArray[101].setColourType(FOREST);
	//badland tiles
	hexArray[8].setColourType(BADLANDS);
	hexArray[12].setColourType(BADLANDS);
	hexArray[17].setColourType(BADLANDS);
	hexArray[44].setColourType(BADLANDS);
	hexArray[55].setColourType(BADLANDS);
	hexArray[63].setColourType(BADLANDS);
	hexArray[74].setColourType(BADLANDS);
	hexArray[80].setColourType(BADLANDS);
	hexArray[83].setColourType(BADLANDS);
	hexArray[98].setColourType(BADLANDS);
	hexArray[103].setColourType(BADLANDS);
	//lake tiles
	hexArray[9].setColourType(LAKES);
	hexArray[11].setColourType(LAKES);
	hexArray[15].setColourType(LAKES);
	hexArray[43].setColourType(LAKES);
	hexArray[48].setColourType(LAKES);
	hexArray[71].setColourType(LAKES);
	hexArray[79].setColourType(LAKES);
	hexArray[88].setColourType(LAKES);
	hexArray[93].setColourType(LAKES);
	hexArray[99].setColourType(LAKES);
	hexArray[108].setColourType(LAKES);

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

void Board::drawBoard(){
	Mat image;
	Hex hello;
	image = imread("hvid.jpg", CV_LOAD_IMAGE_COLOR);
	int* anchors = new int[112];
	int x1 = 100;
	int x2 = 87;
	int x3 = 100;
	int x4 = 87;
	int x5 = 100;
	int x6 = 87;
	int x7 = 100;
	int x8 = 87;
	int x9 = 100;
	//En optimal løsning ville være at have ét x-koordinat som den så ville kunne tegne hele boardet ud fra. 
	int y = 100;
	int h = 13;
	float r = (2.0 / 3.0) * (sqrt(3.0) * h);
	for (int i = 0; i < 12; i++){
		x1 += 2 * 13;
		anchors[i] = x1;
		hello.drawHex(x1, y, h, image, colours[i]/*hexArray[i].getTileType()*/);
	}
	for (int i = 12; i < 25; i++){
		x2 += 2 * 13;
		anchors[i] = x2;
		hello.drawHex(x2, y + ((3 * r) / 2), h, image, colours[i] /*hexArray[i].getTileType()*/);
	}
	for (int i = 25; i < 37; i++){
	
		x3 += 2 * 13;
		anchors[i] = x3;
		hello.drawHex(x3, y + (3 * r), h, image, colours[i] /*hexArray[i].getTileType()*/);
	}
	for (int i = 37; i < 50; i++){

		x4 += 2 * 13;
		anchors[i] = x4;
		hello.drawHex(x4, y + ((9 * r) / 2), h, image, colours[i] /*hexArray[i].getTileType()*/);
	}
	for (int i = 50; i < 62; i++){
		
		x5 += 2 * 13;
		anchors[i] = x5;
		hello.drawHex(x5, y + (6 * r), h, image, colours[i] /*hexArray[i].getTileType()*/);
	}
	for (int i = 62; i < 75; i++){
		
		x6 += 2 * 13;
		anchors[i] = x6;
		hello.drawHex(x6, y + ((15 * r) / 2), h, image, colours[i] /*hexArray[i].getTileType()*/);
	}
	for (int i = 75; i < 87; i++){
		
		x7 += 2 * 13;
		anchors[i] = x7;
		hello.drawHex(x7, y + (9 * r), h, image, colours[i] /*hexArray[i].getTileType()*/);
	}
	for (int i = 87; i < 100; i++){
		
		x8 += 2 * 13;
		anchors[i] = x8;
		hello.drawHex(x8, y + ((21 * r) / 2), h, image, colours[i] /*hexArray[i].getTileType()*/);
	}
	for (int i = 100; i < 112; i++){
		
		x9 += 2 * 13;
		anchors[i] = x9;
		hello.drawHex(x9, y + (12 * r), h, image, colours[i] /*hexArray[i].getTileType()*/);
	}
	imshow("Terra Mystica Board", image);

	waitKey(0);
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