//You need to program this file.

#include "../NoEdit/ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_PrivFunc.h"

//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_Params * params=(ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_Params *)paramsPtr;
	ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_Vars * vars=(ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: open node.
	Procedure:
	1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
	2: initialize variables (vars).
	3: If everything is OK, return 1 for successful opening and vice versa.
	*/
    GetParamValue(xmlloader,params,range);
    GetParamValue(xmlloader,params,minz);
    GetParamValue(xmlloader,params,height);
    GetParamValue(xmlloader,vars,neighbornum);
    GetParamValue(xmlloader,vars,alpha);
    GetParamValue(xmlloader,vars,smoothness);
    GetParamValue(xmlloader,vars,curvthreshold);

	return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_Params * params=(ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_Params *)paramsPtr;
	ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_Vars * vars=(ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_Vars *)varsPtr;
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
	ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_Params * params=(ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_Params *)paramsPtr;
	ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_Vars * vars=(ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_Vars *)varsPtr;
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
	ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_Params * params=(ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_Params *)paramsPtr;
	ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_Vars * vars=(ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_Vars *)varsPtr;
	outputDataPtr=boost::shared_ptr<void>(new ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_Data());
	/*======Occasionally Program below/above======*/
	/*
	Function: initial output data.
	You need to program here when you need to manually initialize output data.
	*/
	
}

void DECOFUNC(getMonoInputDataSize)(void * paramsPtr, void * varsPtr, int & inputDataSize)
{
	ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_Params * params=(ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_Params *)paramsPtr;
	ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_Vars * vars=(ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_Vars *)varsPtr;
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
	ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_Params * params=(ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_Params *)paramsPtr;
	ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_Vars * vars=(ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_Vars *)varsPtr;
	QVector<Simulator_Sensor_Velodyne_Params *> inputparams; copyQVector(inputparams,inputParams);
	QVector<Simulator_Sensor_Velodyne_Data *> inputdata; copyQVector(inputdata,inputData);
	ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_Data * outputdata=(ProcessorMono_Algorithm_Segmentation_Velodyne_GroundObjects_Data *)outputData;
	outputPortIndex=QList<int>();
	if(inputdata.size()==0){return 0;}
	/*======Please Program below======*/
	/*
	Step 1: process inputdata, then store it into outputdata.
	Step 2 [optional]: determine the outputPortIndex. (if not, outputdata will be sent by all ports)
	E.g. outputPortIndex=QList<int>()<<(outportindex1)<<(outportindex2)...
	*/
    params->calib2camera=inputparams.front()->calib2camera;

    outputdata->cloud=inputdata.front()->cloud;
    outputdata->timestamp=inputdata.front()->timestamp;
    outputdata->starttime=inputdata.front()->starttime;
    outputdata->endtime=inputdata.front()->endtime;

    pcl::IndicesPtr indices(new std::vector<int>);
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::IndicesPtr groundid(new std::vector<int>);

    pcl::PassThrough<pcl::PointXYZ> ptfilter;

    ptfilter.setInputCloud(outputdata->cloud);
    ptfilter.setFilterFieldName("x");
    ptfilter.setFilterLimits(-params->range,params->range);
    ptfilter.filter(*indices);

    ptfilter.setIndices(indices);
    ptfilter.setFilterFieldName("y");
    ptfilter.setFilterLimits(-params->range,params->range);
    ptfilter.filter(*cloud);

    pcl::search::Search<pcl::PointXYZ>::Ptr tree(new pcl::search::KdTree<pcl::PointXYZ>);
    pcl::PointCloud <pcl::Normal>::Ptr normals(new pcl::PointCloud <pcl::Normal>);
    pcl::NormalEstimation<pcl::PointXYZ, pcl::Normal> normal_estimator;
    normal_estimator.setInputCloud(cloud);
    normal_estimator.setSearchMethod(tree);
    normal_estimator.setKSearch(vars->neighbornum);
    normal_estimator.compute(*normals);

    pcl::PassThrough<pcl::PointXYZ> ptfiltercloud;
    ptfiltercloud.setInputCloud(cloud);
    ptfiltercloud.setFilterFieldName("z");
    ptfiltercloud.setFilterLimits(params->minz,params->minz+params->height);
    ptfiltercloud.filter(*indices);

    int i,n=indices->size();
    if(n<3)
    {
        return 0;
    }

    float pi=3.14159265359;
    (*groundid).clear();
    for(i=0;i<n;i++)
    {
        float normalvalue=acos((*normals)[(*indices)[i]].normal_z)*180.0/pi;
        if(normalvalue>90)
        {
            normalvalue=180-normalvalue;
        }
        if(normalvalue<vars->alpha)
        {
            (*groundid).push_back((*indices)[i]);
        }
    }

    pcl::ExtractIndices<pcl::PointXYZ> extract;
    extract.setInputCloud(cloud);
    extract.setIndices(groundid);
    extract.filter(*(outputdata->ground));
    extract.setNegative(1);
    extract.filter(*(outputdata->objects));

	return 1;
}

