#include "LDWS.h"

// Default constructor
LDWS::LDWS():imageTransformation(), roi(), laneAnalysis()
{
	inputPath = "";
	img = Mat();
	sourceImg = Mat();
	ipmImage = Mat();
}

// Constructor
LDWS::LDWS(string path):imageTransformation(), roi(), laneAnalysis()
{
	inputPath = path;
	sourceImg = Mat();
	ipmImage = Mat();
}