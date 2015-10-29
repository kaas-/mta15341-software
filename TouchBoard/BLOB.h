#ifndef BLOB_H
#define BLOB_H

#include "opencv2/opencv.hpp"

class BLOB
{
private:
	cv::Mat src;
	cv::Mat thisBLOB;

	cv::Mat getBLOBFromImage(cv::Mat s);
	void setBLOB(cv::Mat newBLOB);
	void setSrc(cv::Mat s) { src = s; };

	BLOB() { }
public:
	BLOB(cv::Mat s);

	cv::Mat getBLOBImage() { return thisBLOB; };
	double compareTo(BLOB otherBLOB);
};
#endif