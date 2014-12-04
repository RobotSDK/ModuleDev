//You need to modify this file.

#ifndef SENSORINTERNALEVENT_ALGORITHM_DETECTION_DPM_PARAMSDATA_H
#define SENSORINTERNALEVENT_ALGORITHM_DETECTION_DPM_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup SensorInternalEvent_Algorithm_Detection_DPM_ParamsData SensorInternalEvent_Algorithm_Detection_DPM_ParamsData
	\ingroup SensorInternalEvent_Algorithm_Detection_DPM
	\brief SensorInternalEvent_Algorithm_Detection_DPM_ParamsData defines the ParamsData in SensorInternalEvent_Algorithm_Detection_DPM.
*/

/*! \addtogroup SensorInternalEvent_Algorithm_Detection_DPM_ParamsData
	@{
*/

/*! \file SensorInternalEvent_Algorithm_Detection_DPM_ParamsData.h
	 Defines the ParamsData of SensorInternalEvent_Algorithm_Detection_DPM
*/

//*******************Please add other headers below*******************
#include<opencv2/opencv.hpp>
#include<rosinterface.h>
#include<dpm/ImageObjects.h>

//There is no input data headers.

/*! \def SensorInternalEvent_Algorithm_Detection_DPM_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=0
*/
#define SensorInternalEvent_Algorithm_Detection_DPM_INPUTPORTSSIZE QList<int>()

//The Params is defined as below
/*! \class SensorInternalEvent_Algorithm_Detection_DPM_Params 
	\brief The Params of SensorInternalEvent_Algorithm_Detection_DPM.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT SensorInternalEvent_Algorithm_Detection_DPM_Params 
{
public:
	/*! \fn SensorInternalEvent_Algorithm_Detection_DPM_Params()
		\brief The constructor of SensorInternalEvent_Algorithm_Detection_DPM_Params. [required]
		\details ****Please add details below****

	*/
	SensorInternalEvent_Algorithm_Detection_DPM_Params() 
	{
        calibfilename="#(CameraCalibFilename)";
        extrinsicmat=cv::Mat::eye(4,4,CV_64F);
        cameramat=cv::Mat::eye(3,3,CV_64F);
        distcoeff=cv::Mat::zeros(1,5,CV_64F);
	}
	/*! \fn ~SensorInternalEvent_Algorithm_Detection_DPM_Params()
		\brief The destructor of SensorInternalEvent_Algorithm_Detection_DPM_Params. [required]
		\details *****Please add details below*****

	*/
	~SensorInternalEvent_Algorithm_Detection_DPM_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    QString calibfilename;
    cv::Mat extrinsicmat;
    cv::Mat cameramat;
    cv::Mat distcoeff;
};

//The Output Data is defined as below
/*! \class SensorInternalEvent_Algorithm_Detection_DPM_Data 
	\brief The Data of SensorInternalEvent_Algorithm_Detection_DPM.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT SensorInternalEvent_Algorithm_Detection_DPM_Data 
{
public:
	/*! \fn SensorInternalEvent_Algorithm_Detection_DPM_Data()
		\brief The constructor of SensorInternalEvent_Algorithm_Detection_DPM_Data. [required]
		\details ****Please add details below****

	*/
	SensorInternalEvent_Algorithm_Detection_DPM_Data() 
	{
		
	}
	/*! \fn ~SensorInternalEvent_Algorithm_Detection_DPM_Data()
		\brief The destructor of SensorInternalEvent_Algorithm_Detection_DPM_Data. [required]
		\details *****Please add details below*****

	*/
	~SensorInternalEvent_Algorithm_Detection_DPM_Data() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    dpm::ImageObjectsConstPtr dpmdetection;
    QTime timestamp;
    QVector<cv::Rect> cvdetection;
};

/*! \def SensorInternalEvent_Algorithm_Detection_DPM_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 1.
*/
#define SensorInternalEvent_Algorithm_Detection_DPM_OUTPUTPORTSNUMBER 1

/*! @}*/ 

#endif
