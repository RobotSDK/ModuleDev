//Generally you need not to program this file.

#include "VisualizationMono_Sensor_Velodyne_PrivCoreFunc.h"

void DECOFUNC(getPortsSize)(QList<int> & inputPortsSize, int & outputPortsNumber)
{
	inputPortsSize=VisualizationMono_Sensor_Velodyne_INPUTPORTSSIZE;
	outputPortsNumber=VisualizationMono_Sensor_Velodyne_OUTPUTPORTSNUMBER;
	/*======No Need to Program======*/
}

void DECOFUNC(initializeParams)(boost::shared_ptr<void> & paramsPtr)
{
	paramsPtr=boost::shared_ptr<void>(new VisualizationMono_Sensor_Velodyne_Params());
	/*======No Need to Program======*/
}

void DECOFUNC(initializeVars)(boost::shared_ptr<void> & varsPtr)
{
	varsPtr=boost::shared_ptr<void>(new VisualizationMono_Sensor_Velodyne_Vars());
	/*======No Need to Program======*/
}

