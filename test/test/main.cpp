#include "opencv2/opencv.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

Mat img;
Mat templ;
Mat result;
char* image_window = "Source Image";
char* result_window = "Result Window";

//int match_method;
//int max_Trackbar = 5;


void MatchingMethod(int, void*);

void imageOutput(Mat image, String path)
{
	image = imread(path, 0);
	imshow("Original", image);
}

int main(int, char)
{
	img = imread("C:/Dropbox/lena.jpg", 0);
	templ = imread("C:/Dropbox/lenaFace.jpg", 0);

	imshow("Original", img);
	imshow("Template", templ);

	namedWindow(image_window, CV_WINDOW_AUTOSIZE);
	namedWindow(result_window, CV_WINDOW_AUTOSIZE);


	MatchingMethod(0, 0);
	waitKey(0);
	// the camera will be deinitialized automatically in VideoCapture destructor
	return 0;
}

void MatchingMethod(int, void*)
{
Mat img_display;
img.copyTo(img_display);

int result_cols = img.cols - templ.cols + 1;
int result_rows = img.rows - templ.rows + 1;

result.create(result_rows, result_cols, CV_32FC1);

matchTemplate(img, templ, result, CV_TM_SQDIFF);
normalize(result, result, 0, 1, NORM_MINMAX, -1, Mat());

double minVal = 0.9;
double maxVal = 0.9;
double threshold = 0.9;
Point minLoc; Point maxLoc;

minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc, Mat());

Point matchLoc = minLoc;

if (maxVal >= threshold)
	{
	cout << "A match has been found";

	rectangle(img_display, matchLoc, Point(matchLoc.x + templ.cols, matchLoc.y + templ.rows), Scalar::all(0), 2, 8, 0);
	rectangle(result, matchLoc, Point(matchLoc.x + templ.cols, matchLoc.y + templ.rows), Scalar::all(0), 2, 8, 0);

	imshow(image_window, img_display);
	imshow(result_window, result);
	}
else
{
	cout << "A match couldn't be found :(";
}



return;
}