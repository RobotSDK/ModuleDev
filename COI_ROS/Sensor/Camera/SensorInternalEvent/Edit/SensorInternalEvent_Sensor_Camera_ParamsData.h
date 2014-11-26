//You need to modify this file.

#ifndef SENSORINTERNALEVENT_SENSOR_CAMERA_PARAMSDATA_H
#define SENSORINTERNALEVENT_SENSOR_CAMERA_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup SensorInternalEvent_Sensor_Camera_ParamsData SensorInternalEvent_Sensor_Camera_ParamsData
	\ingroup SensorInternalEvent_Sensor_Camera
	\brief SensorInternalEvent_Sensor_Camera_ParamsData defines the ParamsData in SensorInternalEvent_Sensor_Camera.
*/

/*! \addtogroup SensorInternalEvent_Sensor_Camera_ParamsData
	@{
*/

/*! \file SensorInternalEvent_Sensor_Camera_ParamsData.h
	 Defines the ParamsData of SensorInternalEvent_Sensor_Camera
*/

//*******************Please add other headers below*******************
#include<opencv2/opencv.hpp>
#include<sensor_msgs/Image.h>

//There is no input data headers.

/*! \def SensorInternalEvent_Sensor_Camera_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=0
*/
#define SensorInternalEvent_Sensor_Camera_INPUTPORTSSIZE QList<int>()

//The Params is defined as below
/*! \class SensorInternalEvent_Sensor_Camera_Params 
	\brief The Params of SensorInternalEvent_Sensor_Camera.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT SensorInternalEvent_Sensor_Camera_Params 
{
public:
	/*! \fn SensorInternalEvent_Sensor_Camera_Params()
		\brief The constructor of SensorInternalEvent_Sensor_Camera_Params. [required]
		\details ****Please add details below****

	*/
	SensorInternalEvent_Sensor_Camera_Params() 
	{
        calibfilename="#(CameraCalibFilename)";
        extrinsicmat=cv::Mat::eye(4,4,CV_64F);
        cameramat=cv::Mat::eye(3,3,CV_64F);
        distcoeff=cv::Mat::zeros(1,5,CV_64F);
	}
	/*! \fn ~SensorInternalEvent_Sensor_Camera_Params()
		\brief The destructor of SensorInternalEvent_Sensor_Camera_Params. [required]
		\details *****Please add details below*****

	*/
	~SensorInternalEvent_Sensor_Camera_Params() 
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
/*! \class SensorInternalEvent_Sensor_Camera_Data 
	\brief The Data of SensorInternalEvent_Sensor_Camera.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT SensorInternalEvent_Sensor_Camera_Data 
{
public:
	/*! \fn SensorInternalEvent_Sensor_Camera_Data()
		\brief The constructor of SensorInternalEvent_Sensor_Camera_Data. [required]
		\details ****Please add details below****

	*/
	SensorInternalEvent_Sensor_Camera_Data() 
	{
		
	}
	/*! \fn ~SensorInternalEvent_Sensor_Camera_Data()
		\brief The destructor of SensorInternalEvent_Sensor_Camera_Data. [required]
		\details *****Please add details below*****

	*/
	~SensorInternalEvent_Sensor_Camera_Data() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    sensor_msgs::ImageConstPtr cameraimage;
    QTime timestamp;
    cv::Mat cvimage;
};

/*! \def SensorInternalEvent_Sensor_Camera_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 1.
*/
#define SensorInternalEvent_Sensor_Camera_OUTPUTPORTSNUMBER 1

/*! @}*/ 

#endif
