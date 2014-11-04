//You need to modify this file.

#ifndef PROCESSORMONO_ALGORITHM_DETECTION_CAMERA_DBM_PARAMSDATA_H
#define PROCESSORMONO_ALGORITHM_DETECTION_CAMERA_DBM_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup ProcessorMono_Algorithm_Detection_Camera_DBM_ParamsData ProcessorMono_Algorithm_Detection_Camera_DBM_ParamsData
	\ingroup ProcessorMono_Algorithm_Detection_Camera_DBM
	\brief ProcessorMono_Algorithm_Detection_Camera_DBM_ParamsData defines the ParamsData in ProcessorMono_Algorithm_Detection_Camera_DBM.
*/

/*! \addtogroup ProcessorMono_Algorithm_Detection_Camera_DBM_ParamsData
	@{
*/

/*! \file ProcessorMono_Algorithm_Detection_Camera_DBM_ParamsData.h
	 Defines the ParamsData of ProcessorMono_Algorithm_Detection_Camera_DBM
*/

//*******************Please add other headers below*******************
#include<opencv2/opencv.hpp>

//1 input data header(s) refered

//Defines Params Simulator_Sensor_Camera_Params and Input Data Simulator_Sensor_Camera_Data
#include<COI/Sensor/Camera/Simulator/Edit/Simulator_Sensor_Camera_ParamsData.h>

//0 new input data type(s) created

/*! \def ProcessorMono_Algorithm_Detection_Camera_DBM_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=1
	\details
	- Input Port #0: Buffer_Size = 0, Params_Type = Simulator_Sensor_Camera_Params, Data_Type = Simulator_Sensor_Camera_Data
*/
#define ProcessorMono_Algorithm_Detection_Camera_DBM_INPUTPORTSSIZE QList<int>()<<0

//The Params is defined as below
/*! \class ProcessorMono_Algorithm_Detection_Camera_DBM_Params : public Simulator_Sensor_Camera_Params 
	\brief The Params of ProcessorMono_Algorithm_Detection_Camera_DBM.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT ProcessorMono_Algorithm_Detection_Camera_DBM_Params : public Simulator_Sensor_Camera_Params 
{
public:
	/*! \fn ProcessorMono_Algorithm_Detection_Camera_DBM_Params()
		\brief The constructor of ProcessorMono_Algorithm_Detection_Camera_DBM_Params. [required]
		\details ****Please add details below****

	*/
	ProcessorMono_Algorithm_Detection_Camera_DBM_Params() 
	{
		
	}
	/*! \fn ~ProcessorMono_Algorithm_Detection_Camera_DBM_Params()
		\brief The destructor of ProcessorMono_Algorithm_Detection_Camera_DBM_Params. [required]
		\details *****Please add details below*****

	*/
	~ProcessorMono_Algorithm_Detection_Camera_DBM_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    QVector<QString> classes;
};

//The Output Data is defined as below
/*! \class ProcessorMono_Algorithm_Detection_Camera_DBM_Data : public Simulator_Sensor_Camera_Data 
	\brief The Data of ProcessorMono_Algorithm_Detection_Camera_DBM.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT ProcessorMono_Algorithm_Detection_Camera_DBM_Data : public Simulator_Sensor_Camera_Data 
{
public:
	/*! \fn ProcessorMono_Algorithm_Detection_Camera_DBM_Data()
		\brief The constructor of ProcessorMono_Algorithm_Detection_Camera_DBM_Data. [required]
		\details ****Please add details below****

	*/
	ProcessorMono_Algorithm_Detection_Camera_DBM_Data() 
	{
		
	}
	/*! \fn ~ProcessorMono_Algorithm_Detection_Camera_DBM_Data()
		\brief The destructor of ProcessorMono_Algorithm_Detection_Camera_DBM_Data. [required]
		\details *****Please add details below*****

	*/
	~ProcessorMono_Algorithm_Detection_Camera_DBM_Data() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    QVector<cv::LatentSvmDetector::ObjectDetection> objects;
};

/*! \def ProcessorMono_Algorithm_Detection_Camera_DBM_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 1.
*/
#define ProcessorMono_Algorithm_Detection_Camera_DBM_OUTPUTPORTSNUMBER 1

/*! @}*/ 

#endif
