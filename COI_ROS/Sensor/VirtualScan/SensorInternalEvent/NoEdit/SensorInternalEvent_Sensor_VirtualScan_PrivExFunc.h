//You need not to modify this file.

#ifndef SENSORINTERNALEVENT_SENSOR_VIRTUALSCAN_PRIVEXFUNC_H
#define SENSORINTERNALEVENT_SENSOR_VIRTUALSCAN_PRIVEXFUNC_H

#include<RobotSDK_Global.h>

/*! \defgroup SensorInternalEvent_Sensor_VirtualScan_PrivExFunc SensorInternalEvent_Sensor_VirtualScan_PrivExFunc
	\ingroup SensorInternalEvent_Sensor_VirtualScan
	\brief SensorInternalEvent_Sensor_VirtualScan_PrivExFunc defines the PrivExFunc in SensorInternalEvent_Sensor_VirtualScan.
*/

/*! \addtogroup SensorInternalEvent_Sensor_VirtualScan_PrivExFunc
	@{
*/

/*! \file SensorInternalEvent_Sensor_VirtualScan_PrivExFunc.h
	 Defines the PrivExFunc of SensorInternalEvent_Sensor_VirtualScan
*/

//*******************Please add other headers below*******************


#include "../Edit/SensorInternalEvent_Sensor_VirtualScan_Vars.h"

/*! \def NODECONFIG
	\brief Forcefully defines the NodeType_NodeClass.
*/
#ifdef NODECONFIG
#undef NODECONFIG
#endif
#define NODECONFIG SensorInternalEvent_Sensor_VirtualScan

/*! bool SensorInternalEvent_Sensor_VirtualScan_generateSourceData_PointCloud2(void * paramsPtr, void * varsPtr, void * outputData, QList<int> & outputPortIndex, QTime & timeStamp)
	\brief [required] Function pointer type for interface function of generating source data.
	\param [in] paramsPtr The node's parameters(\ref Node::paramsptr).
	\param [in] varsPtr The node's variables(\ref Node::varsptr).
	\param [out] outputData The output data.
	\param [out] outputPortIndex The index of output port to send output data.
	\param [out] timeStamp The timestamp. Mainly used in simulator to get the timestamp of one data frame.
	\return 1 for success and 0 for failure.
*/
extern "C" ROBOTSDK_OUTPUT bool DECOFUNC(generateSourceData_PointCloud2)(void * paramsPtr, void * varsPtr, void * outputData, QList<int> & outputPortIndex, QTime & timeStamp);

/*! @}*/ 

#endif
