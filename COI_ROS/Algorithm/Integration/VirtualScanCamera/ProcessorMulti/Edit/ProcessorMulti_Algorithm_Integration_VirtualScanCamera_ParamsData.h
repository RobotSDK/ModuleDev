//You need to modify this file.

#ifndef PROCESSORMULTI_ALGORITHM_INTEGRATION_VIRTUALSCANCAMERA_PARAMSDATA_H
#define PROCESSORMULTI_ALGORITHM_INTEGRATION_VIRTUALSCANCAMERA_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup ProcessorMulti_Algorithm_Integration_VirtualScanCamera_ParamsData ProcessorMulti_Algorithm_Integration_VirtualScanCamera_ParamsData
	\ingroup ProcessorMulti_Algorithm_Integration_VirtualScanCamera
	\brief ProcessorMulti_Algorithm_Integration_VirtualScanCamera_ParamsData defines the ParamsData in ProcessorMulti_Algorithm_Integration_VirtualScanCamera.
*/

/*! \addtogroup ProcessorMulti_Algorithm_Integration_VirtualScanCamera_ParamsData
	@{
*/

/*! \file ProcessorMulti_Algorithm_Integration_VirtualScanCamera_ParamsData.h
	 Defines the ParamsData of ProcessorMulti_Algorithm_Integration_VirtualScanCamera
*/

//*******************Please add other headers below*******************


//2 input data header(s) refered

//Defines Params SensorInternalEvent_Sensor_Camera_Params and Input Data SensorInternalEvent_Sensor_Camera_Data
#include<COI_ROS/Sensor/Camera/SensorInternalEvent/Edit/SensorInternalEvent_Sensor_Camera_ParamsData.h>
//Defines Params SensorInternalEvent_Sensor_VirtualScan_Params and Input Data SensorInternalEvent_Sensor_VirtualScan_Data
#include<COI_ROS/Sensor/VirtualScan/SensorInternalEvent/Edit/SensorInternalEvent_Sensor_VirtualScan_ParamsData.h>

//0 new input data type(s) created

/*! \def ProcessorMulti_Algorithm_Integration_VirtualScanCamera_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=2
	\details
	- Input Port #0: Buffer_Size = 0, Params_Type = SensorInternalEvent_Sensor_VirtualScan_Params, Data_Type = SensorInternalEvent_Sensor_VirtualScan_Data
	- Input Port #1: Buffer_Size = 0, Params_Type = SensorInternalEvent_Sensor_Camera_Params, Data_Type = SensorInternalEvent_Sensor_Camera_Data
*/
#define ProcessorMulti_Algorithm_Integration_VirtualScanCamera_INPUTPORTSSIZE QList<int>()<<0<<0

//The Params is defined as below
/*! \class ProcessorMulti_Algorithm_Integration_VirtualScanCamera_Params 
	\brief The Params of ProcessorMulti_Algorithm_Integration_VirtualScanCamera.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT ProcessorMulti_Algorithm_Integration_VirtualScanCamera_Params 
{
public:
	/*! \fn ProcessorMulti_Algorithm_Integration_VirtualScanCamera_Params()
		\brief The constructor of ProcessorMulti_Algorithm_Integration_VirtualScanCamera_Params. [required]
		\details ****Please add details below****

	*/
	ProcessorMulti_Algorithm_Integration_VirtualScanCamera_Params() 
	{
		
	}
	/*! \fn ~ProcessorMulti_Algorithm_Integration_VirtualScanCamera_Params()
		\brief The destructor of ProcessorMulti_Algorithm_Integration_VirtualScanCamera_Params. [required]
		\details *****Please add details below*****

	*/
	~ProcessorMulti_Algorithm_Integration_VirtualScanCamera_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    cv::Mat velodyneextrinsicmat;
    cv::Mat cameraextrinsicmat;
    cv::Mat cameramat;
    cv::Mat distcoeff;
};

//The Output Data is defined as below
/*! \class ProcessorMulti_Algorithm_Integration_VirtualScanCamera_Data 
	\brief The Data of ProcessorMulti_Algorithm_Integration_VirtualScanCamera.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT ProcessorMulti_Algorithm_Integration_VirtualScanCamera_Data 
{
public:
	/*! \fn ProcessorMulti_Algorithm_Integration_VirtualScanCamera_Data()
		\brief The constructor of ProcessorMulti_Algorithm_Integration_VirtualScanCamera_Data. [required]
		\details ****Please add details below****

	*/
	ProcessorMulti_Algorithm_Integration_VirtualScanCamera_Data() 
	{
		
	}
	/*! \fn ~ProcessorMulti_Algorithm_Integration_VirtualScanCamera_Data()
		\brief The destructor of ProcessorMulti_Algorithm_Integration_VirtualScanCamera_Data. [required]
		\details *****Please add details below*****

	*/
	~ProcessorMulti_Algorithm_Integration_VirtualScanCamera_Data() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    QTime virtualscantimestamp;
    QTime cameratimestamp;
    cv::Mat cvimage;
    QVector<QPoint> imagepoint;
    QVector<QPointF> xypoint;
    QVector<double> heights;
    QVector<int> label;
    QVector<QVector<int> > index;
    int labelcount;
};

/*! \def ProcessorMulti_Algorithm_Integration_VirtualScanCamera_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 1.
*/
#define ProcessorMulti_Algorithm_Integration_VirtualScanCamera_OUTPUTPORTSNUMBER 1

/*! @}*/ 

#endif
