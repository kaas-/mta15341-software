#include "Board.h"
#include "Gesture.h"
#include "Colour.h"
#include "opencv2/opencv.hpp" 
#include "opencv2/imgproc/imgproc.hpp" 
#include "opencv2/highgui/highgui.hpp" 

using namespace std;
using namespace cv;

Board::Board()
{
}


Board::~Board()
{
}

void Board::buildHex(int x, int y, float h, Scalar colour) {


	//calculate radius of hexagon
	float r = (2.0 / 3.0) * (sqrt(3.0) * h);
	cout << endl << "Radius: " << r << endl;


	Point a(x, y);
	Point b(x + h, y + (0.5*r));
	Point c(x + h, y + (1.5*r));
	Point d(x, y + (2 * r));
	cout << "Diameter: " << sqrt((d.x - a.x)*(c.x - a.x) + (c.y - a.y)*(d.y - a.y));
	Point e(x - h, y + (1.5*r));
	Point f(x - h, y + (0.5*r));
	Point points[6] = { a, b, c, d, e, f };
	vector<Point> pointsVec = { a, b, c, d, e, f };

	Hex hex = Hex(colour, pointsVec);
	HexPoints.push_back(hex);
}

//Method for defining all hexes.
 //TOP LEFT (60, 440)
//method for going through the hex array
//this method probably shouldn't return "void". This should be looked at
void Board::buildBoard()
{
	//int* anchors = new int[112];
	int x1 = 978; //505,150
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
	
	//Define initial layout of the board
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

	//Build each hex

	for (int i = 0; i < 12; i++){
		x1 += 2 * h;
		buildHex(x1, y, h, hexArray[i]);

	}
	for (int i = 12; i < 25; i++){
		x2 += 2 * h;
		buildHex(x2, y + ((3 * r) / 2), h, hexArray[i]);
	}
	for (int i = 25; i < 37; i++){

		x3 += 2 * h;
		buildHex(x3, y + (3 * r), h, hexArray[i]);
	}
	for (int i = 37; i < 50; i++){

		x4 += 2 * h;
		buildHex(x4, y + ((9 * r) / 2), h, hexArray[i]);
	}
	for (int i = 50; i < 62; i++){

		x5 += 2 * h;
		buildHex(x5, y + (6 * r), h, hexArray[i]);
	}
	for (int i = 62; i < 75; i++){

		x6 += 2 * h;
		buildHex(x6, y + ((15 * r) / 2), h, hexArray[i]);
	}
	for (int i = 75; i < 87; i++){

		x7 += 2 * h;
		buildHex(x7, y + (9 * r), h, hexArray[i]);
	}
	for (int i = 87; i < 100; i++){

		x8 += 2 * h;
		buildHex(x8, y + ((21 * r) / 2), h, hexArray[i]);
	}
	for (int i = 100; i < 112; i++){

		x9 += 2 * h;
		buildHex(x9, y + (12 * r), h, hexArray[i]);
	}

}
	
//Draw each hex. This method should be called continously.
void Board::drawBoard(Mat image){

	//For each Hex
	for (vector<Hex>::iterator it = HexPoints.begin(); it != HexPoints.end(); ++it)
	{
		//Draw the Hex
		it->drawHex(image);
	}
	
}
