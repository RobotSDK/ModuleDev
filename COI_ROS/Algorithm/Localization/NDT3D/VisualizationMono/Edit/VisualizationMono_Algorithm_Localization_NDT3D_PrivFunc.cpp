//You need to program this file.

#include "../NoEdit/VisualizationMono_Algorithm_Localization_NDT3D_PrivFunc.h"

//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	VisualizationMono_Algorithm_Localization_NDT3D_Params * params=(VisualizationMono_Algorithm_Localization_NDT3D_Params *)paramsPtr;
	VisualizationMono_Algorithm_Localization_NDT3D_Vars * vars=(VisualizationMono_Algorithm_Localization_NDT3D_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: open node.
	Procedure:
	1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
	2: initialize variables (vars).
	3: If everything is OK, return 1 for successful opening and vice versa.
	*/
    vars->viewer->makeCurrent();
    vars->ndt3dlist=glGenLists(1);
    vars->viewer->addDisplayList(vars->ndt3dlist);
    Eigen::Matrix4d camerapose=Eigen::Matrix4d::Identity();
    camerapose(2,3)=10;
    vars->viewer->setCameraPose(camerapose);
    vars->viewer->update();
    vars->positions.clear();
    return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	VisualizationMono_Algorithm_Localization_NDT3D_Params * params=(VisualizationMono_Algorithm_Localization_NDT3D_Params *)paramsPtr;
	VisualizationMono_Algorithm_Localization_NDT3D_Vars * vars=(VisualizationMono_Algorithm_Localization_NDT3D_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: close node.
	Procedure:
	1: handle/close variables (vars).
	2: If everything is OK, return 1 for successful closing and vice versa.
	*/
    vars->viewer->makeCurrent();
    vars->viewer->deleteDisplayList(vars->ndt3dlist);
    glDeleteLists(vars->ndt3dlist,1);
    Eigen::Matrix4d camerapose=Eigen::Matrix4d::Identity();
    camerapose(2,3)=10;
    vars->viewer->setCameraPose(camerapose);
    vars->viewer->update();
    vars->positions.clear();
	return 1;
}

void DECOFUNC(getInternalTrigger)(void * paramsPtr, void * varsPtr, QObject * & internalTrigger, QString & internalTriggerSignal)
{
	VisualizationMono_Algorithm_Localization_NDT3D_Params * params=(VisualizationMono_Algorithm_Localization_NDT3D_Params *)paramsPtr;
	VisualizationMono_Algorithm_Localization_NDT3D_Vars * vars=(VisualizationMono_Algorithm_Localization_NDT3D_Vars *)varsPtr;
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
	VisualizationMono_Algorithm_Localization_NDT3D_Params * params=(VisualizationMono_Algorithm_Localization_NDT3D_Params *)paramsPtr;
	VisualizationMono_Algorithm_Localization_NDT3D_Vars * vars=(VisualizationMono_Algorithm_Localization_NDT3D_Vars *)varsPtr;
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

//Input Port #0: Buffer_Size = 0, Params_Type = SensorInternalEvent_Algorithm_Localization_NDT3D_Params, Data_Type = SensorInternalEvent_Algorithm_Localization_NDT3D_Data
bool DECOFUNC(processMonoDrainData)(void * paramsPtr, void * varsPtr, QVector<void *> drainParams, QVector<void *> drainData)
{
	VisualizationMono_Algorithm_Localization_NDT3D_Params * params=(VisualizationMono_Algorithm_Localization_NDT3D_Params *)paramsPtr;
	VisualizationMono_Algorithm_Localization_NDT3D_Vars * vars=(VisualizationMono_Algorithm_Localization_NDT3D_Vars *)varsPtr;
	QVector<SensorInternalEvent_Algorithm_Localization_NDT3D_Params *> drainparams; copyQVector(drainparams,drainParams);
	QVector<SensorInternalEvent_Algorithm_Localization_NDT3D_Data *> draindata; copyQVector(draindata,drainData);
	if(draindata.size()==0){return 0;}
	/*======Please Program below======*/
	/*
	Function: process draindata.
	*/
    vars->tabwidget->setTabText(0,draindata[0]->timestamp.toString("HH:mm:ss:zzz"));

    vars->viewer->makeCurrent();

    glEnableClientState(GL_VERTEX_ARRAY);

    vars->positions.push_back(draindata[0]->cvtransform.at<double>(0,3));
    vars->positions.push_back(draindata[0]->cvtransform.at<double>(1,3));
    vars->positions.push_back(draindata[0]->cvtransform.at<double>(2,3));
    vars->positions.push_back(1);

    int posenum=vars->positions.size()/4;
    cv::Mat pose=cv::Mat(posenum,4,CV_64F,vars->positions.data());
    cv::Mat invpose=pose*(draindata[0]->cvtransform.inv().t());

    glVertexPointer(3,GL_DOUBLE,4*sizeof(double),invpose.data);

    glNewList(vars->ndt3dlist,GL_COMPILE);

    glColor3f(1.0,1.0,1.0);

    glDrawArrays(GL_LINE_STRIP,0,posenum);

    glEndList();

    glDisableClientState(GL_VERTEX_ARRAY);

    vars->viewer->update();
	return 1;
}

void DECOFUNC(visualizationWidgets)(void * paramsPtr, void * varsPtr, QList<QWidget *> & widgets)
{
	VisualizationMono_Algorithm_Localization_NDT3D_Params * params=(VisualizationMono_Algorithm_Localization_NDT3D_Params *)paramsPtr;
	VisualizationMono_Algorithm_Localization_NDT3D_Vars * vars=(VisualizationMono_Algorithm_Localization_NDT3D_Vars *)varsPtr;
    widgets=QList<QWidget *>()<<(vars->tabwidget);
	/*======Please Program above======*/
	/*
	Function: get visualization widgets [defined in vars].
	You need to program here when you need visualization widgets.
	E.g.
	widgets=QList<QWidget *>()<<(vars->visualization_1)<<(vars->visualization_2)...;
	*/
}

