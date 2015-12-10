#include "opencv2/opencv.hpp"
#include "Player.h"
#include "Board.h"
#include "Segment.h"
#include <vector>
#include "Blob.h"

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace cv;
using namespace std;
using namespace Segment;

Mat image;
int dilation_size = 3;
Gesture gesture(image, image);
Scalar hexArray;
Mat element = getStructuringElement(MORPH_ELLIPSE, Size(2 * dilation_size + 1, 2 * dilation_size + 1), Point(dilation_size, dilation_size));
vector<vector<Point>> HexPoints = {};
Mat src; Mat src_gray;
int thresh = 20;
int max_thresh = 255;
RNG rng(12345);
int detectionHits = 0;
int colourDetection = 0;
Player players[4];
int currentPlayer = 0;
Board board;
Point scaledCenter;
double scalarY = 5.2;
double scalarX = 5;
Scalar lastActionColour;
int lastActionIndex;
double area;


void convexHullFunction(Mat threshold_output, int minArea, int maxArea);
void runWebcam();
void buildPlayerArray();
void undoLastAction();
void nextPlayerTurn();

int main(int, char)
{
	
	runWebcam();
	//Check whether a given point is within a Hex and change the colour unless it's a river.
	
	while (true) {
		string input;
		getline(cin, input);
		if (input == "undo" || input == "Undo")
		{
			undoLastAction();
			cout << "A hex has ben undone!";
			input = "";
		}
		if (input == "player++")
		{
			nextPlayerTurn();
			cout << "The current player is Player " << currentPlayer;
		}
	}

	cin.get();
	cin.get();
	return 0;
}

void runWebcam()
{
	VideoCapture cap(0); // open the default camera
	if (!cap.isOpened()) // check if we succeeded
		cout << "No camera detected!";
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

	/*Mat firstFrame;
	cap >> firstFrame;
	flip(firstFrame, firstFrame, 0); */

	image = imread("BOARD.png", CV_LOAD_IMAGE_COLOR);
	namedWindow("Terra Mystica Board", WINDOW_NORMAL);

	board.buildBoard();

	//Draw the original board.
	board.drawBoard(image);

	buildPlayerArray();

	for (;;)
	{
		Mat current;
		Mat dst;
		Mat finaldst;
		cap >> current; // get a new frame from camera
		imshow("preflip", current);
		flip(current,dst, 1);
		bool ok = cap.read(current);
		if (!ok) continue;

		imshow("Terra Mystica Board", image);
		
		//Conversion to grey
		cvtColor(dst, dst, CV_BGR2GRAY);
		//cvtColor(firstFrame, firstFrame, CV_BGR2GRAY);
		//Background subtraction
		//absdiff(current, firstFrame, dst);
		//absdiff(firstFrame, dst, dst);
		imshow("Camera", dst);
		//Blurring
		GaussianBlur(dst, gblur, Size(5, 5), 1.5, 1.5);
		//Thresholding
		threshold(gblur, thres2, 18, 255, CV_THRESH_BINARY);
		//Morphology - open
		morphologyEx(thres2, eroded1, MORPH_OPEN, element, Point(-1, -1), 1);

		imshow("Threshold", thres2);
		//imshow("current", current);
		imshow("Eroded", eroded1);
		convexHullFunction(eroded1, 100, 20000);
		for (int i = 0; i < 112; ++i)
		{
			if (board.getHex(i).Pointpoly(scaledCenter) && board.getHex(i).getColour() != Colour::RIVER)  
			{
				lastActionColour = board.getHex(i).getColour();
				lastActionIndex = i;
				//cout << "You clicked hex " << i << " and changed from " << lastActionColour << " and will change to " << players[currentPlayer].getFaction() << endl;
				colourDetection++;
				if (colourDetection > 3 && area < 5000 && area > 80) 
				{
					board.changeHex(i, players[currentPlayer].getFaction());
					board.drawBoard(image);
					cout << "Changed " << lastActionColour << " to " << board.getHex(i).getColour() << endl;
					imshow("Terra Mystica Board", image);
					scaledCenter = Point(0, 0);
					colourDetection = 0;
				}
				
			}
			//circle(image, scaledCenter, 8, Scalar(0), -1);
		}
		

		if (waitKey(30) >= 0)
			break;
	}
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

		if (center.y * scalarY + 240 <= 1500)
		{
			scaledCenter = Point((center.x * scalarX) + 650, (center.y * scalarY) + 240);
		}
		else
		{
			scaledCenter = Point((center.x * scalarX) + 650, (center.y * scalarY) + 240);
		}

		area = contourArea(hull[i]);
		//cout << "Object " << i << " has an area of: " << area << "\n";
		if (area > minArea && area < maxArea)
		{
			
			if (area > 13700)  //P4
			{
				detectionHits++;
				if (detectionHits > 10) {
					currentPlayer = 3;
					cout << "New Player is " << currentPlayer + 1 << endl;
					cout << "Area: " << area << "\n";
					detectionHits = 0;
				}
			}
			if (area > 12300 && area < 13700)  //P3
			{
				detectionHits++;
				if (detectionHits > 10) {
					currentPlayer = 2;
					cout << "New Player is " << currentPlayer + 1 << "\n";
					cout << "Area: " << area << "\n";
					detectionHits = 0;
				}
			}
			if (area > 10000 && area < 12000)  //P2
			{
				detectionHits++;
				if (detectionHits > 10) {
					currentPlayer = 1;
					cout << "New Player is " << currentPlayer + 1 << endl;
					cout << "Area: " << area << "\n";
					detectionHits = 0;
				}
			}
			if (area < 10000 && area > 5000)  //P1
			{
				detectionHits++;
				if (detectionHits > 10) {
					currentPlayer = 0;
					cout << "New Player is " << currentPlayer + 1 << endl;
					cout << "Area: " << area << "\n";
					detectionHits = 0;
				}
			}
		}	
	}
	

	/// Show in a window
	namedWindow("Hull demo", CV_WINDOW_AUTOSIZE);
	imshow("Hull demo", drawing);
}

void buildPlayerArray()
{
	players[0] = Player(Colour::SWAMP, "One");
	players[1] = Player(Colour::LAKE, "Two");
	players[2] = Player(Colour::MOUNTAIN, "Three");
	players[3] = Player(Colour::PLAINS, "Four");

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

void undoLastAction()
{
	Scalar tmpActionColour = board.getHex(lastActionIndex).getColour();
	board.changeHex(lastActionIndex, lastActionColour);
	lastActionColour = tmpActionColour;
}