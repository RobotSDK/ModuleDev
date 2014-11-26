//Generally you need not to program this file.

#include "SensorInternalEvent_Sensor_Camera_PrivCoreFunc.h"

void DECOFUNC(getPortsSize)(QList<int> & inputPortsSize, int & outputPortsNumber)
{
	inputPortsSize=SensorInternalEvent_Sensor_Camera_INPUTPORTSSIZE;
	outputPortsNumber=SensorInternalEvent_Sensor_Camera_OUTPUTPORTSNUMBER;
	/*======No Need to Program======*/
}

void DECOFUNC(initializeParams)(boost::shared_ptr<void> & paramsPtr)
{
	paramsPtr=boost::shared_ptr<void>(new SensorInternalEvent_Sensor_Camera_Params());
	/*======No Need to Program======*/
}

void DECOFUNC(initializeVars)(boost::shared_ptr<void> & varsPtr)
{
	varsPtr=boost::shared_ptr<void>(new SensorInternalEvent_Sensor_Camera_Vars());
	/*======No Need to Program======*/
}

