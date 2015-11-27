#include "opencv2/opencv.hpp"
#include "Player.h"
#include "Board.h"
#include "Segment.h"
#include <vector>

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
Player currentPlayer(Tile::Type::BADLANDS,"GIANTS", gesture);
//Hex currentHex;
Mat element = getStructuringElement(MORPH_ELLIPSE, Size(2 * dilation_size + 1, 2 * dilation_size + 1), Point(dilation_size, dilation_size));

Mat src; Mat src_gray;
int thresh = 100;
int max_thresh = 255;
RNG rng(12345);

int convexHullFunction();

void thresh_callback(int, void*);

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

	convexHullFunction();

	//board.buildBoard();
	//board.drawBoard();

	cin.get();
	cin.get();
	return 0;
}

int convexHullFunction()
{
	/// Load source image and convert it to gray
	VideoCapture cap(0); // open the default camera
	if (!cap.isOpened()) // check if we succeeded
		return -1;

	for (;;)
	{
		cap >> src;
		/// Convert image to gray and blur it
		cvtColor(src, src_gray, CV_BGR2GRAY);
		blur(src_gray, src_gray, Size(3, 3));

		/// Create Window
		char* source_window = "Source";
		namedWindow(source_window, CV_WINDOW_AUTOSIZE);
		imshow(source_window, src);

		createTrackbar(" Threshold:", "Source", &thresh, max_thresh, thresh_callback);
		thresh_callback(0, 0);

		cout << thresh;

		if (waitKey(30) >= 0)
			break;
	}
	return(0);
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
	Mat frame;
	cap >> firstFrame;
	nextFrame = firstFrame.clone();
	weightedFrame = firstFrame.clone();
	cap.grab();
	cap.retrieve(nextFrame);
	cvtColor(firstFrame, firstFrame, CV_BGR2GRAY);
	cvtColor(nextFrame, nextFrame, CV_BGR2GRAY);
	addWeighted(firstFrame, 0.95, nextFrame, 0.05, 0.0, weightedFrame);

	for (int i = 0; i < duration; i++)
	{
		cap >> frame;
		addWeighted(weightedFrame, 0.95, frame, 0.05, 0.0, weightedFrame);
		cout << "Weighing frames...";
	}
	return weightedFrame;
}

void thresh_callback(int, void*)
{
	Mat src_copy = src.clone();
	Mat threshold_output;
	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;

	/// Detect edges using Threshold
	threshold(src_gray, threshold_output, thresh, 255, THRESH_BINARY);

	/// Find contours
	findContours(threshold_output, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));

	/// Find the convex hull object for each contour
	vector<vector<Point> >hull(contours.size());
	for (int i = 0; i < contours.size(); i++)
	{
		convexHull(Mat(contours[i]), hull[i], false);
	}

	/// Draw contours + hull results
	Mat drawing = Mat::zeros(threshold_output.size(), CV_8UC3);
	for (int i = 0; i< contours.size(); i++)
	{
		Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
		drawContours(drawing, contours, i, color, 1, 8, vector<Vec4i>(), 0, Point());
		drawContours(drawing, hull, i, color, 1, 8, vector<Vec4i>(), 0, Point());
	}

	/// Show in a window
	namedWindow("Hull demo", CV_WINDOW_AUTOSIZE);
	imshow("Hull demo", drawing);
}