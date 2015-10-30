#include "opencv2/opencv.hpp"
#include "Player.h"
#include "Board.h"

using namespace cv;
using namespace std;

Mat image;
Gesture gesture(image, image);
Player currentPlayer(Tile::Type::BADLANDS,"GIANTS",gesture);
//Hex currentHex;
Board board(gesture);

Hex findCurrentHex(Board currentBoard);

void changeCurrentColour(Hex hex, Player player);

int runWebcam();

int main(int, char)
{
	board.buildBoard(gesture);
	//prints out the type and colour of hex #100
	cout << "Hex type is: " << board.getHex(100).getTileName() << ", and has colour " << board.getHex(100).getColour() << "\n";
	//makes a new hex and gives it the type LAKE, then puts it in #100
	Hex newHex;
	newHex.setTileType(Tile::Type::LAKES);
	board.setHex(newHex, 100);
	//prints out hex #100
	cout << "Hex type is: " << board.getHex(100).getTileName() << ", and has colour " << board.getHex(100).getColour();

	cin.get();
	cin.get();
	return 0;
}

int runWebcam()
{
	VideoCapture cap(0); // open the default camera
	if (!cap.isOpened()) // check if we succeeded
		return -1;
	Mat edges;
	namedWindow("edges", 1);
	for (;;)
	{
		Mat frame;
		cap >> frame; // get a new frame from camera
		cvtColor(frame, edges, CV_BGR2GRAY);
		GaussianBlur(edges, edges, Size(7, 7), 1.5, 1.5);
		Canny(edges, edges, 0, 30, 3);
		imshow("edges", edges);
		if (waitKey(30) >= 0)
			break;
	}
	// the camera will be deinitialized automatically in VideoCapture destructor
	return 0;
}

/*Hex findCurrentHex(Board currentBoard)
{ 

}*/

void changeCurrentColour(Hex hex, Player player)
{

}
