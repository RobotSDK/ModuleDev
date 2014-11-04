//You need to program this file.

#include "../NoEdit/ProcessorMulti_Algorithm_Integration_VelodyneCamera_PrivFunc.h"

//*******************Please add static libraries below*******************

#pragma comment(lib,"Kernel.lib")

#ifdef _DEBUG

#pragma comment(lib,"opencv_features2d249d.lib")

#else

#pragma comment(lib,"opencv_features2d249.lib")

#endif

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	ProcessorMulti_Algorithm_Integration_VelodyneCamera_Params * params=(ProcessorMulti_Algorithm_Integration_VelodyneCamera_Params *)paramsPtr;
	ProcessorMulti_Algorithm_Integration_VelodyneCamera_Vars * vars=(ProcessorMulti_Algorithm_Integration_VelodyneCamera_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: open node.
	Procedure:
	1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
	2: initialize variables (vars).
	3: If everything is OK, return 1 for successful opening and vice versa.
	*/
	GetParamValue(xmlloader,vars,sample);
	GetParamValue(xmlloader,vars,range);
	GetParamValue(xmlloader,vars,colornum);
	GetParamValue(xmlloader,vars,radius);

	vars->init=1;
	return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	ProcessorMulti_Algorithm_Integration_VelodyneCamera_Params * params=(ProcessorMulti_Algorithm_Integration_VelodyneCamera_Params *)paramsPtr;
	ProcessorMulti_Algorithm_Integration_VelodyneCamera_Vars * vars=(ProcessorMulti_Algorithm_Integration_VelodyneCamera_Vars *)varsPtr;
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
	ProcessorMulti_Algorithm_Integration_VelodyneCamera_Params * params=(ProcessorMulti_Algorithm_Integration_VelodyneCamera_Params *)paramsPtr;
	ProcessorMulti_Algorithm_Integration_VelodyneCamera_Vars * vars=(ProcessorMulti_Algorithm_Integration_VelodyneCamera_Vars *)varsPtr;
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
	ProcessorMulti_Algorithm_Integration_VelodyneCamera_Params * params=(ProcessorMulti_Algorithm_Integration_VelodyneCamera_Params *)paramsPtr;
	ProcessorMulti_Algorithm_Integration_VelodyneCamera_Vars * vars=(ProcessorMulti_Algorithm_Integration_VelodyneCamera_Vars *)varsPtr;
	outputDataPtr=boost::shared_ptr<void>(new ProcessorMulti_Algorithm_Integration_VelodyneCamera_Data());
	/*======Occasionally Program below/above======*/
	/*
	Function: initial output data.
	You need to program here when you need to manually initialize output data.
	*/
	
}

void DECOFUNC(getMultiInputDataSize)(void * paramsPtr, void * varsPtr, QList<int> & inputDataSize)
{
	ProcessorMulti_Algorithm_Integration_VelodyneCamera_Params * params=(ProcessorMulti_Algorithm_Integration_VelodyneCamera_Params *)paramsPtr;
	ProcessorMulti_Algorithm_Integration_VelodyneCamera_Vars * vars=(ProcessorMulti_Algorithm_Integration_VelodyneCamera_Vars *)varsPtr;
	inputDataSize=QList<int>()<<-1<<-1;
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

//Input Port #0: Buffer_Size = 0, Params_Type = Simulator_Sensor_Velodyne_Params, Data_Type = Simulator_Sensor_Velodyne_Data
//Input Port #1: Buffer_Size = 0, Params_Type = Simulator_Sensor_Camera_Params, Data_Type = Simulator_Sensor_Camera_Data
bool DECOFUNC(processMultiInputData)(void * paramsPtr, void * varsPtr, QVector<QVector<void *> > inputParams, QVector<QVector<void *> > inputData, void * outputData, QList<int> & outputPortIndex)
{
	ProcessorMulti_Algorithm_Integration_VelodyneCamera_Params * params=(ProcessorMulti_Algorithm_Integration_VelodyneCamera_Params *)paramsPtr;
	ProcessorMulti_Algorithm_Integration_VelodyneCamera_Vars * vars=(ProcessorMulti_Algorithm_Integration_VelodyneCamera_Vars *)varsPtr;
	QVector<Simulator_Sensor_Velodyne_Params *> inputparams_0; copyQVector(inputparams_0,inputParams[0]);
	QVector<Simulator_Sensor_Camera_Params *> inputparams_1; copyQVector(inputparams_1,inputParams[1]);
	QVector<Simulator_Sensor_Velodyne_Data *> inputdata_0; copyQVector(inputdata_0,inputData[0]);
	QVector<Simulator_Sensor_Camera_Data *> inputdata_1; copyQVector(inputdata_1,inputData[1]);
	ProcessorMulti_Algorithm_Integration_VelodyneCamera_Data * outputdata=(ProcessorMulti_Algorithm_Integration_VelodyneCamera_Data *)outputData;
	outputPortIndex=QList<int>();
	if(inputdata_0.size()==0){return 0;}
	if(inputdata_1.size()==0){return 0;}
	/*======Please Program below======*/
	/*
	Step 1: process inputdata_index, then store it into outputdata.
	Step 2 [optional]: determine the outputPortIndex. (if not, outputdata will be sent by all ports)
	E.g. outputPortIndex=QList<int>()<<(outportindex1)<<(outportindex2)...
	*/
	if(vars->init)
	{
		cv::Mat T=cv::Mat::eye(4,4,CV_32F);
		cv::Mat tmpR=T(cv::Rect(0,0,3,3));
		cv::Mat tmpT=T(cv::Rect(0,3,3,1));
		inputparams_0[0]->rotation.copyTo(tmpR);
		inputparams_0[0]->translation.copyTo(tmpT);

		cv::Mat R=inputparams_1[0]->refcamrectrot;
		cv::Mat P=inputparams_1[0]->rectprojection;

		vars->FP=P*R*T;
		vars->init=0;
	}

	outputdata->velodynetimestamp=inputdata_0[0]->timestamp;
	outputdata->imagetimestamp=inputdata_1[0]->timestamp;	

	int pointnum=inputdata_0[0]->spin.size();
	cv::Mat veldata=cv::Mat(pointnum,4,CV_32F,inputdata_0[0]->spin.data(),sizeof(VelodynePoint));
	cv::Mat velpoints=cv::Mat::ones(pointnum,4,CV_32F);
	cv::Mat tmppoints=velpoints(cv::Rect(0,0,3,pointnum));
	veldata(cv::Rect(0,0,3,pointnum)).copyTo(tmppoints);
	cv::Mat imgpoint=velpoints*vars->FP.t();

	int i,n=imgpoint.rows;
	QVector<cv::Point2f> drawpoints;
    QVector<float> scales;
	cv::Rect rectimage=cv::Rect(0,0,inputparams_1[0]->rectsize.width-1,inputparams_1[0]->rectsize.height-1);
    float maxscale=0;
    for(i=0;i<n;i+=vars->sample)
	{
		float scale=imgpoint.at<float>(i,2);
        if(scale>0&&scale<=vars->range)
		{
            if(maxscale<scale)
            {
                maxscale=scale;
            }
			cv::Point2f drawpoint=cv::Point2f(imgpoint.at<float>(i,0)/scale,imgpoint.at<float>(i,1)/scale);
			if(drawpoint.inside(rectimage))
			{
				VelodyneColor color;
				switch(inputdata_1[0]->image.channels())
				{
				case 1:
					color.r=inputdata_1[0]->image.at<uchar>(drawpoint)/255.0;
					color.g=color.r;
					color.b=color.r;
					break;
				case 3:
					color.b=inputdata_1[0]->image.at<cv::Vec3b>(drawpoint)[0]/255.0;
					color.g=inputdata_1[0]->image.at<cv::Vec3b>(drawpoint)[1]/255.0;
					color.r=inputdata_1[0]->image.at<cv::Vec3b>(drawpoint)[2]/255.0;
					break;
				default:
					continue;
				}
				outputdata->colors.push_back(color);
				outputdata->points.push_back(inputdata_0[0]->spin[i]);
				drawpoints.push_back(drawpoint);
                scales.push_back(scale);
			}
		}
	}

	outputdata->image=inputdata_1[0]->image.clone();

	n=drawpoints.size();
	for(i=0;i<n;i++)
    {
        int tmpi=int(scales[i]/maxscale*255.0);
        uchar r=vars->colormap.at<cv::Vec3b>(tmpi/16,tmpi%16)[0];
        uchar g=vars->colormap.at<cv::Vec3b>(tmpi/16,tmpi%16)[1];
        uchar b=vars->colormap.at<cv::Vec3b>(tmpi/16,tmpi%16)[2];
        cv::circle(outputdata->image,drawpoints[i],vars->radius,cv::Scalar(r,g,b),-1);
	}
	return 1;
}

