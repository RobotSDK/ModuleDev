//You need to modify this file.

#ifndef PROCESSORMONO_ALGORITHM_DETECTION_CAMERA_DPM_VARS_H
#define PROCESSORMONO_ALGORITHM_DETECTION_CAMERA_DPM_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup ProcessorMono_Algorithm_Detection_Camera_DPM_Vars ProcessorMono_Algorithm_Detection_Camera_DPM_Vars
	\ingroup ProcessorMono_Algorithm_Detection_Camera_DPM
	\brief ProcessorMono_Algorithm_Detection_Camera_DPM_Vars defines the Vars in ProcessorMono_Algorithm_Detection_Camera_DPM.
*/

/*! \addtogroup ProcessorMono_Algorithm_Detection_Camera_DPM_Vars
	@{
*/

/*! \file ProcessorMono_Algorithm_Detection_Camera_DPM_Vars.h
	 Defines the Vars of ProcessorMono_Algorithm_Detection_Camera_DPM
*/

//*******************Please add other headers below*******************
#include<opencv2/opencv.hpp>

//The Vars is defined as below
/*! \class ProcessorMono_Algorithm_Detection_Camera_DPM_Vars 
	\brief The Vars of ProcessorMono_Algorithm_Detection_Camera_DPM.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT ProcessorMono_Algorithm_Detection_Camera_DPM_Vars 
{
public:
	/*! \fn ProcessorMono_Algorithm_Detection_Camera_DPM_Vars()
		\brief The constructor of ProcessorMono_Algorithm_Detection_Camera_DPM_Vars. [required]
		\details ****Please add details below****

	*/
	ProcessorMono_Algorithm_Detection_Camera_DPM_Vars() 
	{
		modeldir="#(ModelDir)";
		threshold1=0.01;
		threshold2=-0.5;
		threadnum=-1;
		compressrate=1.0;
		grubsize=0;
	}
	/*! \fn ~ProcessorMono_Algorithm_Detection_Camera_DPM_Vars()
		\brief The destructor of ProcessorMono_Algorithm_Detection_Camera_DPM_Vars. [required]
		\details *****Please add details below*****

	*/
	~ProcessorMono_Algorithm_Detection_Camera_DPM_Vars() 
	{
		
	}
public:
	//*******************Please add variables below*******************
	QString modeldir;
	cv::LatentSvmDetector detector;
	float threshold1;
	float threshold2;
	int threadnum;
	float compressrate;
	int grubsize;
};

/*! @}*/ 

#endif
