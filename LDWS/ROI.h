#ifndef __ROI_H__
#define __ROI_H__

#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

/*
 * Project:  Lane Departure Warning System (LDWS)
 *
 * File:     ROI.cpp
 *
 * Contents: The ROI (Region of interest) class implements the following methods:
 *		- Sets the ROI based on the image resolution;
 *		- Computes the homography matrix for the given ROI;
 *		- Computes the inverse homography from the homography matrix;
 *		- Draws the ROI on a image.
 *
 * Author:  PIRAUBE Nicolas
 * 
 * Date : 05/08/2017
 */


class ROI
{
	public:	
		// Default constructor
		/**
		* Default constructor initializing the class attributs to zeros.
		*/
		ROI();	

		// Getter method for the ipmHomography matrix
		Mat& getIpmHomography();

		// Getter method for the inverseHomography matrix
		Mat& getInverseHomography();
	
		// Method implementing the ROI
		/**
		* Method implementing the ROI based on the image width and height.
		* 	Parameters 
		*		int& originalWidth : Integer storing the image width.
		*		int& originalHeight : Integer storing the image height.
		*/
		void setROI(int& originalWidth, int& originalHeight);

		// Method computing the homography matrix
		/**
		* Method computing the homography matrix based on the ROI.
		*/
		void computeHomography();
		
		// Method computing the inverse homography matrix
		/**
		* Method computing the inverse homography matrix based on the homography matrix.
		*/
		void computeInverseHomography();

		// Method displaying the ROI
		/**
		* 	Parameters 
		*		Mat& img : Matrix pointer storing the image on which the ROI should be displayed.
		*/
		void showROI(Mat& img);
	private:
		//Vectores storing the ROI points 
		vector<Point2f> origPointsROI, destPointsROI;

		//Matrices storing the homography and inverse homography. 
		Mat ipmHomography, inverseHomography;
};

#endif