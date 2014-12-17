//You need to modify this file.

#ifndef SENSORINTERNALEVENT_ALGORITHM_SEGMENTATION_VELODYNE_VARS_H
#define SENSORINTERNALEVENT_ALGORITHM_SEGMENTATION_VELODYNE_VARS_H

#include<RobotSDK_Global.h>

/*! \defgroup SensorInternalEvent_Algorithm_Segmentation_Velodyne_Vars SensorInternalEvent_Algorithm_Segmentation_Velodyne_Vars
	\ingroup SensorInternalEvent_Algorithm_Segmentation_Velodyne
	\brief SensorInternalEvent_Algorithm_Segmentation_Velodyne_Vars defines the Vars in SensorInternalEvent_Algorithm_Segmentation_Velodyne.
*/

/*! \addtogroup SensorInternalEvent_Algorithm_Segmentation_Velodyne_Vars
	@{
*/

/*! \file SensorInternalEvent_Algorithm_Segmentation_Velodyne_Vars.h
	 Defines the Vars of SensorInternalEvent_Algorithm_Segmentation_Velodyne
*/

//*******************Please add other headers below*******************
#include<rosinterface.h>
#include<sensor_msgs/PointCloud2.h>

//The Vars is defined as below
/*! \class SensorInternalEvent_Algorithm_Segmentation_Velodyne_Vars 
	\brief The Vars of SensorInternalEvent_Algorithm_Segmentation_Velodyne.
	\details **Please add details below**

*/
class ROBOTSDK_OUTPUT SensorInternalEvent_Algorithm_Segmentation_Velodyne_Vars 
{
public:
	/*! \fn SensorInternalEvent_Algorithm_Segmentation_Velodyne_Vars()
		\brief The constructor of SensorInternalEvent_Algorithm_Segmentation_Velodyne_Vars. [required]
		\details ****Please add details below****

	*/
	SensorInternalEvent_Algorithm_Segmentation_Velodyne_Vars() 
	{
        topic="velodyne_points/labeled_pointcloud";
        queuesize=1000;
        queryinterval=10;
        segmentsub=new ROSSub<sensor_msgs::PointCloud2ConstPtr>(topic,queuesize,queryinterval);
	}
	/*! \fn ~SensorInternalEvent_Algorithm_Segmentation_Velodyne_Vars()
		\brief The destructor of SensorInternalEvent_Algorithm_Segmentation_Velodyne_Vars. [required]
		\details *****Please add details below*****

	*/
	~SensorInternalEvent_Algorithm_Segmentation_Velodyne_Vars() 
	{
        if(segmentsub!=NULL)
        {
            delete segmentsub;
            segmentsub=NULL;
        }
	}
public:
	//*******************Please add variables below*******************
    QString topic;
    u_int32_t queuesize;
    int queryinterval;
    ROSSub<sensor_msgs::PointCloud2ConstPtr> * segmentsub;
};

/*! @}*/ 

#endif
