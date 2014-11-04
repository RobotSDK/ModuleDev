//You need to program this file.

#include "../NoEdit/VisualizationMono_Sensor_Velodyne_PrivFunc.h"

//*******************Please add static libraries in .pro file*******************
//e.g. unix:LIBS += ... or win32:LIBS += ...

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	VisualizationMono_Sensor_Velodyne_Params * params=(VisualizationMono_Sensor_Velodyne_Params *)paramsPtr;
	VisualizationMono_Sensor_Velodyne_Vars * vars=(VisualizationMono_Sensor_Velodyne_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: open node.
	Procedure:
	1: load parameters (params). [GetParamValue(xmlloader,params,tag); GetEnumParamValue(xmlloader,params,tag); GetUEnumParamValue(xmlloader,params,tag)]
	2: initialize variables (vars).
	3: If everything is OK, return 1 for successful opening and vice versa.
	*/
    vars->viewer->makeCurrent();
    vars->displaylist=glGenLists(1);
    vars->viewer->addDisplayList(vars->displaylist);

    Eigen::Matrix4d campos=Eigen::Matrix4d::Identity();
    double pi=3.1415926535897932384626433832795;
    campos.block<3,3>(0,0)=(Eigen::AngleAxisd(-0.5*pi,Eigen::Vector3d::UnitY())*Eigen::AngleAxisd(-0.5*pi,Eigen::Vector3d::UnitZ())).toRotationMatrix();
    vars->viewer->setCameraPose(campos);

    vars->viewer->update();

	return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	VisualizationMono_Sensor_Velodyne_Params * params=(VisualizationMono_Sensor_Velodyne_Params *)paramsPtr;
	VisualizationMono_Sensor_Velodyne_Vars * vars=(VisualizationMono_Sensor_Velodyne_Vars *)varsPtr;
	/*======Please Program below======*/
	/*
	Function: close node.
	Procedure:
	1: handle/close variables (vars).
	2: If everything is OK, return 1 for successful closing and vice versa.
	*/
    vars->viewer->makeCurrent();
    vars->viewer->clearDisplayList();
    glDeleteLists(vars->displaylist,1);
    Eigen::Matrix4d campos=Eigen::Matrix4d::Identity();
    vars->viewer->setCameraPose(campos);
    vars->viewer->update();
    return 1;
}

void DECOFUNC(getInternalTrigger)(void * paramsPtr, void * varsPtr, QObject * & internalTrigger, QString & internalTriggerSignal)
{
	VisualizationMono_Sensor_Velodyne_Params * params=(VisualizationMono_Sensor_Velodyne_Params *)paramsPtr;
	VisualizationMono_Sensor_Velodyne_Vars * vars=(VisualizationMono_Sensor_Velodyne_Vars *)varsPtr;
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
	VisualizationMono_Sensor_Velodyne_Params * params=(VisualizationMono_Sensor_Velodyne_Params *)paramsPtr;
	VisualizationMono_Sensor_Velodyne_Vars * vars=(VisualizationMono_Sensor_Velodyne_Vars *)varsPtr;
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

//Input Port #0: Buffer_Size = 0, Params_Type = Simulator_Sensor_Velodyne_Params, Data_Type = Simulator_Sensor_Velodyne_Data
bool DECOFUNC(processMonoDrainData)(void * paramsPtr, void * varsPtr, QVector<void *> drainParams, QVector<void *> drainData)
{
	VisualizationMono_Sensor_Velodyne_Params * params=(VisualizationMono_Sensor_Velodyne_Params *)paramsPtr;
	VisualizationMono_Sensor_Velodyne_Vars * vars=(VisualizationMono_Sensor_Velodyne_Vars *)varsPtr;
	QVector<Simulator_Sensor_Velodyne_Params *> drainparams; copyQVector(drainparams,drainParams);
	QVector<Simulator_Sensor_Velodyne_Data *> draindata; copyQVector(draindata,drainData);
	if(draindata.size()==0){return 0;}
	/*======Please Program below======*/
	/*
	Function: process draindata.
	*/
    vars->viewer->makeCurrent();

    int i,n=draindata.front()->cloud->size();
    QVector<float> colors(3*n);
    for(i=0;i<n;i++)
    {
        colors[i*3+0]=(*(draindata.front()->cloud))[i].data[3];
        colors[i*3+1]=(*(draindata.front()->cloud))[i].data[3];
        colors[i*3+2]=(*(draindata.front()->cloud))[i].data[3];
    }

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glVertexPointer(3,GL_FLOAT,sizeof(pcl::PointXYZ),draindata.front()->cloud->points.data());
    glColorPointer(3,GL_FLOAT,3*sizeof(float),colors.data());


    glNewList(vars->displaylist,GL_COMPILE);

    glDrawArrays(GL_POINTS,0,n);

    glEndList();

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);

    vars->viewer->update();

	return 1;
}

void DECOFUNC(visualizationWidgets)(void * paramsPtr, void * varsPtr, QList<QWidget *> & widgets)
{
	VisualizationMono_Sensor_Velodyne_Params * params=(VisualizationMono_Sensor_Velodyne_Params *)paramsPtr;
	VisualizationMono_Sensor_Velodyne_Vars * vars=(VisualizationMono_Sensor_Velodyne_Vars *)varsPtr;
    widgets=QList<QWidget *>()<<vars->viewer;
	/*======Please Program above======*/
	/*
	Function: get visualization widgets [defined in vars].
	You need to program here when you need visualization widgets.
	E.g.
	widgets=QList<QWidget *>()<<(vars->visualization_1)<<(vars->visualization_2)...;
	*/
}

