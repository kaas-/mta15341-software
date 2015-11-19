#include "opencv2/opencv.hpp"
#include "Player.h"
#include "Board.h"
#include "Segment.h"

using namespace cv;
using namespace std;
using namespace Segment;

Mat image;
int dilation_size = 3;
Gesture gesture(image, image);
Player currentPlayer(Tile::Type::BADLANDS,"GIANTS", gesture);
//Hex currentHex;
Mat element = getStructuringElement(MORPH_ELLIPSE, Size(2 * dilation_size + 1, 2 * dilation_size + 1), Point(dilation_size, dilation_size));

Board board(gesture);

Hex findCurrentHex(Board currentBoard);

void changeCurrentColour(Hex hex, Player player);

int runWebcam();

int main(int, char)
{
	/*board.buildBoard(gesture);
	//prints out the type and colour of hex #100
	cout << "Hex type is: " << board.getHex(100).getTileName() << ", and has colour " << board.getHex(100).getColour() << "\n";
	//makes a new hex and gives it the type LAKE, then puts it in #100
	Hex newHex;
	newHex.setTileType(Tile::Type::LAKES);
	board.setHex(newHex, 100);
	//prints out hex #100
	cout << "Hex type is: " << board.getHex(100).getTileName() << ", and has colour " << board.getHex(100).getColour();

	cin.get();
	cin.get();*/
	/*
	image = imread("trees06.jpg", CV_LOAD_IMAGE_COLOR);
	image = rgb2gray(image);
	array<int, 256> histogram = getHistogram(image);
	int otsu = getBestOtsuScore(histogram);
	thresholdImg(image, otsu);

	imshow("theshold", image);

	image = erode(image, 1);
	imshow("eroded", image);

	image = dilate(image, 1);
	imshow("dilated", image);
	waitKey(0);

	return 0;*/
	//runWebcam();

	board.buildBoard();
	board.drawBoard();

	cin.get();
	cin.get();
	return 0;
}

int runWebcam()
{
	VideoCapture cap(1); // open the default camera
	if (!cap.isOpened()) // check if we succeeded
		return -1;
	Mat gblur;
	Mat thres1;
	Mat thres2;
	Mat eroded;
	for (;;)
	{
		Mat frame;
		cap >> frame; // get a new frame from camera
		cvtColor(frame, frame, CV_BGR2GRAY);
		//GaussianBlur(frame, blur, Size(19, 19), 1.5, 1.5);
		//threshold(blur, thres, 25, 255, THRESH_BINARY);
		//GaussianBlur(frame, gblur, Size(5, 5), 1.5, 1.5);
		//blur(frame, gblur, Size(5, 5), Point(1, -1));
		bilateralFilter(frame, gblur, 5, 5 * 2, 5 / 2);
		//threshold(blur, thres, 0, 255, THRESH_BINARY | THRESH_OTSU);
		threshold(gblur, gblur, 15, 255, THRESH_BINARY);
		adaptiveThreshold(gblur, thres1, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 111, 0);
		//medianBlur(frame, frame, 3);
		//cv::erode(thres, eroded, element);
		morphologyEx(thres1, eroded, MORPH_OPEN, element);
		//medianBlur(eroded, eroded, 13);
		morphologyEx(eroded, eroded, MORPH_OPEN, element);
		//morphologyEx(eroded, eroded, MORPH_CLOSE, element);
		//morphologyEx(eroded, eroded, MORPH_CLOSE, element);
		//morphologyEx(eroded, eroded, MORPH_CLOSE, element);
		//morphologyEx(eroded, eroded, MORPH_CLOSE, element);
		imshow("orig-grey", frame);
		imshow("blur", gblur);
		imshow("mean", thres1);
		imshow("gauss", eroded);
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
