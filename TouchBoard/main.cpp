#include "opencv2/opencv.hpp"
#include "Segment.h"

using namespace cv;
using namespace std;
using namespace Segment;

Mat normalizeImage(Mat src, double newMax, double newMin)
{
	double min, max;
	minMaxLoc(src, &min, &max);
	Mat output = src.clone();

	for (int y = 0; y < src.rows; ++y)
	{
		for (int x = 0; x < src.cols; ++x)
		{
			output.at<uchar>(y, x) = floor((src.at<uchar>(y, x) - min) * (newMax - newMin) / (max - min) + newMin);
			
		}
	}
	return output;
}

int main(int, char)
{
	VideoCapture cap(0); // open the default camera
	if (!cap.isOpened()) // check if we succeeded
		return -1;
	Mat edges;
	array<int, 256> frameOtsu;

	double min, max;

	for (;;)
	{
		/*Mat frame;
		cap >> frame; // get a new frame from camera
		//imshow("color", frame);
		frame = rgb2gray(frame);
		//imshow("gray", frame);
		GaussianBlur(frame, frame, Size(7, 7), 1.5, 1.5);
		frameOtsu = getHistogram(frame);
		frame = thresholdImg(frame, getBestOtsuScore(frameOtsu));
		imshow("segment", frame);*/
		edges = imread("image1.jpg", CV_LOAD_IMAGE_COLOR);
		edges = rgb2gray(edges);

		//minMaxLoc(edges, &min, &max);
		imshow("gray", edges);
		//cout << min << endl << max << endl;
		edges = normalizeImage(edges, 50, 0);
		//minMaxLoc(edges, &min, &max);
		//cout << min << endl << max << endl;
		imshow("normalized", edges);

		if (waitKey(30) >= 0)
			break;
	}
	
	// the camera will be deinitialized automatically in VideoCapture destructor
	return 0;
}