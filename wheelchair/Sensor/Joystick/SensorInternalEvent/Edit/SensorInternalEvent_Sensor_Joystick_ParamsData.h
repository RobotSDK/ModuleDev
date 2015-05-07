//You need to modify this file.

#ifndef SENSORINTERNALEVENT_SENSOR_JOYSTICK_PARAMSDATA_H
#define SENSORINTERNALEVENT_SENSOR_JOYSTICK_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup SensorInternalEvent_Sensor_Joystick_ParamsData SensorInternalEvent_Sensor_Joystick_ParamsData
	\ingroup SensorInternalEvent_Sensor_Joystick
	\brief SensorInternalEvent_Sensor_Joystick_ParamsData defines the ParamsData in SensorInternalEvent_Sensor_Joystick.
*/

/*! \addtogroup SensorInternalEvent_Sensor_Joystick_ParamsData
	@{
*/

/*! \file SensorInternalEvent_Sensor_Joystick_ParamsData.h
	 Defines the ParamsData of SensorInternalEvent_Sensor_Joystick
*/

//*******************Please add other headers below*******************


//There is no input data headers.

/*! \def SensorInternalEvent_Sensor_Joystick_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=0
*/
#define SensorInternalEvent_Sensor_Joystick_INPUTPORTSSIZE QList<int>()

//The Params is defined as below
/*! \class SensorInternalEvent_Sensor_Joystick_Params 
	\brief The Params of SensorInternalEvent_Sensor_Joystick.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT SensorInternalEvent_Sensor_Joystick_Params 
{
public:
	/*! \fn SensorInternalEvent_Sensor_Joystick_Params()
		\brief The constructor of SensorInternalEvent_Sensor_Joystick_Params. [required]
		\details ****Please add details below****

	*/
	SensorInternalEvent_Sensor_Joystick_Params() 
	{
		
	}
	/*! \fn ~SensorInternalEvent_Sensor_Joystick_Params()
		\brief The destructor of SensorInternalEvent_Sensor_Joystick_Params. [required]
		\details *****Please add details below*****

	*/
	~SensorInternalEvent_Sensor_Joystick_Params() 
	{
		
	}
public:
	//*******************Please add variables below*******************

};

//The Output Data is defined as below
/*! \class SensorInternalEvent_Sensor_Joystick_Data 
	\brief The Data of SensorInternalEvent_Sensor_Joystick.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT SensorInternalEvent_Sensor_Joystick_Data 
{
public:
	/*! \fn SensorInternalEvent_Sensor_Joystick_Data()
		\brief The constructor of SensorInternalEvent_Sensor_Joystick_Data. [required]
		\details ****Please add details below****

	*/
	SensorInternalEvent_Sensor_Joystick_Data() 
	{
        linear_vel = angular_vel = 0;
        forward = back = left = right = 0;
	}
	/*! \fn ~SensorInternalEvent_Sensor_Joystick_Data()
		\brief The destructor of SensorInternalEvent_Sensor_Joystick_Data. [required]
		\details *****Please add details below*****

	*/
	~SensorInternalEvent_Sensor_Joystick_Data() 
	{
		
	}
public:
	//*******************Please add variables below*******************
    double linear_vel;
    double angular_vel;
    bool forward, back, left, right;
    QTime timestamp;
};

/*! \def SensorInternalEvent_Sensor_Joystick_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 1.
*/
#define SensorInternalEvent_Sensor_Joystick_OUTPUTPORTSNUMBER 1

/*! @}*/ 

#endif
