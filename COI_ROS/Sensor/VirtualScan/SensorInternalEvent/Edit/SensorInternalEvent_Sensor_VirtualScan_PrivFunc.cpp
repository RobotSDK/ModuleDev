//You need to program this file.

#include "../NoEdit/SensorInternalEvent_Sensor_VirtualScan_PrivFunc.h"

//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	SensorInternalEvent_Sensor_VirtualScan_Params * params=(SensorInternalEvent_Sensor_VirtualScan_Params *)paramsPtr;
	SensorInternalEvent_Sensor_VirtualScan_Vars * vars=(SensorInternalEvent_Sensor_VirtualScan_Vars *)varsPtr;
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
    GetParamValue(xmlloader,vars,queryinterval);

    GetParamValue(xmlloader,vars,beamnum);
    GetParamValue(xmlloader,vars,heightstep);
    GetParamValue(xmlloader,vars,theta);
    GetParamValue(xmlloader,vars,minfloor);
    GetParamValue(xmlloader,vars,maxceiling);
    GetParamValue(xmlloader,vars,maxfloor);
    GetParamValue(xmlloader,vars,minceiling);
    GetParamValue(xmlloader,vars,rotation);

    GetParamValue(xmlloader,vars,neighbordis);
    GetParamValue(xmlloader,vars,pointsnum);

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
    vars->velodynesub->resetQueryInterval(vars->queryinterval);
    vars->velodynesub->startReceiveSlot();
	return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	SensorInternalEvent_Sensor_VirtualScan_Params * params=(SensorInternalEvent_Sensor_VirtualScan_Params *)paramsPtr;
	SensorInternalEvent_Sensor_VirtualScan_Vars * vars=(SensorInternalEvent_Sensor_VirtualScan_Vars *)varsPtr;
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
	SensorInternalEvent_Sensor_VirtualScan_Params * params=(SensorInternalEvent_Sensor_VirtualScan_Params *)paramsPtr;
	SensorInternalEvent_Sensor_VirtualScan_Vars * vars=(SensorInternalEvent_Sensor_VirtualScan_Vars *)varsPtr;
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
	SensorInternalEvent_Sensor_VirtualScan_Params * params=(SensorInternalEvent_Sensor_VirtualScan_Params *)paramsPtr;
	SensorInternalEvent_Sensor_VirtualScan_Vars * vars=(SensorInternalEvent_Sensor_VirtualScan_Vars *)varsPtr;
	outputDataPtr=boost::shared_ptr<void>(new SensorInternalEvent_Sensor_VirtualScan_Data());
	/*======Occasionally Program below/above======*/
	/*
	Function: initial output data.
	You need to program here when you need to manually initialize output data.
	*/
	
}

bool DECOFUNC(generateSourceData)(void * paramsPtr, void * varsPtr, void * outputData, QList<int> & outputPortIndex, QTime & timeStamp)
{
	SensorInternalEvent_Sensor_VirtualScan_Params * params=(SensorInternalEvent_Sensor_VirtualScan_Params *)paramsPtr;
	SensorInternalEvent_Sensor_VirtualScan_Vars * vars=(SensorInternalEvent_Sensor_VirtualScan_Vars *)varsPtr;
	SensorInternalEvent_Sensor_VirtualScan_Data * outputdata=(SensorInternalEvent_Sensor_VirtualScan_Data *)outputData;
	outputPortIndex=QList<int>();
	timeStamp=QTime();
	/*======Please Program below======*/
	/*
	Step 1: fill outputdata.
	Step 2 [optional]: determine the outputPortIndex. (if not, outputdata will be sent by all ports)
	E.g. outputPortIndex=QList<int>()<<(outportindex1)<<(outportindex2)...
	Step 3: set the timeStamp for Simulator.
	*/
    vars->virtualscan.velodyne=vars->velodynesub->getMessage();
    if(vars->virtualscan.velodyne==NULL)
    {
        return 0;
    }
    int msec=(vars->virtualscan.velodyne->header.stamp.sec)%(24*60*60)*1000+(vars->virtualscan.velodyne->header.stamp.nsec)/1000000;
    outputdata->timestamp=QTime::fromMSecsSinceStartOfDay(msec);

    double PI=3.141592654;
    vars->virtualscan.calculateVirtualScans(vars->beamnum,vars->heightstep,vars->minfloor,vars->maxceiling,vars->rotation*PI/180.0);
    vars->virtualscan.getVirtualScan(vars->theta*PI/180.0,vars->maxfloor,vars->minceiling,outputdata->virtualscan);
    outputdata->heights=vars->virtualscan.minheights;

    int i,n=outputdata->virtualscan.size();
    outputdata->label.fill(-1,n);
    double density=2*PI/n;
    outputdata->labelcount=0;
    for(i=0;i<n;i++)
    {
        if(outputdata->virtualscan[i]>0&&outputdata->label[i]==-1)
        {
            QQueue<int> queue;
            queue.push_back(i);
            outputdata->label[i]=outputdata->labelcount;
            QVector<int> records;
            while(!queue.isEmpty())
            {
                int id=queue.front();
                queue.pop_front();
                records.push_back(id);
                double theta=asin(vars->neighbordis/outputdata->virtualscan[id]);
                int neighbornum=int(theta/density+0.5);
                int j;
                for(j=-neighbornum;j<=neighbornum;j++)
                {
                    if(j==0)
                    {
                        continue;
                    }
                    int nid=id+j;
                    if(nid<0)
                    {
                        nid+=n;
                    }
                    else if(nid>=n)
                    {
                        nid-=n;
                    }
                    if(outputdata->virtualscan[nid]>0&&outputdata->label[nid]==-1)
                    {
                        double angle=fabs(j*density);
                        double distance=outputdata->virtualscan[nid]*outputdata->virtualscan[nid]
                                +outputdata->virtualscan[id]*outputdata->virtualscan[id]
                                -2*cos(angle)*outputdata->virtualscan[nid]*outputdata->virtualscan[id];
                        //double heightdis=fabs(outputdata->heights[nid]-outputdata->heights[id]);
                        //distance=sqrt(distance*distance+heightdis*heightdis);
                        if(distance<=vars->neighbordis)
                        {
                            outputdata->label[nid]=outputdata->labelcount;
                            queue.push_back(nid);
                        }
                    }
                }
            }
            if(records.size()>=vars->pointsnum)
            {
                outputdata->index.push_back(records);
                outputdata->labelcount++;
            }
            else
            {
                int j,m=records.size();
                for(j=0;j<m;j++)
                {
                    outputdata->label[records[j]]=-2;
                }
            }
        }
    }
	return 1;
}

