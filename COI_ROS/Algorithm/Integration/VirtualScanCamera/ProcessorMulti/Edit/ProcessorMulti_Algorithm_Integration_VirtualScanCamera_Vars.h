//You need to modify this file.

#ifndef PROCESSORMULTI_ALGORITHM_INTEGRATION_VIRTUALSCANCAMERA_VARS_H
#define PROCESSORMULTI_ALGORITHM_INTEGRATION_VIRTUALSCANCAMERA_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup ProcessorMulti_Algorithm_Integration_VirtualScanCamera_Vars ProcessorMulti_Algorithm_Integration_VirtualScanCamera_Vars
	\ingroup ProcessorMulti_Algorithm_Integration_VirtualScanCamera
	\brief ProcessorMulti_Algorithm_Integration_VirtualScanCamera_Vars defines the Vars in ProcessorMulti_Algorithm_Integration_VirtualScanCamera.
*/

/*! \addtogroup ProcessorMulti_Algorithm_Integration_VirtualScanCamera_Vars
	@{
*/

/*! \file ProcessorMulti_Algorithm_Integration_VirtualScanCamera_Vars.h
	 Defines the Vars of ProcessorMulti_Algorithm_Integration_VirtualScanCamera
*/

//*******************Please add other headers below*******************
#include<opencv2/opencv.hpp>
#include<datasync.h>

//The Vars is defined as below
/*! \class ProcessorMulti_Algorithm_Integration_VirtualScanCamera_Vars 
	\brief The Vars of ProcessorMulti_Algorithm_Integration_VirtualScanCamera.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT ProcessorMulti_Algorithm_Integration_VirtualScanCamera_Vars 
{
public:
	/*! \fn ProcessorMulti_Algorithm_Integration_VirtualScanCamera_Vars()
		\brief The constructor of ProcessorMulti_Algorithm_Integration_VirtualScanCamera_Vars. [required]
		\details ****Please add details below****

	*/
	ProcessorMulti_Algorithm_Integration_VirtualScanCamera_Vars() 
	{
		
	}
	/*! \fn ~ProcessorMulti_Algorithm_Integration_VirtualScanCamera_Vars()
		\brief The destructor of ProcessorMulti_Algorithm_Integration_VirtualScanCamera_Vars. [required]
		\details *****Please add details below*****

	*/
	~ProcessorMulti_Algorithm_Integration_VirtualScanCamera_Vars() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    struct VirtualScanBufferData
    {
        QTime timestamp;
        QVector<double> virtualscan;
        QVector<double> heights;
    };
    struct CameraBufferData
    {
        QTime timestamp;
        cv::Mat cvimage;
    };
    DataSync<VirtualScanBufferData,CameraBufferData> datasync;
    bool virtualscaninit;
    bool camerainit;
};

/*! @}*/ 

#endif
