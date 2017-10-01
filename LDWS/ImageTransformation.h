#ifndef __IMAGETRANSFORMATION_H__
#define __IMAGETRANSFORMATION_H__

#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;


/*
 * Project:  Lane Departure Warning System (LDWS)
 *
 * File:     ImageTransformation.cpp
 *
 * Contents: The ImageTransformation class implements the fallowing image transformations :
 * 		- Applies inverse perspective mapping;
 * 		- Reverts the inverse perspective mapping (IPM);
 * 		- Applies Gaussian Blur;
 *		- Converts an RGB image to a greyscale image;
 * 		- Applies a Canny edge filter;
 *		- Applies Hough Line detection.
 *
 * Author:  PIRAUBE Nicolas
 * 
 * Date : 05/08/2017
 */

class ImageTransformation
{
	public:
		// Default constructor
		/**
		* Default constructor initializing the class attributs to zero.
		*/
		ImageTransformation();
		
		// Constructor
		/**
		* Constructor initializing the class attributs to the correct values based on an image.
		* 	Parameters 
		*		Mat& sourceImage : Pointer to a matrix storing the input image.
		*/
		ImageTransformation(Mat& sourceImage);		
	
		// Applying IPM
		/**
		* Method applying IPM to an image through a homography matrix.
		* 	Parameters 
		*		Mat& sourceImage : Pointer to a matrix storing the input image.
		*		Mat& detinationImage : Pointer to a matrix storing the output image.
		*		Mat& homography : Pointer to a matrix storing the homography needed for the IPM.
		*/
		void applyIPM(Mat& sourceImage, Mat& detinationImage, Mat& homography);
	
		// Applying reverse IPM
		/**
		* Method applying reverse IPM to a given set of points in a IPM image.
		* 	Parameters 
		*		Mat& inverseHomography : Pointer to a matrix storing the inverse homography.
		*		vector<Vec2f>& linePointsIPM : Pointer to a vector storing the points of the IPM image.
		*/
		vector<Vec2f> applyReverseIPM(Mat& inverseHomography, vector<Vec2f>& linePointsIPM);
	
		// Applying Gaussian Blur
		/**
		* Method applying Gaussian Blur to an image.
		* 	Parameters 
		*		Mat& image : Pointer to a matrix storing the image.
		*/
		void applyGaussianBlur(Mat& image);
		
		// Converting an RGB image to greyscale
		/**
		* Method converting an image to greyscale image.
		* 	Parameters 
		*		Mat& image : Pointer to a matrix storing the image.
		*/
		void applyCvtColor(Mat& image);
		
		// Applying Canny edge detection
		/**
		* Method applying the Canny edge filter to an image.
		* 	Parameters 
		*		Mat& image : Pointer to a matrix storing the image.
		*/
		void applyCanny(Mat& image);
		
		// Applying Hough Transform
		/**
		* Method applying Hough Transform to a given image.
		* 	Parameters 
		*		Mat& image : Pointer to a matrix storing the image.
		*/
		vector<Vec4i> applyHoughLinesP(Mat& image);
		
		// Getter Method returning the width attribute.
		/**
		* Getter Method returning the width of the input image
		*/
		int& getWidth();
	
		// Getter Method returning the height attribute.
		/**
		* Getter Method returning the height of the input image
		*/
		int& getHeight();
	private:
		//Source image dimmension attributes.
		int width, height;
	
		//Threshold values needed for canny edge filter.
		int maxThreshold, minThreshold;
};

#endif
