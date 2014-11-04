//You need to modify this file.

#ifndef SENSORINTERNALEVENT_ROS_SENSOR_VELODYNE_VARS_H
#define SENSORINTERNALEVENT_ROS_SENSOR_VELODYNE_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup SensorInternalEvent_ROS_Sensor_Velodyne_Vars SensorInternalEvent_ROS_Sensor_Velodyne_Vars
	\ingroup SensorInternalEvent_ROS_Sensor_Velodyne
	\brief SensorInternalEvent_ROS_Sensor_Velodyne_Vars defines the Vars in SensorInternalEvent_ROS_Sensor_Velodyne.
*/

/*! \addtogroup SensorInternalEvent_ROS_Sensor_Velodyne_Vars
	@{
*/

/*! \file SensorInternalEvent_ROS_Sensor_Velodyne_Vars.h
	 Defines the Vars of SensorInternalEvent_ROS_Sensor_Velodyne
*/

//*******************Please add other headers below*******************
#include<rosinterface.h>
#include<sensor_msgs/PointCloud2.h>

//The Vars is defined as below
/*! \class SensorInternalEvent_ROS_Sensor_Velodyne_Vars 
	\brief The Vars of SensorInternalEvent_ROS_Sensor_Velodyne.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT SensorInternalEvent_ROS_Sensor_Velodyne_Vars 
{
public:
	/*! \fn SensorInternalEvent_ROS_Sensor_Velodyne_Vars()
		\brief The constructor of SensorInternalEvent_ROS_Sensor_Velodyne_Vars. [required]
		\details ****Please add details below****

	*/
	SensorInternalEvent_ROS_Sensor_Velodyne_Vars() 
	{
        velodynesub=new ROSSub<sensor_msgs::PointCloud2ConstPtr>("velodyne_points", 1000, 10);
	}
	/*! \fn ~SensorInternalEvent_ROS_Sensor_Velodyne_Vars()
		\brief The destructor of SensorInternalEvent_ROS_Sensor_Velodyne_Vars. [required]
		\details *****Please add details below*****

	*/
	~SensorInternalEvent_ROS_Sensor_Velodyne_Vars() 
	{
        if(velodynesub!=NULL)
        {
            delete velodynesub;
            velodynesub=NULL;
        }
	}
public:
	//*******************Please add variables below*******************
    ROSSub<sensor_msgs::PointCloud2ConstPtr> * velodynesub;
};

/*! @}*/ 

#endif
