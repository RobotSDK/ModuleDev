//Generally you need not to program this file.

#include "VisualizationMono_Algorithm_Detection_Camera_DBM_PrivCoreFunc.h"

void DECOFUNC(getPortsSize)(QList<int> & inputPortsSize, int & outputPortsNumber)
{
	inputPortsSize=VisualizationMono_Algorithm_Detection_Camera_DBM_INPUTPORTSSIZE;
	outputPortsNumber=VisualizationMono_Algorithm_Detection_Camera_DBM_OUTPUTPORTSNUMBER;
	/*======No Need to Program======*/
}

void DECOFUNC(initializeParams)(boost::shared_ptr<void> & paramsPtr)
{
	paramsPtr=boost::shared_ptr<void>(new VisualizationMono_Algorithm_Detection_Camera_DBM_Params());
	/*======No Need to Program======*/
}

void DECOFUNC(initializeVars)(boost::shared_ptr<void> & varsPtr)
{
	varsPtr=boost::shared_ptr<void>(new VisualizationMono_Algorithm_Detection_Camera_DBM_Vars());
	/*======No Need to Program======*/
}

