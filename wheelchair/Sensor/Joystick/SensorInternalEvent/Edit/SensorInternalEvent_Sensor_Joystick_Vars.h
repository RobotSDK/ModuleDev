//You need to modify this file.

#ifndef SENSORINTERNALEVENT_SENSOR_JOYSTICK_VARS_H
#define SENSORINTERNALEVENT_SENSOR_JOYSTICK_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup SensorInternalEvent_Sensor_Joystick_Vars SensorInternalEvent_Sensor_Joystick_Vars
	\ingroup SensorInternalEvent_Sensor_Joystick
	\brief SensorInternalEvent_Sensor_Joystick_Vars defines the Vars in SensorInternalEvent_Sensor_Joystick.
*/

/*! \addtogroup SensorInternalEvent_Sensor_Joystick_Vars
	@{
*/

/*! \file SensorInternalEvent_Sensor_Joystick_Vars.h
	 Defines the Vars of SensorInternalEvent_Sensor_Joystick
*/

//*******************Please add other headers below*******************
#include <rosinterface.h>
#include <sensor_msgs/Joy.h>

#include "SensorInternalEvent_Sensor_Joystick_ParamsData.h"

//The Vars is defined as below
/*! \class SensorInternalEvent_Sensor_Joystick_Vars 
	\brief The Vars of SensorInternalEvent_Sensor_Joystick.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT SensorInternalEvent_Sensor_Joystick_Vars 
{
public:
	/*! \fn SensorInternalEvent_Sensor_Joystick_Vars()
		\brief The constructor of SensorInternalEvent_Sensor_Joystick_Vars. [required]
		\details ****Please add details below****

	*/
	SensorInternalEvent_Sensor_Joystick_Vars() 
	{
        topic = "joy";
        joysticksub = new ROSSub<sensor_msgs::JoyConstPtr>(topic, 200, 20);

        angular_index = linear_index = 0;
        angular_scale = linear_scale = 1.0;
	}
	/*! \fn ~SensorInternalEvent_Sensor_Joystick_Vars()
		\brief The destructor of SensorInternalEvent_Sensor_Joystick_Vars. [required]
		\details *****Please add details below*****

	*/
	~SensorInternalEvent_Sensor_Joystick_Vars() 
	{
        if(joysticksub != NULL)
        {
            delete joysticksub;
            joysticksub = NULL;
        }
	}
public:
	//*******************Please add variables below*******************
    QString topic;
    ROSSub<sensor_msgs::JoyConstPtr> *joysticksub;
    double angular_scale, linear_scale;
    int angular_index, linear_index;
};

/*! @}*/ 

#endif
