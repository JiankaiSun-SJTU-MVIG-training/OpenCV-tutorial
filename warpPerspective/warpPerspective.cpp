#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;


Mat AffineTrans(Mat src, Point2f* scrPoints, Point2f* dstPoints)
{
	Mat dst;
	Mat Trans = getAffineTransform(scrPoints, dstPoints);
	warpAffine(src, dst, Trans, Size(src.cols, src.rows), CV_INTER_CUBIC);
	return dst;
}

Mat PerspectiveTrans(Mat src, Point2f* scrPoints, Point2f* dstPoints)
{
	Mat dst;
	Mat Trans = getPerspectiveTransform(scrPoints, dstPoints);
	warpPerspective(src, dst, Trans, Size(src.cols, src.rows), CV_INTER_CUBIC);
	return dst;
}

void main()
{
	Mat I = imread("img2.jpg");	//700*438

	Point2f AffinePoints0[4] = { Point2f(100, 50), Point2f(100, 390), Point2f(600, 50), Point2f(600, 390) };
	Point2f AffinePoints1[4] = { Point2f(200, 100), Point2f(200, 330), Point2f(500, 50), Point2f(600, 390) };
	Mat dst_affine = AffineTrans(I, AffinePoints0, AffinePoints1);
	Mat dst_perspective = PerspectiveTrans(I, AffinePoints0, AffinePoints1);

	for (int i = 0; i < 4; i++)
	{
		circle(I, AffinePoints0[i], 2, Scalar(0, 0, 255), 2);
		circle(dst_affine, AffinePoints1[i], 2, Scalar(0, 0, 255), 2);
		circle(dst_perspective, AffinePoints1[i], 2, Scalar(0, 0, 255), 2);
	}

	imshow("Origin", I);
	imshow("Affine", dst_affine);
	imshow("Perspective", dst_perspective);
	waitKey();
}