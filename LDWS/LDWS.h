#ifndef __LDWS_H__
#define __LDWS_H__

#include <opencv2/opencv.hpp>
#include"ROI.h"
#include"ImageTransformation.h"
#include"LaneAnalysis.h"

using namespace cv;
using namespace std;

/*
 * Project:  Lane Departure Warning System (LDWS)
 *
 * File:     LDWS.cpp
 *
 * Contents: The LDWS class stores the attributes needed for the either 
 * 	     the single image, the video or the live video stream algorithms implemented in child classes.
 *
 * Author:  PIRAUBE Nicolas
 * 
 * Date : 05/08/2017
 */

class LDWS
{
	public:	
		// Default constructor
		/**
		* Default constructor initializing the class attributs to zero.
		*/
		LDWS();

		// Constructor
		/**
		* Constructor initializing the class attributs to zero apart for the path string attribute.
		* 	Parameters 
		*		string path : String storing the path to the algorithm input image or video.
		*/
		LDWS(string path);

	protected:
		//String inputPath storing the path to the algorithm input image or video.
		string inputPath;

		//Matrix storing the input image.
		Mat img;
		
		//Matrix storing the input image on wich the algorithm is applied.
		Mat sourceImg;

		//Matrix storing the IPM if the input image.
		Mat ipmImage;

		//ImageTransformation object used for the algorithm.
		ImageTransformation imageTransformation;

		//ROI object used for the algorithm.
		ROI roi;

		//LaneAnalysis object used for the algorithm.
		LaneAnalysis laneAnalysis;
};

#endif