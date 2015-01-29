//You need to modify this file.

#ifndef PROCESSORMULTI_ALGORITHM_INTEGRATION_VIRTUALSCANNDT3D_PARAMSDATA_H
#define PROCESSORMULTI_ALGORITHM_INTEGRATION_VIRTUALSCANNDT3D_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup ProcessorMulti_Algorithm_Integration_VirtualScanNDT3D_ParamsData ProcessorMulti_Algorithm_Integration_VirtualScanNDT3D_ParamsData
	\ingroup ProcessorMulti_Algorithm_Integration_VirtualScanNDT3D
	\brief ProcessorMulti_Algorithm_Integration_VirtualScanNDT3D_ParamsData defines the ParamsData in ProcessorMulti_Algorithm_Integration_VirtualScanNDT3D.
*/

/*! \addtogroup ProcessorMulti_Algorithm_Integration_VirtualScanNDT3D_ParamsData
	@{
*/

/*! \file ProcessorMulti_Algorithm_Integration_VirtualScanNDT3D_ParamsData.h
	 Defines the ParamsData of ProcessorMulti_Algorithm_Integration_VirtualScanNDT3D
*/

//*******************Please add other headers below*******************
#include<opencv2/opencv.hpp>

//2 input data header(s) refered

//Defines Params SensorInternalEvent_Algorithm_Localization_NDT3D_Params and Input Data SensorInternalEvent_Algorithm_Localization_NDT3D_Data
#include<COI_ROS/Algorithm/Localization/NDT3D/SensorInternalEvent/Edit/SensorInternalEvent_Algorithm_Localization_NDT3D_ParamsData.h>
//Defines Params SensorInternalEvent_Sensor_VirtualScan_Params and Input Data SensorInternalEvent_Sensor_VirtualScan_Data
#include<COI_ROS/Sensor/VirtualScan/SensorInternalEvent/Edit/SensorInternalEvent_Sensor_VirtualScan_ParamsData.h>

//0 new input data type(s) created

/*! \def ProcessorMulti_Algorithm_Integration_VirtualScanNDT3D_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=2
	\details
	- Input Port #0: Buffer_Size = 0, Params_Type = SensorInternalEvent_Sensor_VirtualScan_Params, Data_Type = SensorInternalEvent_Sensor_VirtualScan_Data
	- Input Port #1: Buffer_Size = 0, Params_Type = SensorInternalEvent_Algorithm_Localization_NDT3D_Params, Data_Type = SensorInternalEvent_Algorithm_Localization_NDT3D_Data
*/
#define ProcessorMulti_Algorithm_Integration_VirtualScanNDT3D_INPUTPORTSSIZE QList<int>()<<0<<0

//The Params is defined as below
/*! \class ProcessorMulti_Algorithm_Integration_VirtualScanNDT3D_Params 
	\brief The Params of ProcessorMulti_Algorithm_Integration_VirtualScanNDT3D.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT ProcessorMulti_Algorithm_Integration_VirtualScanNDT3D_Params 
{
public:
	/*! \fn ProcessorMulti_Algorithm_Integration_VirtualScanNDT3D_Params()
		\brief The constructor of ProcessorMulti_Algorithm_Integration_VirtualScanNDT3D_Params. [required]
		\details ****Please add details below****

	*/
	ProcessorMulti_Algorithm_Integration_VirtualScanNDT3D_Params() 
	{
		
	}
	/*! \fn ~ProcessorMulti_Algorithm_Integration_VirtualScanNDT3D_Params()
		\brief The destructor of ProcessorMulti_Algorithm_Integration_VirtualScanNDT3D_Params. [required]
		\details *****Please add details below*****

	*/
	~ProcessorMulti_Algorithm_Integration_VirtualScanNDT3D_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************

};

//The Output Data is defined as below
/*! \class ProcessorMulti_Algorithm_Integration_VirtualScanNDT3D_Data 
	\brief The Data of ProcessorMulti_Algorithm_Integration_VirtualScanNDT3D.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT ProcessorMulti_Algorithm_Integration_VirtualScanNDT3D_Data 
{
public:
	/*! \fn ProcessorMulti_Algorithm_Integration_VirtualScanNDT3D_Data()
		\brief The constructor of ProcessorMulti_Algorithm_Integration_VirtualScanNDT3D_Data. [required]
		\details ****Please add details below****

	*/
	ProcessorMulti_Algorithm_Integration_VirtualScanNDT3D_Data() 
	{
		
	}
	/*! \fn ~ProcessorMulti_Algorithm_Integration_VirtualScanNDT3D_Data()
		\brief The destructor of ProcessorMulti_Algorithm_Integration_VirtualScanNDT3D_Data. [required]
		\details *****Please add details below*****

	*/
	~ProcessorMulti_Algorithm_Integration_VirtualScanNDT3D_Data() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    QTime virtualscantimestamp;
    QTime ndt3dtimestamp;
    cv::Mat cvtransform;
    cv::Mat points;
};

/*! \def ProcessorMulti_Algorithm_Integration_VirtualScanNDT3D_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 1.
*/
#define ProcessorMulti_Algorithm_Integration_VirtualScanNDT3D_OUTPUTPORTSNUMBER 1

/*! @}*/ 

#endif
