//Generally you need not to program this file.

#include "VisualizationMulti_Visualization_Integration_GroundObjectsDBM_PrivCoreFunc.h"

void DECOFUNC(getPortsSize)(QList<int> & inputPortsSize, int & outputPortsNumber)
{
	inputPortsSize=VisualizationMulti_Visualization_Integration_GroundObjectsDBM_INPUTPORTSSIZE;
	outputPortsNumber=VisualizationMulti_Visualization_Integration_GroundObjectsDBM_OUTPUTPORTSNUMBER;
	/*======No Need to Program======*/
}

void DECOFUNC(initializeParams)(boost::shared_ptr<void> & paramsPtr)
{
	paramsPtr=boost::shared_ptr<void>(new VisualizationMulti_Visualization_Integration_GroundObjectsDBM_Params());
	/*======No Need to Program======*/
}

void DECOFUNC(initializeVars)(boost::shared_ptr<void> & varsPtr)
{
	varsPtr=boost::shared_ptr<void>(new VisualizationMulti_Visualization_Integration_GroundObjectsDBM_Vars());
	/*======No Need to Program======*/
}

