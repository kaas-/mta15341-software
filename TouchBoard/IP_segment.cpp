#include "opencv2/opencv.hpp"
#include <array>

using namespace cv;
using namespace std;

Mat otsuSegment(Mat src)
{
	Mat output;
	int threshold;
	


	return output;
}

int getBestOtsuScore(array<int, 256> histogram)
{
	int bestScore;
	
	//TODO: create the algorithm..

	return bestScore;
}

Mat threshold(Mat src, int threshold)
{
	for (int y = 0; y < src.rows; ++y)
	{
		for (int x = 0; x < src.cols; ++x)
		{
			if (src.at<uchar>(y, x) >= threshold)
			{
				src.at<uchar>(y, x) = 255;
			}
			else
			{
				src.at<uchar>(y, x) = 0;
			}
		}
	}
}