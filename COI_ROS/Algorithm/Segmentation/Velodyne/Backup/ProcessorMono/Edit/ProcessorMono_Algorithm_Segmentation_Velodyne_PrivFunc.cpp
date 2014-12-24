//You need to program this file.

#include "../NoEdit/ProcessorMono_Algorithm_Segmentation_Velodyne_PrivFunc.h"

//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	ProcessorMono_Algorithm_Segmentation_Velodyne_Params * params=(ProcessorMono_Algorithm_Segmentation_Velodyne_Params *)paramsPtr;
	ProcessorMono_Algorithm_Segmentation_Velodyne_Vars * vars=(ProcessorMono_Algorithm_Segmentation_Velodyne_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: open node.
	Procedure:
	1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
	2: initialize variables (vars).
	3: If everything is OK, return 1 for successful opening and vice versa.
	*/
    GetParamValue(xmlloader,vars,maxrange);
    GetParamValue(xmlloader,vars,minrange);
    GetParamValue(xmlloader,vars,df);
    GetParamValue(xmlloader,vars,e0);
    GetParamValue(xmlloader,vars,e1);
    GetParamValue(xmlloader,vars,e2);
    GetParamValue(xmlloader,vars,e3);
    GetParamValue(xmlloader,vars,groundheight);
    GetParamValue(xmlloader,vars,groundnormal);
	return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	ProcessorMono_Algorithm_Segmentation_Velodyne_Params * params=(ProcessorMono_Algorithm_Segmentation_Velodyne_Params *)paramsPtr;
	ProcessorMono_Algorithm_Segmentation_Velodyne_Vars * vars=(ProcessorMono_Algorithm_Segmentation_Velodyne_Vars *)varsPtr;
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
	ProcessorMono_Algorithm_Segmentation_Velodyne_Params * params=(ProcessorMono_Algorithm_Segmentation_Velodyne_Params *)paramsPtr;
	ProcessorMono_Algorithm_Segmentation_Velodyne_Vars * vars=(ProcessorMono_Algorithm_Segmentation_Velodyne_Vars *)varsPtr;
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
	ProcessorMono_Algorithm_Segmentation_Velodyne_Params * params=(ProcessorMono_Algorithm_Segmentation_Velodyne_Params *)paramsPtr;
	ProcessorMono_Algorithm_Segmentation_Velodyne_Vars * vars=(ProcessorMono_Algorithm_Segmentation_Velodyne_Vars *)varsPtr;
	outputDataPtr=boost::shared_ptr<void>(new ProcessorMono_Algorithm_Segmentation_Velodyne_Data());
	/*======Occasionally Program below/above======*/
	/*
	Function: initial output data.
	You need to program here when you need to manually initialize output data.
	*/
	
}

void DECOFUNC(getMonoInputDataSize)(void * paramsPtr, void * varsPtr, int & inputDataSize)
{
	ProcessorMono_Algorithm_Segmentation_Velodyne_Params * params=(ProcessorMono_Algorithm_Segmentation_Velodyne_Params *)paramsPtr;
	ProcessorMono_Algorithm_Segmentation_Velodyne_Vars * vars=(ProcessorMono_Algorithm_Segmentation_Velodyne_Vars *)varsPtr;
    inputDataSize=-1;
	/*======Please Program above======*/
	/*
	Function: get input data size to be grabbed from buffer.
	Rules:
	inputDataSize=0: grab and remove all data from buffer.
	inputDataSize>0: grab inputDataSize latest data from buffer.
	inputDataSize<0: grab and remove inputDataSize ancient data from buffer.
	*/
}

//Input Port #0: Buffer_Size = 0, Params_Type = SensorInternalEvent_Sensor_Velodyne_Params, Data_Type = SensorInternalEvent_Sensor_Velodyne_Data
bool DECOFUNC(processMonoInputData)(void * paramsPtr, void * varsPtr, QVector<void *> inputParams, QVector<void *> inputData, void * outputData, QList<int> & outputPortIndex)
{
	ProcessorMono_Algorithm_Segmentation_Velodyne_Params * params=(ProcessorMono_Algorithm_Segmentation_Velodyne_Params *)paramsPtr;
	ProcessorMono_Algorithm_Segmentation_Velodyne_Vars * vars=(ProcessorMono_Algorithm_Segmentation_Velodyne_Vars *)varsPtr;
	QVector<SensorInternalEvent_Sensor_Velodyne_Params *> inputparams; copyQVector(inputparams,inputParams);
	QVector<SensorInternalEvent_Sensor_Velodyne_Data *> inputdata; copyQVector(inputdata,inputData);
	ProcessorMono_Algorithm_Segmentation_Velodyne_Data * outputdata=(ProcessorMono_Algorithm_Segmentation_Velodyne_Data *)outputData;
	outputPortIndex=QList<int>();
	if(inputdata.size()==0){return 0;}
	/*======Please Program below======*/
	/*
	Step 1: process inputdata, then store it into outputdata.
	Step 2 [optional]: determine the outputPortIndex. (if not, outputdata will be sent by all ports)
	E.g. outputPortIndex=QList<int>()<<(outportindex1)<<(outportindex2)...
	*/
    outputdata->velodynepoints=inputdata[0]->velodynepoints;
    outputdata->timestamp=inputdata[0]->timestamp;
    outputdata->pclpoints=inputdata[0]->pclpoints;

    int i,height=outputdata->velodynepoints->height;
    int j,width=outputdata->velodynepoints->width;
    int pointnum=width*height;

    outputdata->graph.resize(pointnum);
    for(i=0;i<height;i++)
    {
        for(j=0;j<width;j++)
        {
            int id=i*width+j;
            outputdata->graph[id].point=cv::Mat(3,1,CV_32F);
            outputdata->graph[id].point.at<float>(0)=outputdata->pclpoints->points[id].x;
            outputdata->graph[id].point.at<float>(1)=outputdata->pclpoints->points[id].y;
            outputdata->graph[id].point.at<float>(2)=outputdata->pclpoints->points[id].z;

            outputdata->graph[id].connect[0]=i-1>=0?(i-1)*width+j:-1;
            outputdata->graph[id].connect[1]=i*width+(j-1>=0?j-1:width-1);
            outputdata->graph[id].connect[2]=i+1<height?(i+1)*width+j:-1;
            outputdata->graph[id].connect[3]=i*width+(j+1<width?j+1:0);

            outputdata->graph[id].label=-1;

            float distance=cv::norm(outputdata->graph[id].point);
            if(distance>vars->maxrange||distance<=vars->minrange)
            {
                outputdata->graph[id].valid=0;
            }
            else
            {
                outputdata->graph[id].valid=1;
            }
        }
    }
    for(i=0;i<height;i++)
    {
        for(j=0;j<width;j++)
        {
            int id=i*width+j;
            if(!(outputdata->graph[id].valid))
            {
                continue;
            }
            int k;
            for(k=0;k<4;k++)
            {
                if(outputdata->graph[id].connect[k]==-1||!(outputdata->graph[outputdata->graph[id].connect[k]].valid))
                {
                    outputdata->graph[id].connect[k]=-1;
                }
                else
                {
                    outputdata->graph[id].connectvec[k]=outputdata->graph[outputdata->graph[id].connect[k]].point-outputdata->graph[id].point;
                    float distance=cv::norm(outputdata->graph[id].connectvec[k]);
                    if(distance>vars->df)
                    {
                        outputdata->graph[id].connect[k]=-1;
                    }
                }
            }
            cv::Mat normal=cv::Mat::zeros(3,1,CV_32F);
            cv::Mat tmpnormal=cv::Mat::zeros(3,1,CV_32F);
            bool flag=0;
            int count=0;
            for(k=0;k<4;k++)
            {
                int p1id=outputdata->graph[id].connect[k];
                int p2id=outputdata->graph[id].connect[(k+1)%4];
                if(p1id>=0&&p2id>=0)
                {
                    cv::Mat point=outputdata->graph[p1id].point.cross(outputdata->graph[p2id].point);
                    float pointnorm=cv::norm(point);
                    if(pointnorm==0)
                    {
                        continue;
                    }
                    if(flag)
                    {
                        float tmpangle=normal.dot(point*(1/pointnorm));
                        if(tmpangle>0)
                        {
                            if(acos(tmpangle)>vars->e0)
                            {
                                continue;
                            }
                        }
                        else if(tmpangle<0)
                        {
                            if(acos(-tmpangle)>vars->e0)
                            {
                                continue;
                            }
                        }
                        else
                        {
                            continue;
                        }
                    }
                    tmpnormal=tmpnormal+point;
                    count++;
                    float norm=cv::norm(tmpnormal);
                    if(norm==0)
                    {
                        flag=0;
                        continue;
                    }
                    else
                    {
                        normal=tmpnormal*(1/norm);
                        flag=1;
                    }
                }
            }
            if(flag&&count>0)
            {
                outputdata->graph[id].normal=normal;
            }
            else
            {
                outputdata->graph[id].valid=0;
            }
        }
    }
    outputdata->segments.clear();
    float PI=3.141592654;
    for(i=0;i<height;i++)
    {
        for(j=0;j<width;j++)
        {
            int id=i*width+j;
            if(!(outputdata->graph[id].valid)||outputdata->graph[id].label>=0)
            {
                continue;
            }
            QQueue<int> grow;
            int label=outputdata->segments.size();
            pcl::PointCloud<pcl::PointXYZI>::Ptr segment(new pcl::PointCloud<pcl::PointXYZI>);

            grow.push_back(id);
            outputdata->graph[id].label=label;

            while(!grow.isEmpty())
            {
                int seedid=grow.front();
                grow.pop_front();

                segment->points.push_back(outputdata->pclpoints->points[seedid]);
                int k;
                for(k=0;k<4;k++)
                {
                    int connectid=outputdata->graph[seedid].connect[k];
                    if(connectid>=0)
                    {
                        if(outputdata->graph[connectid].label>=0)
                        {
                            continue;
                        }
                        if(outputdata->graph[connectid].valid&&outputdata->graph[connectid].connect[(k+2)%4]==seedid)
                        {
                            bool flag=1;
                            flag&=outputdata->graph[seedid].normal.dot(outputdata->graph[seedid].connectvec[k])<=cv::norm(outputdata->graph[seedid].connectvec[k])*cos(PI/2-vars->e1);
                            flag&=outputdata->graph[connectid].normal.dot(-(outputdata->graph[seedid].connectvec[k]))<=cv::norm(outputdata->graph[seedid].connectvec[k])*cos(PI/2-vars->e1);
                            flag|=outputdata->graph[seedid].normal.dot(outputdata->graph[connectid].normal)>=1-cv::norm(outputdata->graph[seedid].connectvec[k])*cos(PI/2-vars->e2);
                            flag|=(fabs(outputdata->graph[seedid].normal.at<double>(2))<vars->e3)&&(fabs(outputdata->graph[connectid].normal.at<double>(2))<vars->e3);
                            if(flag)
                            {
                                grow.push_back(connectid);
                                outputdata->graph[connectid].label=label;
                            }
                            else
                            {
                                outputdata->graph[seedid].connect[k]=-1;
                                outputdata->graph[connectid].connect[(k+2)%4]=-1;
                            }
                        }
                        else
                        {
                            outputdata->graph[seedid].connect[k]=-1;
                            outputdata->graph[connectid].connect[(k+2)%4]=-1;
                        }
                    }
                }
            }
            outputdata->segments.push_back(segment);
        }
    }
	return 1;
}

