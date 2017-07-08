/**
* @file videocapture_starter.cpp
* @brief A starter sample for using OpenCV VideoCapture with capture devices, video files or image sequences
*/
#include <opencv2/highgui.hpp>
#include <cv.h>

using namespace std;
using namespace cv;

int main()
{
	cv::Mat frame;
	cv::VideoCapture cap(0);
	if (!cap.isOpened()) {
		return -1;
	}
	while (true) {
		if (!cap.read(frame))
			break;
		cv::Mat src = cv::Mat(frame);
		cv::imshow("window", src);
		cv::waitKey(30);
	}
}
