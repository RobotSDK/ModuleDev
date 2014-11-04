//You need to program this file.

#include "../NoEdit/ProcessorMulti_Algorithm_Integration_VelodyneCameraSLAM_PrivFunc.h"

//*******************Please add static libraries below*******************

#pragma comment(lib,"Kernel.lib")

#ifdef _DEBUG

#else

#endif

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	ProcessorMulti_Algorithm_Integration_VelodyneCameraSLAM_Params * params=(ProcessorMulti_Algorithm_Integration_VelodyneCameraSLAM_Params *)paramsPtr;
	ProcessorMulti_Algorithm_Integration_VelodyneCameraSLAM_Vars * vars=(ProcessorMulti_Algorithm_Integration_VelodyneCameraSLAM_Vars *)varsPtr;
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
	ProcessorMulti_Algorithm_Integration_VelodyneCameraSLAM_Params * params=(ProcessorMulti_Algorithm_Integration_VelodyneCameraSLAM_Params *)paramsPtr;
	ProcessorMulti_Algorithm_Integration_VelodyneCameraSLAM_Vars * vars=(ProcessorMulti_Algorithm_Integration_VelodyneCameraSLAM_Vars *)varsPtr;
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
	ProcessorMulti_Algorithm_Integration_VelodyneCameraSLAM_Params * params=(ProcessorMulti_Algorithm_Integration_VelodyneCameraSLAM_Params *)paramsPtr;
	ProcessorMulti_Algorithm_Integration_VelodyneCameraSLAM_Vars * vars=(ProcessorMulti_Algorithm_Integration_VelodyneCameraSLAM_Vars *)varsPtr;
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
	ProcessorMulti_Algorithm_Integration_VelodyneCameraSLAM_Params * params=(ProcessorMulti_Algorithm_Integration_VelodyneCameraSLAM_Params *)paramsPtr;
	ProcessorMulti_Algorithm_Integration_VelodyneCameraSLAM_Vars * vars=(ProcessorMulti_Algorithm_Integration_VelodyneCameraSLAM_Vars *)varsPtr;
	outputDataPtr=boost::shared_ptr<void>(new ProcessorMulti_Algorithm_Integration_VelodyneCameraSLAM_Data());
	/*======Occasionally Program below/above======*/
	/*
	Function: initial output data.
	You need to program here when you need to manually initialize output data.
	*/
	
}

void DECOFUNC(getMultiInputDataSize)(void * paramsPtr, void * varsPtr, QList<int> & inputDataSize)
{
	ProcessorMulti_Algorithm_Integration_VelodyneCameraSLAM_Params * params=(ProcessorMulti_Algorithm_Integration_VelodyneCameraSLAM_Params *)paramsPtr;
	ProcessorMulti_Algorithm_Integration_VelodyneCameraSLAM_Vars * vars=(ProcessorMulti_Algorithm_Integration_VelodyneCameraSLAM_Vars *)varsPtr;
	inputDataSize=QList<int>()<<-1<<-1;
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

//Input Port #0: Buffer_Size = 0, Params_Type = ProcessorMulti_Algorithm_Integration_VelodyneCamera_Params, Data_Type = ProcessorMulti_Algorithm_Integration_VelodyneCamera_Data
//Input Port #1: Buffer_Size = 0, Params_Type = Simulator_Algorithm_SLAM_Velodyne_ScanMatching_Params, Data_Type = Simulator_Algorithm_SLAM_Velodyne_ScanMatching_Data
bool DECOFUNC(processMultiInputData)(void * paramsPtr, void * varsPtr, QVector<QVector<void *> > inputParams, QVector<QVector<void *> > inputData, void * outputData, QList<int> & outputPortIndex)
{
	ProcessorMulti_Algorithm_Integration_VelodyneCameraSLAM_Params * params=(ProcessorMulti_Algorithm_Integration_VelodyneCameraSLAM_Params *)paramsPtr;
	ProcessorMulti_Algorithm_Integration_VelodyneCameraSLAM_Vars * vars=(ProcessorMulti_Algorithm_Integration_VelodyneCameraSLAM_Vars *)varsPtr;
	QVector<ProcessorMulti_Algorithm_Integration_VelodyneCamera_Params *> inputparams_0; copyQVector(inputparams_0,inputParams[0]);
	QVector<Simulator_Algorithm_SLAM_Velodyne_ScanMatching_Params *> inputparams_1; copyQVector(inputparams_1,inputParams[1]);
	QVector<ProcessorMulti_Algorithm_Integration_VelodyneCamera_Data *> inputdata_0; copyQVector(inputdata_0,inputData[0]);
	QVector<Simulator_Algorithm_SLAM_Velodyne_ScanMatching_Data *> inputdata_1; copyQVector(inputdata_1,inputData[1]);
	ProcessorMulti_Algorithm_Integration_VelodyneCameraSLAM_Data * outputdata=(ProcessorMulti_Algorithm_Integration_VelodyneCameraSLAM_Data *)outputData;
	outputPortIndex=QList<int>();
	if(inputdata_0.size()==0){return 0;}
	if(inputdata_1.size()==0){return 0;}
	/*======Please Program below======*/
	/*
	Step 1: process inputdata_index, then store it into outputdata.
	Step 2 [optional]: determine the outputPortIndex. (if not, outputdata will be sent by all ports)
	E.g. outputPortIndex=QList<int>()<<(outportindex1)<<(outportindex2)...
	*/

	outputdata->velodynetimestamp=inputdata_0[0]->velodynetimestamp;
	outputdata->imagetimestamp=inputdata_0[0]->imagetimestamp;
	outputdata->gpsimutimestamp=inputdata_1[0]->timestamp;	
	outputdata->points=inputdata_0[0]->points;
	outputdata->colors=inputdata_0[0]->colors;	
	outputdata->pose=inputdata_1[0]->pose;

	int pointnum=inputdata_0[0]->points.size();
	cv::Mat veldata=cv::Mat(pointnum,4,CV_32F,outputdata->points.data(),sizeof(VelodynePoint));
	cv::Mat velpoints=cv::Mat::ones(pointnum,4,CV_32F);
	cv::Mat tmppoints=velpoints(cv::Rect(0,0,3,pointnum));
	veldata(cv::Rect(0,0,3,pointnum)).copyTo(tmppoints);

	cv::Mat tpose=cv::Mat(4,4,CV_32F);
	int i,j;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			tpose.at<float>(i,j)=float(inputdata_1[0]->pose(j,i));
		}
	}

	velpoints=velpoints*tpose;
	tmppoints=veldata(cv::Rect(0,0,3,pointnum));
	velpoints(cv::Rect(0,0,3,pointnum)).copyTo(tmppoints);

	return 1;
}

