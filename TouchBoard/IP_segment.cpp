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
	int bestScore, bestScoreValue;
	float bestScoreValue;
	int sum;
	for (int i = 0; i < histogram.size; ++i) { sum += histogram[i]; }
	int sum_background, sum_foreground;
	float weight_background, weight_foreground;
	float mean_background, mean_foreground, mean_bg_input, mean_fg_input;
	float between_variance, background_variance, foreground_variance;
	float var_bg_input, var_fg_input;

	for (int i = 0; i < histogram.size; ++i)
	{
		sum_background += histogram[i];
		sum_foreground = sum - sum_background;

		weight_background = sum_background / sum;
		weight_foreground = sum_foreground / sum;

		mean_bg_input += i * histogram[i];
		mean_background = mean_bg_input / sum_background;
		
		var_bg_input += (i - mean_background) * (i - mean_background) * histogram[i];
		background_variance = var_bg_input / sum_background;

		for (int mI = i; mI < histogram.size; ++mI)
		{
			mean_fg_input += mI * histogram[mI];
			mean_foreground = mean_fg_input / sum_foreground;

			var_fg_input += (mI - mean_foreground) * (mI - mean_foreground) * histogram[i];
			foreground_variance = var_fg_input / sum_foreground;
		}

		between_variance = weight_background * background_variance + weight_foreground * foreground_variance;

		if (between_variance < bestScoreValue || !bestScoreValue)
		{
			bestScoreValue = between_variance;
			bestScore = i;
		}

		mean_fg_input = 0;
		var_fg_input = 0;
	}
	

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