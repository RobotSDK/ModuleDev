//You need to modify this file.

#ifndef SENSORINTERNALEVENT_SENSOR_CAMERA_VARS_H
#define SENSORINTERNALEVENT_SENSOR_CAMERA_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup SensorInternalEvent_Sensor_Camera_Vars SensorInternalEvent_Sensor_Camera_Vars
	\ingroup SensorInternalEvent_Sensor_Camera
	\brief SensorInternalEvent_Sensor_Camera_Vars defines the Vars in SensorInternalEvent_Sensor_Camera.
*/

/*! \addtogroup SensorInternalEvent_Sensor_Camera_Vars
	@{
*/

/*! \file SensorInternalEvent_Sensor_Camera_Vars.h
	 Defines the Vars of SensorInternalEvent_Sensor_Camera
*/

//*******************Please add other headers below*******************
#include<rosinterface.h>
#include<sensor_msgs/Image.h>

//The Vars is defined as below
/*! \class SensorInternalEvent_Sensor_Camera_Vars 
	\brief The Vars of SensorInternalEvent_Sensor_Camera.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT SensorInternalEvent_Sensor_Camera_Vars 
{
public:
	/*! \fn SensorInternalEvent_Sensor_Camera_Vars()
		\brief The constructor of SensorInternalEvent_Sensor_Camera_Vars. [required]
		\details ****Please add details below****

	*/
	SensorInternalEvent_Sensor_Camera_Vars() 
	{
        topic="image_raw";
        queuesize=1000;
        queryinterval=10;
        camerasub=new ROSSub<sensor_msgs::ImageConstPtr>(topic,queuesize,queryinterval);
	}
	/*! \fn ~SensorInternalEvent_Sensor_Camera_Vars()
		\brief The destructor of SensorInternalEvent_Sensor_Camera_Vars. [required]
		\details *****Please add details below*****

	*/
	~SensorInternalEvent_Sensor_Camera_Vars() 
	{
        if(camerasub!=NULL)
        {
            delete camerasub;
            camerasub=NULL;
        }
	}
public:
	//*******************Please add variables below*******************
    QString topic;
    u_int32_t queuesize;
    int queryinterval;
    ROSSub<sensor_msgs::ImageConstPtr> * camerasub;
};

/*! @}*/ 

#endif
