#ifndef __LIVEVIDEO_H__
#define __LIVEVIDEO_H__

#include <opencv2/opencv.hpp>
#include"LDWS.h"

using namespace cv;
using namespace std;

/*
 * Project:  Lane Departure Warning System (LDWS)
 *
 * File:     LiveVideo.cpp
 *
 * Contents: The LiveVideo class is a child of the LDWS class.
 * 	     This class applies the LDWS algorithm for a live video stream.
 *
 * Author:  PIRAUBE Nicolas
 * 
 * Date : 05/08/2017
 */

class LiveVideo : public LDWS
{
	public:	
		// Default constructor
		/**
		* Default constructor initializing the class attributs through the LDWS constructor.
		*/
		LiveVideo();
		
		// Method applying the LDWS algorithm
		/**
		* Method applying the lane detection warning system algorithm to a live video stream.
		*/
		void applyAlgorithm();
};

#endif