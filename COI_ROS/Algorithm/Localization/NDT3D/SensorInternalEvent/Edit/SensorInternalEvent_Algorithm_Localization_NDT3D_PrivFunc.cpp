//You need to program this file.

#include "../NoEdit/SensorInternalEvent_Algorithm_Localization_NDT3D_PrivFunc.h"

//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	SensorInternalEvent_Algorithm_Localization_NDT3D_Params * params=(SensorInternalEvent_Algorithm_Localization_NDT3D_Params *)paramsPtr;
	SensorInternalEvent_Algorithm_Localization_NDT3D_Vars * vars=(SensorInternalEvent_Algorithm_Localization_NDT3D_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: open node.
	Procedure:
	1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
	2: initialize variables (vars).
	3: If everything is OK, return 1 for successful opening and vice versa.
	*/
    GetParamValue(xmlloader,params,calibfilename);
    GetParamValue(xmlloader,vars,destinationframe);
    GetParamValue(xmlloader,vars,originalframe);

    if(!params->calibfilename.isEmpty())
    {
        cv::FileStorage fs;
        fs.open(params->calibfilename.toStdString(),cv::FileStorage::READ);
        if(fs.isOpened())
        {
            fs["VelodyneExtrinsicMat"]>>params->extrinsicmat;
            fs.release();
        }
        else
        {
            params->extrinsicmat=cv::Mat::eye(4,4,CV_64F);
        }
    }
    else
    {
        params->extrinsicmat=cv::Mat::eye(4,4,CV_64F);
    }

    if(vars->ndt3dsub==NULL)
    {
        return 0;
    }
    vars->ndt3dsub->resetDestinationFrame(vars->destinationframe);
    vars->ndt3dsub->resetOriginalFrame(vars->originalframe);
    vars->ndt3dsub->startReceiveSlot();
	return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	SensorInternalEvent_Algorithm_Localization_NDT3D_Params * params=(SensorInternalEvent_Algorithm_Localization_NDT3D_Params *)paramsPtr;
	SensorInternalEvent_Algorithm_Localization_NDT3D_Vars * vars=(SensorInternalEvent_Algorithm_Localization_NDT3D_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: close node.
	Procedure:
	1: handle/close variables (vars).
	2: If everything is OK, return 1 for successful closing and vice versa.
	*/
    vars->ndt3dsub->stopReceiveSlot();
	return 1;
}

void DECOFUNC(getInternalTrigger)(void * paramsPtr, void * varsPtr, QObject * & internalTrigger, QString & internalTriggerSignal)
{
	SensorInternalEvent_Algorithm_Localization_NDT3D_Params * params=(SensorInternalEvent_Algorithm_Localization_NDT3D_Params *)paramsPtr;
	SensorInternalEvent_Algorithm_Localization_NDT3D_Vars * vars=(SensorInternalEvent_Algorithm_Localization_NDT3D_Vars *)varsPtr;
    internalTrigger=vars->ndt3dsub;
    internalTriggerSignal=QString(SIGNAL(receiveTFSignal()));
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
	SensorInternalEvent_Algorithm_Localization_NDT3D_Params * params=(SensorInternalEvent_Algorithm_Localization_NDT3D_Params *)paramsPtr;
	SensorInternalEvent_Algorithm_Localization_NDT3D_Vars * vars=(SensorInternalEvent_Algorithm_Localization_NDT3D_Vars *)varsPtr;
	outputDataPtr=boost::shared_ptr<void>(new SensorInternalEvent_Algorithm_Localization_NDT3D_Data());
	/*======Occasionally Program below/above======*/
	/*
	Function: initial output data.
	You need to program here when you need to manually initialize output data.
	*/
	
}

bool DECOFUNC(generateSourceData)(void * paramsPtr, void * varsPtr, void * outputData, QList<int> & outputPortIndex, QTime & timeStamp)
{
	SensorInternalEvent_Algorithm_Localization_NDT3D_Params * params=(SensorInternalEvent_Algorithm_Localization_NDT3D_Params *)paramsPtr;
	SensorInternalEvent_Algorithm_Localization_NDT3D_Vars * vars=(SensorInternalEvent_Algorithm_Localization_NDT3D_Vars *)varsPtr;
	SensorInternalEvent_Algorithm_Localization_NDT3D_Data * outputdata=(SensorInternalEvent_Algorithm_Localization_NDT3D_Data *)outputData;
	outputPortIndex=QList<int>();
	timeStamp=QTime();
	/*======Please Program below======*/
	/*
	Step 1: fill outputdata.
	Step 2 [optional]: determine the outputPortIndex. (if not, outputdata will be sent by all ports)
	E.g. outputPortIndex=QList<int>()<<(outportindex1)<<(outportindex2)...
	Step 3: set the timeStamp for Simulator.
	*/
    if(!(vars->ndt3dsub->getTF(outputdata->ndt3dtransform)))
    {
        return 0;
    }
    int msec=(outputdata->ndt3dtransform.stamp_.sec)%(24*60*60)*1000+(outputdata->ndt3dtransform.stamp_.nsec)/1000000;
    outputdata->timestamp=QTime::fromMSecsSinceStartOfDay(msec);
    tf::Matrix3x3 rotation(outputdata->ndt3dtransform.getRotation());
    tf::Vector3 translation=outputdata->ndt3dtransform.getOrigin();
    int i;
    for(i=0;i<3;i++)
    {
            outputdata->cvtransform.at<double>(i,0)=(double)(rotation.getRow(i).x());
            outputdata->cvtransform.at<double>(i,1)=(double)(rotation.getRow(i).y());
            outputdata->cvtransform.at<double>(i,2)=(double)(rotation.getRow(i).z());
    }
    outputdata->cvtransform.at<double>(0,3)=(double)(translation.x());
    outputdata->cvtransform.at<double>(1,3)=(double)(translation.y());
    outputdata->cvtransform.at<double>(2,3)=(double)(translation.z());
	return 1;
}

