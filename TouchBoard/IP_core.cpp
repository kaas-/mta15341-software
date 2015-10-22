#include "opencv2/opencv.hpp"
#include <array>

using namespace cv;
using namespace std;

array<int, 256> getHistogram(Mat src)
{
	array<int, 256> histogram;
	histogram.fill(0);

	for (int y = 0; y < src.rows; ++y)
	{
		for (int x = 0; x < src.cols; ++x)
		{
			//add 1 to the position in the histogram array that corresponds to the pixel value
			histogram.at((int)src.at<uchar>(y, x))++;
		}
	}

	return histogram;
}

Mat rgb2gray(Mat src)
{
	Mat output(src.size(), CV_8U, Scalar(0));

	for (int y = 0; y < src.rows; ++y)
	{
		for (int x = 0; x < src.cols; ++x)
		{
			output.at<uchar>(y, x) = (src.at<Vec3b>(y, x)[0] + src.at<Vec3b>(y, x)[1] + src.at<Vec3b>(y, x)[2]) / 3;
		}
	}
	
	return output;
}

Mat meanFilter(Mat src, int radius)
{
	//stuff here
}

Mat medianFiler(Mat src, int radius)
{
	//dunno if we need one of these
}