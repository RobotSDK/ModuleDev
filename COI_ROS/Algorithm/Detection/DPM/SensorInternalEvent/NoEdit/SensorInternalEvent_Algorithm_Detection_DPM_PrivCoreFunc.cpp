//Generally you need not to program this file.

#include "SensorInternalEvent_Algorithm_Detection_DPM_PrivCoreFunc.h"

void DECOFUNC(getPortsSize)(QList<int> & inputPortsSize, int & outputPortsNumber)
{
	inputPortsSize=SensorInternalEvent_Algorithm_Detection_DPM_INPUTPORTSSIZE;
	outputPortsNumber=SensorInternalEvent_Algorithm_Detection_DPM_OUTPUTPORTSNUMBER;
	/*======No Need to Program======*/
}

void DECOFUNC(initializeParams)(boost::shared_ptr<void> & paramsPtr)
{
	paramsPtr=boost::shared_ptr<void>(new SensorInternalEvent_Algorithm_Detection_DPM_Params());
	/*======No Need to Program======*/
}

void DECOFUNC(initializeVars)(boost::shared_ptr<void> & varsPtr)
{
	varsPtr=boost::shared_ptr<void>(new SensorInternalEvent_Algorithm_Detection_DPM_Vars());
	/*======No Need to Program======*/
}

