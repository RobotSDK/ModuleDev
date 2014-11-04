//Generally you need not to program this file.

#include "ProcessorMono_Algorithm_Detection_Camera_DPM_PrivCoreFunc.h"

void DECOFUNC(getPortsSize)(QList<int> & inputPortsSize, int & outputPortsNumber)
{
	inputPortsSize=ProcessorMono_Algorithm_Detection_Camera_DPM_INPUTPORTSSIZE;
	outputPortsNumber=ProcessorMono_Algorithm_Detection_Camera_DPM_OUTPUTPORTSNUMBER;
	/*======No Need to Program======*/
}

void DECOFUNC(initializeParams)(boost::shared_ptr<void> & paramsPtr)
{
	paramsPtr=boost::shared_ptr<void>(new ProcessorMono_Algorithm_Detection_Camera_DPM_Params());
	/*======No Need to Program======*/
}

void DECOFUNC(initializeVars)(boost::shared_ptr<void> & varsPtr)
{
	varsPtr=boost::shared_ptr<void>(new ProcessorMono_Algorithm_Detection_Camera_DPM_Vars());
	/*======No Need to Program======*/
}

