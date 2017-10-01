#include "ImageTransformation.h"

// Default constructor
ImageTransformation::ImageTransformation():width(0),height(0),minThreshold(0),maxThreshold(0)
{}

// Constructor
ImageTransformation::ImageTransformation(Mat& sourceImage)
{
	width = static_cast<int>(sourceImage.size().width);
	height = static_cast<int>(sourceImage.size().height);
	minThreshold = 0.66 * 72;	//0.66*MeanThreshold
	maxThreshold = 1.33 * 72;	//1.33*MeanThreshold
}

// Getter Method returning the width attribute.
int& ImageTransformation::getWidth()
{
	return width;
}

// Getter Method returning the height attribute.
int& ImageTransformation::getHeight()
{
	return height;
}

// Applying IPM
void ImageTransformation::applyIPM(Mat& sourceImage, Mat& detinationImage, Mat& homography)
{
	// Warp source image to destination
	warpPerspective(sourceImage, detinationImage, homography, Size(width / 5, height / 5));
}

// Applying reverse IPM
vector<Vec2f> ImageTransformation::applyReverseIPM(Mat& inverseHomography, vector<Vec2f>& linePointsIPM)
{
	
	vector<Vec2f> linePointsSourceImage;
	
	perspectiveTransform(linePointsIPM, linePointsSourceImage, inverseHomography);

	return linePointsSourceImage;
}

// Applying Gaussian Blur
void ImageTransformation::applyGaussianBlur(Mat& image)
{
	GaussianBlur(image, image, Size(7, 7), 0, 0);
}
	
// Converting an RGB image to greyscale
void ImageTransformation::applyCvtColor(Mat& image)
{
	cvtColor(image, image, CV_BGR2GRAY);
}

// Applying Canny edge detection
void ImageTransformation::applyCanny(Mat& image)
{
	Canny(image, image, minThreshold, maxThreshold);
}

// Applying Hough Transform
vector<Vec4i> ImageTransformation::applyHoughLinesP(Mat& image)
{
	vector<Vec4i> lines;

	//Hough Lines for 1280*720 video
	HoughLinesP( image, lines, 1, CV_PI/180, 15, 10, 4);
	
	//Hough Lines for 640*420 video
	//HoughLinesP( image, lines, 1, CV_PI/180, 14, 9, 3);

	return lines;
}
