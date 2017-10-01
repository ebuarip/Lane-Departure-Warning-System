#include "ROI.h"

// Default constructor
ROI::ROI()
{
	origPointsROI = {};
	destPointsROI = {};
	ipmHomography = Mat();
	inverseHomography = Mat();
}

// Getter method for the ipmHomography matrix
Mat& ROI::getIpmHomography()
{
	return ipmHomography;
}

// Getter method for the inverseHomography matrix
Mat& ROI::getInverseHomography()
{
	return inverseHomography;
}

// Method implementing the ROI
void ROI::setROI(int& originalWidth, int& originalHeight)
{
	//ROI points in the source image
	origPointsROI.push_back( Point2f(originalWidth - (5 * originalWidth / 8), originalHeight - (3 * originalHeight / 8)) );
	origPointsROI.push_back( Point2f(originalWidth - (3 * originalWidth / 8), originalHeight - (3 * originalHeight / 8)) );
	origPointsROI.push_back( Point2f(originalWidth - (originalWidth / 6), originalHeight - (originalHeight / 6)) );
	origPointsROI.push_back( Point2f(originalWidth - (5 * originalWidth / 6), originalHeight - (originalHeight / 6)) );
		
	//ROI points in the IPM image
	destPointsROI.push_back(Point2d(0,0));
	destPointsROI.push_back(Point2d(originalWidth / 5, 0));
	destPointsROI.push_back(Point2d(originalWidth / 5, originalHeight / 5));
	destPointsROI.push_back(Point2d(0, originalHeight / 5 ));
}

// Method displaying the ROI
void ROI::showROI(Mat& img)
{
	assert(origPointsROI.size() == 4);
	line(img, Point(static_cast<int>(origPointsROI[0].x), static_cast<int>(origPointsROI[0].y)), Point(static_cast<int>(origPointsROI[3].x), static_cast<int>(origPointsROI[3].y)), CV_RGB( 205,205,0), 2);
	line(img, Point(static_cast<int>(origPointsROI[2].x), static_cast<int>(origPointsROI[2].y)), Point(static_cast<int>(origPointsROI[3].x), static_cast<int>(origPointsROI[3].y)), CV_RGB( 205,205,0), 2);
	line(img, Point(static_cast<int>(origPointsROI[0].x), static_cast<int>(origPointsROI[0].y)), Point(static_cast<int>(origPointsROI[1].x), static_cast<int>(origPointsROI[1].y)), CV_RGB( 205,205,0), 2);
	line(img, Point(static_cast<int>(origPointsROI[2].x), static_cast<int>(origPointsROI[2].y)), Point(static_cast<int>(origPointsROI[1].x), static_cast<int>(origPointsROI[1].y)), CV_RGB( 205,205,0), 2);
	
	for(size_t i=0; i<origPointsROI.size(); i++)
	{
		circle(img, Point(static_cast<int>(origPointsROI[i].x), static_cast<int>(origPointsROI[i].y)), 2, CV_RGB(238,238,0), -1);
		circle(img, Point(static_cast<int>(origPointsROI[i].x), static_cast<int>(origPointsROI[i].y)), 5, CV_RGB(255,255,255), 2);
	}
}

// Method computing the homography matrix
void ROI::computeHomography()
{
	// Compute the homography
	ipmHomography = findHomography(origPointsROI, destPointsROI);
}

// Method computing the inverse homography matrix
void ROI::computeInverseHomography()
{
	// Compute the inverse homography matrix
	inverseHomography = ipmHomography.inv();
}

