//You need to program this file.

#include "../NoEdit/ProcessorMulti_Algorithm_Integration_SegmentationCamera_PrivFunc.h"

//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	ProcessorMulti_Algorithm_Integration_SegmentationCamera_Params * params=(ProcessorMulti_Algorithm_Integration_SegmentationCamera_Params *)paramsPtr;
	ProcessorMulti_Algorithm_Integration_SegmentationCamera_Vars * vars=(ProcessorMulti_Algorithm_Integration_SegmentationCamera_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: open node.
	Procedure:
	1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
	2: initialize variables (vars).
	3: If everything is OK, return 1 for successful opening and vice versa.
	*/
	
	return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	ProcessorMulti_Algorithm_Integration_SegmentationCamera_Params * params=(ProcessorMulti_Algorithm_Integration_SegmentationCamera_Params *)paramsPtr;
	ProcessorMulti_Algorithm_Integration_SegmentationCamera_Vars * vars=(ProcessorMulti_Algorithm_Integration_SegmentationCamera_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: close node.
	Procedure:
	1: handle/close variables (vars).
	2: If everything is OK, return 1 for successful closing and vice versa.
	*/
	
	return 1;
}

void DECOFUNC(getInternalTrigger)(void * paramsPtr, void * varsPtr, QObject * & internalTrigger, QString & internalTriggerSignal)
{
	ProcessorMulti_Algorithm_Integration_SegmentationCamera_Params * params=(ProcessorMulti_Algorithm_Integration_SegmentationCamera_Params *)paramsPtr;
	ProcessorMulti_Algorithm_Integration_SegmentationCamera_Vars * vars=(ProcessorMulti_Algorithm_Integration_SegmentationCamera_Vars *)varsPtr;
	internalTrigger=NULL;
	internalTriggerSignal=QString();
	/*======Occasionally Program above======*/
	/*
	Function: get internal trigger [defined in vars] for node.
	You need to program here when you need internal trigger (internalTrigger + internalTriggerSignal) for node.
	E.g.
	internalTrigger=&(vars->trigger);
	internalTriggerSignal=QString(SIGNAL(triggerSignal()));
	*/
}

void DECOFUNC(initializeOutputData)(void * paramsPtr, void * varsPtr, boost::shared_ptr<void> & outputDataPtr)
{
	ProcessorMulti_Algorithm_Integration_SegmentationCamera_Params * params=(ProcessorMulti_Algorithm_Integration_SegmentationCamera_Params *)paramsPtr;
	ProcessorMulti_Algorithm_Integration_SegmentationCamera_Vars * vars=(ProcessorMulti_Algorithm_Integration_SegmentationCamera_Vars *)varsPtr;
	outputDataPtr=boost::shared_ptr<void>(new ProcessorMulti_Algorithm_Integration_SegmentationCamera_Data());
	/*======Occasionally Program below/above======*/
	/*
	Function: initial output data.
	You need to program here when you need to manually initialize output data.
	*/
	
}

void DECOFUNC(getMultiInputDataSize)(void * paramsPtr, void * varsPtr, QList<int> & inputDataSize)
{
	ProcessorMulti_Algorithm_Integration_SegmentationCamera_Params * params=(ProcessorMulti_Algorithm_Integration_SegmentationCamera_Params *)paramsPtr;
	ProcessorMulti_Algorithm_Integration_SegmentationCamera_Vars * vars=(ProcessorMulti_Algorithm_Integration_SegmentationCamera_Vars *)varsPtr;
	inputDataSize=QList<int>();
	/*======Please Program above======*/
	/*
	Function: get input data size to be grabbed from buffer.
	Rules:
	inputDataSize=0: grab and remove all data from buffer.
	inputDataSize>0: grab inputDataSize latest data from buffer.
	inputDataSize<0: grab and remove inputDataSize ancient data from buffer.
	E.g.
	inputDataSize=QList<int>()<<0<<1<<-1...;
	*/
}

//Input Port #0: Buffer_Size = 0, Params_Type = SensorInternalEvent_Algorithm_Segmentation_Velodyne_Params, Data_Type = SensorInternalEvent_Algorithm_Segmentation_Velodyne_Data
//Input Port #1: Buffer_Size = 0, Params_Type = SensorInternalEvent_Sensor_Camera_Params, Data_Type = SensorInternalEvent_Sensor_Camera_Data
bool DECOFUNC(processMultiInputData)(void * paramsPtr, void * varsPtr, QVector<QVector<void *> > inputParams, QVector<QVector<void *> > inputData, void * outputData, QList<int> & outputPortIndex)
{
	ProcessorMulti_Algorithm_Integration_SegmentationCamera_Params * params=(ProcessorMulti_Algorithm_Integration_SegmentationCamera_Params *)paramsPtr;
	ProcessorMulti_Algorithm_Integration_SegmentationCamera_Vars * vars=(ProcessorMulti_Algorithm_Integration_SegmentationCamera_Vars *)varsPtr;
	QVector<SensorInternalEvent_Algorithm_Segmentation_Velodyne_Params *> inputparams_0; copyQVector(inputparams_0,inputParams[0]);
	QVector<SensorInternalEvent_Sensor_Camera_Params *> inputparams_1; copyQVector(inputparams_1,inputParams[1]);
	QVector<SensorInternalEvent_Algorithm_Segmentation_Velodyne_Data *> inputdata_0; copyQVector(inputdata_0,inputData[0]);
	QVector<SensorInternalEvent_Sensor_Camera_Data *> inputdata_1; copyQVector(inputdata_1,inputData[1]);
	ProcessorMulti_Algorithm_Integration_SegmentationCamera_Data * outputdata=(ProcessorMulti_Algorithm_Integration_SegmentationCamera_Data *)outputData;
	outputPortIndex=QList<int>();
	if(inputdata_0.size()==0){return 0;}
	if(inputdata_1.size()==0){return 0;}
	/*======Please Program below======*/
	/*
	Step 1: process inputdata_index, then store it into outputdata.
	Step 2 [optional]: determine the outputPortIndex. (if not, outputdata will be sent by all ports)
	E.g. outputPortIndex=QList<int>()<<(outportindex1)<<(outportindex2)...
	*/
	
	return 1;
}

