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
    vars->segmentationbuffer.clear();
    vars->camerabuffer.clear();
    vars->segmentationinit=1;
    vars->camerainit=1;
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
    vars->segmentationbuffer.clear();
    vars->camerabuffer.clear();
    vars->segmentationinit=1;
    vars->camerainit=1;
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
    inputDataSize=QList<int>()<<0<<0;
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
//	if(inputdata_0.size()==0){return 0;}
//	if(inputdata_1.size()==0){return 0;}
	/*======Please Program below======*/
	/*
	Step 1: process inputdata_index, then store it into outputdata.
	Step 2 [optional]: determine the outputPortIndex. (if not, outputdata will be sent by all ports)
	E.g. outputPortIndex=QList<int>()<<(outportindex1)<<(outportindex2)...
	*/
    if(vars->segmentationinit&&inputparams_0.size()>0)
    {
        params->segmentationextrinsicmat=inputparams_0[0]->extrinsicmat;
        vars->segmentationinit=0;
    }

    if(vars->camerainit&&inputparams_1.size()>0)
    {
        params->cameraextrinsicmat=inputparams_1[0]->extrinsicmat;
        params->cameramat=inputparams_1[0]->cameramat;
        params->distcoeff=inputparams_1[0]->distcoeff;
        vars->camerainit=0;
    }

    int i,n=inputdata_0.size();
    for(i=n-1;i>=0;i--)
    {
        ProcessorMulti_Algorithm_Integration_SegmentationCamera_Vars::SegmentationBufferData data;
        data.timestamp=inputdata_0[i]->timestamp;
        data.pclsegmentation=inputdata_0[i]->pclsegmentation;
        vars->segmentationbuffer.push_back(data);
    }

    int j,m=inputdata_1.size();
    for(j=m-1;j>=0;j--)
    {
        ProcessorMulti_Algorithm_Integration_SegmentationCamera_Vars::CameraBufferData data;
        data.timestamp=inputdata_1[j]->timestamp;
        data.cvimage=inputdata_1[j]->cvimage.clone();
        vars->camerabuffer.push_back(data);
    }

    i=0;n=vars->segmentationbuffer.size();
    j=0;m=vars->camerabuffer.size();
    if(n==0||m==0)
    {
        return 0;
    }
    int delta=0;
    while(i<n&&j<m)
    {
        QTime segmentationtimestamp=vars->segmentationbuffer[i].timestamp;
        QTime cameratimestamp=vars->camerabuffer[j].timestamp;
        int tmpdelta=segmentationtimestamp.msecsTo(cameratimestamp);
        if(tmpdelta!=0)
        {
            if(delta==0)
            {
                delta=tmpdelta;
                if(tmpdelta>0)
                {
                    i++;
                }
                else
                {
                    j++;
                }
            }
            else
            {
                if(abs(tmpdelta)<abs(delta))
                {
                    delta=tmpdelta;
                    if(tmpdelta>0)
                    {
                        i++;
                    }
                    else
                    {
                        j++;
                    }
                }
                else
                {
                    if(delta>0)
                    {
                        i--;
                    }
                    else
                    {
                        j--;
                    }
                    break;
                }
            }
        }
        else
        {
            break;
        }
    }
    if(i==n)
    {
        vars->segmentationbuffer.erase(vars->segmentationbuffer.begin(),vars->segmentationbuffer.begin()+i-1);
        vars->camerabuffer.erase(vars->camerabuffer.begin(),vars->camerabuffer.begin()+j);
        return 0;
    }
    if(j==m)
    {
        vars->segmentationbuffer.erase(vars->segmentationbuffer.begin(),vars->segmentationbuffer.begin()+i);
        vars->camerabuffer.erase(vars->camerabuffer.begin(),vars->camerabuffer.begin()+j-1);
        return 0;
    }

    outputdata->segmentationtimestamp=vars->segmentationbuffer[i].timestamp;
    outputdata->cameratimestamp=vars->camerabuffer[j].timestamp;

    outputdata->cvimage=vars->camerabuffer[j].cvimage;
    cv::Size imagesize;
    imagesize.width=outputdata->cvimage.cols;
    imagesize.height=outputdata->cvimage.rows;
    outputdata->ranges.fill(0,imagesize.width*imagesize.height);
    outputdata->labels.fill(-1,imagesize.width*imagesize.height);

    int segid,segnum=vars->segmentationbuffer[i].pclsegmentation.size();
    for(segid=0;segid<segnum;segid++)
    {
        int k,pointsnum=vars->segmentationbuffer[i].pclsegmentation[segid]->points.size();
        cv::Mat segmentationpoints(pointsnum,8,CV_32F,vars->segmentationbuffer[i].pclsegmentation[segid]->points.data());
        cv::Mat pointscolor;
        segmentationpoints.convertTo(pointscolor,CV_64F);
        cv::Mat points=pointscolor(cv::Rect(0,0,4,pointsnum));
        cv::Mat camerapoints=points*(params->segmentationextrinsicmat.t())*(params->cameraextrinsicmat.inv().t());

        for(k=0;k<pointsnum;k++)
        {
            if(camerapoints.at<double>(k,2)<=0)
            {
                continue;
            }
            double tmpx=camerapoints.at<double>(k,0)/camerapoints.at<double>(k,2);
            double tmpy=camerapoints.at<double>(k,1)/camerapoints.at<double>(k,2);
            double r2=tmpx*tmpx+tmpy*tmpy;
            double tmpdist=1+params->distcoeff.at<double>(0)*r2+params->distcoeff.at<double>(1)*r2*r2+params->distcoeff.at<double>(4)*r2*r2*r2;

            double x=tmpx*tmpdist+2*params->distcoeff.at<double>(2)*tmpx*tmpy+params->distcoeff.at<double>(3)*(r2+2*tmpx*tmpx);
            double y=tmpy*tmpdist+2*params->distcoeff.at<double>(3)*tmpx*tmpy+params->distcoeff.at<double>(2)*(r2+2*tmpy*tmpy);
            x=params->cameramat.at<double>(0,0)*x+params->cameramat.at<double>(0,2);
            y=params->cameramat.at<double>(1,1)*y+params->cameramat.at<double>(1,2);
            if(x>=0 && x<=imagesize.width-1 && y>=0 && y<=imagesize.height-1)
            {
                int px=int(x+0.5);
                int py=int(y+0.5);
                int pid=py*imagesize.width+px;
                if(outputdata->ranges[pid]==0||outputdata->ranges[pid]>camerapoints.at<double>(k,2))
                {
                    outputdata->ranges[pid]=camerapoints.at<double>(k,2);
                    outputdata->labels[pid]=segid;
                }
            }
        }
    }

    vars->segmentationbuffer.erase(vars->segmentationbuffer.begin(),vars->segmentationbuffer.begin()+i+1);
    vars->camerabuffer.erase(vars->camerabuffer.begin(),vars->camerabuffer.begin()+j+1);
	return 1;
}

