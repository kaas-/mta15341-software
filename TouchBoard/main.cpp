#include "opencv2/opencv.hpp"
#include "Segment.h"

using namespace cv;
using namespace std;
using namespace Segment;

int main(int, char)
{
	Mat originalImage = imread("image1.jpg", CV_LOAD_IMAGE_COLOR);
	imshow("Original", originalImage);

	Mat gray = rgb2gray(originalImage);
	imshow("B&W", gray);
	GaussianBlur(gray, gray, Size(7, 7), 1.5, 1.5);
	array<int, 256> frameHistogram = getHistogram(gray);
	int frameOtsu = getBestOtsuScore(frameHistogram);
	Mat segmented = thresholdImg(gray, frameOtsu);


	imshow("Segmented", segmented);
	waitKey(0);
	
	// the camera will be deinitialized automatically in VideoCapture destructor
	return 0;
}