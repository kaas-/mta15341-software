#include "opencv2/opencv.hpp"
#include "Player.h"
#include "Board.h"
#include "Segment.h"
#include <vector>
#include "Blob.h"

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace cv;
using namespace std;
using namespace Segment;

Mat image;
int dilation_size = 3;
Gesture gesture(image, image);
Scalar hexArray;
//Player currentPlayer(Tile::Type::BADLANDS,"GIANTS", gesture);
//Hex currentHex;
Mat element = getStructuringElement(MORPH_ELLIPSE, Size(2 * dilation_size + 1, 2 * dilation_size + 1), Point(dilation_size, dilation_size));

vector<vector<Point>> HexPoints = {};
Mat src; Mat src_gray;
int thresh = 20;
int max_thresh = 255;
RNG rng(12345);

int detectionHits = 0;
Mat getWeightedFrames(VideoCapture cap, Mat firstFrame, Mat weightedFrame, int duration);
bool hu(Mat threshold_output, int minArea, int maxArea);

<<<<<<< HEAD



void convexHullFunction(Mat threshold_output, int minArea, int maxArea);
=======
void convexHullFunction(Mat threshold_output);

>>>>>>> f7659f1d84ae46a1bc77b80356af543585279327

Board board;

Hex findCurrentHex(Board currentBoard);

void changeCurrentColour(Hex hex, Player player);
void Pointpoly();

int runWebcam();

Player players[3];
int currentPlayer = 0;

void buildPlayerArray();
void setCurrentPlayer(int i) { currentPlayer = players[i]; }


//Mat getWeightedFrames(VideoCapture cap, Mat firstFrame, Mat nextFrame, Mat weightedFrame, int duration);

int main(int, char)
{
	image = imread("Test1.jpg", CV_LOAD_IMAGE_COLOR);
	namedWindow("Terra Mystica Board", WINDOW_NORMAL);
	namedWindow("Terra Mystica Board 2", WINDOW_NORMAL);
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
	runWebcam();

<<<<<<< HEAD
	//board.buildBoard();
	//HexPoints = board.drawBoard();
	//Pointpoly();

=======
	board.buildBoard();

	//Draw the original board.
	for (;;)
	{
		board.drawBoard(image);
		imshow("Terra Mystica Board", image);
		if (waitKey(30) >= 0)
			break;

	}
	
	//Check whether a given point is within a Hex and change the colour unless it's a river.
	for (int i = 0; i < 112; ++i)
	{
		if (board.getHex(i).Pointpoly(Point(1400, 1200)) && board.getHex(i).getColour() != Colour::RIVER)
		{
			board.changeHex(i, players[currentPlayer].getFaction());
		}
	}

	//Draw the new board.
	for (;;)
	{
		board.drawBoard(image);
		imshow("Terra Mystica Board 2", image);
		if (waitKey(30) >= 0)
			break;

	}

>>>>>>> f7659f1d84ae46a1bc77b80356af543585279327
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
	Mat blob;
	list<Blob> blobList;
	vector<vector<Point>> HexPoints;

	Mat firstFrame;
	cap >> firstFrame;

	for (;;)
	{
		Mat current;
		Mat dst;
		Mat finaldst;
		imshow("firstframe", firstFrame);
		cap >> current; // get a new frame from camera
		bool ok = cap.read(firstFrame);
		if (!ok) continue;
		cvtColor(current, current, CV_BGR2GRAY);
		cvtColor(firstFrame, firstFrame, CV_BGR2GRAY);

		absdiff(current, firstFrame, dst);
		absdiff(firstFrame, dst, dst);
		//absdiff(current, dst, finaldst);
		

		//imshow("bgsubtracted", dst);
		GaussianBlur(dst, gblur, Size(5, 5), 1.5, 1.5);
		
		threshold(gblur, thres2, 25, 255, CV_THRESH_BINARY);

		morphologyEx(thres2, eroded1, MORPH_OPEN, element, Point(-1, -1), 1);

		imshow("Threshold", thres2);
		//imshow("current", current);
		imshow("eroded", eroded1);
		convexHullFunction(eroded1, 10000, 20000);

		if (waitKey(30) >= 0)
			break;
	}
	// the camera will be deinitialized automatically in VideoCapture destructor
	return 0;
}

Mat getWeightedFrames(VideoCapture cap, Mat firstFrame, Mat weightedFrame, int duration)
{
	cap >> firstFrame;
	Mat nextFrame = firstFrame.clone();
	weightedFrame = firstFrame.clone();
	cap.grab();
	cap.retrieve(nextFrame);
	cvtColor(firstFrame, firstFrame, CV_BGR2GRAY);
	cvtColor(nextFrame, nextFrame, CV_BGR2GRAY);
	addWeighted(firstFrame, 0.5, nextFrame, 0.5, 0.0, weightedFrame);

	for (int i = 0; i < duration; i++)
	{
		cap >> firstFrame;
		cvtColor(firstFrame, firstFrame, CV_BGR2GRAY);
		addWeighted(firstFrame, 0.95, weightedFrame, 0.05, 0.0, weightedFrame);
		cout << "Weighing frames...";
	}
	return weightedFrame;
}

void convexHullFunction(Mat threshold_output, int minArea, int maxArea)
{
	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;

	/// Find contours
	findContours(threshold_output, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));

	/// Find the convex hull object for each contour
	vector<vector<Point>>hull(contours.size());
	for (int i = 0; i < contours.size(); i++)
	{
		convexHull(Mat(contours[i]), hull[i], false);
	}

	/// Draw contours + hull results
	Mat drawing = Mat::zeros(threshold_output.size(), CV_8UC3);
	for (int i = 0; i< contours.size(); i++)
	{
		Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
		if (contourArea(hull[i]) > 500)
		{
			//drawContours(drawing, contours, i, color, 1, 8, vector<Vec4i>(), 0, Point());
			drawContours(drawing, hull, i, color, 1, 8, vector<Vec4i>(), 0, Point());
		}
	}
	
	

	
	/// Go through all the contours and print their area.
	for (int i = 0; i < contours.size(); i++)
	{
		Moments mo = moments(hull[i]);
		Point center = Point(mo.m10 / mo.m00, mo.m01 / mo.m00);

		double area = contourArea(hull[i]);
		//cout << "Object " << i << " has an area of: " << area << "\n";
		if (area > minArea && area < maxArea)
		{
			detectionHits++;
			if (area > 15000) 
			{
				cout << "Whole hand has been detected \n";
				cout << "Object " << i << " has an area of: " << area << "\n";
				cout << "Center of contour" << center;
			}
			if (area > 10000 && area < 150000)
			{
				cout << "Less than a whole hand has been detected \n";
				cout << "Object " << i << " has an area of: " << area << "\n";
				cout << "Center of contour" << center;
			}
		}
		
		
	}
	

	/// Show in a window
	namedWindow("Hull demo", CV_WINDOW_AUTOSIZE);
	imshow("Hull demo", drawing);

	if (detectionHits > 15)
	{
		cout << "A HAND HAS BEEN FOUND! \n";
	}
}

void buildPlayerArray()
{
	players[0] = Player(Colour::DESERT, "One");
	players[1] = Player(Colour::FOREST, "Two");
	players[2] = Player(Colour::MOUNTAIN, "Three");

	currentPlayer = 0;
}

void nextPlayerTurn()
{
	if (currentPlayer >= 2)
	{
		currentPlayer = 0;
	}
	else
	{
		currentPlayer++;
	}
}