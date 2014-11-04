//Generally you need not to program this file.

#include "SensorInternalEvent_ROS_Sensor_Velodyne_PrivCoreFunc.h"

void DECOFUNC(getPortsSize)(QList<int> & inputPortsSize, int & outputPortsNumber)
{
	inputPortsSize=SensorInternalEvent_ROS_Sensor_Velodyne_INPUTPORTSSIZE;
	outputPortsNumber=SensorInternalEvent_ROS_Sensor_Velodyne_OUTPUTPORTSNUMBER;
	/*======No Need to Program======*/
}

void DECOFUNC(initializeParams)(boost::shared_ptr<void> & paramsPtr)
{
	paramsPtr=boost::shared_ptr<void>(new Simulator_Sensor_Velodyne_Params());
	/*======No Need to Program======*/
}

void DECOFUNC(initializeVars)(boost::shared_ptr<void> & varsPtr)
{
	varsPtr=boost::shared_ptr<void>(new SensorInternalEvent_ROS_Sensor_Velodyne_Vars());
	/*======No Need to Program======*/
}

