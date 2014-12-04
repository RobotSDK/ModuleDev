//You need to program this file.

#include "../NoEdit/SensorInternalEvent_Algorithm_Detection_DPM_PrivFunc.h"

//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	SensorInternalEvent_Algorithm_Detection_DPM_Params * params=(SensorInternalEvent_Algorithm_Detection_DPM_Params *)paramsPtr;
	SensorInternalEvent_Algorithm_Detection_DPM_Vars * vars=(SensorInternalEvent_Algorithm_Detection_DPM_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: open node.
	Procedure:
	1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
	2: initialize variables (vars).
	3: If everything is OK, return 1 for successful opening and vice versa.
	*/
    GetParamValue(xmlloader,params,calibfilename);
    GetParamValue(xmlloader,vars,topic);
    GetParamValue(xmlloader,vars,queuesize);

    if(!params->calibfilename.isEmpty())
    {
        cv::FileStorage fs;
        fs.open(params->calibfilename.toStdString(),cv::FileStorage::READ);
        if(fs.isOpened())
        {
            fs["CameraExtrinsicMat"]>>params->extrinsicmat;
            fs["CameraMat"]>>params->cameramat;
            fs["DistCoeff"]>>params->distcoeff;
            fs.release();
        }
        else
        {
            params->extrinsicmat=cv::Mat::eye(4,4,CV_64F);
            params->cameramat=cv::Mat::eye(3,3,CV_64F);
            params->distcoeff=cv::Mat::zeros(1,5,CV_64F);
        }
    }
    else
    {
        params->extrinsicmat=cv::Mat::eye(4,4,CV_64F);
        params->cameramat=cv::Mat::eye(3,3,CV_64F);
        params->distcoeff=cv::Mat::zeros(1,5,CV_64F);
    }

    if(vars->dpmsub==NULL)
    {
        return 0;
    }
    vars->dpmsub->resetTopic(vars->topic,vars->queuesize);
    vars->dpmsub->startReceiveSlot();
	return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	SensorInternalEvent_Algorithm_Detection_DPM_Params * params=(SensorInternalEvent_Algorithm_Detection_DPM_Params *)paramsPtr;
	SensorInternalEvent_Algorithm_Detection_DPM_Vars * vars=(SensorInternalEvent_Algorithm_Detection_DPM_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: close node.
	Procedure:
	1: handle/close variables (vars).
	2: If everything is OK, return 1 for successful closing and vice versa.
	*/
    vars->dpmsub->stopReceiveSlot();
	return 1;
}

void DECOFUNC(getInternalTrigger)(void * paramsPtr, void * varsPtr, QObject * & internalTrigger, QString & internalTriggerSignal)
{
	SensorInternalEvent_Algorithm_Detection_DPM_Params * params=(SensorInternalEvent_Algorithm_Detection_DPM_Params *)paramsPtr;
	SensorInternalEvent_Algorithm_Detection_DPM_Vars * vars=(SensorInternalEvent_Algorithm_Detection_DPM_Vars *)varsPtr;
    internalTrigger=vars->dpmsub;
    internalTriggerSignal=QString(SIGNAL(receiveMessageSignal()));
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
	SensorInternalEvent_Algorithm_Detection_DPM_Params * params=(SensorInternalEvent_Algorithm_Detection_DPM_Params *)paramsPtr;
	SensorInternalEvent_Algorithm_Detection_DPM_Vars * vars=(SensorInternalEvent_Algorithm_Detection_DPM_Vars *)varsPtr;
	outputDataPtr=boost::shared_ptr<void>(new SensorInternalEvent_Algorithm_Detection_DPM_Data());
	/*======Occasionally Program below/above======*/
	/*
	Function: initial output data.
	You need to program here when you need to manually initialize output data.
	*/
	
}

bool DECOFUNC(generateSourceData)(void * paramsPtr, void * varsPtr, void * outputData, QList<int> & outputPortIndex, QTime & timeStamp)
{
	SensorInternalEvent_Algorithm_Detection_DPM_Params * params=(SensorInternalEvent_Algorithm_Detection_DPM_Params *)paramsPtr;
	SensorInternalEvent_Algorithm_Detection_DPM_Vars * vars=(SensorInternalEvent_Algorithm_Detection_DPM_Vars *)varsPtr;
	SensorInternalEvent_Algorithm_Detection_DPM_Data * outputdata=(SensorInternalEvent_Algorithm_Detection_DPM_Data *)outputData;
	outputPortIndex=QList<int>();
	timeStamp=QTime();
	/*======Please Program below======*/
	/*
	Step 1: fill outputdata.
	Step 2 [optional]: determine the outputPortIndex. (if not, outputdata will be sent by all ports)
	E.g. outputPortIndex=QList<int>()<<(outportindex1)<<(outportindex2)...
	Step 3: set the timeStamp for Simulator.
	*/
    outputdata->dpmdetection=vars->dpmsub->getMessage();
    if(outputdata->dpmdetection==NULL)
    {
        return 0;
    }
    int msec=(outputdata->dpmdetection->header.stamp.sec)%(24*60*60)*1000+(outputdata->dpmdetection->header.stamp.nsec)/1000000;
    outputdata->timestamp=QTime::fromMSecsSinceStartOfDay(msec);
    outputdata->cvdetection.resize(outputdata->dpmdetection->car_num);
    int i;
    for(i=0;i<outputdata->dpmdetection->car_num;i++)
    {
        outputdata->cvdetection[i].x=outputdata->dpmdetection->corner_point[i*4];
        outputdata->cvdetection[i].y=outputdata->dpmdetection->corner_point[i*4+1];
        outputdata->cvdetection[i].width=outputdata->dpmdetection->corner_point[i*4+2];
        outputdata->cvdetection[i].height=outputdata->dpmdetection->corner_point[i*4+3];
    }
	return 1;
}

