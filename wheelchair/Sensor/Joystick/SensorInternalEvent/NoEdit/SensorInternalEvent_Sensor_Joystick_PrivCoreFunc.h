//You need not to modify this file.

/*! \defgroup SensorInternalEvent_Sensor_Joystick SensorInternalEvent_Sensor_Joystick
	\ingroup SensorInternalEvent_Library Sensor_Joystick_NodeClass
	\brief SensorInternalEvent_Sensor_Joystick defines the Sensor_Joystick in SensorInternalEvent.
*/

#ifndef SENSORINTERNALEVENT_SENSOR_JOYSTICK_PRIVCOREFUNC_H
#define SENSORINTERNALEVENT_SENSOR_JOYSTICK_PRIVCOREFUNC_H

#include<RobotSDK_Global.h>

/*! \defgroup SensorInternalEvent_Sensor_Joystick_PrivCoreFunc SensorInternalEvent_Sensor_Joystick_PrivCoreFunc
	\ingroup SensorInternalEvent_Sensor_Joystick
	\brief SensorInternalEvent_Sensor_Joystick_PrivCoreFunc defines the PrivCoreFunc in SensorInternalEvent_Sensor_Joystick.
*/

/*! \addtogroup SensorInternalEvent_Sensor_Joystick_PrivCoreFunc
	@{
*/

/*! \file SensorInternalEvent_Sensor_Joystick_PrivCoreFunc.h
	 Defines the PrivCoreFunc of SensorInternalEvent_Sensor_Joystick
*/

//*******************Please add other headers below*******************


#include "../Edit/SensorInternalEvent_Sensor_Joystick_Vars.h"

/*! \def NODECONFIG
	\brief Forcefully defines the NodeType_NodeClass.
*/
#ifdef NODECONFIG
#undef NODECONFIG
#endif
#define NODECONFIG SensorInternalEvent_Sensor_Joystick

/*! void SensorInternalEvent_Sensor_Joystick_getPortsSize(QList<int> & inputPortsSize, int & outputPortsNumber)
	\brief [required] Function pointer type for interface function of getting node's port(s)' size.
	\param [out] inputPortsSize The size of each input port's data buffer.
	\param [out] outputPortsNumber The number of output ports.
*/
extern "C" ROBOTSDK_OUTPUT void DECOFUNC(getPortsSize)(QList<int> & inputPortsSize, int & outputPortsNumber);

/*! void SensorInternalEvent_Sensor_Joystick_initializeParams(boost::shared_ptr<void> & paramsPtr)
	\brief [required] Function pointer type for interface function of initializing node's parameters.
	\param [out] paramsPtr The parameters embelished by boost::shared_pointer<void>.
	\details To initialize parameters:
	- paramsPtr=boost::shared_ptr<void> (new ParametersType);
*/
extern "C" ROBOTSDK_OUTPUT void DECOFUNC(initializeParams)(boost::shared_ptr<void> & paramsPtr);

/*! void SensorInternalEvent_Sensor_Joystick_initializeVars(boost::shared_ptr<void> & varsPtr)
	\brief [required] Function pointer type for interface function of initializing node's variables.
	\param [out] varsPtr The variables embelished by boost::shared_pointer<void>.
	\details To initialize variables:
	- varsPtr=boost::shared_ptr<void> (new VariablesType);
*/
extern "C" ROBOTSDK_OUTPUT void DECOFUNC(initializeVars)(boost::shared_ptr<void> & varsPtr);

/*! @}*/ 

#endif