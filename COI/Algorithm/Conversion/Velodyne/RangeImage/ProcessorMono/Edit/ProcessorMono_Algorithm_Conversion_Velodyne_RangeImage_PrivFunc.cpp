//You need to program this file.

#include "../NoEdit/ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_PrivFunc.h"

//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_Params * params=(ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_Params *)paramsPtr;
	ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_Vars * vars=(ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: open node.
	Procedure:
	1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
	2: initialize variables (vars).
	3: If everything is OK, return 1 for successful opening and vice versa.
	*/
    GetParamValue(xmlloader,params,vangstart);
    GetParamValue(xmlloader,params,vangend);
    GetParamValue(xmlloader,params,hangstart);
    GetParamValue(xmlloader,params,hangend);
    GetParamValue(xmlloader,params,maxdis);
    GetParamValue(xmlloader,params,vresolution);
    GetParamValue(xmlloader,params,hresolution);

    params->imgsize.height=(params->vangend-params->vangstart)/params->vresolution+1;
    params->imgsize.width=(params->hangend-params->hangstart)/params->hresolution+1;
    GetParamValue(xmlloader,vars,venhancegap);
    GetParamValue(xmlloader,vars,henhancegap);
    GetParamValue(xmlloader,vars,vgaussianangle);
    GetParamValue(xmlloader,vars,hgaussianangle);

	return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_Params * params=(ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_Params *)paramsPtr;
	ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_Vars * vars=(ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_Vars *)varsPtr;
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
	ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_Params * params=(ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_Params *)paramsPtr;
	ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_Vars * vars=(ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_Vars *)varsPtr;
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
	ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_Params * params=(ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_Params *)paramsPtr;
	ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_Vars * vars=(ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_Vars *)varsPtr;
	outputDataPtr=boost::shared_ptr<void>(new ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_Data());
	/*======Occasionally Program below/above======*/
	/*
	Function: initial output data.
	You need to program here when you need to manually initialize output data.
	*/
	
}

void DECOFUNC(getMonoInputDataSize)(void * paramsPtr, void * varsPtr, int & inputDataSize)
{
	ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_Params * params=(ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_Params *)paramsPtr;
	ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_Vars * vars=(ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_Vars *)varsPtr;
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

//Input Port #0: Buffer_Size = 0, Params_Type = Simulator_Sensor_Velodyne_Params, Data_Type = Simulator_Sensor_Velodyne_Data
bool DECOFUNC(processMonoInputData)(void * paramsPtr, void * varsPtr, QVector<void *> inputParams, QVector<void *> inputData, void * outputData, QList<int> & outputPortIndex)
{
	ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_Params * params=(ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_Params *)paramsPtr;
	ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_Vars * vars=(ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_Vars *)varsPtr;
	QVector<Simulator_Sensor_Velodyne_Params *> inputparams; copyQVector(inputparams,inputParams);
	QVector<Simulator_Sensor_Velodyne_Data *> inputdata; copyQVector(inputdata,inputData);
	ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_Data * outputdata=(ProcessorMono_Algorithm_Conversion_Velodyne_RangeImage_Data *)outputData;
	outputPortIndex=QList<int>();
	if(inputdata.size()==0){return 0;}
	/*======Please Program below======*/
	/*
	Step 1: process inputdata, then store it into outputdata.
	Step 2 [optional]: determine the outputPortIndex. (if not, outputdata will be sent by all ports)
	E.g. outputPortIndex=QList<int>()<<(outportindex1)<<(outportindex2)...
	*/
    Simulator_Sensor_Velodyne_Params * tmpparams=params;
    Simulator_Sensor_Velodyne_Data * tmpdata=outputdata;
    *tmpparams=*(inputparams.front());
    *tmpdata=*(inputdata.front());

    outputdata->rangeimage=cv::Mat::zeros(params->imgsize,CV_32F);
    int i,n=outputdata->cloud->size();
    float pi=3.14159265359;
    for(i=0;i<n;i++)
    {
        pcl::PointXYZ point=(*(outputdata->cloud))[i];

        float dis=sqrt(point.x*point.x+point.y*point.y+point.z*point.z);
        if(dis==0)
        {
            continue;
        }


        float alpha=asin(point.z/dis)*180/pi;
        int row=int((params->vangend-alpha)/params->vresolution+0.5);

        if(row<0||row>=params->imgsize.height)
        {
            continue;
        }

        float beta=atan2(point.x,point.y)*180/pi;
        int column=int((params->hangend-beta)/params->hresolution+0.5);
        if(column<0||column>=params->imgsize.width)
        {
            continue;
        }

        if(outputdata->rangeimage.at<float>(row,column)==0.0f||outputdata->rangeimage.at<float>(row,column)>dis)
        {
            outputdata->rangeimage.at<float>(row,column)=dis;
        }
    }

    {
        int i,n=outputdata->rangeimage.rows;
        int j,m=outputdata->rangeimage.cols;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(outputdata->rangeimage.at<float>(i,j)!=0.0f)
                {
                    break;
                }
            }
            int startpixel=j;
            int endpixel=j;
            for(j=j+1;j<m;j++)
            {
                if(outputdata->rangeimage.at<float>(i,j)!=0.0f)
                {
                    startpixel=j;
                }
                else
                {
                    int k;
                    for(k=2;k<m;k++)
                    {
                        int tmpidx=(startpixel+k)%m;
                        if(outputdata->rangeimage.at<float>(i,tmpidx)!=0.0f)
                        {
                            endpixel=tmpidx;
                            break;
                        }
                    }
                    if(k<m)
                    {
                        float startdis=outputdata->rangeimage.at<float>(i,startpixel);
                        float enddis=outputdata->rangeimage.at<float>(i,endpixel);
                        float angle=(k*params->hresolution)*pi/180.0;
                        float dis=sqrt(startdis*startdis+enddis*enddis-2*startdis*enddis*cos(angle));
                        if(dis<=vars->henhancegap)
                        {
                            int l;
                            for(l=1;l<k;l++)
                            {
                                int tmpidx=(startpixel+l)%m;
                                float tmpdis=startdis+(enddis-startdis)*l/k;
                                outputdata->rangeimage.at<float>(i,tmpidx)=tmpdis;
                            }
                        }
                    }
                    j=startpixel+k<m?startpixel+k:m;
                    if(j<m)
                    {
                        startpixel=j;
                    }
                }
            }
        }
    }
    {
        int i,n=outputdata->rangeimage.rows;
        int j,m=outputdata->rangeimage.cols;
        for(j=0;j<m;j++)
        {
            for(i=0;i<n;i++)
            {
                if(outputdata->rangeimage.at<float>(i,j)!=0.0f)
                {
                    break;
                }
            }
            int startpixel=i;
            int endpixel=i;
            for(i=i+1;i<n;i++)
            {
                if(outputdata->rangeimage.at<float>(i,j)!=0.0f)
                {
                    startpixel=i;
                }
                else
                {
                    int k;
                    for(k=2;k<n-startpixel;k++)
                    {
                        int tmpidx=startpixel+k;
                        if(outputdata->rangeimage.at<float>(tmpidx,j)!=0.0f)
                        {
                            endpixel=tmpidx;
                            break;
                        }
                    }
                    if(k<n-startpixel)
                    {
                        float startdis=outputdata->rangeimage.at<float>(startpixel,j);
                        float enddis=outputdata->rangeimage.at<float>(endpixel,j);
                        float angle=(k*params->vresolution)*pi/180.0;
                        float dis=sqrt(startdis*startdis+enddis*enddis-2*startdis*enddis*cos(angle));
                        if(dis<=vars->venhancegap)
                        {
                            int l;
                            for(l=1;l<k;l++)
                            {
                                int tmpidx=startpixel+l;
                                float tmpdis=startdis+(enddis-startdis)*l/k;
                                outputdata->rangeimage.at<float>(tmpidx,j)=tmpdis;
                            }
                        }
                    }
                    i=startpixel+k<n?startpixel+k:n;
                    if(i<n)
                    {
                        startpixel=i;
                    }
                }
            }
        }
    }
    cv::GaussianBlur(outputdata->rangeimage,outputdata->rangeimage,cv::Size(int(vars->hgaussianangle/params->hresolution+0.5)*2+1,int(vars->vgaussianangle/params->vresolution+0.5)*2+1),0,0);
    {
        int i,n=outputdata->rangeimage.rows;
        int j,m=outputdata->rangeimage.cols;
        outputdata->rangepoints->resize(m*n);
        int pointid=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(outputdata->rangeimage.at<float>(i,j)>params->maxdis)
                {
                    outputdata->rangeimage.at<float>(i,j)=0;
                }
                if(outputdata->rangeimage.at<float>(i,j)!=0.0f)
                {
                    float alpha=(params->vangend-i*params->vresolution)*pi/180.0;
                    float beta=(params->hangstart+j*params->hresolution)*pi/180.0;
                    float dis=outputdata->rangeimage.at<float>(i,j);
                    (*(outputdata->rangepoints))[pointid].x=dis*cos(alpha)*cos(beta);
                    (*(outputdata->rangepoints))[pointid].y=dis*cos(alpha)*sin(beta);
                    (*(outputdata->rangepoints))[pointid].z=dis*sin(alpha);
                    (*(outputdata->rangepoints))[pointid].data[3]=dis/params->maxdis;
                    pointid++;
                }
            }
        }
        outputdata->rangepoints->resize(pointid);
    }
    float scale=1.0/params->maxdis;
    outputdata->rangeimage=outputdata->rangeimage*scale;
	return 1;
}

