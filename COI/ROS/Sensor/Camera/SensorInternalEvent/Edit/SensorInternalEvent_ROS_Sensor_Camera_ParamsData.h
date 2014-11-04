//You need to modify this file.

#ifndef SENSORINTERNALEVENT_ROS_SENSOR_CAMERA_PARAMSDATA_H
#define SENSORINTERNALEVENT_ROS_SENSOR_CAMERA_PARAMSDATA_H

#include<RobotSDK_Global.h>

/*! \defgroup SensorInternalEvent_ROS_Sensor_Camera_ParamsData SensorInternalEvent_ROS_Sensor_Camera_ParamsData
	\ingroup SensorInternalEvent_ROS_Sensor_Camera
	\brief SensorInternalEvent_ROS_Sensor_Camera_ParamsData defines the ParamsData in SensorInternalEvent_ROS_Sensor_Camera.
*/

/*! \addtogroup SensorInternalEvent_ROS_Sensor_Camera_ParamsData
	@{
*/

/*! \file SensorInternalEvent_ROS_Sensor_Camera_ParamsData.h
	 Defines the ParamsData of SensorInternalEvent_ROS_Sensor_Camera
*/

//*******************Please add other headers below*******************


//There is no input data headers.

/*! \def SensorInternalEvent_ROS_Sensor_Camera_INPUTPORTSSIZE
	\brief Defines input port(s) info: number=0
*/
#define SensorInternalEvent_ROS_Sensor_Camera_INPUTPORTSSIZE QList<int>()

//The Params Simulator_Sensor_Camera_Params is defined in the header below
#include<COI/Sensor/Camera/Simulator/Edit/Simulator_Sensor_Camera_ParamsData.h>

//The Output Data Simulator_Sensor_Camera_Data is defined in the header below
#include<COI/Sensor/Camera/Simulator/Edit/Simulator_Sensor_Camera_ParamsData.h>

/*! \def SensorInternalEvent_ROS_Sensor_Camera_OUTPUTPORTSNUMBER
	\brief Defines output port(s) info: number = 1.
*/
#define SensorInternalEvent_ROS_Sensor_Camera_OUTPUTPORTSNUMBER 1

/*! @}*/ 

#endif