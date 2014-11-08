//You need to modify this file.

#ifndef SENSORINTERNALEVENT_ROS_SENSOR_CAMERA_VARS_H
#define SENSORINTERNALEVENT_ROS_SENSOR_CAMERA_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup SensorInternalEvent_ROS_Sensor_Camera_Vars SensorInternalEvent_ROS_Sensor_Camera_Vars
	\ingroup SensorInternalEvent_ROS_Sensor_Camera
	\brief SensorInternalEvent_ROS_Sensor_Camera_Vars defines the Vars in SensorInternalEvent_ROS_Sensor_Camera.
*/

/*! \addtogroup SensorInternalEvent_ROS_Sensor_Camera_Vars
	@{
*/

/*! \file SensorInternalEvent_ROS_Sensor_Camera_Vars.h
	 Defines the Vars of SensorInternalEvent_ROS_Sensor_Camera
*/

//*******************Please add other headers below*******************
#include<rosinterface.h>
#include<sensor_msgs/Image.h>

//The Vars is defined as below
/*! \class SensorInternalEvent_ROS_Sensor_Camera_Vars 
	\brief The Vars of SensorInternalEvent_ROS_Sensor_Camera.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT SensorInternalEvent_ROS_Sensor_Camera_Vars 
{
public:
	/*! \fn SensorInternalEvent_ROS_Sensor_Camera_Vars()
		\brief The constructor of SensorInternalEvent_ROS_Sensor_Camera_Vars. [required]
		\details ****Please add details below****

	*/
	SensorInternalEvent_ROS_Sensor_Camera_Vars() 
	{
        topic="Camera";
        camerasub=new ROSSub<sensor_msgs::ImageConstPtr>(topic,1000,10);
	}
	/*! \fn ~SensorInternalEvent_ROS_Sensor_Camera_Vars()
		\brief The destructor of SensorInternalEvent_ROS_Sensor_Camera_Vars. [required]
		\details *****Please add details below*****

	*/
	~SensorInternalEvent_ROS_Sensor_Camera_Vars() 
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
    ROSSub<sensor_msgs::ImageConstPtr> * camerasub;
};

/*! @}*/ 

#endif
