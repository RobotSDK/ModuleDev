//You need to program this file.

#include "../NoEdit/VisualizationMono_Sensor_GPSIMU_PrivFunc.h"

//*******************Please add static libraries below*******************

#pragma comment(lib,"Kernel.lib")

#ifdef _DEBUG

#else

#endif

bool DECOFUNC(setParamsVarsOpenNode)(QString qstrConfigName, QString qstrNodeType, QString qstrNodeClass, QString qstrNodeName, void * paramsPtr, void * varsPtr)
{
	XMLDomInterface xmlloader(qstrConfigName,qstrNodeType,qstrNodeClass,qstrNodeName);
	VisualizationMono_Sensor_GPSIMU_Params * params=(VisualizationMono_Sensor_GPSIMU_Params *)paramsPtr;
	VisualizationMono_Sensor_GPSIMU_Vars * vars=(VisualizationMono_Sensor_GPSIMU_Vars *)varsPtr;
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
	campos.block<3,3>(0,0)=Eigen::AngleAxisd(-0.5*pi,Eigen::Vector3d::UnitZ()).toRotationMatrix();
	campos(2,3)=30.0;
	vars->viewer->setCameraPose(campos);

	vars->viewer->update();
	vars->poses.clear();
	vars->lastpose=Eigen::Matrix4d::Identity();
	return 1;
}

bool DECOFUNC(handleVarsCloseNode)(void * paramsPtr, void * varsPtr)
{
	VisualizationMono_Sensor_GPSIMU_Params * params=(VisualizationMono_Sensor_GPSIMU_Params *)paramsPtr;
	VisualizationMono_Sensor_GPSIMU_Vars * vars=(VisualizationMono_Sensor_GPSIMU_Vars *)varsPtr;
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
	vars->displaylist=0;
	vars->viewer->update();
	vars->poses.clear();
	vars->lastpose=Eigen::Matrix4d::Identity();
	return 1;
}

void DECOFUNC(getInternalTrigger)(void * paramsPtr, void * varsPtr, QObject * & internalTrigger, QString & internalTriggerSignal)
{
	VisualizationMono_Sensor_GPSIMU_Params * params=(VisualizationMono_Sensor_GPSIMU_Params *)paramsPtr;
	VisualizationMono_Sensor_GPSIMU_Vars * vars=(VisualizationMono_Sensor_GPSIMU_Vars *)varsPtr;
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
	VisualizationMono_Sensor_GPSIMU_Params * params=(VisualizationMono_Sensor_GPSIMU_Params *)paramsPtr;
	VisualizationMono_Sensor_GPSIMU_Vars * vars=(VisualizationMono_Sensor_GPSIMU_Vars *)varsPtr;
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

//Input Port #0: Buffer_Size = 10, Params_Type = Simulator_Sensor_GPSIMU_Params, Data_Type = Simulator_Sensor_GPSIMU_Data
bool DECOFUNC(processMonoDrainData)(void * paramsPtr, void * varsPtr, QVector<void *> drainParams, QVector<void *> drainData)
{
	VisualizationMono_Sensor_GPSIMU_Params * params=(VisualizationMono_Sensor_GPSIMU_Params *)paramsPtr;
	VisualizationMono_Sensor_GPSIMU_Vars * vars=(VisualizationMono_Sensor_GPSIMU_Vars *)varsPtr;
	QVector<Simulator_Sensor_GPSIMU_Params *> drainparams; copyQVector(drainparams,drainParams);
	QVector<Simulator_Sensor_GPSIMU_Data *> draindata; copyQVector(draindata,drainData);
	if(draindata.size()==0){return 0;}
	/*======Please Program below======*/
	/*
	Function: process draindata.
	*/
	//Eigen::Vector3d offset;
	//if(vars->poses.size()>0)
	//{
	//	offset=draindata.front()->pose.block<3,1>(0,3)-vars->poses.back().block<3,1>(0,3);
	//	Eigen::Matrix4d camerapos=vars->viewer->getCameraPose();
	//	camerapos.block<3,1>(0,3)=camerapos.block<3,1>(0,3)+offset;
	//	vars->viewer->setCameraPose(camerapos);
	//}

	int i,n=draindata.size();
	for(i=n-1;i>=0;i--)
	{
		vars->poses.push_back(draindata[i]->pose);
	}
	vars->viewer->makeCurrent();
	QVector<Eigen::Vector3d> poses;
	Eigen::Matrix4d normalize=vars->poses.front().inverse();
	glNewList(vars->displaylist,GL_COMPILE);
	glBegin(GL_LINE_STRIP);
	n=vars->poses.size();
	glColor3f(1.0,1.0,1.0);
	for(i=0;i<n;i++)
	{
		Eigen::Vector3d pose=(normalize*vars->poses[i]).block<3,1>(0,3);
		poses.push_back(pose);
		glVertex3d(pose.x(),pose.y(),pose.z());
	}
	glEnd();
	Eigen::Matrix4d ends=Eigen::Matrix4d::Identity();
	ends(3,0)=1;ends(3,1)=1;ends(3,2)=1;
	ends=normalize*vars->poses.back()*ends;
	glBegin(GL_LINES);
	glColor3f(1.0,0.0,0.0);
	glVertex3d(ends(0,3),ends(1,3),ends(2,3));
	glVertex3d(ends(0,0),ends(1,0),ends(2,0));
	glColor3f(0.0,1.0,0.0);
	glVertex3d(ends(0,3),ends(1,3),ends(2,3));
	glVertex3d(ends(0,1),ends(1,1),ends(2,1));
	glColor3f(0.0,0.0,1.0);
	glVertex3d(ends(0,3),ends(1,3),ends(2,3));
	glVertex3d(ends(0,2),ends(1,2),ends(2,2));
	glEnd();
	glEndList();

	Eigen::Matrix4d camtrans=(normalize*vars->poses.back())*vars->lastpose.inverse();
	Eigen::Matrix4d campose=camtrans*vars->viewer->getCameraPose();
	vars->viewer->setCameraPose(campose);
	vars->lastpose=(normalize*vars->poses.back());

	vars->viewer->update();	
	return 1;
}

void DECOFUNC(visualizationWidgets)(void * paramsPtr, void * varsPtr, QList<QWidget *> & widgets)
{
	VisualizationMono_Sensor_GPSIMU_Params * params=(VisualizationMono_Sensor_GPSIMU_Params *)paramsPtr;
	VisualizationMono_Sensor_GPSIMU_Vars * vars=(VisualizationMono_Sensor_GPSIMU_Vars *)varsPtr;
	widgets=QList<QWidget *>()<<vars->viewer;
	/*======Please Program above======*/
	/*
	Function: get visualization widgets [defined in vars].
	You need to program here when you need visualization widgets.
	E.g.
	widgets=QList<QWidget *>()<<(vars->visualization_1)<<(vars->visualization_2)...;
	*/
}

