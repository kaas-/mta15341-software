#ifndef BLOB_H
#define BLOB_H

#include "opencv2\opencv.hpp"

class Blob {
private:
	cv::Mat image;
	int minX;
	int maxX;
	int minY;
	int maxY;

public:
	cv::Mat getImage() { return image; };
	std::vector<cv::Point> getPosition() { return{ cv::Point(minX, minY), cv::Point(maxX, maxY) }; };
	Blob();
	Blob(cv::Mat image, int minX, int maxX, int minY, int maxY);
	~Blob();
};

#endif