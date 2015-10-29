#include "opencv2/opencv.hpp"
#include <array>
#include "Segment.h""

using namespace cv;
using namespace std;

int Segment::getBestOtsuScore(array<int, 256> histogram)
{
	int bestScore;
	double bestScoreValue = 0;
	int sum = 0;
	for (int i = 0; i < 256; ++i) { sum += histogram[i]; }
	int sum_background = 0;
	int sum_foreground = 0;
	double weight_background, weight_foreground;
	double mean_background, mean_foreground;
	int mean_bg_input = 0;
	double mean_fg_input = 0;
	double between_variance, background_variance, foreground_variance;
	double var_bg_input = 0;
	double var_fg_input = 0;

	for (int i = 0; i < 256; ++i)
	{
		sum_background += histogram[i];
		if (sum_background == 0) { continue; }
		sum_foreground = sum - sum_background;

		weight_background = sum_background / (double)sum;
		weight_foreground = sum_foreground / (double)sum;

		mean_bg_input += i * histogram[i];
		mean_background = mean_bg_input / (double)sum_background;
		
		var_bg_input += (i - mean_background) * (i - mean_background) * histogram[i];
		background_variance = var_bg_input / (double)sum_background;

		for (int mI = i; mI < 256; ++mI)
		{
			mean_fg_input += mI * histogram[mI];


		}

		mean_foreground = (double)mean_fg_input / (double)sum_foreground;

		for (int mI = i; mI < 256; ++mI)
		{
			var_fg_input += (mI - mean_foreground) * (mI - mean_foreground) * histogram[mI];
		}
	
		foreground_variance = (double)var_fg_input / (double)sum_foreground;


		between_variance = weight_background * background_variance + weight_foreground * foreground_variance;
		
		mean_fg_input = 0;
		var_fg_input = 0;
		//mean_bg_input = 0;
		//var_bg_input = 0;
		//sum_background = 0;
		sum_foreground = 0;


		if (bestScoreValue == 0)
		{
			bestScoreValue = between_variance;
			bestScore = i;
			continue;
		}

		if (between_variance < bestScoreValue)
		{
			bestScoreValue = between_variance;
			bestScore = i;
		}


	}
	

	return bestScore;
}

Mat Segment::thresholdImg(Mat src, int threshold)
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
	return src;
}
array<int, 256> Segment::getHistogram(Mat src)
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

Mat Segment::rgb2gray(Mat src)
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

Mat Segment::meanFilter(Mat src, int radius)
{
	//stuff here

	return src;
}

Mat Segment::medianFilter(Mat src, int radius)
{
	//dunno if we need one of these

	return src;
}