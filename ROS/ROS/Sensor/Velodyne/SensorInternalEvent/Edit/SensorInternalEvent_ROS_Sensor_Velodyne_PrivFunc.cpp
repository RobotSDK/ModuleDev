//You need to program this file.

#include "../NoEdit/SensorInternalEvent_ROS_Sensor_Velodyne_PrivFunc.h"

//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	SensorInternalEvent_ROS_Sensor_Velodyne_Params * params=(SensorInternalEvent_ROS_Sensor_Velodyne_Params *)paramsPtr;
	SensorInternalEvent_ROS_Sensor_Velodyne_Vars * vars=(SensorInternalEvent_ROS_Sensor_Velodyne_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: open node.
	Procedure:
	1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
	2: initialize variables (vars).
	3: If everything is OK, return 1 for successful opening and vice versa.
	*/
    GetParamValue(xmlloader,params,velodynecalibfile);
    GetParamValue(xmlloader,params,velodynecalibmatstr);

    cv::FileStorage fs(params->velodynecalibfile.toStdString(),cv::FileStorage::READ);
    fs[params->velodynecalibmatstr.toUtf8().data()]>>params->velodynecalibmat;
    fs.release();

    GetParamValue(xmlloader,vars,topic);

    vars->velodynesub=new ROSSub<sensor_msgs::PointCloud2ConstPtr>(vars->topic,1000,10);
    if(vars->velodynesub==NULL)
    {
        return 0;
    }
    vars->velodynesub->startReceiveSlot();

    return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	SensorInternalEvent_ROS_Sensor_Velodyne_Params * params=(SensorInternalEvent_ROS_Sensor_Velodyne_Params *)paramsPtr;
	SensorInternalEvent_ROS_Sensor_Velodyne_Vars * vars=(SensorInternalEvent_ROS_Sensor_Velodyne_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: close node.
	Procedure:
	1: handle/close variables (vars).
	2: If everything is OK, return 1 for successful closing and vice versa.
	*/
    if(vars!=NULL)
    {
        vars->velodynesub->stopReceiveSlot();
        delete vars->velodynesub;
        vars->velodynesub=NULL;
    }
	return 1;
}

void DECOFUNC(getInternalTrigger)(void * paramsPtr, void * varsPtr, QObject * & internalTrigger, QString & internalTriggerSignal)
{
	SensorInternalEvent_ROS_Sensor_Velodyne_Params * params=(SensorInternalEvent_ROS_Sensor_Velodyne_Params *)paramsPtr;
	SensorInternalEvent_ROS_Sensor_Velodyne_Vars * vars=(SensorInternalEvent_ROS_Sensor_Velodyne_Vars *)varsPtr;
    internalTrigger=vars->velodynesub;
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
	SensorInternalEvent_ROS_Sensor_Velodyne_Params * params=(SensorInternalEvent_ROS_Sensor_Velodyne_Params *)paramsPtr;
	SensorInternalEvent_ROS_Sensor_Velodyne_Vars * vars=(SensorInternalEvent_ROS_Sensor_Velodyne_Vars *)varsPtr;
	outputDataPtr=boost::shared_ptr<void>(new SensorInternalEvent_ROS_Sensor_Velodyne_Data());
	/*======Occasionally Program below/above======*/
	/*
	Function: initial output data.
	You need to program here when you need to manually initialize output data.
	*/
	
}

bool DECOFUNC(generateSourceData)(void * paramsPtr, void * varsPtr, void * outputData, QList<int> & outputPortIndex, QTime & timeStamp)
{
	SensorInternalEvent_ROS_Sensor_Velodyne_Params * params=(SensorInternalEvent_ROS_Sensor_Velodyne_Params *)paramsPtr;
	SensorInternalEvent_ROS_Sensor_Velodyne_Vars * vars=(SensorInternalEvent_ROS_Sensor_Velodyne_Vars *)varsPtr;
	SensorInternalEvent_ROS_Sensor_Velodyne_Data * outputdata=(SensorInternalEvent_ROS_Sensor_Velodyne_Data *)outputData;
	outputPortIndex=QList<int>();
	timeStamp=QTime();
	/*======Please Program below======*/
	/*
	Step 1: fill outputdata.
	Step 2 [optional]: determine the outputPortIndex. (if not, outputdata will be sent by all ports)
	E.g. outputPortIndex=QList<int>()<<(outportindex1)<<(outportindex2)...
	Step 3: set the timeStamp for Simulator.
	*/
    if(vars->velodynesub==NULL)
    {
        return 0;
    }
    sensor_msgs::PointCloud2ConstPtr msg=vars->velodynesub->getMessage();
    if(msg==NULL)
    {
        return 0;
    }
    outputdata->timestamp=QTime::fromMSecsSinceStartOfDay(msg->header.stamp.sec*1000+msg->header.stamp.nsec/1000);
    int pointnum=msg->height*msg->width;
    outputdata->cloud->resize(pointnum);
    char * data=(char *)(msg->data.data());
    int i;
    for(i=0;i<pointnum;i++)
    {
        float * base=(float *)(data+i*msg->point_step);
        outputdata->cloud->points[i].x=base[0];
        outputdata->cloud->points[i].y=base[1];
        outputdata->cloud->points[i].z=base[2];
        outputdata->cloud->points[i].intensity=base[4];
    }
    return 1;
}

