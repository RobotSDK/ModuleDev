//Generally you need not to program this file.

#include "ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_PrivCoreFunc.h"

void DECOFUNC(getPortsSize)(QList<int> & inputPortsSize, int & outputPortsNumber)
{
	inputPortsSize=ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_INPUTPORTSSIZE;
	outputPortsNumber=ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_OUTPUTPORTSNUMBER;
	/*======No Need to Program======*/
}

void DECOFUNC(initializeParams)(boost::shared_ptr<void> & paramsPtr)
{
	paramsPtr=boost::shared_ptr<void>(new ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_Params());
	/*======No Need to Program======*/
}

void DECOFUNC(initializeVars)(boost::shared_ptr<void> & varsPtr)
{
	varsPtr=boost::shared_ptr<void>(new ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_Vars());
	/*======No Need to Program======*/
}

