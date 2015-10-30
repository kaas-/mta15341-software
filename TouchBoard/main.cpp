#include "opencv2/opencv.hpp"
#include "Segment.h"

using namespace cv;
using namespace std;
using namespace Segment;

int main(int, char)
{
	VideoCapture cap(0); // open the default camera
	if (!cap.isOpened()) // check if we succeeded
		return -1;
	Mat edges;
	array<int, 256> frameOtsu;
	for (;;)
	{
		Mat frame;
		cap >> frame; // get a new frame from camera
		imshow("color", frame);
		frame = rgb2gray(frame);
		imshow("gray", frame);
		GaussianBlur(frame, frame, Size(7, 7), 1.5, 1.5);
		frameOtsu = getHistogram(frame);
		frame = thresholdImg(frame, getBestOtsuScore(frameOtsu));
		imshow("segment", frame);
		if (waitKey(30) >= 0)
			break;
	}
	
	// the camera will be deinitialized automatically in VideoCapture destructor
	return 0;
}