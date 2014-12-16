//You need to program this file.

#include "../NoEdit/SensorInternalEvent_Sensor_Velodyne_PrivFunc.h"

//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	SensorInternalEvent_Sensor_Velodyne_Params * params=(SensorInternalEvent_Sensor_Velodyne_Params *)paramsPtr;
	SensorInternalEvent_Sensor_Velodyne_Vars * vars=(SensorInternalEvent_Sensor_Velodyne_Vars *)varsPtr;
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

    if(vars->velodynesub==NULL)
    {
        return 0;
    }
    vars->velodynesub->resetTopic(vars->topic,vars->queuesize);
    vars->velodynesub->startReceiveSlot();
	return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	SensorInternalEvent_Sensor_Velodyne_Params * params=(SensorInternalEvent_Sensor_Velodyne_Params *)paramsPtr;
	SensorInternalEvent_Sensor_Velodyne_Vars * vars=(SensorInternalEvent_Sensor_Velodyne_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: close node.
	Procedure:
	1: handle/close variables (vars).
	2: If everything is OK, return 1 for successful closing and vice versa.
	*/
    vars->velodynesub->stopReceiveSlot();
	return 1;
}

void DECOFUNC(getInternalTrigger)(void * paramsPtr, void * varsPtr, QObject * & internalTrigger, QString & internalTriggerSignal)
{
	SensorInternalEvent_Sensor_Velodyne_Params * params=(SensorInternalEvent_Sensor_Velodyne_Params *)paramsPtr;
	SensorInternalEvent_Sensor_Velodyne_Vars * vars=(SensorInternalEvent_Sensor_Velodyne_Vars *)varsPtr;
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
	SensorInternalEvent_Sensor_Velodyne_Params * params=(SensorInternalEvent_Sensor_Velodyne_Params *)paramsPtr;
	SensorInternalEvent_Sensor_Velodyne_Vars * vars=(SensorInternalEvent_Sensor_Velodyne_Vars *)varsPtr;
	outputDataPtr=boost::shared_ptr<void>(new SensorInternalEvent_Sensor_Velodyne_Data());
	/*======Occasionally Program below/above======*/
	/*
	Function: initial output data.
	You need to program here when you need to manually initialize output data.
	*/
	
}

bool DECOFUNC(generateSourceData)(void * paramsPtr, void * varsPtr, void * outputData, QList<int> & outputPortIndex, QTime & timeStamp)
{
	SensorInternalEvent_Sensor_Velodyne_Params * params=(SensorInternalEvent_Sensor_Velodyne_Params *)paramsPtr;
	SensorInternalEvent_Sensor_Velodyne_Vars * vars=(SensorInternalEvent_Sensor_Velodyne_Vars *)varsPtr;
	SensorInternalEvent_Sensor_Velodyne_Data * outputdata=(SensorInternalEvent_Sensor_Velodyne_Data *)outputData;
	outputPortIndex=QList<int>();
	timeStamp=QTime();
	/*======Please Program below======*/
	/*
	Step 1: fill outputdata.
	Step 2 [optional]: determine the outputPortIndex. (if not, outputdata will be sent by all ports)
	E.g. outputPortIndex=QList<int>()<<(outportindex1)<<(outportindex2)...
	Step 3: set the timeStamp for Simulator.
    */
    sensor_msgs::PointCloud2ConstPtr msg=vars->velodynesub->getMessage();
    if(msg==NULL)
    {
        return 0;
    }
    int msec=(msg->header.stamp.sec)%(24*60*60)*1000+(msg->header.stamp.nsec)/1000000;
    outputdata->timestamp=QTime::fromMSecsSinceStartOfDay(msec);

    {
        int width=0;
        int height=64;
        int pointnum=msg->height*msg->width;
        int i;
        char * data=(char *)(msg->data.data());
        bool startflag=1,larger32flag,start32flag;
        for(i=0;i<pointnum;i++)
        {
            float * tmpdata=(float *)(data+i*(msg->point_step));
            int ringnum=*((u_int16_t *)(tmpdata+5));
            if(startflag)
            {
                if(ringnum<32)
                {
                    larger32flag=0;
                    start32flag=0;
                }
                else
                {
                    larger32flag=1;
                    start32flag=1;
                }
                width++;
                startflag=0;
            }
            else
            {
                if(ringnum<32)
                {
                    if(larger32flag)
                    {
                        if(!start32flag)
                        {
                            width++;
                        }
                        larger32flag=0;
                    }
                }
                else
                {
                    if(!larger32flag)
                    {
                        if(start32flag)
                        {
                            width++;
                        }
                        larger32flag=1;
                    }
                }
            }
        }

        outputdata->velodynepoints->header=msg->header;
        outputdata->velodynepoints->width=width;
        outputdata->velodynepoints->height=height;
        outputdata->velodynepoints->fields=msg->fields;
        outputdata->velodynepoints->is_bigendian=msg->is_bigendian;
        outputdata->velodynepoints->point_step=msg->point_step;
        outputdata->velodynepoints->row_step=msg->point_step;
        outputdata->velodynepoints->data.resize(width*height*(outputdata->velodynepoints->point_step));
        outputdata->velodynepoints->is_dense=msg->is_dense;

        float PI=fabs(atan2(0.0,-1.0));
        float res=2*PI/width;

        char * destdata=(char *)(outputdata->velodynepoints->data.data());
        for(i=0;i<pointnum;i++)
        {
            float * tmpdata=(float *)(data+i*(msg->point_step));
            int colid=int((atan2(tmpdata[1],tmpdata[0])+PI)/res+0.5);
            int ringnum=*((u_int16_t *)(tmpdata+5));

            int id=(63-ringnum)*width+colid;
            char * tmpdestdata=(char *)(destdata+id*(outputdata->velodynepoints->point_step));
            memcpy(tmpdestdata,(char *)tmpdata,msg->point_step);
        }
    }

    outputdata->pclpoints->header.frame_id=outputdata->velodynepoints->header.frame_id;
    outputdata->pclpoints->header.seq=outputdata->velodynepoints->header.seq;
    outputdata->pclpoints->header.stamp=msec;

    outputdata->pclpoints->height=outputdata->velodynepoints->height;
    outputdata->pclpoints->width=outputdata->velodynepoints->width;

    int pointnum=outputdata->pclpoints->height*outputdata->pclpoints->width;
    outputdata->pclpoints->resize(pointnum);
    char * data=(char *)(outputdata->velodynepoints->data.data());
    int i,j;
    for(i=0;i<outputdata->velodynepoints->height;i++)
    {
        for(j=0;j<outputdata->velodynepoints->width;j++)
        {
            int id=i*outputdata->velodynepoints->width+j;
            float * tmpdata=(float *)(data+id*(outputdata->velodynepoints->point_step));
            outputdata->pclpoints->points[id].x=tmpdata[0];
            outputdata->pclpoints->points[id].y=tmpdata[1];
            outputdata->pclpoints->points[id].z=tmpdata[2];
            outputdata->pclpoints->points[id].data[3]=1.0;
            outputdata->pclpoints->points[id].intensity=tmpdata[4]/255.0f;
            outputdata->pclpoints->points[id].data_c[1]=tmpdata[4]/255.0f;
            outputdata->pclpoints->points[id].data_c[2]=tmpdata[4]/255.0f;
            outputdata->pclpoints->points[id].data_c[3]=tmpdata[4]/255.0f;
        }
    }
	return 1;
}
