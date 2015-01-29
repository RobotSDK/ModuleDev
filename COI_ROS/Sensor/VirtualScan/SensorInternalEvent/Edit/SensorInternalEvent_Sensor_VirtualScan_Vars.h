//You need to modify this file.

#ifndef SENSORINTERNALEVENT_SENSOR_VIRTUALSCAN_VARS_H
#define SENSORINTERNALEVENT_SENSOR_VIRTUALSCAN_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup SensorInternalEvent_Sensor_VirtualScan_Vars SensorInternalEvent_Sensor_VirtualScan_Vars
	\ingroup SensorInternalEvent_Sensor_VirtualScan
	\brief SensorInternalEvent_Sensor_VirtualScan_Vars defines the Vars in SensorInternalEvent_Sensor_VirtualScan.
*/

/*! \addtogroup SensorInternalEvent_Sensor_VirtualScan_Vars
	@{
*/

/*! \file SensorInternalEvent_Sensor_VirtualScan_Vars.h
	 Defines the Vars of SensorInternalEvent_Sensor_VirtualScan
*/

//*******************Please add other headers below*******************
#include<virtualscan.h>
#include<rosinterface.h>
#include<sensor_msgs/PointCloud2.h>

//The Vars is defined as below
/*! \class SensorInternalEvent_Sensor_VirtualScan_Vars 
	\brief The Vars of SensorInternalEvent_Sensor_VirtualScan.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT SensorInternalEvent_Sensor_VirtualScan_Vars 
{
public:
	/*! \fn SensorInternalEvent_Sensor_VirtualScan_Vars()
		\brief The constructor of SensorInternalEvent_Sensor_VirtualScan_Vars. [required]
		\details ****Please add details below****

	*/
	SensorInternalEvent_Sensor_VirtualScan_Vars() 
	{
        topic="velodyne_points";
        queuesize=1000;
        queryinterval=10;
        velodynesub=new ROSSub<sensor_msgs::PointCloud2ConstPtr>(topic,queuesize,queryinterval);

        beamnum=1000;
        heightstep=0.3;
        theta=30;
        minfloor=-3;
        maxceiling=3;
        maxfloor=-1.2;
        minceiling=0.5;

        neighbordis=0.3;
        pointsnum=10;
	}
	/*! \fn ~SensorInternalEvent_Sensor_VirtualScan_Vars()
		\brief The destructor of SensorInternalEvent_Sensor_VirtualScan_Vars. [required]
		\details *****Please add details below*****

	*/
	~SensorInternalEvent_Sensor_VirtualScan_Vars() 
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

    int beamnum;
    double heightstep;
    double theta;
    double minfloor;
    double maxceiling;
    double maxfloor;
    double minceiling;

    double neighbordis;
    int pointsnum;

    VirtualScan virtualscan;
};

/*! @}*/ 

#endif
