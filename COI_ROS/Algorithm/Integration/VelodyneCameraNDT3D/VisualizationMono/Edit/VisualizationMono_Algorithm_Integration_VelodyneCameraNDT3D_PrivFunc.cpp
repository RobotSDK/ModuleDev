//You need to program this file.

#include "../NoEdit/VisualizationMono_Algorithm_Integration_VelodyneCameraNDT3D_PrivFunc.h"

//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	VisualizationMono_Algorithm_Integration_VelodyneCameraNDT3D_Params * params=(VisualizationMono_Algorithm_Integration_VelodyneCameraNDT3D_Params *)paramsPtr;
	VisualizationMono_Algorithm_Integration_VelodyneCameraNDT3D_Vars * vars=(VisualizationMono_Algorithm_Integration_VelodyneCameraNDT3D_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: open node.
	Procedure:
	1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
	2: initialize variables (vars).
	3: If everything is OK, return 1 for successful opening and vice versa.
	*/
    GetParamValue(xmlloader,vars,maxframes);

    vars->viewer->makeCurrent();
    vars->velodynecamerandt3dlist=glGenLists(vars->maxframes);
    vars->viewer->addDisplayLists(vars->velodynecamerandt3dlist,vars->maxframes);
    vars->curid=0;

    vars->ndt3dlist=glGenLists(1);
    vars->viewer->addDisplayList(vars->ndt3dlist);
    vars->positions.clear();

    Eigen::Matrix4d camerapose=Eigen::Matrix4d::Identity();
    camerapose(2,3)=10;
    vars->viewer->setCameraPose(camerapose);
    vars->viewer->update();
	return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	VisualizationMono_Algorithm_Integration_VelodyneCameraNDT3D_Params * params=(VisualizationMono_Algorithm_Integration_VelodyneCameraNDT3D_Params *)paramsPtr;
	VisualizationMono_Algorithm_Integration_VelodyneCameraNDT3D_Vars * vars=(VisualizationMono_Algorithm_Integration_VelodyneCameraNDT3D_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: close node.
	Procedure:
	1: handle/close variables (vars).
	2: If everything is OK, return 1 for successful closing and vice versa.
	*/
    vars->viewer->makeCurrent();
    vars->viewer->clearDisplayList();
    glDeleteLists(vars->velodynecamerandt3dlist,vars->maxframes);
    vars->curid=0;

    glDeleteLists(vars->ndt3dlist,1);
    vars->positions.clear();

    Eigen::Matrix4d camerapose=Eigen::Matrix4d::Identity();
    camerapose(2,3)=10;
    vars->viewer->setCameraPose(camerapose);
    vars->viewer->update();
	return 1;
}

void DECOFUNC(getInternalTrigger)(void * paramsPtr, void * varsPtr, QObject * & internalTrigger, QString & internalTriggerSignal)
{
	VisualizationMono_Algorithm_Integration_VelodyneCameraNDT3D_Params * params=(VisualizationMono_Algorithm_Integration_VelodyneCameraNDT3D_Params *)paramsPtr;
	VisualizationMono_Algorithm_Integration_VelodyneCameraNDT3D_Vars * vars=(VisualizationMono_Algorithm_Integration_VelodyneCameraNDT3D_Vars *)varsPtr;
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
	VisualizationMono_Algorithm_Integration_VelodyneCameraNDT3D_Params * params=(VisualizationMono_Algorithm_Integration_VelodyneCameraNDT3D_Params *)paramsPtr;
	VisualizationMono_Algorithm_Integration_VelodyneCameraNDT3D_Vars * vars=(VisualizationMono_Algorithm_Integration_VelodyneCameraNDT3D_Vars *)varsPtr;
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

//Input Port #0: Buffer_Size = 0, Params_Type = ProcessorMulti_Algorithm_Integration_VelodyneCameraNDT3D_Params, Data_Type = ProcessorMulti_Algorithm_Integration_VelodyneCameraNDT3D_Data
bool DECOFUNC(processMonoDrainData)(void * paramsPtr, void * varsPtr, QVector<void *> drainParams, QVector<void *> drainData)
{
	VisualizationMono_Algorithm_Integration_VelodyneCameraNDT3D_Params * params=(VisualizationMono_Algorithm_Integration_VelodyneCameraNDT3D_Params *)paramsPtr;
	VisualizationMono_Algorithm_Integration_VelodyneCameraNDT3D_Vars * vars=(VisualizationMono_Algorithm_Integration_VelodyneCameraNDT3D_Vars *)varsPtr;
	QVector<ProcessorMulti_Algorithm_Integration_VelodyneCameraNDT3D_Params *> drainparams; copyQVector(drainparams,drainParams);
	QVector<ProcessorMulti_Algorithm_Integration_VelodyneCameraNDT3D_Data *> draindata; copyQVector(draindata,drainData);
	if(draindata.size()==0){return 0;}
	/*======Please Program below======*/
	/*
	Function: process draindata.
	*/
    vars->tabwidget->setTabText(0,QString("%1 - %2 - %3").arg(draindata[0]->velodynetimestamp.toString("HH:mm:ss:zzz"))
                                                         .arg(draindata[0]->cameratimestamp.toString("HH:mm:ss:zzz"))
                                                         .arg(draindata[0]->ndt3dtimestamp.toString("HH:mm:ss:zzz")));

    vars->viewer->makeCurrent();

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    void * pointsptr=(void *)(draindata[0]->pclpoints->points.data());
    glVertexPointer(3,GL_FLOAT,sizeof(pcl::PointXYZI),pointsptr);

    void * colorsptr=pointsptr+sizeof(pcl::PointXYZ)+sizeof(float);
    glColorPointer(3,GL_FLOAT,sizeof(pcl::PointXYZI),colorsptr);

    GLuint list=vars->velodynecamerandt3dlist+vars->curid;
    glNewList(list,GL_COMPILE);
    vars->curid=(vars->curid+1)%(vars->maxframes);

    int pointsnum=draindata[0]->pclpoints->size();
    glDrawArrays(GL_POINTS,0,pointsnum);

    glEndList();

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);

    vars->viewer->update();

    glEnableClientState(GL_VERTEX_ARRAY);

    vars->positions.push_back(draindata[0]->cvtransform.at<double>(0,3));
    vars->positions.push_back(draindata[0]->cvtransform.at<double>(1,3));
    vars->positions.push_back(draindata[0]->cvtransform.at<double>(2,3));
    vars->positions.push_back(1);

    int posenum=vars->positions.size()/4;
    cv::Mat pose=cv::Mat(posenum,4,CV_64F,vars->positions.data());
    glVertexPointer(3,GL_DOUBLE,4*sizeof(double),pose.data);

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
	VisualizationMono_Algorithm_Integration_VelodyneCameraNDT3D_Params * params=(VisualizationMono_Algorithm_Integration_VelodyneCameraNDT3D_Params *)paramsPtr;
	VisualizationMono_Algorithm_Integration_VelodyneCameraNDT3D_Vars * vars=(VisualizationMono_Algorithm_Integration_VelodyneCameraNDT3D_Vars *)varsPtr;
    widgets=QList<QWidget *>()<<(vars->tabwidget);
	/*======Please Program above======*/
	/*
	Function: get visualization widgets [defined in vars].
	You need to program here when you need visualization widgets.
	E.g.
	widgets=QList<QWidget *>()<<(vars->visualization_1)<<(vars->visualization_2)...;
	*/
}

