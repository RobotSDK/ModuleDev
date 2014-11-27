//You need to modify this file.

#ifndef VISUALIZATIONMONO_ROS_SENSOR_CAMERA_PARAMSDATA_H
#define VISUALIZATIONMONO_ROS_SENSOR_CAMERA_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMono_ROS_Sensor_Camera_ParamsData VisualizationMono_ROS_Sensor_Camera_ParamsData
	\ingroup VisualizationMono_ROS_Sensor_Camera
	\brief VisualizationMono_ROS_Sensor_Camera_ParamsData defines the ParamsData in VisualizationMono_ROS_Sensor_Camera.
*/

/*! \addtogroup VisualizationMono_ROS_Sensor_Camera_ParamsData
	@{
*/

/*! \file VisualizationMono_ROS_Sensor_Camera_ParamsData.h
	 Defines the ParamsData of VisualizationMono_ROS_Sensor_Camera
*/

//*******************Please add other headers below*******************


//1 input data header(s) refered

//Defines Params SensorInternalEvent_ROS_Sensor_Camera_Params and Input Data SensorInternalEvent_ROS_Sensor_Camera_Data
#include<ROS/ROS/Sensor/Camera/SensorInternalEvent/Edit/SensorInternalEvent_ROS_Sensor_Camera_ParamsData.h>

//0 new input data type(s) created

/*! \def VisualizationMono_ROS_Sensor_Camera_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=1
	\details
	- Input Port #0: Buffer_Size = 0, Params_Type = SensorInternalEvent_ROS_Sensor_Camera_Params, Data_Type = SensorInternalEvent_ROS_Sensor_Camera_Data
*/
#define VisualizationMono_ROS_Sensor_Camera_INPUTPORTSSIZE QList<int>()<<0

//The Params is defined as below
/*! \class VisualizationMono_ROS_Sensor_Camera_Params 
	\brief The Params of VisualizationMono_ROS_Sensor_Camera.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT VisualizationMono_ROS_Sensor_Camera_Params 
{
public:
	/*! \fn VisualizationMono_ROS_Sensor_Camera_Params()
		\brief The constructor of VisualizationMono_ROS_Sensor_Camera_Params. [required]
		\details ****Please add details below****

	*/
	VisualizationMono_ROS_Sensor_Camera_Params() 
	{
        compressrate=1;
	}
	/*! \fn ~VisualizationMono_ROS_Sensor_Camera_Params()
		\brief The destructor of VisualizationMono_ROS_Sensor_Camera_Params. [required]
		\details *****Please add details below*****

	*/
	~VisualizationMono_ROS_Sensor_Camera_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    double compressrate;
};

//There is no Output Data.

/*! \def VisualizationMono_ROS_Sensor_Camera_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 0.
*/
#define VisualizationMono_ROS_Sensor_Camera_OUTPUTPORTSNUMBER 0

/*! @}*/ 

#endif
