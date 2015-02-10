//Generally you need not to program this file.

#include "VisualizationMono_Algorithm_Integration_VirtualScanCameraDPM_PrivCoreFunc.h"

void DECOFUNC(getPortsSize)(QList<int> & inputPortsSize, int & outputPortsNumber)
{
	inputPortsSize=VisualizationMono_Algorithm_Integration_VirtualScanCameraDPM_INPUTPORTSSIZE;
	outputPortsNumber=VisualizationMono_Algorithm_Integration_VirtualScanCameraDPM_OUTPUTPORTSNUMBER;
	/*======No Need to Program======*/
}

void DECOFUNC(initializeParams)(boost::shared_ptr<void> & paramsPtr)
{
	paramsPtr=boost::shared_ptr<void>(new VisualizationMono_Algorithm_Integration_VirtualScanCameraDPM_Params());
	/*======No Need to Program======*/
}

void DECOFUNC(initializeVars)(boost::shared_ptr<void> & varsPtr)
{
	varsPtr=boost::shared_ptr<void>(new VisualizationMono_Algorithm_Integration_VirtualScanCameraDPM_Vars());
	/*======No Need to Program======*/
}

