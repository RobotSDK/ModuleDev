//You need to program this file.

#include "../NoEdit/ProcessorMulti_Algorithm_Integration_VelodyneCameraNDT3D_PrivFunc.h"

//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	ProcessorMulti_Algorithm_Integration_VelodyneCameraNDT3D_Params * params=(ProcessorMulti_Algorithm_Integration_VelodyneCameraNDT3D_Params *)paramsPtr;
	ProcessorMulti_Algorithm_Integration_VelodyneCameraNDT3D_Vars * vars=(ProcessorMulti_Algorithm_Integration_VelodyneCameraNDT3D_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: open node.
	Procedure:
	1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
	2: initialize variables (vars).
	3: If everything is OK, return 1 for successful opening and vice versa.
	*/
    vars->initcalib=1;
    vars->initvelodyne=1;
    vars->initndt3d=1;
	return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	ProcessorMulti_Algorithm_Integration_VelodyneCameraNDT3D_Params * params=(ProcessorMulti_Algorithm_Integration_VelodyneCameraNDT3D_Params *)paramsPtr;
	ProcessorMulti_Algorithm_Integration_VelodyneCameraNDT3D_Vars * vars=(ProcessorMulti_Algorithm_Integration_VelodyneCameraNDT3D_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: close node.
	Procedure:
	1: handle/close variables (vars).
	2: If everything is OK, return 1 for successful closing and vice versa.
	*/
    vars->initcalib=1;
    vars->initvelodyne=1;
    vars->initndt3d=1;
	return 1;
}

void DECOFUNC(getInternalTrigger)(void * paramsPtr, void * varsPtr, QObject * & internalTrigger, QString & internalTriggerSignal)
{
	ProcessorMulti_Algorithm_Integration_VelodyneCameraNDT3D_Params * params=(ProcessorMulti_Algorithm_Integration_VelodyneCameraNDT3D_Params *)paramsPtr;
	ProcessorMulti_Algorithm_Integration_VelodyneCameraNDT3D_Vars * vars=(ProcessorMulti_Algorithm_Integration_VelodyneCameraNDT3D_Vars *)varsPtr;
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
	ProcessorMulti_Algorithm_Integration_VelodyneCameraNDT3D_Params * params=(ProcessorMulti_Algorithm_Integration_VelodyneCameraNDT3D_Params *)paramsPtr;
	ProcessorMulti_Algorithm_Integration_VelodyneCameraNDT3D_Vars * vars=(ProcessorMulti_Algorithm_Integration_VelodyneCameraNDT3D_Vars *)varsPtr;
	outputDataPtr=boost::shared_ptr<void>(new ProcessorMulti_Algorithm_Integration_VelodyneCameraNDT3D_Data());
	/*======Occasionally Program below/above======*/
	/*
	Function: initial output data.
	You need to program here when you need to manually initialize output data.
	*/
	
}

void DECOFUNC(getMultiInputDataSize)(void * paramsPtr, void * varsPtr, QList<int> & inputDataSize)
{
	ProcessorMulti_Algorithm_Integration_VelodyneCameraNDT3D_Params * params=(ProcessorMulti_Algorithm_Integration_VelodyneCameraNDT3D_Params *)paramsPtr;
	ProcessorMulti_Algorithm_Integration_VelodyneCameraNDT3D_Vars * vars=(ProcessorMulti_Algorithm_Integration_VelodyneCameraNDT3D_Vars *)varsPtr;
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

//Input Port #0: Buffer_Size = 0, Params_Type = ProcessorMulti_Algorithm_Integration_VelodyneCamera_Params, Data_Type = ProcessorMulti_Algorithm_Integration_VelodyneCamera_Data
//Input Port #1: Buffer_Size = 0, Params_Type = SensorInternalEvent_Algorithm_Localization_NDT3D_Params, Data_Type = SensorInternalEvent_Algorithm_Localization_NDT3D_Data
bool DECOFUNC(processMultiInputData)(void * paramsPtr, void * varsPtr, QVector<QVector<void *> > inputParams, QVector<QVector<void *> > inputData, void * outputData, QList<int> & outputPortIndex)
{
	ProcessorMulti_Algorithm_Integration_VelodyneCameraNDT3D_Params * params=(ProcessorMulti_Algorithm_Integration_VelodyneCameraNDT3D_Params *)paramsPtr;
	ProcessorMulti_Algorithm_Integration_VelodyneCameraNDT3D_Vars * vars=(ProcessorMulti_Algorithm_Integration_VelodyneCameraNDT3D_Vars *)varsPtr;
	QVector<ProcessorMulti_Algorithm_Integration_VelodyneCamera_Params *> inputparams_0; copyQVector(inputparams_0,inputParams[0]);
	QVector<SensorInternalEvent_Algorithm_Localization_NDT3D_Params *> inputparams_1; copyQVector(inputparams_1,inputParams[1]);
	QVector<ProcessorMulti_Algorithm_Integration_VelodyneCamera_Data *> inputdata_0; copyQVector(inputdata_0,inputData[0]);
	QVector<SensorInternalEvent_Algorithm_Localization_NDT3D_Data *> inputdata_1; copyQVector(inputdata_1,inputData[1]);
	ProcessorMulti_Algorithm_Integration_VelodyneCameraNDT3D_Data * outputdata=(ProcessorMulti_Algorithm_Integration_VelodyneCameraNDT3D_Data *)outputData;
	outputPortIndex=QList<int>();
//	if(inputdata_0.size()==0){return 0;}
//	if(inputdata_1.size()==0){return 0;}
	/*======Please Program below======*/
	/*
	Step 1: process inputdata_index, then store it into outputdata.
	Step 2 [optional]: determine the outputPortIndex. (if not, outputdata will be sent by all ports)
	E.g. outputPortIndex=QList<int>()<<(outportindex1)<<(outportindex2)...
	*/
    if(vars->initvelodyne&&inputparams_0.size()>0)
    {
        vars->velodynemat=inputparams_0[0]->velodyneextrinsicmat;
        vars->initvelodyne=0;
    }

    if(vars->initndt3d&&inputparams_1.size()>0)
    {
        vars->ndt3dmat=inputparams_1[0]->extrinsicmat;
        vars->initndt3d=0;
    }

    if(vars->initcalib&&!vars->initvelodyne&&!vars->initndt3d)
    {
        vars->calibmat=vars->ndt3dmat.inv()*vars->velodynemat;
        vars->initcalib=0;
    }

    int i,n=inputdata_0.size();
    for(i=n-1;i>=0;i--)
    {
        ProcessorMulti_Algorithm_Integration_VelodyneCameraNDT3D_Vars::VelodyneCameraBufferData data;
        data.velodynetimestamp=inputdata_0[i]->velodynetimestamp;
        data.cameratimestamp=inputdata_0[i]->cameratimestamp;
        data.pclpoints=inputdata_0[i]->pclpoints;
        vars->velodynecamerabuffer.push_back(data);
    }

    int j,m=inputdata_1.size();
    for(j=0;j<m;j++)
    {
        ProcessorMulti_Algorithm_Integration_VelodyneCameraNDT3D_Vars::NDT3DBufferData data;
        data.timestamp=inputdata_1[j]->timestamp;
        data.cvtransform=inputdata_1[j]->cvtransform;
        vars->ndt3dbuffer.push_back(data);
    }

    i=0;n=vars->velodynecamerabuffer.size();
    j=0;m=vars->ndt3dbuffer.size();
    if(n==0||m==0)
    {
        return 0;
    }
    int delta=0;
    while(i<n&&j<m)
    {
        QTime velodynetimestamp=vars->velodynecamerabuffer[i].velodynetimestamp;
        QTime ndt3dtimestamp=vars->ndt3dbuffer[j].timestamp;
        int tmpdelta=velodynetimestamp.msecsTo(ndt3dtimestamp);
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
        vars->velodynecamerabuffer.erase(vars->velodynecamerabuffer.begin(),vars->velodynecamerabuffer.begin()+i-1);
        vars->ndt3dbuffer.erase(vars->ndt3dbuffer.begin(),vars->ndt3dbuffer.begin()+j);
        return 0;
    }
    if(j==m)
    {
        vars->velodynecamerabuffer.erase(vars->velodynecamerabuffer.begin(),vars->velodynecamerabuffer.begin()+i);
        vars->ndt3dbuffer.erase(vars->ndt3dbuffer.begin(),vars->ndt3dbuffer.begin()+j-1);
        return 0;
    }

    outputdata->velodynetimestamp=vars->velodynecamerabuffer[i].velodynetimestamp;
    outputdata->cameratimestamp=vars->velodynecamerabuffer[i].cameratimestamp;
    outputdata->pclpoints->header=vars->velodynecamerabuffer[i].pclpoints->header;
    outputdata->pclpoints->height=vars->velodynecamerabuffer[i].pclpoints->height;
    outputdata->pclpoints->width=vars->velodynecamerabuffer[i].pclpoints->width;
    outputdata->pclpoints->points=vars->velodynecamerabuffer[i].pclpoints->points;

    outputdata->ndt3dtimestamp=vars->ndt3dbuffer[j].timestamp;
    outputdata->cvtransform=vars->ndt3dbuffer[j].cvtransform;

    int pointsnum=outputdata->pclpoints->size();
    cv::Mat pointscolor(pointsnum,8,CV_32F,outputdata->pclpoints->points.data());
    cv::Mat transpoints=pointscolor(cv::Rect(0,0,4,pointsnum));
    cv::Mat points;
    transpoints.convertTo(points,CV_64F);
    points=points*(vars->calibmat.t())*(outputdata->cvtransform.t());
    points.convertTo(transpoints,CV_32F);

    vars->velodynecamerabuffer.erase(vars->velodynecamerabuffer.begin(),vars->velodynecamerabuffer.begin()+i+1);
    vars->ndt3dbuffer.erase(vars->ndt3dbuffer.begin(),vars->ndt3dbuffer.begin()+j+1);
	return 1;
}

