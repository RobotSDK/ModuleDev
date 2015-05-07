//You need to modify this file.

#ifndef VISUALIZATIONMONO_SENSOR_JOYSTICK_PARAMSDATA_H
#define VISUALIZATIONMONO_SENSOR_JOYSTICK_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup VisualizationMono_Sensor_Joystick_ParamsData VisualizationMono_Sensor_Joystick_ParamsData
	\ingroup VisualizationMono_Sensor_Joystick
	\brief VisualizationMono_Sensor_Joystick_ParamsData defines the ParamsData in VisualizationMono_Sensor_Joystick.
*/

/*! \addtogroup VisualizationMono_Sensor_Joystick_ParamsData
	@{
*/

/*! \file VisualizationMono_Sensor_Joystick_ParamsData.h
	 Defines the ParamsData of VisualizationMono_Sensor_Joystick
*/

//*******************Please add other headers below*******************


//1 input data header(s) refered

//Defines Params SensorInternalEvent_Sensor_Joystick_Params and Input Data SensorInternalEvent_Sensor_Joystick_Data
#include<wheelchair/Sensor/Joystick/SensorInternalEvent/Edit/SensorInternalEvent_Sensor_Joystick_ParamsData.h>

//0 new input data type(s) created

/*! \def VisualizationMono_Sensor_Joystick_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=1
	\details
	- Input Port #0: Buffer_Size = 10, Params_Type = SensorInternalEvent_Sensor_Joystick_Params, Data_Type = SensorInternalEvent_Sensor_Joystick_Data
*/
#define VisualizationMono_Sensor_Joystick_INPUTPORTSSIZE QList<int>()<<10

//The Params is defined as below
/*! \class VisualizationMono_Sensor_Joystick_Params 
	\brief The Params of VisualizationMono_Sensor_Joystick.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT VisualizationMono_Sensor_Joystick_Params 
{
public:
	/*! \fn VisualizationMono_Sensor_Joystick_Params()
		\brief The constructor of VisualizationMono_Sensor_Joystick_Params. [required]
		\details ****Please add details below****

	*/
	VisualizationMono_Sensor_Joystick_Params() 
	{
		
	}
	/*! \fn ~VisualizationMono_Sensor_Joystick_Params()
		\brief The destructor of VisualizationMono_Sensor_Joystick_Params. [required]
		\details *****Please add details below*****

	*/
	~VisualizationMono_Sensor_Joystick_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************

};

//There is no Output Data.

/*! \def VisualizationMono_Sensor_Joystick_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 0.
*/
#define VisualizationMono_Sensor_Joystick_OUTPUTPORTSNUMBER 0

/*! @}*/ 

#endif