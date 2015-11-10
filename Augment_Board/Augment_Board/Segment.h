#ifndef SEGMENT_H
#define SEGMENT_H

#include <array>
#include "opencv2/opencv.hpp"

namespace Segment {
	
	int getBestOtsuScore(std::array<int, 256> histogram);
	cv::Mat thresholdImg(cv::Mat src, int threshold);
	std::array<int, 256> getHistogram(cv::Mat src);
	cv::Mat rgb2gray(cv::Mat src);
	cv::Mat meanFilter(cv::Mat src, int radius);
	cv::Mat medianFilter(cv::Mat src, int radius);
	cv::Mat dilate(cv::Mat src, int radius);
	cv::Mat erode(cv::Mat src, int radius);
	void burn(cv::Mat src/*, int x, int y*/);
	//void grassFire(cv::Mat src, int x, int y, int blobCount, bool init);
	cv::Mat normalizeImage(cv::Mat src, double newMax, double newMin);
}
#endif