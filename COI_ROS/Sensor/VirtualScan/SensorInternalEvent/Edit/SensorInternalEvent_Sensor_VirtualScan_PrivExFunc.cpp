//You need to program this file.

#include "../NoEdit/SensorInternalEvent_Sensor_VirtualScan_PrivExFunc.h"

bool DECOFUNC(generateSourceData_PointCloud2)(void * paramsPtr, void * varsPtr, void * outputData, QList<int> & outputPortIndex, QTime & timeStamp)
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
    sensor_msgs::PointCloud2ConstPtr virtualscan=vars->velodynesub->getMessage();
    if(virtualscan==NULL)
    {
        return 0;
    }
    int msec=(virtualscan->header.stamp.sec)%(24*60*60)*1000+(virtualscan->header.stamp.nsec)/1000000;
    outputdata->timestamp=QTime::fromMSecsSinceStartOfDay(msec);

    double PI=3.141592654;
    double density=2*PI/vars->beamnum;
    outputdata->virtualscan.resize(vars->beamnum);
    outputdata->minheights.resize(vars->beamnum);
    outputdata->maxheights.resize(vars->beamnum);

    int i,n=virtualscan->data.size()/(virtualscan->point_step);
    const unsigned char * base=virtualscan->data.data();
    for(i=0;i<n;i++)
    {
        float * data=(float *)(base+i*virtualscan->point_step);
        double theta=atan2(data[1],data[0]);
        int id=(theta+PI)/density+0.5;
        id=id>=0?id:0;
        id=id<vars->beamnum?id:vars->beamnum-1;
        outputdata->virtualscan[id]=sqrt(data[0]*data[0]+data[1]*data[1]);
        outputdata->minheights[id]=data[2];
        outputdata->maxheights[id]=data[2];
    }

    outputdata->label.fill(-1,vars->beamnum);
    outputdata->labelcount=0;
    for(i=0;i<vars->beamnum;i++)
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

