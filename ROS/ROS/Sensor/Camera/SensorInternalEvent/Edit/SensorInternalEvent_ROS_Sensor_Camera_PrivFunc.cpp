//You need to program this file.

#include "../NoEdit/SensorInternalEvent_ROS_Sensor_Camera_PrivFunc.h"

//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	SensorInternalEvent_ROS_Sensor_Camera_Params * params=(SensorInternalEvent_ROS_Sensor_Camera_Params *)paramsPtr;
	SensorInternalEvent_ROS_Sensor_Camera_Vars * vars=(SensorInternalEvent_ROS_Sensor_Camera_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: open node.
	Procedure:
	1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
	2: initialize variables (vars).
	3: If everything is OK, return 1 for successful opening and vice versa.
	*/
    GetParamValue(xmlloader,params,cameracalibfile);
    GetParamValue(xmlloader,params,cameraid);
    GetParamValue(xmlloader,params,cameramatstr);
    GetParamValue(xmlloader,params,distcoefstr);
    GetParamValue(xmlloader,params,cameracalibmatstr);

    cv::FileStorage fs(params->cameracalibfile.toStdString(),cv::FileStorage::READ);
    fs[QString("%1_%2").arg(params->cameramatstr).arg(params->cameraid).toUtf8().data()]>>params->cameramat;
    fs[QString("%1_%2").arg(params->distcoefstr).arg(params->cameraid).toUtf8().data()]>>params->distcoef;
    fs[QString("%1_%2").arg(params->cameracalibmatstr).arg(params->cameraid).toUtf8().data()]>>params->cameracalibmat;
    fs.release();

    GetParamValue(xmlloader,vars,topic);

    if(vars->camerasub==NULL)
    {
        return 0;
    }
    QString topic=QString("%1_%2").arg(vars->topic).arg(params->cameraid);
    if(topic!=vars->camerasub->getTopic())
    {
        vars->camerasub->resetTopic(topic,1000);
    }
    vars->camerasub->startReceiveSlot();
	return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	SensorInternalEvent_ROS_Sensor_Camera_Params * params=(SensorInternalEvent_ROS_Sensor_Camera_Params *)paramsPtr;
	SensorInternalEvent_ROS_Sensor_Camera_Vars * vars=(SensorInternalEvent_ROS_Sensor_Camera_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: close node.
	Procedure:
	1: handle/close variables (vars).
	2: If everything is OK, return 1 for successful closing and vice versa.
	*/
    if(vars->camerasub!=NULL)
    {
        vars->camerasub->stopReceiveSlot();
    }
	return 1;
}

void DECOFUNC(getInternalTrigger)(void * paramsPtr, void * varsPtr, QObject * & internalTrigger, QString & internalTriggerSignal)
{
	SensorInternalEvent_ROS_Sensor_Camera_Params * params=(SensorInternalEvent_ROS_Sensor_Camera_Params *)paramsPtr;
	SensorInternalEvent_ROS_Sensor_Camera_Vars * vars=(SensorInternalEvent_ROS_Sensor_Camera_Vars *)varsPtr;
    internalTrigger=vars->camerasub;
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
	SensorInternalEvent_ROS_Sensor_Camera_Params * params=(SensorInternalEvent_ROS_Sensor_Camera_Params *)paramsPtr;
	SensorInternalEvent_ROS_Sensor_Camera_Vars * vars=(SensorInternalEvent_ROS_Sensor_Camera_Vars *)varsPtr;
	outputDataPtr=boost::shared_ptr<void>(new SensorInternalEvent_ROS_Sensor_Camera_Data());
	/*======Occasionally Program below/above======*/
	/*
	Function: initial output data.
	You need to program here when you need to manually initialize output data.
	*/
	
}

bool DECOFUNC(generateSourceData)(void * paramsPtr, void * varsPtr, void * outputData, QList<int> & outputPortIndex, QTime & timeStamp)
{
	SensorInternalEvent_ROS_Sensor_Camera_Params * params=(SensorInternalEvent_ROS_Sensor_Camera_Params *)paramsPtr;
	SensorInternalEvent_ROS_Sensor_Camera_Vars * vars=(SensorInternalEvent_ROS_Sensor_Camera_Vars *)varsPtr;
	SensorInternalEvent_ROS_Sensor_Camera_Data * outputdata=(SensorInternalEvent_ROS_Sensor_Camera_Data *)outputData;
	outputPortIndex=QList<int>();
	timeStamp=QTime();
	/*======Please Program below======*/
	/*
	Step 1: fill outputdata.
	Step 2 [optional]: determine the outputPortIndex. (if not, outputdata will be sent by all ports)
	E.g. outputPortIndex=QList<int>()<<(outportindex1)<<(outportindex2)...
	Step 3: set the timeStamp for Simulator.
	*/
    if(vars->camerasub==NULL)
    {
        return 0;
    }
    sensor_msgs::ImageConstPtr msg=vars->camerasub->getMessage();
    if(msg==NULL)
    {
        return 0;
    }

    outputdata->timestamp=QTime::fromMSecsSinceStartOfDay(msg->header.stamp.sec*1000+msg->header.stamp.nsec/1000);
    void * data=(void *)(msg->data.data());
    if(QString::fromStdString(msg->encoding)=="rgb8")
    {
        outputdata->image=cv::Mat(msg->height,msg->width,CV_8UC3,data);
        cv::cvtColor(outputdata->image,outputdata->image,CV_BGR2RGB);
        return 1;
    }
    else if(QString::fromStdString(msg->encoding)=="mono8")
    {
        outputdata->image=cv::Mat(msg->height,msg->width,CV_8UC1,data);
        return 1;
    }
    else
    {
        return 0;
    }
}

