//Generally you need not to program this file.

#include "SensorInternalEvent_Sensor_VirtualScan_PrivCoreFunc.h"

void DECOFUNC(getPortsSize)(QList<int> & inputPortsSize, int & outputPortsNumber)
{
	inputPortsSize=SensorInternalEvent_Sensor_VirtualScan_INPUTPORTSSIZE;
	outputPortsNumber=SensorInternalEvent_Sensor_VirtualScan_OUTPUTPORTSNUMBER;
	/*======No Need to Program======*/
}

void DECOFUNC(initializeParams)(boost::shared_ptr<void> & paramsPtr)
{
	paramsPtr=boost::shared_ptr<void>(new SensorInternalEvent_Sensor_VirtualScan_Params());
	/*======No Need to Program======*/
}

void DECOFUNC(initializeVars)(boost::shared_ptr<void> & varsPtr)
{
	varsPtr=boost::shared_ptr<void>(new SensorInternalEvent_Sensor_VirtualScan_Vars());
	/*======No Need to Program======*/
}

