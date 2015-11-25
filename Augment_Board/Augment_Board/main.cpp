#include "opencv2/opencv.hpp"
#include "Player.h"
#include "Board.h"
#include "Segment.h"
#include <vector>

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

Mat getWeightedFrames(VideoCapture cap, Mat firstFrame, Mat nextFrame, Mat weightedFrame, int duration);

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
	VideoCapture cap(0); // open the default camera
	if (!cap.isOpened()) // check if we succeeded
		return -1;
	Mat frame;
	Mat frame2;
	Mat finalFrame;
	Mat gblur;
	Mat thres1;
	Mat thres2;
	Mat median;
	Mat eroded1;
	Mat eroded2;
	Mat frameArray;
	
	finalFrame = getWeightedFrames(cap, frame, frame2, finalFrame, 60);
	//cout << frameArray.size();

	for (;;)
	{
		Mat current;
		Mat dst;
		Mat finaldst;
		cap >> current; // get a new frame from camera
		cvtColor(current, current, CV_BGR2GRAY);
		/*Scalar tempVal = mean(frameArray);
		float myMatatMean = tempVal.val[0];*/
		absdiff(current, finalFrame, dst);
		//absdiff(myMatatMean, dst, dst);
		//absdiff(current, dst, finaldst);
		//absdiff(current, firstFrame, dst);
		//absdiff(firstFrame, dst, dst);
		//absdiff(current, dst, finaldst);
		//GaussianBlur(frame, blur, Size(19, 19), 1.5, 1.5);
		//threshold(blur, thres, 25, 255, THRESH_BINARY);
		GaussianBlur(dst, gblur, Size(5, 5), 1.5, 1.5);
		//blur(finaldst, gblur, Size(3, 3), Point(1, -1));
		inRange(gblur, Scalar(21), Scalar(100), thres2);
		
		//threshold(gblur, thres1, 15, 255, THRESH_BINARY);
		//adaptiveThreshold(gblur, thres1, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 111, 0);
		//medianBlur(thres2, median, 5);
		//cv::erode(thres, eroded, element);
		morphologyEx(thres2, eroded1, MORPH_OPEN, element, Point(-1, -1), 1);
		//morphologyEx(thres1, eroded, MORPH_CLOSE, element, Point(-1, -1), 1);
		//medianBlur(eroded, eroded, 13);
		imshow("current", current);
		imshow("subtracted", dst);
		//imshow("dst", finaldst);
		//imshow("blur", gblur);
		//imshow("mean", thres2);
//		imshow("median", median);
		//imshow("morph1", eroded1);
		//imshow("morph2", eroded2);
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

Mat getWeightedFrames(VideoCapture cap, Mat firstFrame, Mat nextFrame, Mat weightedFrame, int duration)
{
	cap >> firstFrame;
	nextFrame = firstFrame.clone();
	weightedFrame = firstFrame.clone();
	cap.grab();
	cap.retrieve(nextFrame);
	cvtColor(firstFrame, firstFrame, CV_BGR2GRAY);
	cvtColor(nextFrame, nextFrame, CV_BGR2GRAY);
	addWeighted(firstFrame, 0.5, nextFrame, 0.5, 0.0, weightedFrame);

	for (int i = 0; i < duration; i++)
	{
		getWeightedFrames(cap, firstFrame, weightedFrame, weightedFrame, duration);
		cout << "Weighing frames...";
	}
	return weightedFrame;
}