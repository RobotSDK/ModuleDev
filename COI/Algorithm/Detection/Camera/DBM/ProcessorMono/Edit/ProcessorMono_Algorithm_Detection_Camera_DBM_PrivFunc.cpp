//You need to program this file.

#include "../NoEdit/ProcessorMono_Algorithm_Detection_Camera_DBM_PrivFunc.h"

//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	ProcessorMono_Algorithm_Detection_Camera_DBM_Params * params=(ProcessorMono_Algorithm_Detection_Camera_DBM_Params *)paramsPtr;
	ProcessorMono_Algorithm_Detection_Camera_DBM_Vars * vars=(ProcessorMono_Algorithm_Detection_Camera_DBM_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: open node.
	Procedure:
	1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
	2: initialize variables (vars).
	3: If everything is OK, return 1 for successful opening and vice versa.
	*/
    GetParamValue(xmlloader,vars,modeldir);
    GetParamValue(xmlloader,vars,threshold1);
    GetParamValue(xmlloader,vars,threshold2);
    GetParamValue(xmlloader,vars,threadnum);
    GetParamValue(xmlloader,vars,compressrate);
    GetParamValue(xmlloader,vars,grubsize);

    if(vars->modeldir.size()==0)
    {
        return 0;
    }
    QDir dir(vars->modeldir);
    if(dir.exists())
    {
        dir.setFilter(QDir::Files);
        dir.setNameFilters(QStringList()<<"*.xml");
        QFileInfoList files=dir.entryInfoList();
        int i,n=files.size();
        std::vector<std::string> modelfiles;
        for(i=0;i<n;i++)
        {
            modelfiles.push_back(files[i].absoluteFilePath().toStdString());
        }
        if(n>0)
        {
            if(!vars->detector.load(modelfiles))
            {
                return 0;
            }
            modelfiles=vars->detector.getClassNames();
            n=vars->detector.getClassCount();
            params->classes.resize(n);
            for(i=0;i<n;i++)
            {
                params->classes[i]=QString::fromStdString(modelfiles[i]);
            }
            vars->init=1;
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	ProcessorMono_Algorithm_Detection_Camera_DBM_Params * params=(ProcessorMono_Algorithm_Detection_Camera_DBM_Params *)paramsPtr;
	ProcessorMono_Algorithm_Detection_Camera_DBM_Vars * vars=(ProcessorMono_Algorithm_Detection_Camera_DBM_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: close node.
	Procedure:
	1: handle/close variables (vars).
	2: If everything is OK, return 1 for successful closing and vice versa.
	*/
    vars->detector.clear();
    vars->init=0;
	return 1;
}

void DECOFUNC(getInternalTrigger)(void * paramsPtr, void * varsPtr, QObject * & internalTrigger, QString & internalTriggerSignal)
{
	ProcessorMono_Algorithm_Detection_Camera_DBM_Params * params=(ProcessorMono_Algorithm_Detection_Camera_DBM_Params *)paramsPtr;
	ProcessorMono_Algorithm_Detection_Camera_DBM_Vars * vars=(ProcessorMono_Algorithm_Detection_Camera_DBM_Vars *)varsPtr;
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
	ProcessorMono_Algorithm_Detection_Camera_DBM_Params * params=(ProcessorMono_Algorithm_Detection_Camera_DBM_Params *)paramsPtr;
	ProcessorMono_Algorithm_Detection_Camera_DBM_Vars * vars=(ProcessorMono_Algorithm_Detection_Camera_DBM_Vars *)varsPtr;
	outputDataPtr=boost::shared_ptr<void>(new ProcessorMono_Algorithm_Detection_Camera_DBM_Data());
	/*======Occasionally Program below/above======*/
	/*
	Function: initial output data.
	You need to program here when you need to manually initialize output data.
	*/
	
}

void DECOFUNC(getMonoInputDataSize)(void * paramsPtr, void * varsPtr, int & inputDataSize)
{
	ProcessorMono_Algorithm_Detection_Camera_DBM_Params * params=(ProcessorMono_Algorithm_Detection_Camera_DBM_Params *)paramsPtr;
	ProcessorMono_Algorithm_Detection_Camera_DBM_Vars * vars=(ProcessorMono_Algorithm_Detection_Camera_DBM_Vars *)varsPtr;
    inputDataSize=vars->grubsize;
	/*======Please Program above======*/
	/*
	Function: get input data size to be grabbed from buffer.
	Rules:
	inputDataSize=0: grab and remove all data from buffer.
	inputDataSize>0: grab inputDataSize latest data from buffer.
	inputDataSize<0: grab and remove inputDataSize ancient data from buffer.
	*/
}

//Input Port #0: Buffer_Size = 0, Params_Type = Simulator_Sensor_Camera_Params, Data_Type = Simulator_Sensor_Camera_Data
bool DECOFUNC(processMonoInputData)(void * paramsPtr, void * varsPtr, QVector<void *> inputParams, QVector<void *> inputData, void * outputData, QList<int> & outputPortIndex)
{
	ProcessorMono_Algorithm_Detection_Camera_DBM_Params * params=(ProcessorMono_Algorithm_Detection_Camera_DBM_Params *)paramsPtr;
	ProcessorMono_Algorithm_Detection_Camera_DBM_Vars * vars=(ProcessorMono_Algorithm_Detection_Camera_DBM_Vars *)varsPtr;
	QVector<Simulator_Sensor_Camera_Params *> inputparams; copyQVector(inputparams,inputParams);
	QVector<Simulator_Sensor_Camera_Data *> inputdata; copyQVector(inputdata,inputData);
	ProcessorMono_Algorithm_Detection_Camera_DBM_Data * outputdata=(ProcessorMono_Algorithm_Detection_Camera_DBM_Data *)outputData;
	outputPortIndex=QList<int>();
	if(inputdata.size()==0){return 0;}
	/*======Please Program below======*/
	/*
	Step 1: process inputdata, then store it into outputdata.
	Step 2 [optional]: determine the outputPortIndex. (if not, outputdata will be sent by all ports)
	E.g. outputPortIndex=QList<int>()<<(outportindex1)<<(outportindex2)...
	*/
    if(vars->init)
    {
        params->cameraid=inputparams[0]->cameraid;
        params->size=inputparams[0]->size;
        params->calibmat=inputparams[0]->calibmat;
        params->distcoef=inputparams[0]->distcoef;
        params->rotation=inputparams[0]->rotation;
        params->translation=inputparams[0]->translation;
        params->rectsize=inputparams[0]->rectsize;
        params->rectrotation=inputparams[0]->rectrotation;
        params->rectprojection=inputparams[0]->rectprojection;
        params->refcamrectrot=inputparams[0]->refcamrectrot;
        vars->init=0;
    }
    cv::Size imgsize=inputdata[0]->image.size();
    imgsize.width=int(imgsize.width*vars->compressrate);
    imgsize.height=int(imgsize.height*vars->compressrate);
    cv::resize(inputdata[0]->image,outputdata->image,imgsize);
    outputdata->timestamp=inputdata[0]->timestamp;

    std::vector<cv::LatentSvmDetector::ObjectDetection> objects;
    vars->detector.detect(outputdata->image,objects,vars->threshold1,vars->threadnum);
    outputdata->image=inputdata[0]->image;
    int i,n=objects.size();
    outputdata->objects.clear();
    for(i=0;i<n;i++)
    {
        if(objects[i].score>=vars->threshold2)
        {
            objects[i].rect.x/=vars->compressrate;
            objects[i].rect.y/=vars->compressrate;
            objects[i].rect.width/=vars->compressrate;
            objects[i].rect.height/=vars->compressrate;
            outputdata->objects.push_back(objects[i]);
        }
    }
	return 1;
}

