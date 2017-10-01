#ifndef __LANEANALYSIS_H__
#define __LANEANALYSIS_H__

#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

/*
 * Project:  Lane Departure Warning System (LDWS)
 *
 * File:     LaneAnalysis.cpp
 *
 * Contents: The LaneAnalysis class implements the fallowing analyzing methods :
 * 		- Sorts the detected lanes by angle to obtain right and left lanes;
 *		- Selects a single lane for both right and left lanes;
 *		- Creates a line fitting in IPM image for both right and left lanes;
 *		- Adds up un a vector the points corresponding to the detected left and right lanes;
 *		- Draws the detected lanes in IPM image;
 *		- Checks and displays the departure warning;
 *
 * Author:  PIRAUBE Nicolas
 * 
 * Date : 05/08/2017
 */

class LaneAnalysis
{
	public:	
		// Default constructor
		/**
		* Default constructor initializing the class attributs to zero.
		*/
		LaneAnalysis();
		
		// Constructor
		/**
		* Constructor initializing the class attributs to zero apart from the initial IPM lines detected.
		* 	Parameters 
		*		vector<Vec4i> lines : Vector storing initial IPM lines detected.
		*/
		LaneAnalysis(vector<Vec4i> lines);
		
		// Setter method for the initial IPM lines detected.
		/**
		* Parameters 
		*	vector<Vec4i> lines : Vector storing initial IPM lines detected.
		*/
		void setSourceLines(vector<Vec4i> lines);
	
		// Getter method for the rightLaneDetected boolean attribute.
		bool getRightLaneDetected();
	
		// Getter method for the lefttLaneDetected boolean attribute.
		bool getLeftLaneDetected();
		
		// Getter method for the linePointsIPMImage vector attribute.
		vector<Vec2f>& getLinePointsIPMImage();
	
		// Setter method for the linePointsSourceImage attribute
		/**
		* Parameters 
		*	vector<Vec2f> linePoints : Vector storing final source image lanes detected.
		*/
		void setlinePointsSourceImage(vector<Vec2f> linePoints);
	
		// Method sorting the initialy detected IPM lines by angle
		/**
		* This method sorts the initialy detected IPM lines into right and left lines.
		* Parameters 
		*	int& imageWidth : Integer storing the IPM image width.
		*/
		void sortLinesByAngle(int& imageWidth);
		
		// Method selecting a single line from the initialy detected IPM lines for both right and left lanes.
		void getSingleLaneSegment();
		
		// Method creating a line fitting in hole image for both right and left lanes.
		/**
		* Parameters 
		*	int& imageHeight : Integer storing the IPM image height.
		*/
		void getLineFromSegment(int& imageHeight);
		
		// Method adding up final right and left detected lanes in a single vector.
		void addIPMPoints();
		
		// Method Drawing the final right and left detected lanes in a given source image.
		/**
		* Parameters 
		*	Mat& img : Pointer to a matrix storing the source image.
		*/
		void drawFinalLines(Mat& img);
		
		// Method checking and drawing the lane departure warnings.
		/**
		* Parameters 
		*	Mat& img : Pointer to a matrix storing the source image.
		*	int& originalWidth : Integer storing the original image width.
		*/
		void checkAndDrawDeparture(Mat& img, int& originalWidth);
		
	private:
		//Vectors storing lane points in the different images.
		Vec4i rightLine, leftLine;
		vector<Vec2f> linePointsSourceImage, linePointsIPMImage;
		vector<Vec4i> sourceLines, rightLines, leftLines;
	
		//Booleans storing if right or left lanes were detected.
		bool rightLaneDetected, leftLaneDetected;
};

#endif
