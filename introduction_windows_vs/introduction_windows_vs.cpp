#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char ** argv)
{
	Mat image;
	image = imread("opencvLogo.jpg", IMREAD_COLOR);
	if (image.empty())
	{
		cout << "Could not open or find the image." << std::endl;
		return -1;
	}
	namedWindow("Display Window", WINDOW_AUTOSIZE);//Create a window for display.
	imshow("Display Window", image);//Show the image inside it.

	waitKey(0);//Wait for a keystroke in the window
	return 0;
}