//You need to program this file.

#include "../NoEdit/VisualizationMono_Algorithm_Segmentation_Velodyne_PrivFunc.h"

//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	VisualizationMono_Algorithm_Segmentation_Velodyne_Params * params=(VisualizationMono_Algorithm_Segmentation_Velodyne_Params *)paramsPtr;
	VisualizationMono_Algorithm_Segmentation_Velodyne_Vars * vars=(VisualizationMono_Algorithm_Segmentation_Velodyne_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: open node.
	Procedure:
	1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
	2: initialize variables (vars).
	3: If everything is OK, return 1 for successful opening and vice versa.
	*/
    vars->viewer->makeCurrent();
    vars->segmentlist=glGenLists(1);
    vars->viewer->addDisplayList(vars->segmentlist);
    Eigen::Matrix4d camerapose=Eigen::Matrix4d::Identity();
    camerapose(2,3)=10;
    vars->viewer->setCameraPose(camerapose);
    vars->viewer->update();
	return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	VisualizationMono_Algorithm_Segmentation_Velodyne_Params * params=(VisualizationMono_Algorithm_Segmentation_Velodyne_Params *)paramsPtr;
	VisualizationMono_Algorithm_Segmentation_Velodyne_Vars * vars=(VisualizationMono_Algorithm_Segmentation_Velodyne_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: close node.
	Procedure:
	1: handle/close variables (vars).
	2: If everything is OK, return 1 for successful closing and vice versa.
	*/
    vars->viewer->makeCurrent();
    vars->viewer->deleteDisplayList(vars->segmentlist);
    glDeleteLists(vars->segmentlist,1);
    Eigen::Matrix4d camerapose=Eigen::Matrix4d::Identity();
    camerapose(2,3)=10;
    vars->viewer->setCameraPose(camerapose);
    vars->viewer->update();
	return 1;
}

void DECOFUNC(getInternalTrigger)(void * paramsPtr, void * varsPtr, QObject * & internalTrigger, QString & internalTriggerSignal)
{
	VisualizationMono_Algorithm_Segmentation_Velodyne_Params * params=(VisualizationMono_Algorithm_Segmentation_Velodyne_Params *)paramsPtr;
	VisualizationMono_Algorithm_Segmentation_Velodyne_Vars * vars=(VisualizationMono_Algorithm_Segmentation_Velodyne_Vars *)varsPtr;
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

void DECOFUNC(getMonoDrainDataSize)(void * paramsPtr, void * varsPtr, int & drainDataSize)
{
	VisualizationMono_Algorithm_Segmentation_Velodyne_Params * params=(VisualizationMono_Algorithm_Segmentation_Velodyne_Params *)paramsPtr;
	VisualizationMono_Algorithm_Segmentation_Velodyne_Vars * vars=(VisualizationMono_Algorithm_Segmentation_Velodyne_Vars *)varsPtr;
	drainDataSize=0;
	/*======Please Program above======*/
	/*
	Function: get drain data size to be grabbed from buffer.
	Rules:
	drainDataSize=0: grab and remove all data from buffer.
	drainDataSize>0: grab drainDataSize latest data from buffer.
	drainDataSize<0: grab and remove drainDataSize ancient data from buffer.
	*/
}

//Input Port #0: Buffer_Size = 0, Params_Type = SensorInternalEvent_Algorithm_Segmentation_Velodyne_Params, Data_Type = SensorInternalEvent_Algorithm_Segmentation_Velodyne_Data
bool DECOFUNC(processMonoDrainData)(void * paramsPtr, void * varsPtr, QVector<void *> drainParams, QVector<void *> drainData)
{
	VisualizationMono_Algorithm_Segmentation_Velodyne_Params * params=(VisualizationMono_Algorithm_Segmentation_Velodyne_Params *)paramsPtr;
	VisualizationMono_Algorithm_Segmentation_Velodyne_Vars * vars=(VisualizationMono_Algorithm_Segmentation_Velodyne_Vars *)varsPtr;
	QVector<SensorInternalEvent_Algorithm_Segmentation_Velodyne_Params *> drainparams; copyQVector(drainparams,drainParams);
	QVector<SensorInternalEvent_Algorithm_Segmentation_Velodyne_Data *> draindata; copyQVector(draindata,drainData);
	if(draindata.size()==0){return 0;}
	/*======Please Program below======*/
	/*
	Function: process draindata.
	*/
    vars->tabwidget->setTabText(0,draindata[0]->timestamp.toString("HH:mm:ss:zzz"));

    vars->viewer->makeCurrent();

    glNewList(vars->segmentlist,GL_COMPILE);

    glBegin(GL_POINTS);

    int i,n=draindata[0]->segmentations->data.size()/draindata[0]->segmentations->point_step;
    char * data=(char *)(draindata[0]->segmentations->data.data());
    for(i=0;i<n;i++)
    {
        float * tmpdata=(float *)(data+i*draindata[0]->segmentations->point_step);
        u_int16_t * label=(u_int16_t *)(tmpdata+5);
        cv::Vec3b color=vars->colormap.at<cv::Vec3b>(*label);
        glColor3f(color[0]/255.0,color[1]/255.0,color[2]/255.0);
        glVertex3f(tmpdata[0],tmpdata[1],tmpdata[2]);
    }

    glEnd();

    glEndList();

    vars->viewer->update();

	return 1;
}

void DECOFUNC(visualizationWidgets)(void * paramsPtr, void * varsPtr, QList<QWidget *> & widgets)
{
	VisualizationMono_Algorithm_Segmentation_Velodyne_Params * params=(VisualizationMono_Algorithm_Segmentation_Velodyne_Params *)paramsPtr;
	VisualizationMono_Algorithm_Segmentation_Velodyne_Vars * vars=(VisualizationMono_Algorithm_Segmentation_Velodyne_Vars *)varsPtr;
    widgets=QList<QWidget *>()<<(vars->tabwidget);
	/*======Please Program above======*/
	/*
	Function: get visualization widgets [defined in vars].
	You need to program here when you need visualization widgets.
	E.g.
	widgets=QList<QWidget *>()<<(vars->visualization_1)<<(vars->visualization_2)...;
	*/
}

