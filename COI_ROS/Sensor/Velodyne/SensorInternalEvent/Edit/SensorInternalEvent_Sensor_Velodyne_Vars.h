//You need to modify this file.

#ifndef SENSORINTERNALEVENT_SENSOR_VELODYNE_VARS_H
#define SENSORINTERNALEVENT_SENSOR_VELODYNE_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup SensorInternalEvent_Sensor_Velodyne_Vars SensorInternalEvent_Sensor_Velodyne_Vars
	\ingroup SensorInternalEvent_Sensor_Velodyne
	\brief SensorInternalEvent_Sensor_Velodyne_Vars defines the Vars in SensorInternalEvent_Sensor_Velodyne.
*/

/*! \addtogroup SensorInternalEvent_Sensor_Velodyne_Vars
	@{
*/

/*! \file SensorInternalEvent_Sensor_Velodyne_Vars.h
	 Defines the Vars of SensorInternalEvent_Sensor_Velodyne
*/

//*******************Please add other headers below*******************
#include<rosinterface.h>
#include<sensor_msgs/PointCloud2.h>

//The Vars is defined as below
/*! \class SensorInternalEvent_Sensor_Velodyne_Vars 
	\brief The Vars of SensorInternalEvent_Sensor_Velodyne.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT SensorInternalEvent_Sensor_Velodyne_Vars 
{
public:
	/*! \fn SensorInternalEvent_Sensor_Velodyne_Vars()
		\brief The constructor of SensorInternalEvent_Sensor_Velodyne_Vars. [required]
		\details ****Please add details below****

	*/
	SensorInternalEvent_Sensor_Velodyne_Vars() 
	{
        topic="velodyne_points";
        queuesize=1000;
        queryinterval=10;
        velodynesub=new ROSSub<sensor_msgs::PointCloud2ConstPtr>(topic,queuesize,queryinterval);
	}
	/*! \fn ~SensorInternalEvent_Sensor_Velodyne_Vars()
		\brief The destructor of SensorInternalEvent_Sensor_Velodyne_Vars. [required]
		\details *****Please add details below*****

	*/
	~SensorInternalEvent_Sensor_Velodyne_Vars() 
	{
        if(velodynesub!=NULL)
        {
            delete velodynesub;
            velodynesub=NULL;
        }
	}
public:
	//*******************Please add variables below*******************
    QString topic;
    u_int32_t queuesize;
    int queryinterval;
    ROSSub<sensor_msgs::PointCloud2ConstPtr> * velodynesub;
};

/*! @}*/ 

#endif
